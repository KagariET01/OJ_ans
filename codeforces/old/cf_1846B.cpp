/*
[q]https://codeforces.com/contest/1846/problem/B
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

bool seq(char a,char b,char c){
	return (a==b && b==c);
}

INT ecd(char c){
	if(c=='X')return 1;
	if(c=='O')return 2;
	if(c=='+')return 3;
	return 0;
}
string rec(INT a){
	switch(a){
		case 0:
			return "DRAW";
		break;
		case 1:
			return "X";
		break;
		case 2:
			return "O";
		break;
		case 3:
			return "+";
		break;
	}
	return "DRAW";
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		string str[3];
		for(INT i=0;i<3;i++){
			cin>>str[i];
		}
		DBG{
		for(INT i=0;i<3;i++){
			cerr<<str[i];
		}
		}
		INT ans=0;
		//橫
		for(INT i=0;i<3 && (!ans); i++){
			if(seq(
				str[i][0],
				str[i][1],
				str[i][2]
			)){
				ans=ecd(str[i][0]);
			}
		}

		//直
		for(INT i=0;i<3 && (!ans); i++){
			if(seq(
				str[0][i],
				str[1][i],
				str[2][i]
			)){
				ans=ecd(str[0][i]);
			}
		}

		//協
		if(
			seq(
				str[0][0],
				str[1][1],
				str[2][2]
			)||seq(
				str[0][2],
				str[1][1],
				str[2][0]
			)
		){
				ans=ecd(str[1][1]);
		}

		cout<<rec(ans)<<endl;
	}
	return 0;
}
//#endif
