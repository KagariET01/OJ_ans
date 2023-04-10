/*
[Q]https://neoj.sprout.tw/problem/70/
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;cin>>n;
		priority_queue<INT,vector<INT>,greater<INT>> que;
		for(INT i=0;i<n;i++){
			int inin;
			cin>>inin;
			que.push(inin);
		}
		n--;
		INT ans=0;
		while(n--){
			INT a,b;
			a=que.top();
			que.pop();
			b=que.top();
			que.pop();
			ans+=a+b;
			que.push(a+b);
		}
		cout<<ans<<endl;
	}
	return 0;
}