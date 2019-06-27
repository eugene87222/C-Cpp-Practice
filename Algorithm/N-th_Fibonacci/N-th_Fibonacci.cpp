#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
void multiply(ll a[2][2], ll b[2][2]){
    ll x=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    ll y=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    ll z=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    ll w=a[1][0]*b[0][1]+a[1][1]*b[1][1];
    a[0][0]=x%29989;
    a[0][1]=y%29989;
    a[1][0]=z%29989;
    a[1][1]=w%29989;
}
void power(ll a[2][2],ll n){
    if(n==0||n==1) return;
    ll b[2][2]={{1,1},{1,0}};
    power(a,n/2);
    multiply(a,a);
    if(n%2!=0)
        multiply(a,b);
}
ll fib(ll n){
    ll a[2][2]={{1,1},{1,0}};
    if(n==0) return 0;
    power(a,n-1);
    return a[0][0];
}
int main(){
	int t,n;
	while(cin>>t){
		while(t--){
			cin>>n;
			cout<<fib(n)<<endl;
		}
	}
    return 0;  
}