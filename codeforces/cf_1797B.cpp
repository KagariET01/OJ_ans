/*
[Q]https://codeforces.com/contest/1797/problem/A
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
		INT n,k;
		cin>>n>>k;
		bool mp[n][n];
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n;j++){
				cin>>mp[i][j];
			}
		}
		bool ans=true;
		for(INT i=0,bi=n-1;i<(n+1)/2;i++,bi--){
			if(ans) for(INT j=0,bj=n-1;j<n;j++,bj--){
				if(mp[i][j] ^mp[bi][bj]){
					k--;
					mp[i][j]=mp[bi][bj];
				}
				if(k<0){
					ans=false;
					break;
				}
			}
		}
		if(k>0 && n%2==0 && k%2==1){//如果還可以按，就進行判斷
		//如果邊長是奇數，那我們就一直按正中央的格子
		//如果邊長不是奇數，那我們就按角落
			ans=false;
		}
		if(ans)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
/*
1
4 3
1 0 1 1
1 0 0 0
0 1 0 1
1 1 0 1

*/