/*
[CF]				[Q]https://codeforces.com/contest/1623/problem/C

[BIT serach][greedy]

[result]		[AC]
[time]			[78]
[mem]				[3200]
[challenge]	[198939069]
[sub time]	[2023/03/24 20:19:00]
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
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

vector<INT> avec;//最原始資料



bool vser(INT fnd,INT nw){
	vector<INT> bvec(fnd);//別人給過的
	for(INT i=0;i<fnd;i++){
		bvec[i]=avec[i];
	}
	for(INT i=fnd-1;i>=2;i--){
		if(bvec[i]<nw)return false;//別人給的和自己原本的加起來沒辦法滿足自己就re 0
		INT dd=min(bvec[i]-nw,avec[i])/3;//題目是由左至右做，但我們是由後往前做，我們給其他人的最多就是自己原本的
		//前面的，扣掉我需要的，我可以給多少，後項，我最多只能給多少
		bvec[i-1]+=dd;
		bvec[i-2]+=2*dd;
	}
	for(INT i=0;i<fnd;i++){
		if(bvec[i]<nw)return false;
	}
	return true;
}




template<typename TPE,typename TPE2,typename Fn>TPE Bit_Search(TPE l,TPE r,TPE2 n,Fn isit){
	while(l<r){
		TPE nw=(l+r+1)/2;
		if(isit(n,nw)){
			l=nw;
		}else{
			r=nw-1;
		}
		//cerr<<"l="<<l<<",r="<<r<<endl;
	}
	return l;
}




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*CIN*/
		INT n=read(INT);
		avec.clear();
		avec.resize(n);
		INT mn=1e9;
		INT mx=0;
		for(INT i=0;i<n;i++){avec[i]=read(INT);mn=min(mn,avec[i]);mx=max(mx,avec[i]);}
		/*solve*/
		cout<<Bit_Search<INT>(0,mx,n,vser)<<endl;
		//cerr<<endl;
	}
	return 0;
}

/*
[I1]
4 4 1 2 10 100 4 100 100 100 1 5 5 1 1 1 8 6 1 2 3 4 5 6

1 4 1 2 10 100
[O1]
*/

/*think*/
/*

*/
