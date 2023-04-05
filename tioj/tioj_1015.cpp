/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m;
	while(cin>>n>>m && n && m){
		if(n>m)swap(n,m);
		cout<<(n*(n+1)*(3*m-n+1)/6)<<endl;
	}
	return 0;
}










/*
1^2:n*m個
2:(n-1)(m-1)個
i:(n-i+1)(m-i+1)個
n:m-n+1個
數量=sigma(1~n) (n-i+1)(m-i+1)
=sigma(1~n) (n-i+1)(m-i+1)
=>sigma nm-ni+n-mi+i^2-i+m-i+1
=>sigma nm+n+m+1-ni-mi-i-i+i^2
=>n (nm+n+m+1)-ni-mi-2i+i^2
=>n(n+1)(m+1) -(n+m+2)(n(n+1)/2) + (n(n+1)(2n+1))/6

n(n+1)(m+1)-n*(n+1)(n+m+2)/2+n*(n+1)(2n+1)/6
n(n+1)(m+1)-n*(n+1)3(n+m+2)/6+n*(n+1)(2n+1)/6
n(n+1)(6m+6)/6-n*(n+1)(3n+3m+6)/6+n*(n+1)(2n+1)/6
n(n+1)(3m-n+1)/6
*/