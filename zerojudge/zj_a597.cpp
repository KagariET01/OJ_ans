/*
[q]
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
const INT mxn=500;
bool mp[mxn][mxn];
bool walk[mxn][mxn];
INT ansa=0;
INT ansb=0;
INT n,m;
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};

INT dfs(INT x,INT y){
	if(!mp[x][y] || walk[x][y])return 0;
	walk[x][y]=1;
	INT re=1;
	for(INT i=0;i<4;i++){
		INT nx=x+mx[i];
		INT ny=y+my[i];
		if(0<=nx && nx<n && 0<=ny && ny<m && mp[nx][ny] && !walk[nx][ny]){
			re+=dfs(nx,ny);
		}
	}
	return re;
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
	INT t=1;
	while(cin>>n>>m){
		memset(mp,0,sizeof(mp));
		memset(walk,0,sizeof(walk));
		ansa=0;
		ansb=0;
		for(INT i=0;i<n;i++){
			string str=read(string);
			for(INT j=0;j<m;j++){
				mp[i][j]=(str[j]=='J');
			}
		}
		DBG{
			for(INT i=0;i<n;i++){
				for(INT j=0;j<m;j++){
					cerr<<(mp[i][j]?'1':'0');
				}
				cerr<<endl;
			}
		}
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				if(walk[i][j])continue;
				if(!mp[i][j])continue;
				INT nw=dfs(i,j);
				if(!nw)continue;
				ansa++;
				ansb=max(ansb,nw);
			}
		}
		cout<<ansa<<" "<<ansb<<endl;
	}
	return 0;
}
//#endif
