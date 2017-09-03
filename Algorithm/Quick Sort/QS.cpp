#include <bits/stdc++.h>
using namespace std;

int cmp(const void *a,const void *b){
    int c=*(int*)a;
    int d=*(int*)b;
    if(c<d) return -1;
    else if(c==d) return 0;
    else return 1;
}
void quicksort(int* arr,int left,int right){
    if(left<right){
        int i=left+1,j=right,pivot=arr[left],temp;
        do{
            while(i<right&&arr[i]<=pivot) i++;
            while(j>left&&arr[j]>pivot) j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }while(i<j);
        temp=arr[j];
        arr[j]=arr[left];
        arr[left]=temp;
        quicksort(arr,left,j-1);
        quicksort(arr,j+1,right);
    }
}
int main()
{
    int size,i;
    while(1){
        printf("How many number do you want to sort ? (input 0 to exit)\n");
        scanf("%d",&size);
        if(size==0) break;
        else{
            int arr[size];
            printf("Input the numbers: ");
            for(i=0;i<size;i++)
                scanf("%d",&arr[i]);
  			quicksort(arr,0,size-1);
            printf("After quick sort: ");
            for(i=0;i<size;i++)
                printf("%d ",arr[i]);
            printf("\n\n");
        }
    }
    return 0;
}
