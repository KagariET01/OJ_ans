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

INT finder(INT n){
	INT l=1,r=1e10;
	while(l<r){
		INT mnt=(r-l)/2+l;
		INT nw=(mnt*(mnt-1))>>1;
		if(nw<n){
			l=mnt+1;
		}else{
			r=mnt;
		}
	}
	return r;
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
		INT inin=read(INT);
		if(inin==1){
			cout<<2<<endl;
			continue;
		}
		INT ans=finder(inin);
		INT nw=(ans*(ans-1))/2;
		if(nw==inin){
			cout<<ans<<endl;
			continue;
		}else{
			ans--;
			nw=(ans*(ans-1))/2;
			ans+=inin-nw;
			cout<<ans<<endl;
		}
	}
	return 0;
}
//#endif
