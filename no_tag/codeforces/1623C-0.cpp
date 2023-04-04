/*
[CF]				[Q]https://codeforces.com/contest/1623/problem/C

[BIT serach][greedy]

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
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

vector<INT> origvec;



bool vser(INT fnd,INT nw){
	vector<INT> nwvec(fnd);
	for(INT i=0;i<fnd;i++){
		nwvec[i]=origvec[i];
	}
	for(INT i=fnd-1;i>=2;i--){
		if(nwvec[i]<nw)return false;
		INT nwadd=nwvec[i]-nw;
		nwadd/=3;
		nwvec[i]-=3*nwadd;
		nwvec[i-1]+=nwadd;
		nwvec[i-2]+=2*nwadd;
	}
	for(INT i=0;i<fnd;i++){
		cerr<<nwvec[i]<<",";
		if(nwvec[i]<nw)return false;
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
		cerr<<endl;
		cerr<<"l="<<l<<",r="<<r<<endl;
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
		origvec.resize(n);
		INT mn=1e9;
		INT mx=0;
		for(INT i=0;i<n;i++){
			origvec[i]=read(INT);
			mn=min(mn,origvec[i]);
			mx=max(mx,origvec[i]);
		}
		/*solve*/
		cout<<Bit_Search<INT>(mn-1,mx,n,vser)<<endl;
		cerr<<endl;
	}
	return 0;
}

/*
[I1]
4 4 1 2 10 100 4 100 100 100 1 5 5 1 1 1 8 6 1 2 3 4 5 6
[O1]
*/

/*think*/
/*

*/
