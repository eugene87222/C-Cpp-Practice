#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
int stack[N+1],pointer=1;
void generate(int remain){
	if(remain){
		int take=stack[pointer-1]>remain?remain:stack[pointer-1];
		int i;
		for(i=take;i>0;i--){
			stack[pointer++]=i;
			remain-=i;
			generate(remain);
			remain+=i;
			pointer--;
		}
	}
	else{
		int i=1;
		for(;i<pointer;i++){
			if(i!=1) printf(" ");
			printf("%d",stack[i]);
		}
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)&&n){
		memset(stack,0,sizeof(stack));
		stack[0]=INT_MAX;
		generate(n);
	}
	return 0;
}