#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

const INT mxn=2e5;
INT n;
INT a[mxn];
vector<INT> vec[mxn];
bool disab[mxn];	

vector<INT> anslst;
vector<INT> nwlst;
bool vis[mxn];

bool vser(INT a,INT b){return a<b;}

void dfs(INT nw=0){
	vis[nw]=1;
	nwlst.push_back(nw);
	for(INT i:vec[nw]){
		if(vis[i])continue;
		if(nw>0 && a[i]<a[nw])continue;//拿到更小的寶相
		if(nw>0 && disab[i])continue;//進入有>=3條通道的房間
		DBG cerr<<"id:"<<nw<<"->"<<i<<endl;
		DBG cerr<<"sz:"<<a[nw]<<"->"<<a[i]<<endl;
		dfs(i);
	}
	if(nwlst.size()>anslst.size()){
		anslst.clear();
		anslst.reserve(n);
		for(INT i:nwlst){
			anslst.push_back(i);
		}
	}
	nwlst.pop_back();
	vis[nw]=0;
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
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG{
		cerr<<"=====DBG mod====="<<endl;
	}
	cin>>n;
	for(INT i=0;i<n;i++){
		cin>>a[i];
	}
	for(INT i=1;i<n;i++){
		INT x,y;
		cin>>x>>y;
		x--;y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
		if(x>1 && vec[x].size()>2){
			disab[x]=1;
		}
		if(y>1 && vec[y].size()>2){
			disab[y]=1;
		}
	}
	anslst.reserve(n);
	nwlst.reserve(n);
	for(INT i=0;i<n;i++){
		sort(vec[i].begin(),vec[i].end());
	}
	dfs();
	cout<<anslst.size()<<endl;
	bool ot=0;
	for(INT i:anslst){
		if(ot)cout<<" ";
		cout<<i+1;
		ot=1;
	}
	cout<<endl;
}