/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1402

[BFS]

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

struct dta{
	INT x=0,y=0,h=0;
	bool operator<(const dta b)const{
		return h<b.h;
	}
	bool operator<=(const dta b)const{
		return h<=b.h;
	}
	bool operator>(const dta b)const{
		return h>b.h;
	}
	bool operator>=(const dta b)const{
		return h>=b.h;
	}
};



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n,m;
	while(cin>>n>>m){
		/*CIN*/
		priority_queue<dta,vector<dta>greater<dta>> que;
		INT mp[n+2][m+2];
		bool ps[n+2][n+2];
		set0(mp);
		set0(ps);
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=m;j++){
				cin>>mp[i][j];
				if(i<=1 || i>=n || j<=1 || j>=n){
					ps[i][j]=true;
					que.push({i,j,mp[i][j]});
				}
			}
		}
		/*solve*/
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
