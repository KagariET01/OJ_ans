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

INT n;
vector<PII> vec;
set<PII> se;

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
	INT t=1;
	while(t){
		n=read(INT);
		if(!n)break;
		vec.clear();
		vec.reserve(n);
		for(INT i=0;i<n;i++){
			vec.push_back({read(INT),read(INT)});
		}
		INT ans=0,ansa=0,ansb=0;
		for(INT i=0;i<n;i++){
			for(INT j=i+1;j<n;j++){
				INT nwx=(vec[i].first-vec[j].first);
				INT nwy=(vec[i].second-vec[j].second);
				INT nw=nwx*nwx+nwy*nwy;
				if(nw>ans){
					ans=nw;
					ansa=i;
					ansb=j;
				}
			}
		}
		cout<<ansa<<" "<<ansb<<endl;
	}
	return 0;
}
//#endif
