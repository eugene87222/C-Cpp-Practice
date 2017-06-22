#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "0516034.h"
using namespace std;
BigNum::BigNum(){
    fill(number,number+MAX,0);
}
BigNum::BigNum(const BigNum& a){
    for(int i=0;i<MAX;i++)
        (*this).number[i]=a.number[i];
}
BigNum::BigNum(const string& str){
	fill(number,number+MAX,0);
    bool isneg=(str[0]=='-');
	for(int i=isneg;i<str.length();i++){
        int idx=str.length()-i-1;
		number[idx/WIDTH]=number[idx/WIDTH]*10+str[i]-'0';
	}
	if(isneg) (*this)=-(*this);
}
int BigNum::len() const{
    int idx=MAX-1;
    for(;idx>=0;idx--){
        if(number[idx]!=0) break;
    }
    return idx+1;
}
bool BigNum::isneg() const{
    return (number[MAX-1]==BASE-1);
}
bool BigNum::operator<(const BigNum& b) const{
    if(isneg()!=b.isneg()){
        return isneg();
    }
    else if(isneg()==b.isneg()){
        for(int i=MAX-1;i>=0;i--){
            if(number[i]!=b.number[i])
                return (number[i]<b.number[i])^isneg();
        }
    }
    return false;
}
bool BigNum::operator>(const BigNum& b) const{
    return b<(*this);
}
bool BigNum::operator!=(const BigNum& b) const{
    return (*this)>b||(*this)<b;
}
bool BigNum::operator==(const BigNum& b) const{
    return !((*this)!=b);
}
bool BigNum::operator>=(const BigNum& b) const{
    return !((*this)<b);
}
bool BigNum::operator<=(const BigNum& b) const{
    return !((*this)>b);
}
BigNum BigNum::operator-() const{
    BigNum b;
    for(int i=0;i<MAX;i++)
        b.number[i]=BASE-number[i]-1;
    return b+BigNum("1");
}
BigNum BigNum::operator~() const{
	BigNum ta=(*this);
	if(isneg()) ta=-ta;
	int la=ta.len();
	string res="";
	for(int i=0;i<la-1;i++){
		string str="",zero_str="";
		int cnt=9;
		while(ta.number[i]>0){
			str+=(char)(ta.number[i]%10+'0');
			ta.number[i]/=10;
			cnt--;
		}
		for(int j=0;j<cnt;j++){
			zero_str+='0';
		}
		zero_str+=str;
		res+=zero_str;
	}
	string str="";
	while(ta.number[la-1]>0){
		str+=(char)(ta.number[la-1]%10+'0');
		ta.number[la-1]/=10;
	}
	res+=str;
	BigNum a(res);
	if(isneg()) a=-a;
	return a;
}
BigNum BigNum::operator+(const BigNum& b) const{
    BigNum c;
    long long int carry=0L;
    for(int i=0;i<MAX;i++){
        c.number[i]+=(number[i]+b.number[i]+carry);
        carry=c.number[i]/BASE;
        c.number[i]%=BASE;
    }
    return c;
}
BigNum BigNum::operator-(const BigNum& b) const{
    return (*this)+(-b);
}
BigNum BigNum::operator*(const long long int& b) const{
    BigNum ta=(*this);
    long long int tb=b;
    if(isneg()) ta=-ta;
    if(b<0) tb=-1*tb;
    BigNum c;
    long long int carry=0;
    for(int i=0;i<MAX;i++){
        c.number[i]=ta.number[i]*tb+carry;
        carry=c.number[i]/BASE;
        c.number[i]%=BASE;
    }
    if(isneg()^b<0) c=-c;
    return c;
}
BigNum BigNum::operator*(const BigNum& b) const{
    BigNum ta=(*this),tb=b;
    if(isneg()) ta=-ta;
    if(b.isneg()) tb=-tb;
    BigNum c;
    int la=ta.len(),lb=tb.len();
    for(int i=0;i<la;i++){
        long long int carry=0;
        for(int j=0;j<lb+1;j++){
            c.number[i+j]+=(ta.number[i]*tb.number[j]+carry);
            carry=c.number[i+j]/BASE;
            c.number[i+j]%=BASE;
        }
    }
    if(isneg()^b.isneg()) c=-c;
    return c;
}
BigNum BigNum::operator/(const long long int& b) const{
    BigNum ta=(*this);
    long long int tb=b;
    if(isneg()) ta=-ta;
    if(b<0) tb=-1*tb;
    long long int remain=0L;
    int la=ta.len();
    for(int i=la+1;i>=0;i--){
        long long int temp=ta.number[i]+remain*BASE;
        ta.number[i]=temp/tb;
        remain=temp%tb;
    }
    if(isneg()^(b<0)) ta=-ta;
    return ta;
}
BigNum BigNum::operator/(const BigNum& b) const{
	BigNum remain,temp,result;
	BigNum ta=(*this),tb=b;
    if(isneg()) ta=-ta;
    if(b.isneg()) tb=-tb;
	int la=ta.len(),lb=tb.len();
	if(la<lb)
		return BigNum("0");
	if(ta==tb){
		BigNum ans("1");
		if(isneg()^b.isneg()) ans=-ans;
		return ans;
	}
	if(tb==BigNum("1")){
		if(isneg()^b.isneg()) ta=-ta;
		return ta;
	}
	for(int i=0;i<lb;i++)
		remain.number[i]=ta.number[la-lb+i];
	long long int quot,L=0,R=BASE;
	while(L+1!=R){
	    quot=(L+R)/2;
	    if(tb*quot>remain) R=quot;
	    else L=quot;
    }
	remain=remain-tb*L;
	int l=remain.len();
	for(int i=l;i>0;i--)
		remain.number[i]=remain.number[i-1];
	remain.number[0]=0;
	result.number[0]=L;
	for(int i=0;i<la-lb;i++){
		remain.number[0]=ta.number[la-lb-i-1];
		L=0,R=BASE;
		while(L+1!=R){
		    quot=(L+R)/2;
		    if(tb*quot>remain) R=quot;
		    else L=quot;
    	}
		remain=remain-tb*L;
		l=remain.len();
		for(int j=l;j>0;j--)
			remain.number[j]=remain.number[j-1];
		remain.number[0]=0;
		l=result.len();
		for(int j=l;j>0;j--)
			result.number[j]=result.number[j-1];
		result.number[0]=L;
	}
	if(isneg()^b.isneg())  result=-result;
	return result;
}
BigNum BigNum::operator%(const long long int& b) const{
    return (*this)-((*this)/b*b);
}
BigNum BigNum::operator++(){
	(*this)=(*this)+BigNum("1");
	return (*this);
}
BigNum BigNum::operator++(int){
	BigNum tmp=(*this);
	++(*this);
	return tmp;
}
void BigNum::operator+=(const BigNum& b){
	(*this)=(*this)+b;
}
void BigNum::operator-=(const BigNum& b){
	(*this)=(*this)+(-b);
}
void BigNum::operator*=(const long long int& b){
	(*this)=(*this)*b;	
}
void BigNum::operator*=(const BigNum& b){
	(*this)=(*this)*b;
}
void BigNum::operator/=(const long long int& b){
	(*this)=(*this)/b;
}
void BigNum::operator/=(const BigNum& b){
	(*this)=(*this)/b;
}
istream& operator>>(istream& is,BigNum& a){
    string str;
    is>>str;
    a=BigNum(str);
    return is;
}
ostream& operator<<(ostream& os,const BigNum& a){
    BigNum ta=a;
    if(a.isneg()){
        ta=-ta;
        os<<'-';
    }
	bool not_zero=false;
	int idx=MAX-1;
	while(ta.number[idx]==0) idx--;
    if(idx<0) os<<"0";
	else{
        os<<ta.number[idx--];
        while(idx>=0) os<<setw(WIDTH)<<setfill('0')<<ta.number[idx--];
	}
	return os;
}
