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
		INT a,b,c,d;
		cin>>a>>b>>c>>d;
		INT amin=1,amax=1;
		INT bmin=1,bmax=1;
		INT cmin=1,cmax=1;
		for(INT i=1;i<a;i++){
			amin*=10;
		}
		for(INT i=1;i<b;i++){
			bmin*=10;
		}
		for(INT i=1;i<c;i++){
			cmin*=10;
		}
		amax=amin*10-1;
		bmax=bmin*10-1;
		cmax=cmin*10-1;
		INT ansa=-1,ansb=-1;
		for(INT nwa=amin;nwa<=amax;nwa++){
			INT nwbmax=min(bmax,cmax-nwa);
			INT nwbmin=max(bmin,cmin-nwa);
			if(nwbmin>nwbmax)continue;
			INT nwall=nwbmax-nwbmin+1;
			if(nwall<d){
				d-=nwall;
			}
			else{
				ansa=nwa;
				ansb=nwbmin+d-1;
				break;
			}
		}
		if(ansa==-1 && ansb==-1){
			cout<<-1<<endl;
			continue;
		}else{
			cout<<ansa<<" + "<<ansb<<" = "<<ansa+ansb<<endl;
		}
	}
	return 0;
}
//#endif
