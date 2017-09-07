#include <bits/stdc++.h>
using namespace std;

int isNarcissistic(double number){
	int digit[39]={0};
	double num=number;
	int i;
	for(i=0;num!=0;i++){
		digit[i]=(int)num%10;
		num=(int)(num/10);
	}
	double sum=0.0;
	int j;
	for(j=0;j<=i;j++)
		sum+=pow(digit[j],i);
	return sum==number;
}
void Narcissistic(double *armstrongs,int n){
	double bound=pow(10,n<40?n:39);
	double i;
	int j;
	for(i=0,j=0;i<bound;i++){
		if(isNarcissistic(i)){
			armstrongs[j]=i;
			j++;
		}
	}
}
int main(int argc, char const *argv[])
{
	double armstrongs[88]={0};
	Narcissistic(armstrongs,3);
	for(int i=0;armstrongs[i]!=0;i++)
		cout<<(int)armstrongs[i]<<endl;
	return 0;
}