#include <bits/stdc++.h>
using namespace std;

/*************************************/
/* n: number of people in the circle */
/* k: count for each step            */
/* g(): index of the survivor        */
/* g(1,k)=0                          */
/* g(n,k)=(g(n-1,k)+k)%n             */
/*************************************/

/* find the last survivor directly */

int josephus(int n,int k){        /* non-recursive */
	int s=0;
	for(int i=2;i<=n;i++){
		s=(s+k)%i;
	}
	return s;
}

int josephus_rec(int n,int k){    /*  recursive */
	return n>1?(josephus_rec(n-1,k)+k)%n:0;
}

/******************************************************/

/* figure out the execution order of each person */

int next(int* man,int len,int n,int k){ /* pick the next person */
    int count=0;
    while(count<k) {
        n=(n+1)%len;
        if(man[n]==0) count++; /* if n-th person has not been killed, count him */
    }    
    return n;
}
void josephus(int* man,int len,int k){
    int i,n;
    for(i=1,n=-1;i<=len;i++){
        n=next(man,len,n,k);
        man[n]=i;
    }
}
int winner(int len,int k){
    int g,n;
    for(g=0,n=1;n<=len;n++){
        g=(g+k)%n;
    }
    return g;
}

/******************************************************/

int main(int argc, char const *argv[])
{
	int len=41;
	int step=3;

	int man[len];
	memset(man,0,sizeof(man));
	josephus(man,len,step);
	cout<<"Index  Order"<<endl;
	for(int i=0;i<len;i++)
		cout<<setw(5)<<i<<setw(7)<<man[i]<<endl;
	cout<<"Winner: "<<winner(len,step)<<endl<<endl;
	/*cout<<"Winner: "<<josephus_rec(len,step)<<endl;*/
	return 0;
}
