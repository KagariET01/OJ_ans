/*
[q]https://neoj.sprout.tw/problem/165/
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define dbg if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(INT);
	while(t--){
		INT n,m;
		cin>>n>>m;
		vector<INT> vec[n];
		INT indo[n];
		memset(indo,0,sizeof(indo));
		while(m--){
			INT a,b;
			cin>>a>>b;
			vec[a].push_back(b);
			indo[b]++;
		}
		priority_queue<INT,vector<INT>,greater<INT>> pq;
		vector<INT> ans;
		ans.reserve(n);
		for(INT i=0;i<n;i++)if(!indo[i])pq.push(i);
		while(!pq.empty()){
			INT nw=pq.top();
			pq.pop();
			ans.push_back(nw);
			for(INT i:vec[nw]){
				indo[i]--;
				if(!indo[i]){
					pq.push(i);
				}
			}
		}
		if(ans.size()<n){
			cout<<"QAQ"<<endl;
		}else{
			for(INT i=0;i<n;i++){
				if(i)cout<<" ";
				cout<<ans[i];	
			}
			cout<<endl;
		}
	}
	return 0;
}
