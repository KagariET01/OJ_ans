/*
[Q]
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()

template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m;cin>>n>>m;
	INT mx=0,mxid=0;
	INT mn=0,mnid=0;
	for(INT i=1;i<=n;i++){
		INT lst=0;
		INT dn=0;
		INT up=0;
		for(INT j=0;j<m;j++){
			INT inin=read(INT);
			if(j){
				if(inin-lst>0){
					up+=inin-lst;
				}else if(lst-inin>0){
					dn+=lst-inin;
				}
			}
			lst=inin;
		}
		if(mx<up){
			mx=up;mxid=i;
		}
		if(mn<dn){
			mn=dn;mnid=i;
		}
	}
	cout<<mxid<<endl<<mnid<<endl;
	return 0;
}