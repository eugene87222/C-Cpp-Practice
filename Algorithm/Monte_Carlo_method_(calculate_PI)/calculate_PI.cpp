#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int sum=0;
	const int N=100000;
	for(int i=1;i<N;i++){
		double x=(double)rand()/RAND_MAX;
		double y=(double)rand()/RAND_MAX;
		if((x*x+y*y)<1){
			sum++;
		}
	}
	cout<<"PI = "<<(double)4*sum/(N-1)<<endl;
	return 0;
}