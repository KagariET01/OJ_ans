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
#define FI if(filewrite)
bool debug=0;
bool noTLE=1;
bool filewrite=0;
string fname="a.out";
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

INT Isqrt(INT n){
	INT l=0,r=n;
	while(l<r){
		INT mnt=(r-l)/2+l;
		if(mnt*mnt<n){
			l=mnt+1;
		}else if(mnt*mnt>n){
			r=mnt;
		}else{
			return mnt;
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
		}else if(nwstr=="-W"){
			filewrite=1;
			if(argc-1>i){
				string nxstr=argv[i+1];
				fname=nxstr;
				i++;
			}
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
	ofstream fout(fname);
	INT t=1000;
	for(INT n=2;n<=t;n++){
		PII mx={0,0};
		for(INT i=n;i>=1 && i>=mx.first*2;i--){
			INT ano=1;
			while(i%ano==0 && ano<i){
				ano++;
			}
			ano--;
			DBG cerr<<"i="<<i<<" ano="<<ano<<endl;
			PII nw={(ano!=1?max(ano,i/ano):ano),i};
			mx=max(mx,nw);
		}
		FI fout<<mx.first<<" "<<mx.second;
		cout<<mx.first<<" "<<mx.second;
		for(INT i=1;i<=n;i++){
			if(i==mx.first || i==mx.second)continue;
			FI fout<<" "<<i;
			cout<<" "<<i;
		}
		FI fout<<endl;
		cout<<endl;
	}
	return 0;
}
//#endif
