#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b,ll&x,ll&y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll r=gcd(b,a%b,y,x);
    ll t=x;
    y=y-a/b*t;
    return r;
}
int main(){ 
    return 0;  
}  