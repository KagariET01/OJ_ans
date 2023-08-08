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
	INT cnt=0;
	bool hnx['Z'-'A'+1];
	dta *nxt['Z'-'A'+1];
};

void ptre(dta *root,INT deep=1){
	cerr<<(*root).cnt<<endl;
	for(INT i=0;i<('Z'-'A'+1);i++){
		if((*root).hnx[i]){
			INT dpc=deep;
			while(dpc--){
				cerr<<"|";
			}
			cerr<<char(i+'A')<<" ";
			ptre((*root).nxt[i],deep+1);
		}
	}
}
string str[1000000];

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
		INT n=read(INT);
		dta root;
		memset(root.hnx,0,('Z'-'A'+1));

		for(INT i=0;i<n;i++){
			str[i]=read(string);
		}
		//solve
		for(INT i=0;i<n;i++){
			dta *it;
			it=&root;
			for(char c:str[i]){
				(*it).cnt++;
				if(!((*it).hnx[c-'A'])){
					(*it).nxt[c-'A']=new dta;
					memset((*(*it).nxt[c-'A']).hnx,0,('Z'-'A'+1));
				}
				(*it).hnx[c-'A']=1;
				it=(*it).nxt[c-'A'];
			}
			(*it).cnt++;
		}
		//cout
		for(INT i=0;i<n;i++){
			dta *it;
			it=&root;
			INT ans=0;
			for(char c:str[i]){
				it=(*it).nxt[c-'A'];
				if((*it).cnt>1){
					ans+=(*it).cnt-1;
				}else{
					break;
				}
			}
			cout<<ans<<endl;
			DBG{
				ptre(&root);
				cerr<<endl;
			}
		}
	}
	return 0;
}
//#endif