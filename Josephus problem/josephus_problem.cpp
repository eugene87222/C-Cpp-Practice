#include <bits/stdc++.h>
using namespace std;

/*************************************/
/* n: number of people in the circle */
/* k: count for each step            */
/* g(): index of the survivor        */
/* g(1,k)=0                          */
/* g(n,k)=(g(n-1,k)+k)%n             */
/*************************************/

/* find the last survivor directly (non-recursive) */
int josephus(int n,int k){
	int s=0;
	for(int i=2;i<=n;i++){
		s=(s+k)%i;
	}
	return s;
}
/* find the last survivor directly (recursive) */
int josephus_rec(int n,int k){
	return n>1?(josephus_rec(n-1,k)+k)%n:0;
}
int main(int argc, char const *argv[])
{
	cout<<josephus_rec(41,3)<<endl;
	return 0;
}