/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[]

[result]		[AC]
[time]			[2820]
[mem]				[108780]
[challenge]	[240340]
[sub time]	[2023/03/29 23:03:26]
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
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

const INT mxn=1e5;
INT flag[mxn+1];
vector<INT> vec[mxn+1];
string ans="NORMAL.";

bool dfs(INT n,INT nwf=1){
	flag[n]=nwf;
	for(INT i:vec[n]){
		if(flag[i]){
			if(flag[i]==nwf){
				ans="RAINBOW.";
				return false;
			}
		}
		else if(!dfs(i,3-nwf))return false;
	}
	return true;
}

INT n;
INT m;

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*re0*/
		ans="NORMAL.";
		for(INT i=0;i<mxn+1;i++){
			vec[i].clear();
		}
		set0(flag);
		/*CIN*/
		n=read(INT);
		m=read(INT);
		for(INT i=0;i<m;i++){
			INT a,b;
			cin>>a>>b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		/*solve*/
		for(INT i=0;i<n;i++){
			if(flag[i])continue;
			if(!dfs(i))break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
