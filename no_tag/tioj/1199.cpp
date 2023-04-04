/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1199

[]

[result]		[AC]
[time]			[829]
[mem]				[3664]
[challenge]	[341766]
[sub time]	[2023/04/02 14:03]
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

INT modpow(INT x,INT n,INT mod){
	INT re=1;
	while(n>0){
		if(n&1){
			re=(re*x)%mod;
		}
		x=(x*x)%mod;
		n>>=1;
	}
	return re;
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT qans,n,y;
	while(cin>>qans>>n>>y){
		/*CIN*/
		if(qans==0 && n==0 && y==0)break;
		/*solve*/
		INT ans=0;
		for(INT x=0;x<y;x++){
			if(x==0 && n==0)continue;
			if(modpow(x,n,y)==qans)ans++;
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
