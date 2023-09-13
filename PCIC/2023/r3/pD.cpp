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
	INT n;
	cin>>n;
	INT dp[n+1]={};
	INT apple[n+1]={};
	INT have10[n+1]={};
	for(INT i=1;i<=n;i++){
		cin>>apple[i];
		INT nw=0;
		INT j=i;
		while(j>0 && nw<10){
			nw+=apple[j];
			j--;
		}
		if(nw!=10)dp[i]=dp[i-1];
		else{
			dp[i]=max(dp[i-1],dp[j]+(i-j));
			have10[i]=dp[i];
		}
	}
	INT w=1;
	INT cnt=0;
	INT mxcnt=10;
	INT mx=dp[n];
	for(INT i=n;i>=1;i--){
		if(have10[i]==mx)cnt++;
		else if(cnt){
			cnt=min(cnt,mxcnt);
			w*=cnt;
			mxcnt=cnt;
			cnt=0;

		}else{
			mxcnt++;
		}
		if(have10[i]){
			mx=have10[i];
		}
	}
	if(cnt)w*=cnt;
	cout<<dp[n]<<" "<<w<<endl;
	DBG{
		for(INT i=1;i<=n;i++){
			cerr<<have10[i]<<" ";
		}
		cerr<<endl;
	}
}