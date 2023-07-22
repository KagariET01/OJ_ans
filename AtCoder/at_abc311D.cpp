/*
[q]
[Grapth 圖論]
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

INT mx[]={1,0,-1,0};
INT my[]={0,1,0,-1};

struct dta{
	INT x=2;
	INT y=2;
};
dta operator+(const dta &a,const INT &b){
	dta re;
	re.x=a.x+mx[b];
	re.y=a.y+my[b];
	return re;
}
dta operator-(const dta &a,const INT &b){
	dta re;
	re.x=a.x-mx[b];
	re.y=a.y-my[b];
	return re;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
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
	while(t--){
		INT n,m;
		cin>>n>>m;
		bool mp[n+2][m+2];
		memset(mp,0,sizeof(mp));
		for(INT i=1;i<=n;i++){
			string str=read(string);
			for(INT j=1;j<=m;j++){
				if(str[j-1]=='.'){
					mp[i][j]=1;
				}
			}
		}
		DBG{
			for(INT i=0;i<=n+1;i++){
				for(INT j=0;j<=m+1;j++){
					cerr<<(mp[i][j]?1:0)<<" ";
				}
				cerr<<endl;
			}
		}
		deque<dta> todo;
		bool canwalk[n+2][m+2];memset(canwalk,0,sizeof(canwalk));
		bool already[n+2][m+2];memset(already,0,sizeof(already));
		dta root;
		root.x=2;
		root.y=2;
		todo.push_back(root);
		already[2][2]=1;
		while(!todo.empty()){
			dta nw=todo.front();
			todo.pop_front();
			DBG{
				cerr<<"run x:"<<nw.x<<" y:"<<nw.y<<endl;
			}
			for(INT i=0;i<4;i++){
				dta nx=nw;
				while(true){
					if(!mp[nx.x][nx.y]){
						nx=nx-i;
						if(!already[nx.x][nx.y]){
							todo.push_back(nx);
							already[nx.x][nx.y]=1;
						}
						break;
					}
					canwalk[nx.x][nx.y]=1;
					nx=nx+i;
					DBG cerr<<"nx x:"<<nx.x<<" y:"<<nx.y<<endl;
				}
			}
		}
		INT ans=0;
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=m;j++){
				ans+=(canwalk[i][j]?1:0);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
