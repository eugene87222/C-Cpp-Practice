#include <bits/stdc++.h>
using namespace std;
#define NUM 10
#define DEBUG 1

/* f(5) = f(4, 1) + f(3,2) + f(2,3) + f(1,4) + f(0,5) 
		= f(4, 1) + f(3,2) + f(2,3) + f(1,1) + f(0,0) */
int main(void) { 
    int table[NUM][NUM/2+1]={0};
    int count=0; 
    int result=0; 
    int i,j,k; 
    cout<<"How many ways to separate "<<NUM<<endl;
    for(i=0;i<NUM;i++){ 
        table[i][0]=1;  // 任何數以0以下的數拆解必只有1種
        table[i][1]=1;  // 任何數以1以下的數拆解必只有1種 
    } 
    for(i=2;i<=NUM;i++){  // dp
       for(j=2;j<=i;j++){ 
            if(i+j>NUM)
                continue; 
            count=0;    
            for(k=1;k<=j;k++){ 
                count+=table[i-k][(i-k>=k)?k:i-k];  
            }
            table[i][j]=count;
        }        
    }
    for(k=1;k<=NUM;k++) 
        result+=table[NUM-k][(NUM-k>=k)?k:NUM-k];
    cout<<"result: "<<result<<endl;
    if(DEBUG){ 
        cout<<"DEBUG: "<<endl;
        for(i=0;i<NUM;i++){ 
            for(j=0;j<NUM/2+1;j++) 
                 cout<<setw(3)<<table[i][j];
            cout<<endl;
        }
    }
    return 0; 
}