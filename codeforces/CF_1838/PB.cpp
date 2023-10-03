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
		INT n=read(INT);
		INT a=0,b=0,c=0;
		for(INT i=1;i<=n;i++){
			INT inin=read(INT);
			if(inin==1)a=i;
			else if(inin==2)b=i;
			else if(inin==n)c=i;
		}

		if(false)return 0;
		else if(a<b && b<c)cout<<c<<" "<<b<<endl;
		else if(a<c && c<b)cout<<"1 1"<<endl;
		else if(b<a && a<c)cout<<a<<" "<<c<<endl;
		else if(b<c && c<a)cout<<"1 1"<<endl;
		else if(c<a && a<b)cout<<a<<" "<<c<<endl;
		else if(c<b && b<a)cout<<c<<" "<<b<<endl;
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
