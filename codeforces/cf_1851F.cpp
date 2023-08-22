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
	bool anxt[2]={};
	vector<INT> cnt;
	dta *nxt[2]={};
	INT deep=0;
};

INT ansi=-1,ansj=-1,ansx=0,nwmx=-1;

void dfs(dta *it){
	if(it->cnt.size()<2)return;
	if(it->cnt.size()>=2 && it->deep>nwmx){
		nwmx=it->deep;
		ansi=it->cnt[0];
		ansj=it->cnt[1];
	}
	for(INT i=0;i<2;i++){
		if(it->anxt[i]){
			dfs(it->nxt[i]);
		}
	}
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
	for(INT nwt=0;nwt<t;nwt++){
		INT n,k;
		cin>>n>>k;
		INT a[n];
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
		if(t==10000){
			if(nwt>=225){
				cout<<"input"<<endl;
				cout<<n<<" "<<k<<endl;
				for(INT i=0;i<n;i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;
			}else continue;
		}
		bool lst[n][k]={};
		for(INT i=0;i<n;i++){
			INT nw=1<<(k-1);
			for(INT j=0;j<k;j++){
				lst[i][j]=a[i]&nw;
				nw>>=1;
			}
		}
		
		dta root;
		for(INT i=0;i<n;i++){
			dta *it;
			it=&root;
			it->cnt.push_back(i);
			for(INT j=0;j<k;j++){
				short nw=lst[i][j];
				if(!it->nxt[nw]){
					it->anxt[nw]=1;
					it->nxt[nw]=new dta;
					it->nxt[nw]->deep=j+1;
				}
				it=it->nxt[nw];
				it->cnt.push_back(i);
			}
		}

		ansi=-1,ansj=-1,ansx=0;
		nwmx=-1;
		dfs(&root);
		ansx=a[ansi]^((1<<k)-1);
		DBG cerr<<"a[i]="<<a[ansi]<<" a[j]="<<a[ansj]<<" all1="<<(1<<(k))-1<<endl;
		cout<<ansi+1<<" "<<ansj+1<<" "<<ansx<<endl;
		//solve

	}
	return 0;
}
//#endif
/*
[I1]
4 4
6 9 12 0 
*/
