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
[time]			[1850]
[mem]				[400188]
[challenge]	[240309]
[sub time]	[2023/03/29 17:38:58]
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
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}
INT n,m;
bool isout(INT i,INT j,INT n,INT m){
	return (i<0 || i>n || j<0 || j>m);
}
const INT mxnm=1000;
INT mp[mxnm+1][mxnm+1];
INT ans=0;
void bfs(INT nwi,INT nwj){
	if(mp[nwi][nwj]==0){
		ans++;mp[nwi][nwj]=ans;
	}
	for(INT i=0;i<4;i++){
		INT nxi=nwi+mx[i];
		INT nxj=nwj+my[i];
		if(isout(nxi,nxj,n-1,m-1))continue;
		if(mp[nxi][nxj])continue;
		mp[nxi][nxj]=mp[nwi][nwj];
		bfs(nxi,nxj);
	}
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*re0*/
		set0(mp);
		ans=0;
		/*CIN*/
		cin>>n>>m;
		for(INT i=0;i<n;i++){
			string nwstr=read(string);
			for(INT j=0;j<m;j++){
				mp[i][j]=nwstr[j]=='.'?0:-1;
			}
		}
		/*solve*/
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				if(mp[i][j])continue;
				bfs(i,j);
			}
		}
		cout<<ans<<endl;
		DBG{
			for(INT i=0;i<n;i++){
				for(INT j=0;j<m;j++){
					if(mp[i][j]==-1)cout<<"#";
					else cout<<mp[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}

/*
[I1]
4 3 4 .### ###. ##.. 4 4 .### #.## ##.# ###. 4 4 ..## #.## #... ##.. 4 4 .### #..# #..# ###.
[O1]
*/

/*think*/
/*

*/
