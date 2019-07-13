#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Process{
public:
    int ID;
    int arr_time, burst_time, remain;
    int waiting_time, turnaround_time;
    int quantum;
    int Q_ID;
};
Process process[100];
queue<int> High_RR, Medium_RR;
vector<Process> Low_SJF;

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

bool Cmp_SJF(Process const &a, Process const &b){
    if(a.remain == b.remain){
        return a.arr_time > b.arr_time;
    }
    return a.remain > b.remain;
}

int pick_next(){
    int next_id = -1;
    if(!High_RR.empty()){
        next_id = High_RR.front();
    }
    else{
        if(!Medium_RR.empty()){
            next_id = Medium_RR.front();
        }
        else{
            if(!Low_SJF.empty()){
                sort(Low_SJF.begin(), Low_SJF.end(), Cmp_SJF);
                next_id = Low_SJF[Low_SJF.size()-1].ID;
            }
        }
    }
    return next_id;
}

void process_finish(int id, int time_line){
    process[id].waiting_time = time_line - process[id].arr_time - process[id].burst_time;
    process[id].turnaround_time = time_line - process[id].arr_time;
    if(process[id].Q_ID == 1){
        High_RR.pop();
    }
    else if(process[id].Q_ID == 2){
        Medium_RR.pop();
    }
    else{
        Low_SJF.pop_back();
    }
}

void Multilevel_Q(int process_num, int quantum_1, int quantum_2){
    int total_waiting_time = 0, total_turnaround_time = 0;
    int time_line = 0, running = -1, finished = 0;
    int flag = 0;    
    while(finished < process_num){
        //cout << time_line << " " << running << endl;
        for(int i=0; i<process_num; i++){
            if(process[i].arr_time == time_line){
                process[i].quantum = quantum_1;
                process[i].Q_ID = 1;
                High_RR.push(i);
                if(running == -1){
                    running = pick_next();
                    flag = 1;
                }
                else if(process[running].Q_ID != 1){
                    if(process[running].Q_ID == 2){
                        process[running].remain --;
                        if(process[running].remain == 0){
                            process_finish(running, time_line);
                            finished ++;
                        }
                        else{
                            process[running].quantum --;
                            if(!process[running].quantum){
                                Medium_RR.pop();
                                process[running].Q_ID = 3;
                                process[running].quantum = -1;
                                Low_SJF.push_back(process[running]);
                            }
                        }
                    }
                    running = pick_next();
                    flag = 1;
                }
            }
        }
        if(flag){
            flag = 0;
            time_line ++;
            continue;
        }
        process[running].remain --;
        if(process[running].remain == 0){
            process_finish(running, time_line);
            finished ++;
            running = pick_next();
        }
        else{
            if(process[running].Q_ID != 3){
                process[running].quantum --;

                if(!process[running].quantum){
                    if(process[running].Q_ID == 1){
                        High_RR.pop();
                        process[running].Q_ID = 2;
                        process[running].quantum = quantum_2;
                        Medium_RR.push(running);
                    }
                    else{
                        Medium_RR.pop();
                        process[running].Q_ID = 3;
                        process[running].quantum = -1;
                        Low_SJF.push_back(process[running]);
                    }
                    running = pick_next();
                }
            }
        }
        
        time_line ++;
    }

    ofstream fout;
    fout.open("ans4.txt");
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
    int process_num, arr_time, burst_time, quantum_1, quantum_2;

    ifstream fin;
    fin.open(argv[1]);
    fin >> process_num;
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
    fin >> quantum_1 >> quantum_2;
    fin.close();
    
    Multilevel_Q(process_num, quantum_1, quantum_2);
    
    return 0;
}