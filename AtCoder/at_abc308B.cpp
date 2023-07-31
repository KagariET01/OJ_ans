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
	INT t=1;
	while(t--){
		INT n,m;
		cin>>n>>m;
		map<string,INT> eat;
		for(INT i=0;i<n;i++){
			eat[read(string)]++;
		}
		map<string,INT> ctoi;
		for(INT i=1;i<=m;i++){
			ctoi[read(string)]=i;
		}
		INT price[m+1];
		for(INT i=0;i<=m;i++){
			cin>>price[i];
		}
		INT ans=0;
		for(pair<string,INT> i:eat){
			string ns=i.first;
			INT cnt=i.second;
			ans+=price[ctoi[ns]]*cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
