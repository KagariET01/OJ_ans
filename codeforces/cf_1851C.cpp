/*
[q]
[water]
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
	INT t=read(int);
	while(t--){
		INT n,k;
		cin>>n>>k;
		INT c[n];
		for(INT i=0;i<n;i++){
			cin>>c[i];
		}
		INT l=k,r=k,i=0;
		if(c[0]==c[n-1])r=0;
		for(;i<n && l;i++){
			if(c[i]==c[0]){
				l--;
				if(!l)break;
			}
		}
		for(;i<n && r;i++){
			if(c[i]==c[n-1]){
				r--;
				if(!r)break;
			}
		}
		if(l || r){
			cout<<"no"<<endl;
		}else{
			cout<<"yes"<<endl;
		}
	}
	return 0;
}
//#endif
