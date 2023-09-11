//[AC]
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
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	INT t=1;
	while(t--){
		INT n,x,y,t;
		cin>>n>>x>>y>>t;
		n+=1;
		PII lst[n+1];
		lst[0]={0,0};
		for(INT i=1;i<n;i++){
			cin>>lst[i].first>>lst[i].second;
		}
		lst[n]={t,x*t+5};
		DBG cerr<<lst[n].second<<endl;
		// INT finalrun=0;
		// finalrun=t-lst[n-1].first;
		// finalrun*=x;
		INT basicsp=0;//到最後一個測站時的速度
		for(INT i=0;i<n;i++){
			INT road=lst[i+1].first-lst[i].first;
			basicsp=basicsp+road*x;
			basicsp=min(basicsp,lst[i+1].second);
			DBG cerr<<basicsp<<" ";
		}

		cout<<basicsp<<endl;;
	}
	return 0;
}



