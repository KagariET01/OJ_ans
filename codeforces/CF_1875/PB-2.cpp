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
		INT a,b,n;
		cin>>a>>b>>n;
		n=min(n,(INT)100+n%2);
		multiset<INT> sea;
		multiset<INT> seb;
		for(INT i=0;i<a;i++){
			sea.insert(read(INT));
		}
		for(INT i=0;i<b;i++){
			seb.insert(read(INT));
		}
		for(INT i=1;i<=n;i++){
			if(i%2){
				auto eedd=seb.end();
				eedd--;
				sea.insert(*(eedd));
				seb.erase((eedd));
				seb.insert(*(sea.begin()));
				sea.erase((sea.begin()));
			}else{
				auto eedd=sea.end();
				eedd--;
				seb.insert(*(eedd));
				sea.erase((eedd));
				sea.insert(*(seb.begin()));
				seb.erase((seb.begin()));
			}
			DBG{
				cerr<<"a:";
				for(INT i:sea)cerr<<" "<<i;
				cerr<<endl;
				cerr<<"b:";
				for(INT i:seb)cerr<<" "<<i;
				cerr<<endl<<endl;
			}
		}
		INT ans=0;
		for(INT i:sea){
			ans+=i;
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