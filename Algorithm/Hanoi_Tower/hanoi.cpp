#include <bits/stdc++.h>
using namespace std;

int Time;
void hanoi(int n,char A,char B,char C){
    if(n==1){
        cout<<"Move disk from "<<A<<" to "<<C<<endl;
        Time++;
    }
    else{
        hanoi(n-1,A,C,B);
        hanoi(1,A,B,C);
        hanoi(n-1,B,A,C);
    }
}
int main(int argc, char const *argv[])
{
    int n;
	cout<<"Input number of disks: ";
    cin>>n;
    Time=0;
    hanoi(n,'A','B','C');
    cout<<"Total steps: "<<Time<<endl;
    return 0; 
}