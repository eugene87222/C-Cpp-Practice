#include <bits/stdc++.h>
using namespace std;

/* Pick m elements from a set with n elements (m<=n) */
#define MAX 20
void init(int *list,int n){
    for(int i=0;i<n;i++)
    	list[i]=i+1;
}
int position(int *list,int m,int n){
    if(list[n-1]!=m){
        return n-1;
    }
    else{
        int pos=n-2;
        while(list[pos+1]-list[pos]==1) pos--;
        return pos;
    }
}
int hasNext(int *list,int m,int n){
    return list[0]<m-n+1;
}
void next(int *list,int m,int n){
    int pos=position(list,m,n);
    list[pos]++; 
    for(int i=pos+1;i<n;i++)
    	list[i]=list[i-1]+1;
}
void print(int *list,int n){        
    for(int i=0;i<n;i++)
    	cout<<list[i]<<" ";
    cout<<endl; 
}
int main(int argc, char const *argv[])
{
	int list[MAX]={0};
    int m,n; 
    
    cout<<"m(<20): ";
    cin>>m; 
    cout<<"n(<=m): "; 
    cin>>n; 
    
    init(list,n);
    print(list,n);
    while(hasNext(list,m,n)){
        next(list,m,n);
        print(list,n);
    } 
	return 0;
}
