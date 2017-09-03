#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{	
	char ch;
	double num;
	bool is_head=1;
	string num_str;
	vector<string> post;
	vector<double> ans;
	stack<string> oper;
	//cout<<"Input any expression (cannot over 2147483647)\neg: 1+(2*3-4)/2"<<endl;
	while(scanf("%c",&ch)!=EOF){
		if(ch=='\n'){//calculate
			while(!oper.empty()){
				post.push_back(oper.top());
				oper.pop();
			}
			for(vector<string>::iterator it=post.begin();it!=post.end();it++){
				if(*it=="+"||*it=="-"||*it=="*"||*it=="/"){
					double b=ans.back(); ans.pop_back();
					double a=ans.back(); ans.pop_back();
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
					ans.push_back(stof(*it));
				}
			}
			cout<<ans.back()<<endl;
			is_head=1;
			post.clear();
			ans.clear();
		}
		else if(isdigit(ch)){
			ungetc(ch,stdin);
			cin>>num;
			num_str=to_string(num);
			post.push_back(num_str);
			is_head=0;
		}
		else{
			if(ch=='+'){
				while(!oper.empty()&&oper.top()!="("){
					post.push_back(oper.top());
					oper.pop();
				}
				oper.push("+");
				is_head=1;
			}
			else if(ch=='*'||ch=='/'){
				while(!oper.empty()){
					if(oper.top()=="+"||oper.top()=="-"||oper.top()=="(") break;
					post.push_back(oper.top());
					oper.pop();
				}
				if(ch=='*') oper.push("*");
				else oper.push("/");
				is_head=1;
			}
			else if(ch=='-'){
				if(is_head){
					ungetc(ch,stdin);
					cin>>num;
					num_str=to_string(num);
					post.push_back(num_str);
					is_head=0;
				}
				else{
					ch=getc(stdin);
					if(ch=='-'||isdigit(ch)){
						while(!oper.empty()&&oper.top()!="("){
							post.push_back(oper.top());
							oper.pop();
						}
						oper.push("-");
						ungetc(ch,stdin);
						cin>>num;
						num_str=to_string(num);
						post.push_back(num_str);
						is_head=0;
					}
					else if(ch=='('){
						ungetc(ch,stdin);
						while(!oper.empty()&&oper.top()!="("){
							post.push_back(oper.top());
							oper.pop();
						}
						oper.push("-");
						is_head=0;
					}
				}
			}
			else if(ch=='('){
				oper.push("(");
				is_head=1;
			}
			else if(ch==')'){
				while(oper.top()!="("){
					post.push_back(oper.top());
					oper.pop();
				}
				oper.pop();
				is_head=1;
			}
		}
	}
	return 0;
}