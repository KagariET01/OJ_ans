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
		set<INT> vec[55];//哪些人有i
		vector<INT> se[n];//第i人有什麼
		set<INT> allse;
		for(INT i=0;i<n;i++){
			INT sz=read(INT);
			for(INT j=0;j<sz;j++){
				INT inin=read(INT);
				se[i].push_back(inin);
				vec[inin].insert(i);
				allse.insert(inin);
			}
		}
		set<INT> nw;
		INT ans=0;
		for(INT i:allse){
			nw.clear();
			for(INT j=0;j<n;j++){
				if(vec[i].count(j))continue;
				for(INT k:se[j]){
					nw.insert(k);
				}
			}
			ans=max(ans,(INT)(nw.size()));
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
