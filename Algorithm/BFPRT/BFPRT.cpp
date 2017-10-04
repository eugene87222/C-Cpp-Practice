#include <bits/stdc++.h>
using namespace std;

int BFPRT(vector<int>& v,int left,int right,const int& k);
int InsertSort(vector<int>& v,int left,int right){  /* find median of one group */ 
    int temp;
    int j;
    for(int i=left+1;i<=right;i++){
        temp=v[i];
        j=i-1;
        while(j>=left&&v[j]>temp)
            v[j+1]=v[j--];
        v[j+1]=temp;
    }
    return ((right-left)>>1)+left;
}
int GetPivotIndex(vector<int>& v,int left,int right){  /* find median of median */
    if(right-left<5)
        return InsertSort(v,left,right);
    int sub_right=left-1;
    for(int i=left;i+4<=right;i+=5){
        int index=InsertSort(v,i,i+4);
        swap(v[++sub_right],v[index]);
    }
    return BFPRT(v,left,sub_right,((sub_right-left+1)>>1)+1);
}
int Partition(vector<int>& v,int left,int right,int pivot_index){
    swap(v[pivot_index],v[right]);
    int divide_index=left;
    for(int i=left;i<right;i++){
        if(v[i]<v[right])
            swap(v[divide_index++],v[i]);
    }
    swap(v[divide_index],v[right]);
    return divide_index;
}
int BFPRT(vector<int>& v,int left,int right,const int& k){
    int pivot_index=GetPivotIndex(v,left,right);
    int divide_index=Partition(v,left,right,pivot_index);
    int num=divide_index-left+1;
    if(num==k)
        return divide_index;
    else if(num>k)
        return BFPRT(v,left,divide_index-1,k);
    else
        return BFPRT(v,divide_index+1,right,k-num);
}
int main(){
	vector<int> v;
	int n,num,k,tmp;
    cout<<"Input length of vector: ";
	cin>>n;
    tmp=n;
	k=n/2+n%2;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	while(n%5){
		v.push_back(INT_MAX);
		n++;
	}
    cout<<"Before BFPRT: ";
    for (int i=0;i<tmp;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    cout<<"The "<<k<<"-th small element is "<<v[BFPRT(v,0,n-1,k)]<<endl;
    cout<<"After BFPRT: ";
    for (int i=0;i<tmp;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}