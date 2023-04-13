/*
[Q]https://neoj.sprout.tw/problem/19
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define UINT unsigned long long int

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT t;
	cin>>t;
	while(t--){
		INT n=read(INT);
		INT fnl[n];
		for(INT i=0;i<n;i++){
			cin>>fnl[i];
		}

		INT it=0;
		stack<INT>st;
		for(INT i=1;i<=n;i++){
			st.push(i);
			while(!st.empty() && it<n && st.top()==fnl[it]){
				st.pop();
				it++;
			}
		}
		if(it==n){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}