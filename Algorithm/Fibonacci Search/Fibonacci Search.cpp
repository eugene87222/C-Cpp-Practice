#include <bits/stdc++.h>
using namespace std;

/* * * * * * * * * * * * * *

 	Fy + m = n
 	Fy >= n + 1
 	x = y - 1
 	(n = length of array)

* * * * * * * * * * * * * */
void createFibonacci(int *Fib,int length){ 
    Fib[0]=0; 
    Fib[1]=1; 
    for(int i=2;i<length;i++) 
        Fib[i]=Fib[i-1]+Fib[i-2]; 
} 
int findY(int *Fib,int n){ 
    int i=0; 
    while(Fib[i]<=n) i++; 
    i--; 
    return i; 
} 
int fibonacciSearch(int *number,int length,int find){ 
    int *Fib=new int[length];
    for(int f=0;f<length;f++){
        Fib[f]=INT_MIN;
    }
    createFibonacci(Fib,length); 
    int y=findY(Fib,length+1); 
    int m=length-Fib[y]; 
    int x=y-1; 
    int i=x; 
    if(number[i]<find) 
        i+=m;
    int result=-1;
    while(Fib[x]>0){ 
        if(number[i]<find) 
            i+=Fib[--x]; 
        else if(number[i]>find) 
            i-=Fib[--x]; 
        else {
            result=i;
            break;
        }
    } 
    delete [] Fib;
    return result; 
}  
int main(int argc, char const *argv[])
{
	int number[]={1, 2, 3, 5, 6, 8, 9, 10, 11};
    int length=sizeof(number)/sizeof(int);
    cout<<"arr: ";
    int i;
    for(i=0;i<length;i++) 
        cout<<number[i]<<" ";
    cout<<endl;
    cout<<"Input number to search: ";
    int find;
    cin>>find;
    if((i=fibonacciSearch(number,length,find))>=0){
        cout<<"index: "<<i<<endl;
    }
    else{
        cout<<"cannot find the number"<<endl;
    }
	return 0;
}
