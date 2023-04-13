/*
[Q]https://neoj.sprout.tw/problem/74/
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;cin>>t;
	while(t--){
		INT n;cin>>n;
		INT lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		INT ans=1;
		INT nwans=1;
		INT nw=lst[0];
		INT go=-1;
		for(INT i=1;i<n;i++){
			if(go==1){
				if(nw<lst[i]){
					nwans++;
					go*=-1;
				}
			}else{
				if(nw>lst[i]){
					nwans++;
					go*=-1;
				}
			}
			nw=lst[i];
		}
		ans=max(ans,nwans);
		if(ans%2==0)ans--;






		cout<<ans<<endl;
	}
	return 0;
}