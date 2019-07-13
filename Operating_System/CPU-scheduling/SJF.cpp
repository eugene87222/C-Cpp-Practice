#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Process{
public:
    int ID;
    int arr_time, burst_time, remain;
    int waiting_time, turnaround_time;
};

bool Cmp_SJF(Process const &a, Process const &b){
    if(a.burst_time == b.burst_time){
        return a.arr_time > b.arr_time;
    }
    return a.burst_time > b.burst_time;
}

string print_format(double num){
    char str[32];
    sprintf(str, "%.5f", num);
    string res = "";
    int i = strlen(str)-1;
    while(str[i] == '0') i--;
    if(str[i] == '.'){
        i--;
    }
    for(int j=0; j<=i; j++){
        res += str[j];
    }
    return res;
}

void SJF(int process_num, Process process[]){
    int total_waiting_time = 0, total_turnaround_time = 0;
    int time_line = 0, running = -1, finished = 0;
    vector<Process> waiting_list;

    while(finished < process_num){ // look for the next process
         // add the process into waiting list once it arrives
        for(int i=0; i<process_num; i++){
            if(process[i].arr_time == time_line){
                waiting_list.push_back(process[i]);
            }
        }
        // SJF
        sort(waiting_list.begin(), waiting_list.end(), Cmp_SJF);
        
        // there is a running process
        if(running != -1){
            process[running].remain --;
            // finish !!
            if(process[running].remain == 0){
                process[running].waiting_time = time_line - process[running].arr_time - process[running].burst_time;
                process[running].turnaround_time = time_line - process[running].arr_time;
                finished ++;
                running = -1;
            }
        }
        
        // there is no running process and the waiting list is not empty
        if(running == -1 && !waiting_list.empty()){
            // last process in the waiting list is the one with the shortest busrt time
            running = waiting_list[waiting_list.size()-1].ID;
            waiting_list.pop_back();
        }

        time_line ++;
    }

    ofstream fout;
    fout.open("ans1.txt");
    for(int i=0; i<process_num; i++){
        fout << process[i].waiting_time << " " << process[i].turnaround_time << "\n";
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
    }
    double tmp = (double)total_waiting_time / (double)process_num;
    string res = print_format(tmp);
    fout << res << "\n";
    tmp = (double)total_turnaround_time / (double)process_num;
    res = print_format(tmp);
    fout << res << "\n";
    fout.close();
}

int main(int argc, char *argv[]){
    int process_num, arr_time, burst_time;

    ifstream fin;
    fin.open(argv[1]);
    fin >> process_num;
    Process process[100];
    for(int i=0; i<process_num; i++){
        fin >> arr_time;
        process[i].ID = i;
        process[i].arr_time = arr_time;
    }
    for(int i=0; i<process_num; i++){
        fin >> burst_time;
        process[i].burst_time = burst_time;
        process[i].remain = burst_time;
    }
    fin.close();
    
    SJF(process_num, process);
    
    return 0;
}