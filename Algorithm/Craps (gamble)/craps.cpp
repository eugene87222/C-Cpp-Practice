#include <bits/stdc++.h>
using namespace std;

#define WIN 0
#define LOSE 1
#define CONT 2
int dice(){
	return (rand()%6)+(rand()%6)+2;
}
int initroll(int first){
	switch(first){
		case 7: case 11: return WIN;
		case 2: case 3: case 12: return LOSE;
		default: return CONT;
	}
}
int reroll(int first,int point){
	return first==point?WIN:(point==7?LOSE:CONT);
}
int main(int argc, char const *argv[])
{
	srand(time(0));
	int first=dice(),point;
	cout<<"Player's point: "<<first<<endl;
	int status=initroll(first);
	while(status==CONT){
		point=dice();
		cout<<"Player's point: "<<point<<endl;
		status=reroll(first,point);
	}
	cout<<(status==WIN?"Win":"Lose")<<endl;
	return 0;
}