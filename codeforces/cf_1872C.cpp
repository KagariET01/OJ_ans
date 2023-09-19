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
const INT nn=100000;
INT ll[nn+5];
vector<INT> odlst;
void ggetod(INT n=nn){
	memset(ll,0,sizeof(ll));
	odlst.push_back(2);
	for(INT i=3;i<=n;i++){
		if(ll[i]<=1){
			odlst.push_back(i);
		}
		for(INT j:odlst){
			if(j*i>n)break;
			ll[j*i]=j;
			if(j==ll[i])break;
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
	ggetod();
	INT t=read(int);
	while(t--){
		INT l,r;
		cin>>l>>r;
		INT t=4;
		if(r<4){
			cout<<-1<<endl;
			continue;
		}
		bool ans=0;
		while(t-- && !ans){
			if(l>r)break;
			INT bse=0;
			for(INT i:odlst){
				//DBG cerr<<" i="<<i<<endl;
				if(i>=l)break;
				if(l%i==0){
					bse=i;
					break;
				}
			}
			//DBG cerr<<"l="<<l<<"bse="<<bse<<endl;
			if(!bse){
				l++;
				continue;
			}
			cout<<bse<<" ";
			l-=bse;
			cout<<l<<endl;
			ans=1;
			break;
		}
		if(!ans)cout<<-1<<endl;
	}
	return 0;
}
//#endif
