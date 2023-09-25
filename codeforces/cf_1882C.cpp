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
		INT n=read(INT);
		INT lst[n+1]={};
		INT ans=0;
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		if(n<=2){
			cout<<max((INT) 0,max(lst[0],lst[1]+lst[0]))<<endl;
			return 0;
		}
		INT i=0;
		while(i<n){
			if(lst[i]>=0){
				ans+=lst[i];
				i++;
				while(i<n && lst[i]<0)i++;
			}
			else if(i+1<n && lst[i]+lst[i+1]>=0){
				ans+=lst[i]+lst[i+1];
				i+=2;
				while(i<n && lst[i]<0)i++;
			}
			else{
				i+=2;
				while(i<n && lst[i]<0)i++;
			}
			INT E1實作明明;
			INT D;
			cout<<(E1實作明明<<D);
		}
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	string yes="yes";
	string no="no";
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=(one_case?1:read(int));
	for(INT i=0;i<t;i++){
		if(!ynans){
			solve(i);
		}else{
			if(solve(i)){
				cout<<yes<<endl;
			}else{
				cout<<no<<endl;
			}
		}
	}
	return 0;
}
