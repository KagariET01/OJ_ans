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

struct dta{
	INT id=0;
	INT w=0;
	INT a=0;
	INT l=0;
	string sortby="WAL";
	INT getv(char c){
		if(c=='w' || c=='W')return w;
		else if(c=='a' || c=='A')return a;
		else return l;
	}
};
/*
bool operator>(const dta &a,const dta &b){
	string sortby=a.sortby;
	for(INT i=0;i<3;i++){
		if(a.getv(sortby[i])!=b.getv(sortby[i])){
			return a.getv(sortby[i])>b.getv(sortby[i]);
		}
	}
	return a.id>b.id;
}
*/
struct vser{
	bool operator()(dta a,dta b){
		for(INT i=0;i<3;i++){
			if(a.getv(a.sortby[i])!=b.getv(b.sortby[i])){
				return a.getv(a.sortby[i])>b.getv(b.sortby[i]);
			}
		}
		return a.id>b.id;
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
		string s[n];
		for(INT i=0;i<n;i++){
			cin>>s[i];
		}
		priority_queue<dta,vector<dta>,vser> pq_WAL;
		priority_queue<dta,vector<dta>,vser> pq_WLA;
		priority_queue<dta,vector<dta>,vser> pq_AWL;
		priority_queue<dta,vector<dta>,vser> pq_ALW;
		priority_queue<dta,vector<dta>,vser> pq_LAW;
		priority_queue<dta,vector<dta>,vser> pq_LWA;
		vector<dta> vec;
		vec.reserve(m+q);
		INT id=0;
		for(;id<m;){
			dta nw;
			cin>>nw.w>>nw.a>>nw.l;
			nw.id=id;
			vec.push_back(nw);
			nw.sortby="WAL";pq_WAL.push(nw);
			nw.sortby="WLA";pq_WLA.push(nw);
			nw.sortby="AWL";pq_AWL.push(nw);
			nw.sortby="ALW";pq_ALW.push(nw);
			nw.sortby="LAW";pq_LAW.push(nw);
			nw.sortby="LWA";pq_LWA.push(nw);
			id++;
		}
		INT ans[n][3]={};
		INT mp[m+q+5]={};
		while(q--){
			INT a=read(INT);
			if(a==1){
				dta nw;
				cin>>nw.w>>nw.a>>nw.l;
				nw.id=id;
				vec.push_back(nw);
				nw.sortby="WAL";pq_WAL.push(nw);
				nw.sortby="WLA";pq_WLA.push(nw);
				nw.sortby="AWL";pq_AWL.push(nw);
				nw.sortby="ALW";pq_ALW.push(nw);
				nw.sortby="LAW";pq_LAW.push(nw);
				nw.sortby="LWA";pq_LWA.push(nw);
				id++;
			}else{
				INT b=read(INT)-1;
				INT tk=0;
				if(s[b]=="WAL"){while(!pq_WAL.empty() && mp[pq_WAL.top().id])pq_WAL.pop();tk=pq_WAL.top().id;}
				if(s[b]=="WLA"){while(!pq_WLA.empty() && mp[pq_WLA.top().id])pq_WLA.pop();tk=pq_WLA.top().id;}
				if(s[b]=="AWL"){while(!pq_AWL.empty() && mp[pq_AWL.top().id])pq_AWL.pop();tk=pq_AWL.top().id;}
				if(s[b]=="ALW"){while(!pq_ALW.empty() && mp[pq_ALW.top().id])pq_ALW.pop();tk=pq_ALW.top().id;}
				if(s[b]=="LAW"){while(!pq_LAW.empty() && mp[pq_LAW.top().id])pq_LAW.pop();tk=pq_LAW.top().id;}
				if(s[b]=="LWA"){while(!pq_LWA.empty() && mp[pq_LWA.top().id])pq_LWA.pop();tk=pq_LWA.top().id;}
				ans[b][0]+=vec[tk].w;
				ans[b][1]+=vec[tk].a;
				ans[b][2]+=vec[tk].l;
				mp[tk]=1;
			}
		}
		for(INT i=0;i<n;i++){
			cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
		}
	}
	return 0;
}
//#endif
