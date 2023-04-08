/*
[Q]https://tioj.ck.tp.edu.tw/problems/1072
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define PII pair<INT,INT>
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n;
	while(cin>>n && n){
		PII lst[n];//{吃飯時間,煮的時間}
		for(INT i=0;i<n;i++){
			cin>>lst[i].second>>lst[i].first;
		}
		INT nwt=0;
		INT ans=0;
		
		sort(lst,lst+n,greater<PII>());
		for(PII i:lst){
			nwt+=i.second;
			ans=max(ans,nwt+i.first);
		}
		cout<<ans<<endl;
	}
	return 0;
}