/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[]

[result]		[WA]
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
dta mpadd[1001][1001];
bool domp[1001][1001];

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*re0*/
		priority_queue<id,vector<id>,greater<id>> que;
		set0(mp);
		set0(domp);
		/*CIN*/
		INT n=read(INT);
		for(INT i=0;i<3;i++){
			char c=read(char);
			INT x,y;
			cin>>x>>y;
			dta nw;
			if(c=='Y'){
				nw.Y=true;
			}elif(c=='B'){
				nw.B=true;
			}else{
				nw.R=true;
			}
			mp[x][y]=nw;
			id da;
			da.x=x;
			da.y=y;
			da.id=0;
			que.push(da);
		}
		char fc=read(char);
		dta fnd;
		INT ans=0;
		INT nwcount=0;
			if(fc=='Y' || fc=='O' || fc=='D' || fc=='G'){
				fnd.Y=true;
			}if(fc=='B' || fc=='G' || fc=='D' || fc=='P'){
				fnd.B=true;
			}if(fc=='R' || fc=='O' || fc=='D' || fc=='P'){
				fnd.R=true;
			}
		DBG{
			dta aft=fnd;
			cerr<<"fnd"<<":"<<(aft.R?1:0)<<(aft.Y?1:0)<<(aft.B?1:0)<<"nw="<<nwcount<<endl;
		}
		if(fc=='Y' || fc=='B' || fc=='R'){nwcount++;ans++;}
		/*solve*/
		INT nwid=0;
		queue<id> clque;
		queue<id> addque;
		while(!que.empty()){
			id now=que.top();
			if(now.id>nwid){
				ans=max(ans,nwcount);
				nwid++;
				DBG cerr<<"nwans"<<ans<<endl;
				while(!clque.empty()){
					id nwd=clque.front();
					domp[nwd.x][nwd.y]=false;
					clque.pop();
				}
				while(!addque.empty()){
					id nwd=addque.front();
					mp[nwd.x][nwd.y]=mpadd[nwd.x][nwd.y];
					addque.pop();
				}
				continue;
				
			}else{
				que.pop();
				INT nx=now.x;
				INT ny=now.y;
				INT nid=now.id;
				if(domp[nx][ny])continue;
				domp[nx][ny]=true;
				que.push(now);
				//if(mp[nx][ny]==fnd)nwcount++;
				for(INT i=0;i<3;i++){
					INT nxx=nx+mx[i];
					if(nxx<0 || n<=nxx)continue;
					for(INT j=0;j<3;j++){
						INT nxy=ny+mx[j];
						if(!(mx[i] || mx[j]))continue;
						if(nxy<0 || n<=nxy)continue;

						DBG{
							dta aft=mp[nxx][nxy];
							cerr<<nxx<<","<<nxy<<":"<<(aft.R?1:0)<<(aft.Y?1:0)<<(aft.B?1:0)<<"nw="<<nwcount<<endl;
						}

						dta bef=mp[nxx][nxy];
						if(mp[nxx][nxy]==fnd)nwcount--;
						dta aft=mp[nxx][nxy]+mp[nx][ny];
						if(aft==fnd)nwcount++;
						if(bef!=aft){
							que.push({nxx,nxy,nid+1});
							mpadd[nxx][nxy]=aft;
							addque.push({nxx,nxy,nid+1});
						}

						DBG{
							dta aft=mp[nxx][nxy];
							cerr<<"nw="<<nwid<<"   "<<nxx<<","<<nxy<<":"<<(aft.R?1:0)<<(aft.Y?1:0)<<(aft.B?1:0)<<"nw="<<nwcount<<endl;
						}
					}
				}
			}
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
[I2]
1
5
Y 1 1
B 3 3
R 4 0
G
[O2]
9
*/

/*think*/
/*

*/
