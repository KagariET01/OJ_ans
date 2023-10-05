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

INT mod=998244353;

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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		INT n,m;
		cin>>n>>m;
		INT lst[n];//紀錄現在狀態
		INT las[n];//紀錄上次值改變的時候
		INT nwcnt[n+m+1]={};
		INT allcnt[n+m+1]={};
		for(INT i=0;i<n;i++){
			cin>>lst[i];
			las[i]=0;
			nwcnt[lst[i]]++;
		}


		for(INT i=1;i<=m;i++){
			INT a,b;
			cin>>a>>b;
			a--;
			allcnt[lst[a]]+=i-las[a];
			lst[a]=b;
			las[a]=i;
		}
		for(INT i=0;i<n;i++){
			allcnt[lst[i]]+=(m+1)-las[i];
		}
		INT ans=((m+1)*m)*n;
		for(INT j:allcnt){
			ans-=j*(j-1)/2;
			DBG cout<<"  -"<<j*(j-1)/2<<endl;
		}
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	debug=0;
	string yes="yes";
	string no="no";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(!ynans){
			if(re==-1)return 0;
		}else{
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}