/*
[Q]https://codeforces.com/group/VEc3guEDmO/contest/431641/problem/A
[AC]
[AC in contest]
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
	INT t=1;
	while(t--){
		INT N,L;cin>>N>>L;
		for(INT i=0;i<N && L>=0;i++){
			L-=read(INT);
		}
		if(L==0){
			cout<<N-1<<endl;
		}else if(L>0){
			cout<<N<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}