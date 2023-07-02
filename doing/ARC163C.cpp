/*
[q]
[]
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
		INT n=read(INT);
		INT tt=(n+1)*n/2;
		bool ans=1;
		for(INT i=1;i<=n;i++){
			if(tt%i>0){
				ans=0;
				break;
			}
		}
		if(ans){
			cout<<"Yes"<<endl;
			for(INT i=n;i>=1;i--){
				if(i<n)cout<<" ";
				cout<<tt/i;
			}
			cout<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
//#endif
