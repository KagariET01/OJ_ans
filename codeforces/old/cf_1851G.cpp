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
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

struct dta{
	INT h=0;
	INT a=0;
	INT b=0;
	INT id=0;
};
bool operator<(dta a,dta b){
	return a.h<b.h;
}

struct dsu{
	vector<INT> vec;//vec[i]紀錄i連到哪裡
	vector<set<INT>> se;//se[i]記錄所有連到i的點編號
	void init(INT n){//初始化
		se.clear();
		se.resize(n+1);
		vec.clear();
		vec.resize(n+1);
		for(INT i=0;i<=n;i++){
			vec[i]=i;
			se[i].clear();
		}
	}
	INT find(INT n){//查詢編號
		if(vec[n]==n){
			return n;
		}else{
			INT re=find(vec[n]);//找出最終老大
			se[vec[n]].erase(n);//將n連到re，所以要把vec[n]的被動連線解除掉
			vec[n]=re;//將n連到re
			se[re].insert(n);//re被n連
			return re;
		}
	}
	void merge(INT a,INT b){//合併兩者
		INT aboss=find(a);
		INT bboss=find(b);
		vec[aboss]=bboss;//將a樹連到b樹
		se[bboss].insert(aboss);//b樹被a連
	}
	void erase(INT n){//將n孤立
		vec[n]=n;//將自己連到自己
		INT othboss=*(se[n].begin());//其他的老大就用第一個連到n的人來當
		for(INT i:se[n]){
			vec[i]=othboss;
			se[othboss].insert(i);
		}
		se[n].clear();
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
	INT t=read(int);
	while(t--){
		INT n,m;
		cin>>n>>m;
		INT h[n+1];
		for(INT i=1;i<=n;i++){
			cin>>h[i];
		}
		dsu tre;
		tre.init(n+1);
		vector<dta> bri;
		for(INT i=0;i<m;i++){
			INT a,b;
			cin>>a>>b;
			INT nh=max(h[a],h[b]);
			dta addto;
			addto.h=nh;
			addto.a=a;
			addto.b=b;
			bri.push_back(addto);
		}
		sort(bri.begin(),bri.end());
		vector<dta>::iterator it=bri.begin();

		INT q=read(INT);
		bool ans[q];
		memset(ans,0,sizeof(ans));
		vector<dta> qlist;
		for(INT i=0;i<q;i++){
			INT a,b,e;
			cin>>a>>b>>e;
			dta addto;
			addto.h=h[a]+e;
			addto.a=a;
			addto.b=b;
			addto.id=i;
			qlist.push_back(addto);
		}
		sort(qlist.begin(),qlist.end());

		for(dta nwdta:qlist){
			INT mxh=nwdta.h;
			INT a=nwdta.a;
			INT b=nwdta.b;
			INT id=nwdta.id;
			while(it<bri.end() && (*it).h<=mxh){
				tre.merge((*it).a,(*it).b);
				it++;
			}
			if(tre.find(a)==tre.find(b)){
				ans[id]=1;
			}else{
				ans[id]=0;
			}
		}
		for(INT i=0;i<q;i++){
			if(ans[i]){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
//#endif
