#include "load.h"
#include <stdio.h>
#include <string.h>

void load() {
    char input[128];
    char *ptr;
    int i,j,num[64],size,count;
    for(i=0;i<128;i++){
        for(j=0;j<128;j++)
            mtrx[i][j]=0;
    }
    printf("Input n:");
    scanf("%d",&n); getchar();
    printf("Input the relation:\n");
    while(gets(input)&&strlen(input)!=0){
        size=0;
        ptr=input;
        while(sscanf(ptr,"%d%n",&num[size++],&count)==1)
            ptr+=count;
        for(i=1;i<size;i++){
            mtrx[num[0]][num[i]]=1;
            mtrx[num[i]][num[0]]=1;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",mtrx[i][j]);
        }
        printf("\n");
    }
}
