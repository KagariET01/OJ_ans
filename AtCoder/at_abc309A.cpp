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
	INT t=1;
	while(t--){
		INT a,b;
		cin>>a>>b;
		a--;b--;

		INT ax,ay,bx,by;
		ax=a%3;
		ay=a/3;
		bx=b%3;
		by=b/3;
		INT all=abs(ax-bx)+abs(ay-by)*2;
		DBG{
			for(INT i=1;i<=9;i++){
				INT aa=i-1;
				INT aax=aa%3;
				INT aay=aa/3;
				cerr<<i<<":"<<aax<<","<<aay<<endl;
			}
			cerr<<ax<<","<<ay<<endl;
			cerr<<bx<<","<<by<<endl;
		}
		if(all<=1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
//#endif
