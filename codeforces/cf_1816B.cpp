/*

[Q]https://codeforces.com/contest/1816/problem/B

[WA]

*/

#include<bits/stdc++.h>

using namespace std;

#define INT long long int

#define endl "\n"

 

int main(){

	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);	INT t;cin>>t;

	while(t--){

		INT n;cin>>n;

		INT ans[2][n];

		INT nw=n*2;

		ans[0][0]=n*2;

		ans[1][n-1]=n*2-1;

		for(INT i=0;i<n;i++){

			ans[(i+1)%2][i]=i+1;

		}

		for(INT i=1;i<n-1;i++){

			ans[(i)%2][i]=i+n;

		}

		for(INT i=0;i<2;i++){

			for(INT j=0;j<n;j++){

				cout<<ans[i][j]<<" ";

			}

			cout<<endl;

		}

	}

	return 0;

}
