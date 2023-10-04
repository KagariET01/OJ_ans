/*
[q]
[]
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
		INT n;cin>>n;
		INT lst[n];
		INT mn=1e9+7;
		INT mncount=0;
		for(INT i=0;i<n;i++){
			lst[i]=read(INT);
			if(lst[i]<mn){
				mn=lst[i];
				mncount=0;
			}
			if(lst[i]==mn){
				mncount++;
			}
		}
		if(mncount==n){
			cout<<-1<<endl;
			continue;
		}else{
			cout<<mncount<<" "<<n-mncount<<endl;
			for(INT i=0;i<mncount;i++){
				if(i)cout<<" ";
				cout<<mn;
			}
			cout<<endl;
			bool a=0;
			for(INT i=0;i<n;i++){
				if(lst[i]==mn)continue;
				if(a)cout<<" ";
				cout<<lst[i];
				if(!a)a=1;
			}
			cout<<endl;
		}
	}
	return 0;
}
//#endif
