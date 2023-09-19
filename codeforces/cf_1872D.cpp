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
		INT n,x,y;
		cin>>n>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		INT ad=0;
		INT mn=0;
		INT xxx=__gcd(x,y);
		INT aaa=x*(y/xxx);
		INT sme=n/aaa;
		INT adcnt=n/x-sme;
		INT mncnt=n/y-sme;
		ad=(n+(n-adcnt+1))*adcnt/2;
		mn=(1+mncnt)*mncnt/2;
		cout<<ad-mn<<endl;
	}
	return 0;
}
//#endif
