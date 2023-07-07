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
		INT a[n];
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
		INT ans=0;
		INT nwn=0;
		INT l=0;
		for(INT r=0;i<n;i++){
			nwn^=a[r];
			while(l<r){
				INT nxn=nwn^a[l];
				if(nxn>=nwn){
					nwn^=a[l];
					l++;
				}else break;
			}
			ans=max(ans,nwn);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
