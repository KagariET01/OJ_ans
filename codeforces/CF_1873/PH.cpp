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

INT n,a,b;
const INT mxn=2e5+5;
vector<INT> tre[mxn];//樹
bool circ[mxn];//紀錄是否在環上
bool visi[mxn];//紀錄是否走過
deque<INT> road;//紀錄走過的路
INT ato=0;
INT atolen=1e9+7;
INT btolen=1e9+7;

bool findcirc(INT n,INT lst){
	DBG cerr<<"n="<<n<<" lst="<<lst<<endl;
	if(visi[n] && !circ[n]){//發現環
		deque<INT>::iterator i=road.begin();
		while(*i!=n)i++;
		do{
			if(i==road.end())break;
			circ[*i]=1;
			i++;
		}while(*i!=n);
		return 1;
	}else{
		visi[n]=1;
		road.push_back(n);
		for(INT i:tre[n]){
			if(i==lst)continue;
			if(circ[i])continue;
			if(findcirc(i,n))return 1;
		}
	}
	visi[n]=0;
	road.pop_back();
	return 0;
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
		cin>>n>>b>>a;
		a--,b--;
		for(INT i=0;i<=n;i++){
			tre[i].clear();
		}
		fill(circ,circ+n+1,false);
		fill(visi,visi+n+1,false);
		road.clear();
		for(INT i=0;i<n;i++){
			INT u,v;
			cin>>u>>v;
			u--;v--;
			tre[u].push_back(v);
			tre[v].push_back(u);
		}
		findcirc(0,0);
		
		bool vst[n+5]={};
		deque<PII> dq;
		dq.push_back({a,0});
		vst[a]=1;
		atolen=1e9+7;
		while(!dq.empty()){
			PII nw=dq.front();
			dq.pop_front();
			if(circ[nw.first]){
				ato=nw.first;
				atolen=nw.second;
				break;
			}
			for(INT i:tre[nw.first]){
				if(!vst[i]){
					vst[i]=1;
					dq.push_back({i,nw.second+1});
				}
			}
		}

		memset(vst,0,sizeof(vst));
		dq.clear();
		dq.push_back({b,0});
		vst[b]=1;
		btolen=1e9+7;
		while(!dq.empty()){
			PII nw=dq.front();
			dq.pop_front();
			if(nw.first==ato){
				//bto=nw.first;
				btolen=nw.second;
				break;
			}
			for(INT i:tre[nw.first]){
				if(!vst[i]){
					vst[i]=1;
					dq.push_back({i,nw.second+1});
				}
			}
		}
		DBG cerr<<"atolen="<<atolen<<" btolen="<<btolen<<endl;
		return (atolen<btolen);
	};
	bool one_case=0;
	bool ynans=1;
	string yes="yes";
	string no="no";
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=(one_case?1:read(int));
	for(INT i=0;i<t;i++){
		if(!ynans){
			solve(i);
		}else{
			if(solve(i)){
				cout<<yes<<endl;
			}else{
				cout<<no<<endl;
			}
		}
	}
	return 0;
}
