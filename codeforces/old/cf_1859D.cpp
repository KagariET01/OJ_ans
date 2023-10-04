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
#define vecit vector<PII>::iterator
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

bool operator<(PII a,PII b){
	if(a.first!=b.first)return a.first<b.first;
	else return a.second<b.second;
}

vecit finder(vecit l,vecit r,INT find){
	while(l<r){
		vecit mnt=(r-l)/2+l;
		PII nw=*mnt;
		if(nw.first<=find){
			r=mnt;
		}else{
			l=mnt+1;
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
		INT n;
		cin>>n;
		vector<PII> vec;
		for(INT i=0;i<n;i++){
			INT l,r,a,b;
			cin>>l>>r>>a>>b;
			vec.push_back({l,b});
		}
		sort(vec.begin(),vec.end());
		INT q;
		cin>>q;
		vector<PII> nvec;
		nvec.reserve(n);
		PII nw=vec[0];
		for(PII i:vec){
			if(i.first<=nw.second){
				nw.second=max(nw.second,i.second);
			}else{
				nvec.push_back(nw);
				nw=i;
			}
		}
		nvec.push_back(nw);
		DBG{
			for(PII i:nvec){
				cerr<<"fir:"<<i.first<<" sec:"<<i.second<<endl;
			}
		}
		for(INT i=0;i<q;i++){
			if(i)cout<<" ";
			INT x;
			cin>>x;
			vector<PII>::iterator it=upper_bound(nvec.begin(),nvec.end(),make_pair(x,(INT)1e9+7));
			it--;
			if(it<nvec.begin() || nvec.end()<=it){
				cout<<x;
				continue;
			}
			PII nw=*it;
			DBG cerr<<"it-fir="<<nw.first<<" it-sec="<<nw.second<<endl;
			INT ans=x;
			if(nw.first<=x){
				ans=max(ans,nw.second);
			}
			cout<<ans;
			DBG cerr<<endl;
		}
		cout<<endl;
	}
	return 0;
}
//#endif
