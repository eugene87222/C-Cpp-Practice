#include <bits/stdc++.h>
using namespace std;

void kmp_fail(string s,int len,int *fail){
	int id=-1;
	fail[0]=-1;
	for(int i=1;i<len;++i){
		while(id!=-1&&s[id+1]!=s[i]) id=fail[id];
		if(s[id+1]==s[i])++id;
		fail[i]=id;
	}
}
int kmp_match(string A,int lenA,string B,int lenB,int *fail){
	int id=-1,ans=0;
	for(int i=0;i<lenA;++i){
		while(id!=-1&&B[id+1]!=A[i]) id=fail[id];
		if(B[id+1]==A[i])++id;
		if(id==lenB-1){
			++ans;
			id=fail[id];
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	string str="abababab";
	int fail[10];
	kmp_fail(str,8,fail);
	for(int i=0;i<str.length();i++)
		cout<<fail[i]<<' ';
	cout<<endl;
	return 0;
}