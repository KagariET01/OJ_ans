/*
[Q]https://codeforces.com/group/VEc3guEDmO/contest/431641/problem/B
[AC]
[AC after ans open]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
INT mod=1e9+7;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT N,a,d;cin>>N>>a>>d;
		cout<<((a*2+(N-1)*d%mod)*N/2)%mod<<endl;
	}
	return 0;
}