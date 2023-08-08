/*
[q]
[]
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
		INT n,l,k;
		cin>>n>>l>>k;
		INT d[n+1];
		memset(d,0,sizeof(d));
		for(INT i=0;i<n;i++){
			cin>>d[i];
		}
		d[n]=l;
		for(INT i=n;i>0;i--){
			d[i]-=d[i-1];
		}
		INT a[n+1];
		memset(a,0,sizeof(a));
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		PII dp[n+1][k+1];
		for(INT i=0;i<=n;i++){
			for(INT j=0;j<=k;j++){
				dp[i][j]={0,0};
			}
		}
		for(INT i=1;i<=n;i++){
			dp[i][0]={dp[i-1][0].first+d[i]*a[i],a[i]};
		}
		for(INT j=1;j<=k;j++){
			dp[1][j]=dp[1][j-1];
		}
		for(INT i=2;i<=n;i++){
			for(INT j=1;j<=k;j++){
				dp[i][j]=min(make_pair(dp[i-1][j-1].first+d[i]*dp[i-1][j-1].second,dp[i-1][j-1].second),make_pair(dp[i-1][j].first+d[i]*a[i],a[i]));
			}
		}
		INT ans=dp[n][0].first;
		for(INT j=1;j<=k;j++){
			ans=min(ans,dp[n][j].first);
		}
		cout<<ans<<endl;
		DBG{
			cerr<<"d:"<<endl;
			for(INT i=0;i<=n;i++){
				cerr<<d[i]<<" ";
			}
			cerr<<endl;
			cerr<<"a:"<<endl;
			for(INT i=0;i<=n;i++){
				cerr<<a[i]<<" ";
			}
			cerr<<endl;
			cerr<<"DP:"<<endl;
			for(INT i=0;i<=n;i++){
				for(INT j=0;j<=k;j++){
					cerr<<dp[i][j].first<<","<<dp[i][j].second<<" ";
				}
				cerr<<endl;
			}
			cerr<<endl;
		}
	}
	return 0;
}
//#endif
