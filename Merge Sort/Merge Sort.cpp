#include <bits/stdc++.h>
using namespace std;

template <class T>
void merge_sort_rec(T *arr,T *reg,int start,int end) {
	if (start>=end) return;
	int len=end-start,mid=(len>>1)+start;
	int start1=start,end1=mid;
	int start2=mid+1,end2=end;
	merge_sort_rec(arr,reg,start1,end1);
	merge_sort_rec(arr,reg,start2,end2);
	int k=start;
	while(start1<=end1&&start2<=end2)
		reg[k++]=arr[start1]<arr[start2]?arr[start1++]:arr[start2++];
	while(start1<=end1)
		reg[k++]=arr[start1++];
	while(start2<=end2)
		reg[k++]=arr[start2++];
	for(k=start;k<=end;k++)
		arr[k]=reg[k];
}
template<typename T>
void merge_sort(T *arr,const int len) {
	T reg[len];
	merge_sort_rec(arr,reg,0,len-1);
}
int main(int argc, char const *argv[])
{
	int arr[]={1234,123,12,1,0};
	merge_sort(arr,5);
	for(int i=0;i<5;i++)
		cout<<arr[i]<<endl;
	return 0;
}