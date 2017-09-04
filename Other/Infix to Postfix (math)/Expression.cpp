#include <bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[])
{
	string in,sub;
	cout<<"Input an expression:"<<endl;
	while(getline(cin,in)){
		vector<string> post;
		vector<int> ans;
		stack<string> oper;
		stringstream ss;
		ss.clear();
		ss.str(in);
		while(ss>>sub){
			if(isdigit(sub[0])||isdigit(sub[1])){
				post.push_back(sub);
			}
			else{
				if(sub=="+"||sub=="-"){
					while(!oper.empty()&&oper.top()!="("){
						post.push_back(oper.top());
						oper.pop();
					}
					oper.push(sub);
				}
				else if(sub=="*"||sub=="/"){
					while(!oper.empty()){
						if(oper.top()=="+"||oper.top()=="-"||oper.top()=="(") break;
						post.push_back(oper.top());
						oper.pop();
					}
					oper.push(sub);
				}
				else if(sub=="("){
					oper.push(sub);
				}
				else if(sub==")"){
					while(oper.top()!="("){
						post.push_back(oper.top());
						oper.pop();
					}
					oper.pop();
				}
			}
		}
		while(!oper.empty()){
			post.push_back(oper.top());
			oper.pop();
		}
		for(vector<string>::iterator it=post.begin();it!=post.end();it++){
			cout<<*it<<" ";
			if(*it=="+"||*it=="-"||*it=="*"||*it=="/"){
				int b=ans.back(); ans.pop_back();
				int a=ans.back(); ans.pop_back();
				if(*it=="+")
					ans.push_back(a+b);
				else if(*it=="-")
					ans.push_back(a-b);
				else if(*it=="*")
					ans.push_back(a*b);
				else if(*it=="/")
					ans.push_back(a/b);
			}
			else{
				ans.push_back(stoi(*it));
			}
		}
		cout<<endl<<ans.back()<<endl;
	}
	return 0;
}