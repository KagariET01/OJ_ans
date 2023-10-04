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

const INT mxm=1e5;

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
		INT n;
		cin>>n;
		INT mx=0,mn=1e9+5;
		INT mxc=0,mnc=0;
		for(INT i=0;i<n;i++){
			INT nw=read(INT);
			if(nw>mx){
				mx=nw;
				mxc=0;
			}if(nw>=mx){
				mxc++;
			}
			if(nw<mn){
				mn=nw;
				mnc=0;
			}if(nw<=mn){
				mnc++;
			}
		}
		INT ans=0;
		ans=mxc*mnc*(n>1?2:0);
		if(mx==mn)ans=mxc*(mnc-1);
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
