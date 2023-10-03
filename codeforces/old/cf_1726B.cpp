/*
[Q]https://codeforces.com/contest/1726/problem/B
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
		INT n,m;cin>>n>>m;
		if(n>m){
			cout<<"no"<<endl;
			continue;
		}else if(n==1){
			cout<<"Yes"<<endl;
			cout<<m<<endl;
			continue;
		}else if(m%n==0){
			cout<<"Yes"<<endl;
			for(INT i=0;i<n;i++){
				if(i)cout<<" ";
				cout<<m/n;
			}
			cout<<endl;
			continue;
		}else if(n%2==0 && m%2==1){
			cout<<"no"<<endl;
			continue;
		}else if(n%2==0 && m%2==0){
			cout<<"yes"<<endl;
			m/=2;
			n/=2;
			n--;
			for(INT i=0;i<2;i++){
				if(i)cout<<" ";
				cout<<m-n;
				for(INT i=0;i<n;i++){
					cout<<" "<<1;
				}
			}
			cout<<endl;
			continue;
		}else if(n%2==1){
			cout<<"Yes"<<endl;
			n--;
			cout<<m-n;
			for(INT i=0;i<n;i++){
				cout<<" "<<1;
			}
			cout<<endl;
			continue;
		}else{
			cout<<"No"<<endl;
			continue;
		}
	}
	return 0;
}