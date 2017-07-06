#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ext_euclidean(ll a,ll b,ll&x,ll&y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll r=ext_euclidean(b,a%b,y,x);
    ll t=x;
    y=y-a/b*t;
    return r;
}
int main(){
	ll a=100,b=70;
	ll x,y,gcd;
	gcd=ext_euclidean(a,b,x,y);
	cout<<"a="<<a<<endl<<"b="<<b<<endl;
	cout<<x<<"*a+"<<y<<"*b="<<gcd<<endl;
    return 0;  
}  