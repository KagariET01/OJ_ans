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
		INT n;
		cin>>n;
		bool ans=1;
		INT a[n]={};
		INT bmn[n]={};
		INT b[n]={};
		for(INT i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>n)ans=0;
			else bmn[a[i]-1]++;
		}
		INT nw=n;
		for(INT i=0;i<n && ans;i++){
			b[i]=nw;
			nw-=bmn[i];
			if(b[i]!=a[i])ans=0;
		}
		if(ans)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
//#endif
