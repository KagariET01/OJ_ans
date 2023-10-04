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

INT mod=998244353;

struct str{
	INT nw=0;
	INT n=0;
	INT x=0;
	INT p=0;
	INT id=0;
};
bool operator>(str a,str b){
	return a.nw>b.nw;
}
struct vser{
	bool operator()(str a,str b){
		return a>b;
	}
};

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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		INT t;
		cin>>t;
		priority_queue<str,vector<str>,vser> pq;
		bool ans[t]={};
		for(INT i=0;i<t;i++){
			str nw;
			cin>>nw.n>>nw.x>>nw.p;
			nw.id=i;
			nw.nw=nw.n-nw.x;
			pq.push(nw);
		}
		INT f=1;
		INT ftt=1;
		while(!pq.empty()){
			DBG cerr<<"f="<<f<<" ftt="<<ftt<<endl;
			while(!pq.empty()){
				str nw=pq.top();
				pq.pop();
				DBG cerr<<"f="<<f<<" ftt="<<ftt<<" nw="<<nw.nw<<" n="<<nw.n<<" x="<<nw.x<<" p="<<nw.p<<" id="<<nw.id<<endl;
				if(ftt<nw.nw){
					pq.push(nw);
					break;
				}
				if(nw.nw<ftt){
					INT xx=ftt-nw.nw;
					xx=xx/nw.n+(xx%nw.n?1:0);
					nw.nw+=nw.n*xx;
				}
				if(nw.p<f || nw.n<f*2)continue;
				if(nw.nw==ftt){
					DBG cerr<<nw.id<<" pass"<<endl;
					ans[nw.id]=1;
					continue;
				}
				pq.push(nw);
			}
			f++;
			ftt+=f;
		}
		for(INT i=0;i<t;i++){
			cout<<(ans[i]?"yes":"no")<<endl;
		}
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=0;
	string yes="yes";
	string no="no";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		if(!ynans){
			if(solve(i)==-1)return 0;
		}else{
			if(solve(i)==1){
				cout<<yes<<endl;
			}else if(solve(i)==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
