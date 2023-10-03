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

INT lowbit(INT n){
	return n&(-n);
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
		INT x,y,n;
		cin>>x>>y>>n;
		n--;
		INT mnx=(n+1)*n/2;
		if(y-x>=mnx){
			INT nw=x;
			cout<<nw;
			nw+=n+y-x-mnx;
			for(INT i=n-1;i>=1;i--){
				cout<<" "<<nw;
				nw+=i;
			}
			cout<<" "<<nw<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
//#endif
