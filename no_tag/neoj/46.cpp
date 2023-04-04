/*
[neoj] [Q]https://neoj.sprout.tw/problem/46

[]

[result]		[AC]
[time]			[720]
[mem]				[33732]
[challenge]	[240530]
[sub time]	[2023/03/31 15:11:33]
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
INT mx[]={0,1,-1};
INT my[]={1,0,-1};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
TPE a;
cin>>a;
return a;
}

struct dta{
	bool R=false,Y=false,B=false;
};

dta mrge(dta a,dta b){
	a.R|=b.R;
	a.Y|=b.Y;
	a.B|=b.B;
	return a;
}

struct id{
	INT x,y,id=0;
};
bool operator>(const id &a,const id &b){
	return a.id>b.id;
}

bool operator==(const dta &a,const dta &b){
	return (a.R==b.R && a.Y==b.Y && a.B==b.B);
}

dta operator+(const dta &a,const dta &b){
	dta re;
	re.R=a.R|b.R;
	re.Y=a.Y|b.Y;
	re.B=a.B|b.B;
	return re;
}

bool operator!=(const dta &a,const dta &b){
	return !(a==b);
}


dta mp[1001][1001];

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*re0*/
		set0(mp);
		/*cin*/
		INT n=read(INT);
		PII ink[3];
		for(INT i=0;i<3;i++){
			char c=read(char);
			INT x,y;
			cin>>x>>y;
			if(c=='R'){
				ink[0]={x,y};
				mp[x][y]={1,0,0};
			}elif(c=='Y'){
				ink[1]={x,y};
				mp[x][y]={0,1,0};
			}else{
				ink[2]={x,y};
				mp[x][y]={0,0,1};
			}
		}
		char fc=read(char);
		dta fnd;
			if(fc=='R' || fc=='O' || fc=='D' || fc=='P'){
				fnd.R=1;
			}
			if(fc=='Y' || fc=='O' || fc=='D' || fc=='G'){
				fnd.Y=1;
			}
			if(fc=='B' || fc=='G' || fc=='D' || fc=='P'){
				fnd.B=1;
			}
		INT nw=0,ans=0;
		if(fc=='R' || fc=='Y' || fc=='B'){
			nw=1;
			ans=1;
		}
		dta RYB[3];
		RYB[0].R=1;
		RYB[1].Y=1;
		RYB[2].B=1;
		bool isfull[3]={0,0,0};
		for(INT i=1;i<=n;i++){//擴散範圍
			if(isfull[0] && isfull[1] && isfull[2])break;
			for(INT j=0;j<3;j++){//give color, way:only board need
				if(isfull[j])continue;
				dta &nwc=RYB[j];
				INT &cx=ink[j].FIR;
				INT &cy=ink[j].SEC;
				INT lx=max((INT)0,cx-i);
				INT rx=min(n-1,cx+i);

				INT ly=max((INT)0,cy-i);
				INT ry=min(n-1,cy+i);

				INT runx,runy;
				for(runx=lx,runy=ly;runx<=rx;runx++){
					if(mp[runx][runy]==fnd)nw--;
					mp[runx][runy]=mp[runx][runy]+nwc;
					if(mp[runx][runy]==fnd)nw++;
				}
				for(runx=lx,runy=ry;runx<=rx;runx++){
					if(mp[runx][runy]==fnd)nw--;
					mp[runx][runy]=mp[runx][runy]+nwc;
					if(mp[runx][runy]==fnd)nw++;
				}
				for(runx=lx,runy=ly;runy<=ry;runy++){
					if(mp[runx][runy]==fnd)nw--;
					mp[runx][runy]=mp[runx][runy]+nwc;
					if(mp[runx][runy]==fnd)nw++;
				}
				for(runx=rx,runy=ly;runy<=ry;runy++){
					if(mp[runx][runy]==fnd)nw--;
					mp[runx][runy]=mp[runx][runy]+nwc;
					if(mp[runx][runy]==fnd)nw++;
				}
				if(lx==0 && rx==n-1 && ly==0 && ry==n-1){
					isfull[j]=1;
				}
			}
			ans=max(ans,nw);
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
1
5
Y 1 1
B 3 3
R 4 0
Y
[O1]
8
*/

/*think*/
/*

*/