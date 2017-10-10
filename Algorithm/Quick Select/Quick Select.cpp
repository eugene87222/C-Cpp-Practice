#include <bits/stdc++.h>
using namespace std;

int partition(int *arr,int l,int r){
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<arr[r]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int quickselect(int *arr,int l,int r,int k){
    if(l==r)
        return arr[l];
    int j=partition(arr,l,r);
    int length=j-l+1;
    if(length==k)
        return arr[j];
    else if(k<length)
        return quickselect(arr,l,j-1,k);
    else
        return quickselect(arr,j+1,r,k-length);
}
int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    cout<<quickselect(arr,0,n-1,k)<<endl;
    return 0;
}