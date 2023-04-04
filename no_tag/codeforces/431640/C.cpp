/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[]

[result]		[]
[time]			[]
[mem]				[]
[challenge]	[]
[sub time]	[YYYY/MM/DD HH:MM:SS]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>
/*using namespace*/
using namespace std;
/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*num*/
bool debug=1;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=1e9+7;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

vector<INT> tre_num(INT n){
	vector<INT> vec(n+1,1);
	vector<INT> ans;
	for(INT i=2;i<=n;i++){
		if(vec[i]==1){
			vec[i]=i;
			ans.push_back(i);
		}
		for(INT j:ans){
			INT aa=i*j;
			if(aa>n)break;
			vec[aa]=i;
			if(j>=vec[i])break;
		}
	}
	return ans;
}

INT xxer(INT n,INT m){
	INT re=1;
	INT nw=n;
	while(m){
		if(m & 1){
			re*=nw;
			re%=mod;
		}
		nw*=nw;
		nw%=mod;
		m>>=1;
	}
	return re;
}





/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n=read(INT);
	vector<INT>tre_lst;
	tre_lst=tre_num(6e5);
	string s1=read(string);
	string s2=read(string);
	INT q1=1;
	INT q2=1;
	for(INT i=0;i<n;i++){
		if(s1[i]=='1' && s2[i]=='0'){
			q1*=tre_lst[i];
			q1%=mod;
		}
		if(s1[i]=='0' && s2[i]=='1'){
			q2*=tre_lst[i];
			q2%=mod;
		}
	}
	DBG cerr<<q1<<" "<<q2<<endl;
	q2=xxer(q2,mod-2);
	INT outer=q1*q2;
	outer%=mod;
	cout<<outer<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
