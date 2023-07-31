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

pair<INT,PII> supergcd(INT r1,INT s1,INT t1,INT r2,INT s2,INT t2){
	if(r2)return supergcd(r2,s2,t2,r1%r2,s1-s2*(r1/r2),t1-t2*(r1/r2));
	else return {r1,{s1,t1}}; 
}

INT ggcd=0,ggcda=0,ggcdb=0,lcma=0,lcmn=0,lcmm=0;
bool checker(INT q){
	if(q%ggcd)return 0;
	INT xx=q/ggcd;
	INT a=ggcda*xx;
	INT b=ggcdb*xx;
	if(0)DBG{
		cerr<<"a:"<<a<<" b:"<<b<<endl;
	}
	if(a<0){
		INT aneed=-a;
		INT swapc=aneed/lcmn+((a%lcmn)?1:0);//代表需要多少次轉換，p.s. 須無條件進入
		b-=swapc*lcmm;//將b部分轉給a
		DBG{
			cerr<<"a:"<<a<<" b:"<<b<<" swapc:"<<swapc<<endl;
		}
		return b>=0;
	}else if(b<0){
		INT bneed=-b;
		INT swapc=bneed/lcmm+((b%lcmm)?1:0);
		a-=swapc*lcmn;
		DBG{
			cerr<<"a:"<<a<<" b:"<<b<<" swapc:"<<swapc<<" bneed:"<<bneed<<endl;
		}
		return a>=0;
	}else{
		return 1;
	}
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
		INT n,m,q;
		cin>>n>>m>>q;
		INT d[q];
		for(INT i=0;i<q;i++){
			cin>>d[i];
		}
		pair<INT,PII> sgcd=supergcd(n,1,0,m,0,1);
		ggcd=sgcd.first;
		ggcda=sgcd.second.first;
		ggcdb=sgcd.second.second;
		lcma=n*m/ggcd;
		lcmn=lcma/n;//表lcmn個n可以換lcmm個m
		lcmm=lcma/m;
		DBG{
			cerr<<"ggcd:"<<ggcd<<" ggcda:"<<ggcda<<" ggcdb:"<<ggcdb<<" lcma:"<<lcma<<" lcmn:"<<lcmn<<" lcmm:"<<lcmm<<endl;
		}
		for(INT i=0;i<q;i++){
			if(checker(d[i])){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
//#endif
