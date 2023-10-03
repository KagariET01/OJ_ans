/*
[q]
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}



vector<INT> s;
INT c=0;
INT n=0;

__int128 check(__int128 n){
	__int128 re=0;
	for(INT i:s){
		re+=(n*2+i)*(n*2+i);
	}
	return re;
}

INT solve(){
	__int128 l=0,r=1e9+7;
	//DBG cerr<<"first setting l:"<<l<<" r:"<<r<<endl;
	__int128 root=check(0);
	if(root==c)return 0;
	//r=c-root;
	while(l<r){
		__int128 mnt=(r-l)/2+l;
		__int128 nw=check(mnt);
		//DBG cerr<<"l:"<<l<<" r:"<<r<<" mnt:"<<mnt<<" nw:"<<nw<<endl;
		if(nw<c){
			l=mnt+1;
		}else if(nw>c){
			r=mnt;
		}else{
			INT re=mnt;
			return re;
		}
	}
	INT re=r;
	return re;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
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
		cin>>n>>c;
		s.resize(n);
		for(INT &i:s){
			cin>>i;
		}
		INT ans=solve();
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
