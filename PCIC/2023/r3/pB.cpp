#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define tmin(a,b) a=min(a,b)
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
	INT n=read(INT);
	INT road[n+2]={};
	INT dp[n+2]={};
	for(INT i=0;i<=n;i++){
		dp[i]=(INT)1e9;
		road[i]=0;
	}
	for(INT i=1;i<=n;i++){
		road[i]=read(INT);
	}
	dp[1]=0;
	deque<INT> dq;
	dq.push_back(1);
	bool in[n+2]={};
	in[1]=1;
	while(!dq.empty()){
		INT nw=dq.front();
		dq.pop_front();
		in[nw]=0;
		//walk
		if(dp[nw]+1<dp[nw+1]){
			dp[nw+1]=dp[nw]+1;
			if(!in[nw+1]){
				in[nw+1]=1;
				dq.push_back(nw+1);
			}
		}
		//jump
		if(dp[nw]+1<dp[road[nw]]){
			dp[road[nw]]=dp[nw]+1;
			if(!in[road[nw]]){
				in[road[nw]]=1;
				dq.push_back(road[nw]);
			}
		}
		DBG{
			cerr<<"nw="<<nw<<endl;
			for(INT i=1;i<=n;i++){
				cerr<<dp[i]<<" ";
			}
			cerr<<endl;
		}
	}
	cout<<dp[n]<<endl;
}