/*
[q]https://kagariet01.github.io/swap/?OJ=at&CID=arc164&PID=A
[math]
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,k;
		cin>>n>>k;
		INT myans=0;
		while(n){
			myans+=n%3;
			n/=3;
		}
		if(myans>k){
			cout<<"No"<<endl;
		}else{
			INT lst=k-myans;
			if(lst%2){
				cout<<"No"<<endl;
			}else{
				lst/=2;
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;
}
//#endif
