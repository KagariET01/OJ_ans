/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1843&P=D
[DFS]
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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
const INT mxn=2e5;
INT stepl[mxn+5];
INT n;
vector<INT> tre[mxn+5];
INT dfs(INT n,INT upp){
	for(INT i:tre[n]){
		if(i==upp)continue;
		stepl[n]+=dfs(i,n);
	}
	stepl[n]=(stepl[n]?stepl[n]:1);
	return stepl[n];
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		memset(stepl,0,sizeof(stepl));
		cin>>n;
		for(INT i=1;i<=n;i++){
			tre[i].clear();
		}
		for(INT i=0;i<n-1;i++){
			INT a,b;
			cin>>a>>b;
			tre[a].push_back(b);
			tre[b].push_back(a);
		}
		dfs(1,0);
		INT q=read(INT);
		while(q--){
			INT a,b;
			cin>>a>>b;
			cout<<stepl[a]*stepl[b]<<endl;
		}
	}
	return 0;
}
//#endif
