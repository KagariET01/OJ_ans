/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[]

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
bool debug=1;
bool iofast=0;
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

vector<INT> gcder(INT n){
	deque<INT> dqa;
	deque<INT> dqb;
	for(INT i=1;i<=n;i++){
		if(n%i)continue;
		dqa.push_back(i);
		if(n/i!=i)dqb.push_front(n/i);
		else break;
		if((n/i)<=i)break;
	}
	vector<INT> re;
	deque<INT>::iterator it=dqa.begin();
	for(;it!=dqa.end();it++){
		re.push_back(*it);
		DBG cerr<<*it<<" ";
	}
	it=dqb.begin();
	for(;it!=dqb.end();it++){
		re.push_back(*it);
		DBG cerr<<*it<<" ";
	}
	DBG cerr<<endl;
	return re;
}


/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		vector<INT> vec;
		cout<<"+ 1"<<endl;
		INT k;
		INT inin=read(INT);
		if(inin==0)k=-1;
		else k=inin-1;
		vec.push_back(1);

		INT out=1e9-1-k;
		cout<<"+ "<<out<<endl;
		inin=read(INT);
		vec.push_back(out);
		INT maybez=(INT)(1e9)-inin;

		INT mxre=0;
		INT z=0;
		vector<INT> aass=gcder(maybez);
		INT lst=inin;
		for(INT i:aass){
			if(i<k)continue;
			if(i<mxre)continue;
			cout<<"+ "<<i<<endl;
			inin=read(INT);
			if(inin==lst){
				z=i;
				break;
			}
			lst=inin;
			mxre=max(mxre,inin);
		}
		if(k==-1)k=z-1;
		cout<<"! "<<k<<" "<<z<<endl;
		/*CIN*/
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
首先詢問一個1
mod(1+k,z)的計算結果一定為1+k或0
如果回傳0，代表k=z-1
所以k+1就被z整除，剩下0了
如果回傳其他數字，就代表沒被進位掉

再來詢問一個1e9-1-k
1e9=n*z+mod(1e9+k,z)


mod(1e9+k,z)


*/
