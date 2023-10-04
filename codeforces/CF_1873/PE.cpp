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

vector<INT> vec;
INT x;

bool mxer(INT h){
	INT nw=0;
	for(INT i:vec){
		nw+=max((INT)0,h-i);
		//if(i>h)break;
	}
	if(nw<=x)return 1;
	else return 0;
}

INT BITsearch(INT l,INT r){
	while(l<r){
		INT mnt=(l+r)/2+1;
		if(mxer(mnt)){
			l=mnt;
		}else{
			r=mnt-1;
		}
	}
	return l;
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
		INT n;
		cin>>n>>x;
		vec.clear();
		vec.reserve(n);
		for(INT i=0;i<n;i++){
			vec.push_back(read(INT));
		}
		sort(vec.begin(),vec.end());
		cout<<BITsearch((INT)(1),(INT)(1e10+7))<<endl;
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
