/*
[q]
[DP]
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
const INT mxn=3000;
bool mp[mxn+5][mxn+5];
INT dp[mxn+5][mxn+5];

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
		INT h,w,n;
		cin>>h>>w>>n;
		DBG cerr<<"h:"<<h<<" w:"<<w<<" n:"<<n<<endl;
		for(INT i=0;i<n;i++){
			INT a,b;
			cin>>a>>b;
			mp[a][b]=true;
		}
		DBG cerr<<"operating"<<endl;
		INT ans=0;
		for(INT i=1;i<=h;i++){
			for(INT j=1;j<=w;j++){
				DBG cerr<<"i:"<<i<<" j:"<<j<<endl;
				if(mp[i][j])continue;
				dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
				ans+=dp[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
