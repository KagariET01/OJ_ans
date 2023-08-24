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
		INT n=read(INT);
		string a,b;
		cin>>a>>b;
		INT nw=0;
		INT ans=n*2+5;
		for(INT i=0;i<n;i++){
			if(a[i]!=b[i])nw++;
		}
		DBG cerr<<"nw="<<nw<<endl;
		if(nw==0){
			nw=ans=0;
		}else if(nw%2){
			nw+=nw-1;
		}else{
			nw*=2;
		}
		ans=min(ans,nw);
		nw=0;
		for(INT i=0;i<n;i++){
			if(a[i]!=b[n-i-1])nw++;
		}
		if(nw==0){
			nw+=2;
		}else if(nw%2){
			nw*=2;
		}else{
			nw+=nw-1;
		}
		ans=min(ans,nw);
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
