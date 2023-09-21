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

const INT mxn=100;
const INT mxz=1e5;

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
		INT n;
		cin>>n;
		INT x[n],y[n],z[n];
		for(INT i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		
		INT ztt=0;
		for(INT i=0;i<n;i++){ztt+=z[i];}
		INT zneed=(ztt+1)/2;
		vector<PII> vec;
		INT mx=0;
		for(INT i=0;i<n;i++){
			if(x[i]>y[i]){
				zneed-=z[i];
			}else{
				vec.push_back({(y[i]-x[i]+1)/2,z[i]});
				mx+=(y[i]-x[i]+1)/2;
			}
		}
		INT dp[mxz+5];
		for(INT i=1;i<=zneed+1;i++){
			dp[i]=mx;
		}
		dp[0]=0;
		for(PII i:vec){
			if(i.second>zneed){
				dp[zneed]=min(dp[zneed],i.first);
			}
			for(INT j=zneed;j>=0;j--){
				dp[j]=min(dp[j],dp[j+1]);
				if(j>=i.second){
					dp[j]=min(dp[j],dp[j-i.second]+i.first);
				}
			}
		}
		cout<<dp[zneed]<<endl;

	}
	return 0;
}
//#endif
