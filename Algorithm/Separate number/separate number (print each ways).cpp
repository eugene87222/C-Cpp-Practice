#include <bits/stdc++.h>
using namespace std;
#define N 100
int stk[N+1],pointer=1;
void generate(int remain){
	if(remain){
		int take=stk[pointer-1]>remain?remain:stk[pointer-1];
		int i;
		for(i=take;i>0;i--){
			stk[pointer++]=i;
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
			printf("%d",stk[i]);
		}
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)&&n){
		memset(stk,0,sizeof(stk));
		stk[0]=INT_MAX;
		generate(n);
	}
	return 0;
}