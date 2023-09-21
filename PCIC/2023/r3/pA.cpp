#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

struct dta{
	INT a=0;
	INT b=0;
	INT c=0;
};

bool operator==(dta a,INT b){
	if(a.a==b || a.b==b || a.c==b)return 1;
	else return 0;
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
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG{
		cerr<<"=====DBG mod====="<<endl;
	}
	INT n;
	cin>>n;
	map<INT,dta> mp;
	for(INT i=0;i<n;i++){
		INT id;
		dta nw;
		cin>>id>>nw.a>>nw.b>>nw.c;
		if(mp[id]==(INT)0){
			mp[id]=nw;
		}
	}
	INT ansa=0,ansb=0,ansc=0;
	for(pair<INT,dta> i:mp){
		ansa+=i.second.a;
		ansb+=i.second.b;
		ansc+=i.second.c;
	}
	cout<<ansa<<" "<<ansb<<" "<<ansc<<endl;
}