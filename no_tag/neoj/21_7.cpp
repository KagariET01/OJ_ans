/*
[neoj]			[Q]https://neoj.sprout.tw/problem/21

[linked_list]

[result]		[AC]
[time]			[40]
[mem]				[8596]
[challenge]	[232153]
[sub time]	[2023/03/09 01:08:08]
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
bool iofast=1;
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

struct lklst{
	INT n=0;
	lklst *l,*r;
	lklst(){
		l=NULL;
		r=NULL;
	}
};



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n;
	while(cin>>n){
		/*CIN*/
		//INT n=read(INT);
		lklst rk[n+2];
		for(INT i=1;i<=n;i++){
			(rk[i]).n=i;
				(rk[i]).l=&(rk[i-1]);
				(rk[i]).r=&(rk[i+1]);
		}
		(rk[1]).l=NULL;
		(rk[n]).r=NULL;
		/*solve*/
		INT m=read(INT);
		while(m--){
			INT a,b;
			cin>>a>>b;
			if(a){
				lklst &nw=rk[b];
				if(nw.l==NULL)continue;
				lklst &nxt=*(nw.l);
					lklst &dtar=*(nw.r);
					lklst &dtal=*(nxt.l);
				if(nxt.l!=NULL){
					dtal.r=&nw;
				}
				if(nw.r!=NULL){
					dtar.l=&nxt;
				}
				nw.l=(nxt.l);
				nxt.r=nw.r;
				nw.r=&nxt;
				nxt.l=&nw;
			}else{
				lklst &nw=rk[b];
					lklst &dtal=*(nw.l);
					lklst &dtar=*(nw.r);
				if(nw.l!=NULL){
					dtal.r=nw.r;
				}
				if(nw.r!=NULL){
					dtar.	l=nw.l;
				}
				nw.n=0;
			}
		}
		lklst *bgn;
		bgn=NULL;
		/*while(true){
			bgn=(*bgn).l;
			if((*bgn).l==NULL)break;
		}*/
		for(INT i=1;i<=n;i++){
			if((rk[i]).l==NULL && (rk[i]).n!=0){
				bgn=&(rk[i]);
				break;
			}
		}
		bool ot=false;
		if(bgn!=NULL){
			while(true){
				if(ot)cout<<" ";
				ot=true;
				cout<<(*(bgn)).n;
				if((*(bgn)).r==NULL)break;
				bgn=(*bgn).r;
			}
			cout<<endl;
		}

		DBG{
			for(INT i=1;i<=n;i++){
				if((rk[i]).l==NULL){
					cerr<<"<";
				}
				cerr<<(rk[i]).n;
				if((rk[i]).r==NULL){
					cerr<<">";
				}

				cerr<<" ";
			}
			cerr<<endl;
		}


	}
	return 0;
}

/*
[I1]
7
9
0 6
1 3
1 5
0 7
1 1
1 5
1 3
1 2
0 2

5
4
1 2
1 3
1 4
1 5

2
2
0 1
0 2
[O1]
3 1 5 4
2 3 4 5 1

*/

/*think*/
/*

*/
