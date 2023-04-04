/*
[neoj]			[Q]https://neoj.sprout.tw/problem/44

[]

[result]		[AC]
[time]			[0]
[mem]				[4960]
[challenge]	[240311]
[sub time]	[2023/03/29 18:16:42]
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

const INT mxnm=100;
INT n,m;
INT mp[mxnm+1][mxnm+1];
INT kn,km;

bool isout(INT i,INT j,INT n,INT m){
	return (i<0 || i>n || j<0 || j>m);
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*re0*/
		set0(mp);
		/*CIN*/
		cin>>n>>m;
		for(INT i=0;i<n;i++){
			string str=read(string);
			for(INT j=0;j<m;j++){
				mp[i][j]=str[j]=='#'?-1:(str[j]=='@'?-2:1e9);
				if(str[j]=='K'){
					kn=i;
					km=j;
					mp[i][j]=0;
				}
			}
		}
		/*solve*/
		deque<PII> dq;
		dq.push_front({kn,km});
		INT ans=1e9;
		while(!dq.empty()){
			PII nwp=dq.front();
			INT nwx=nwp.FIR;
			INT nwy=nwp.SEC;
			dq.pop_front();
			for(INT i=0;i<4;i++){
				INT nxx=nwx+mx[i];
				INT nxy=nwy+my[i];
				if(isout(nxx,nxy,n-1,m-1))continue;
				if(mp[nxx][nxy]==-2){
					ans=min(ans,mp[nwx][nwy]+1);
					continue;
				}
				if(mp[nxx][nxy]>mp[nwx][nwy]+1){
					mp[nxx][nxy]=mp[nwx][nwy]+1;
					dq.push_back({nxx,nxy});
				}
			}
		}
		if(ans==1e9){
			cout<<"= =\""<<endl;
		}else cout<<ans<<endl;
		DBG{
			for(INT i=0;i<n;i++){
				for(INT j=0;j<m;j++){
					cerr<<mp[i][j]<<" ";
				}
				cerr<<endl;
			}
		}
	}
	return 0;
}

/*
[I1]
2 3 10 ########## #K......@# ########## 3 10 ########## #K..#...@# ##########
[O1]
*/

/*think*/
/*

*/
