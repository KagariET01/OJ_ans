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

const INT mxn=1e6;
vector<INT> tre[mxn+5];
INT n=0;
INT bst[mxn+5];
INT tre_cen(INT a,INT bk=-1){
	INT mx=0;
	INT all=0;
	for(INT i:tre[a]){
		if(i==bk)continue;
		INT nxt=tre_cen(i,a);
		all+=nxt;
		mx=max(mx,nxt);
	}
	bst[a]=max(mx,n-all-1);
	return all+1;
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
	INT t=1;
	while(t--){
		cin>>n;
		for(INT i=1;i<n;i++){
			INT a,b;
			cin>>a>>b;
			tre[a].push_back(b);
			tre[b].push_back(a);
		}
		tre_cen(0);
		INT mn=n;
		INT ans=-1;
		for(INT i=0;i<n;i++){
			if(mn>bst[i]){
				mn=bst[i];
				ans=i;
			}
		}
		DBG{
			for(INT i=0;i<n;i++){
				cerr<<bst[i]<<" ";
			}
			cerr<<endl;
		}
		cout<<mn<<endl;
	}
	return 0;
}
//#endif
