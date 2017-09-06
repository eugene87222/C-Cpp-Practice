#include <bits/stdc++.h>
using namespace std;

#define N 5000
void factor(int num,int *factors,int *is_comp){
	int i,j;
	for(i=2,j=0;i<=num;){
		if(!is_comp[i]&&num%i==0){
			factors[j++]=i;
			num/=i;
		}
		else i++;
	}
}
int is_perfect(int num,int *is_comp){
	int factors[N/2+1]={0};
	factor(num,factors,is_comp);
	int s=1,i=0;
	while(factors[i]!=0){
		int r=1,q=1;
		do{
			r*=factors[i];
			q+=r;
			i++;
		}while(factors[i-1]==factors[i]);
		s*=q;
	}
	return s/2==num;
}
int main(int argc, char const *argv[])
{
	int is_comp[N+1]={1,1,0};
	for(int i=0;i<N+1;i++){
		if(!is_comp[i]){
			for(int j=i+i;j<N+1;j+=i)
				is_comp[j]=1;
		}
	}
	for(int i=1;i<N+1;i++){
		if(is_perfect(i,is_comp))
			cout<<i<<endl;
	}
	return 0;
}