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
		INT n,m;
		string str;
		cin>>n>>m>>str;
		set<PII> se;
		INT dp[2][n];
		dp[0][0]=-1;
		dp[1][n-1]=n+5;
		for(INT i=0;i<n;i++){
			if(i)dp[0][i]=dp[0][i-1];
			if(str[i]=='0')dp[0][i]=i;
		}
		for(INT i=n-1;i>=0;i--){
			if(i<n-1)dp[1][i]=dp[1][i+1];
			if(str[i]=='1')dp[1][i]=i;
		}
		for(INT i=0;i<m;i++){
			INT l,r;
			cin>>l>>r;
			l--,r--;
			l=dp[1][l];
			r=dp[0][r];
			if(l<r){
				se.insert(make_pair(l,r));
			}else{
				se.insert(make_pair(-1,-1));
			}
		}
		cout<<se.size()<<endl;
		DBG{
			for(PII i:se){
				cerr<<"{"<<i.first<<","<<i.second<<"}"<<endl;
			}
		}
	}
	return 0;
}
//#endif
