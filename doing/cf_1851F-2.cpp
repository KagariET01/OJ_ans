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
#define DBG2 if(debug2)
#define PII pair<INT,INT>
bool debug=0;
bool debug2=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

vector<PII> a;
INT ansl,ansr;
INT ansx=0;
INT nwmx=0;
INT mx=0;
INT n,m;
INT dbg_n=0;

INT BITs(INT l,INT r,INT s){
	while(l<r){
		INT mnt=(r-l)/2+l;
		if(a[mnt].first<s){
			l=mnt+1;
		}else if(s<=a[mnt].first){
	r=mnt;
		}
	}
	return r;
}

void dfs(INT l,INT r,INT n,INT deep=0){//檢查l~r-1的範圍
	DBG2{
		for(INT i=0;i<deep;i++){
			cerr<<" |";
		}
		cerr<<"deep:"<<deep<<" l:"<<l<<" r:"<<r<<" n:"<<n<<endl;
	}
	INT nwl=l;
	INT nwr=l+1;
	INT nwx=((mx*2-1)^(a[nwl].first|a[nwr].first));
	INT nw=((a[nwl].first^nwx)&(a[nwr].first^nwx));
	if(nw>nwmx){
		nwmx=nw;
		ansx=nwx;
		ansl=nwl;
		ansr=nwr;
	}
	if(deep==m)return;
	INT mnt=BITs(l,r,n);
	dfs(l,mnt,n>>1,deep+1);
	dfs(mnt,r,(n>>1)|n,deep+1);
}

bool operator<(PII a,PII b){
	return a.first<b.first;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}else if(nwstr=="-DBG2"){
			debug2=1;
			noTLE=0;
		}
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	if(debug || debug2){
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
		a.clear();
		ansl=0,ansr=0;
		ansx=0;
		nwmx=0;
		mx=0;
		cin>>n>>m;
		mx=1<<(m-1);
		DBG2 cerr<<"mx:"<<mx<<endl;
		for(INT i=0;i<n;i++){
			a.push_back({read(INT),i});
		}
		sort(a.begin(),a.end());
		dfs(0,n,mx);
		cout<<a[ansl].second+1<<" "<<a[ansr].second+1<<" "<<ansx<<endl;
	}
	return 0;
}
//#endif
