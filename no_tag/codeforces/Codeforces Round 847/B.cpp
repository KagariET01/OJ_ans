/*
[CF]				[Q]https://codeforces.com/contest/1790/problem/B
[AC]
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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n,s,r;
		cin>>n>>s>>r;
		INT mx=s-r;//被幹 走的那顆是哪顆
		INT disc[7];
		memset(disc,0,sizeof(disc));
		disc[1]=n-1;
		r-=(n-1);//涉其他色子都是點數1，那我們還有多少點需要增加
		if(mx>1){
			INT a=r/(mx-1);//將a個骰子從1轉到mx，所以點數增加a(mx-1)
			disc[mx]+=a;
			disc[1]-=a;
			r-=a*(mx-1);
			disc[r+1]++;
			disc[1]--;
		}




		disc[mx]++;//把被 幹 走的那顆加回來
		for(INT i=1;i<=6;i++){
			for(INT j=0;j<disc[i];j++){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
