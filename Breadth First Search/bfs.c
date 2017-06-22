#include "load.h"
#include "queue.h"

int ans[128],size=0;
int check(int temp){
    int i;
    for(i=0;i<size;i++){
        if(ans[i]==temp)
            return 0;
    }
    return 1;
}
void bfs(){
    int temp,i;
    push(0);
    while(!isempty()){
        temp=pop();
        if(check(temp)){
            ans[size++]=temp;
            for(i=0;i<n;i++){
                if(mtrx[temp][i]==1){
                    if(check(i))
                        push(i);
                }
            }
        }
    }
    printf("The result of BFS:");
    for(i=0;i<size;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
