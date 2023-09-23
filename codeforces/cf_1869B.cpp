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

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,k,a,b;
		cin>>n>>k>>a>>b;
		a--;b--;
		PII lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i].first>>lst[i].second;
		}
		INT alen=0;
		alen=abs(lst[a].first-lst[b].first)+abs(lst[a].second-lst[b].second);
		INT blena=2e10+7;
		INT blenb=2e10+7;
		for(INT i=0;i<k;i++){
			blena=min(blena,(abs(lst[a].first-lst[i].first)+abs(lst[a].second-lst[i].second)));
			blenb=min(blenb,(abs(lst[b].first-lst[i].first)+abs(lst[b].second-lst[i].second)));
		}
		cout<<min(alen,(blena+blenb))<<endl;
	}
	return 0;
}