/*
[Q]https://codeforces.com/problemset/problem/1592/B
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(INT);
	while(t--){
		INT n,x;cin>>n>>x;
		INT a[n];for(INT i=0;i<n;i++)cin>>a[i];
		if((n/2+1)>=x){
			cout<<"YES"<<endl;
			continue;
		}else{
			INT cal=n-x;
			INT car=n-cal-1;
			DBG{
				cout<<"cal="<<cal<<" ";
				cout<<"car="<<car<<endl;
			}
			bool ans=1;
			INT camx=a[car];
			INT camn=a[cal];
			for(INT i=cal;i<car && ans;i++){
				DBG cout<<"i="<<i<<" ";
				if(a[i]<=a[i+1]){
					continue;
				}else{
					DBG cout<<"a[i]="<<a[i]<<" a[i+1]="<<a[i+1]<<" break"<<endl;
					ans=0;
					break;
				}
			}
			DBG cout<<endl;
			for(INT i=0;i<cal && ans;i++){
				DBG cout<<"i="<<i<<" ";
				if(camn<a[i] && a[i]<camx){
					DBG cout<<"break"<<endl;
					ans=0;
					break;
				}
			}
			if(ans){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}