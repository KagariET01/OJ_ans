#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define PPIIPII pair<PII,PII>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=1;
bool iofast=1;
template<typename TPE> TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read(n) reader<n>()



INT geter(INT w,INT a,INT l,char c){
	if(c=='W')return w;
	if(c=='A')return a;
	if(c=='L')return l;
}

PPIIPII make_PPIIPII(INT a,INT b,INT c,INT d){
	PPIIPII re={{a,b},{c,d}};
	return re;
}

void outPPIIPII(PPIIPII n){
	//DBG cerr<<n.first.first<<","<<n.first.second<<","<<n.second.first<<","<<n.second.second<<endl;
}

PPIIPII make(INT id,INT w,INT a,INT l,string str){
	DBG cerr<<"str="<<str<<endl;
	PPIIPII re=make_PPIIPII(
		-geter(w,a,l,str[0]),
		-geter(w,a,l,str[1]),
		-geter(w,a,l,str[2]),
		id
	);
	DBG outPPIIPII(re);
	return re;
}



int main(){
	if(iofast && !debug){ET01}
	INT t=1;
	while(t--){
		INT n,m,q;
		cin>>n>>m>>q;
		vector<INT> ans[n];//計算[i]拿到的總重量...
		string man[n];//記錄他的喜好排序
		for(INT i=0;i<n;i++){
			cin>>man[i];
		}
		vector<PPIIPII> vec;
		priority_queue<PPIIPII,vector<PPIIPII>> pq_WAL;
		priority_queue<PPIIPII,vector<PPIIPII>> pq_WLA;
		priority_queue<PPIIPII,vector<PPIIPII>> pq_AWL;
		priority_queue<PPIIPII,vector<PPIIPII>> pq_ALW;
		priority_queue<PPIIPII,vector<PPIIPII>> pq_LAW;
		priority_queue<PPIIPII,vector<PPIIPII>> pq_LWA;
		INT id=0;
		for(;id<m;){
			INT w,a,l;
			cin>>w>>a>>l;
			vec.push_back(make(id,w,a,l,"WAL"));
			pq_WAL.push(make(id,w,a,l,"WAL"));
			pq_WLA.push(make(id,w,a,l,"WLA"));
			pq_AWL.push(make(id,w,a,l,"AWL"));
			pq_ALW.push(make(id,w,a,l,"ALW"));
			pq_LAW.push(make(id,w,a,l,"LAW"));
			pq_LWA.push(make(id,w,a,l,"LWA"));
			id++;
		}
		DBG{
			PPIIPII *nw=pq_WAL.back();
			for(INT i=0;i<m;i++){
				DBG cerr<<"id:"<<(*nw).second.second<<" w:"<<(*nw).first.first<<" s:"<<(*nw).first.second<<" l:"<<(*nw).second.first<<endl;
				nw++;
			}
		}
		map<INT,bool> mp;
		while(q--){
			while(!pq_WAL.empty() && mp[pq_WAL.top().second.second]){pq_WAL.pop();}//DBG cerr<<"WAL top:"<<pq_WAL.top().second.second<<endl;
			while(!pq_WLA.empty() && mp[pq_WLA.top().second.second]){pq_WLA.pop();}//DBG cerr<<"WLA top:"<<pq_WLA.top().second.second<<endl;
			while(!pq_AWL.empty() && mp[pq_AWL.top().second.second]){pq_AWL.pop();}//DBG cerr<<"AWL top:"<<pq_AWL.top().second.second<<endl;
			while(!pq_ALW.empty() && mp[pq_ALW.top().second.second]){pq_ALW.pop();}//DBG cerr<<"ALW top:"<<pq_ALW.top().second.second<<endl;
			while(!pq_LAW.empty() && mp[pq_LAW.top().second.second]){pq_LAW.pop();}//DBG cerr<<"LAW top:"<<pq_LAW.top().second.second<<endl;
			while(!pq_LWA.empty() && mp[pq_LWA.top().second.second]){pq_LWA.pop();}//DBG cerr<<"LWA top:"<<pq_LWA.top().second.second<<endl;
			INT a=read(INT);
			if(a==2){
				INT b=read(INT)-1;
				PPIIPII nw;
				if(false){}
				else if(man[b]=="WAL"){PPIIPII nw=pq_WAL.top();pq_WAL.pop();}
				else if(man[b]=="WLA"){PPIIPII nw=pq_WLA.top();pq_WLA.pop();}
				else if(man[b]=="AWL"){PPIIPII nw=pq_AWL.top();pq_AWL.pop();}
				else if(man[b]=="ALW"){PPIIPII nw=pq_ALW.top();pq_ALW.pop();}
				else if(man[b]=="LAW"){PPIIPII nw=pq_LAW.top();pq_LAW.pop();}
				else if(man[b]=="LWA"){PPIIPII nw=pq_LWA.top();pq_LWA.pop();}
				ans[b].push_back(nw.second.second);
				DBG cerr<<"p "<<b<<" get id "<<nw.second.second<<endl;
			}else if(a==1){
				INT w,a,l;
				cin>>w>>a>>l;
				vec.push_back(make(id,w,a,l,"WAL"));
				pq_WAL.push(make(id,w,a,l,"WAL"));
				pq_WLA.push(make(id,w,a,l,"WLA"));
				pq_AWL.push(make(id,w,a,l,"AWL"));
				pq_ALW.push(make(id,w,a,l,"ALW"));
				pq_LAW.push(make(id,w,a,l,"LAW"));
				pq_LWA.push(make(id,w,a,l,"LWA"));
				id++;
			}
		}

		for(INT i=0;i<n;i++){
			INT w=0,s=0,l=0;
			for(INT j:ans[i]){
				PPIIPII nw=vec[i];
				w-=nw.first.first;
				s-=nw.first.second;
				l-=nw.second.first;
				DBG cerr<<"id:"<<nw.second.second<<" w:"<<nw.first.first<<" s:"<<nw.first.second<<" l:"<<nw.second.first<<endl;
			}
			cout<<w<<" "<<s<<" "<<l<<endl;
		}


	}
	return 0;
}