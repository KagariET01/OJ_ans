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

const INT mxn=10000;
vector<INT> tre[mxn+5];
INT n;
PII tre_deep(INT a,INT bk=-1){
	PII re={1,a};
	for(INT i:tre[a]){
		if(i==bk)continue;
		PII nxt=tre_deep(i,a);
		nxt.first++;
		re=max(re,nxt);
	}
	DBG cerr<<"a="<<a<<" bk="<<bk<<" re.first="<<re.first<<" re.second="<<re.second<<endl;
	return re;
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
		INT n=read(INT);
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			while(inin!=-1){
				tre[i].push_back(inin);
				tre[inin].push_back(i);
				inin=read(INT);
			}
		}
		PII fir=tre_deep(0);
		INT nxt=fir.second;
		cout<<(tre_deep(nxt).first-1)<<endl;

	}
	return 0;
}
//#endif
