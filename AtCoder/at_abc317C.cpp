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
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

const INT mxn=10;
INT n,m;
vector<PII> vec[mxn];
INT ans=0;
bool wk[mxn];
void dfs(INT a,INT nw=0){
	DBG cerr<<a<<" ";
	wk[a]=1;
	ans=max(ans,nw);
	for(PII i:vec[a]){
		if(!wk[i.first]){
			dfs(i.first,nw+i.second);
		}
	}
	wk[a]=0;
	DBG cerr<<"- ";
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
	while(t--){
		cin>>n>>m;
		for(INT i=0;i<m;i++){
			INT a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			vec[a].push_back({b,c});
			vec[b].push_back({a,c});
		}

	}
	for(INT i=0;i<n;i++){
		dfs(i);
		DBG cerr<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
//#endif
