#include <bits/stdc++.h>
using namespace std;

/* Find all combinations of a set (lexicographic) */
int MAXSIZE=20 ;
int getPosition(int *list){
	int i;
    for(i=0;list[i]!=0;i++);
    return i-1;
}
void print(int *list){
    cout<<"[";
    int i,position;
    for(i=0,position=getPosition(list);i<position;i++){
        cout<<list[i]<<" ";
    }
    if(position!=-1) cout<<list[i];
    cout<<"]"<<endl;
}
int hasNext(int *list,int n){
    int position=getPosition(list);
    return position==-1||list[position]<n||position!=0;
}
void next(int *list,int n){
    int position=getPosition(list);
    if(position==-1){
        list[0]=1;
    }
    else if(list[position]<n){
        list[position+1]=list[position]+1; 
    } 
    else if(position!=0){
        list[position]=0;
        list[position-1]++;
    } 
}
int main(int argc, char const *argv[])
{
	int list[MAXSIZE]={0}; 
    int n;
    cout<<"Input n (number of elements in the set): ";
    cin>>n;
    cout<<"[";
    for(int i=0;i<n;i++){
    	if(i) cout<<" ";
    	cout<<i+1;
    }
    cout<<"]"<<endl;
    cout<<"All combination of this set: "<<endl;
    print(list);
    while(hasNext(list,n)){
        next(list,n);
        print(list);
    }
    return 0; 
}