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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,m,q;
		cin>>n>>m>>q;
		vector<PII> vec[n+1];//格式：連接點,怪物等級
		for(INT i=0;i<m;i++){
			INT u,v,l;
			cin>>u>>v>>l;
			vec[u].push_back({v,l});
			vec[v].push_back({u,l});
		}
	}
	return 0;
}
//#endif
