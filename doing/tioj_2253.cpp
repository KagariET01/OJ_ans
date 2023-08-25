/*
[q]
[give up]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define PIPII pair<INT,PII>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

const INT mxn=2005;
bool wk[mxn];
vector<pair<INT,PII>> vec[mxn];//{node{min c,finalc}}
deque<INT> path;
bool dfs(INT n=-1,INT c=0){
	path.push_back(n);
	wk[n]=1;
	for(PIPII i:vec[n]){
		if(i.first==path.front() && c+i.second.first>=0){
			path.push_back(path.front());
			return true;
		}else if(wk[i.first])continue;
		else if(c+i.second.first<0)continue;
		if(dfs(i.first,c+i.second.second))return true;
	}
	wk[n]=-1;
	path.pop_back();
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	INT t=read(int);
	while(t--){
		INT n,m,k;
		cin>>n>>m>>k;
		INT c[n];
		for(INT i=0;i<n;i++)cin>>c[i];
		INT x,y,c;
		for(INT i=0;i<m;i++){
			cin>>x>>y;
			c=0;
			for(INT i=0;i<k;i++){
				c+=read(INT);
			}
		}

		
	}
	return 0;
}
//#endif
