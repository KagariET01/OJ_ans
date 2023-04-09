/*
[Q]https://neoj.sprout.tw/problem/74/
[]
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
		INT updn=0;//-1:(接下來要)下爬，1:上爬，0:都可
		INT it=0;
		for(INT i=1;i<n;i++){
			if(updn){
				if(updn==1){
					if(lst[it]<lst[i]){
						ans++;
						updn*=-1;
					}
					it=i;
				}else{
					if(lst[it]>lst[i]){
						ans++;
						updn*=-1;
					}
					it=i;
				}
			}else if(lst[it]!=lst[i]){
				ans++;
				if(lst[it]<lst[i])updn=-1;
				else updn=1;
				it=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}