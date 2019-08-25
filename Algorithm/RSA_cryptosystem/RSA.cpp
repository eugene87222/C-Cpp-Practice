#include <bits/stdc++.h>
#include "bignum.h"
using namespace std;

/* RSA cryptosystem */
/***********************************************/
/* 1.let p,q=two different prime               */
/* 2.N=p*q                                     */
/* 3.let r=(p-1)(q-1)                          */
/* 4.find e that gcd(e,r)=1                    */
/* 5.find d that e*d=1 mod r                   */
/* 6.(N,e) -> public key, (N,d) -> private key */
/* 7.c=m^e mod N (encryption)                  */
/* 8.m2=c^d mod N (decryption)                 */
/* m2 must equal to m                          */
/***********************************************/
BigNum seed("1");
BigNum rand(BigNum& a){
	seed=(seed*BigNum("1103515245")+BigNum("12345"))%a;
	return seed;
}
BigNum ext_euclidean(BigNum a,BigNum b,BigNum& x,BigNum& y){
	/* a*x+b*y=gcd(a,b) */
    if(b==BigNum("0")){
        x=BigNum("1");
        y=BigNum("0");
        return a;
    }
    BigNum r=ext_euclidean(b,a%b,y,x);
    BigNum t=x;
    y=y-a/b*t;
    return r;
}
/*
BigNum power(BigNum a,BigNum k,BigNum N){
	BigNum p("1"),i;
	for(i=BigNum("1");i<=k;i++)
		p=(p*a)%N;
	return p;
}
*/
BigNum power_faster(BigNum a,BigNum k,BigNum N){ /* recursive */
	if(k<BigNum("0"))
		assert(0);
	if(k==BigNum("0"))
		return BigNum("1");
	else if(k==BigNum("1"))
		return a;
	BigNum k2=k/2;
	BigNum re=k%2;
	BigNum ak2=power_faster(a,k2,N);
	BigNum ak=ak2*ak2;
	BigNum akN=ak%N;
	if(re==BigNum("1")){
		akN=akN*a;
		return akN%N;
	}
	else
		return akN;
}
void Modular_Inverse(BigNum& r,BigNum& e,BigNum& d,BigNum& k,BigNum& gcd){
	/*******************/
	/* Modular Inverse */
	/* gcd(e,r)=1      */
	/* e*d=1 mod r     */
	/* e*d-1=k*r       */
	/* d>0             */
	/*******************/
	do{
		e=rand(r);
		//cout<<e<<endl;
		gcd=ext_euclidean(e,r,d,k);
	}while(gcd!=BigNum("1")); /* make sure gcd(e,r)=1 */
	if(d<=BigNum("0")){   
		d+=r;		
		d=d%r;
	}
	if(k>=BigNum("0")){
		k-=e;
		k=k%e;
	}
}
int main(int argc, char const *argv[])
{
	BigNum p("2213"),q("2663"),N,r,e,d,k,gcd;
	N=p*q;
	r=(p-BigNum("1"))*(q-BigNum("1"));
	cout<<"N="<<N<<endl<<"r="<<r<<endl;
	Modular_Inverse(r,e,d,k,gcd);
	cout<<"e="<<e<<" d="<<d<<" r="<<r<<" (e*d) mod r=1"<<endl;
	BigNum m("123"),c,m2;
	cout<<"m="<<m<<endl;
	c=power_faster(m,e,N);
	cout<<"c="<<c<<endl;
	m2=power_faster(c,d,N);
	cout<<"m2="<<m2<<endl;
	return 0;
}
