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
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

struct dta{
	INT cnt=0;
	vector<INT> all;
	dta *nxt[2]={};
};

INT mxdeep=0;
dta *ansit;

void dfs(dta *root,INT deep=0){
	if(root->cnt>=2 && deep>mxdeep){
		ansit=root;
		mxdeep=deep;
	}
	if(root->nxt[0]!=nullptr){
		dfs(root->nxt[0],deep+1);
	}
	if(root->nxt[1]!=nullptr){
		dfs(root->nxt[1],deep+1);
	}
}

void clear(dta *root){
	if(root->nxt[0]!=nullptr){
		clear(root->nxt[0]);
		free(root->nxt[0]);
	}
	if(root->nxt[1]!=nullptr){
		clear(root->nxt[1]);
		free(root->nxt[1]);
	}
	root->cnt=0;
	root->all.clear();
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
		dta root;
		INT n,k;
		cin>>n>>k;
		INT ansx=0;
		DBG cin>>ansx;
		INT mx=1<<(k-1);
		INT a[n];
		for(INT i=0;i<n;i++){
			cin>>a[i];
			dta *it;
			it=&root;
			it->cnt++;
			it->all.push_back(i);
			for(INT j=mx,deep=0;j>0;j>>=1,deep++){
				bool nwb=j&a[i];
				if(it->nxt[nwb]==nullptr){
					it->nxt[nwb]=new dta;
				}
				it=it->nxt[nwb];
				it->cnt++;
				it->all.push_back(i);
			}
		}
		ansit=&root;
		mxdeep=-1;
		dfs(&root);
		INT l=ansit->all[0];
		INT r=ansit->all[1];
		INT x=((mx*2-1)^(a[l]|a[r]));
		cout<<l+1<<" "<<r+1<<" "<<x<<endl;
		DBG cerr<<((a[l]^x)&(a[r]^x))<<endl;
		DBG cerr<<((a[l]^ansx)&(a[r]^ansx))<<endl;
		DBG cerr<<"-------"<<endl;

		clear(&root);
	}
	return 0;
}
//#endif
