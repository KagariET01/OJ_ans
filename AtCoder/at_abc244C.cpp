/*
[q]https://atcoder.jp/contests/newjudge-2308-algorithm/tasks/abc244_c
[q]https://kagariet01.github.io/swap/?OJ=at&C=abc244&P=C
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
bool noTLE=0;
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
		INT n;
		cin>>n;
		INT mx=n*2+1;
		bool a[mx+1]={};
		INT al=mx;
		for(INT i=1;i<=mx;i++){
			if(a[i])continue;
			cout<<i<<endl;
			a[i]=1;
			al--;
			if(al){
				a[read(INT)]=1;
				al--;
			}else{
				break;
			}
		}
	}
	return 0;
}
//#endif
