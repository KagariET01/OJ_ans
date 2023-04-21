/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT int
#define endl "\n"
const INT mxn=500000;
INT zipnum=600;
INT n;
INT origlst[mxn+1];
INT ziplst[mxn+1];
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		zipnum=sqrt(n);
		for(INT i=0;i<n;i++){
			cin>>origlst[i];
			if(i%zipnum==0){
				ziplst[i/zipnum]=origlst[i];
			}else{
				ziplst[i/zipnum]=max(ziplst[i/zipnum],origlst[i]);
			}
		}
		INT q;
		cin>>q;
		while(q--){
			INT l,r;
			cin>>l>>r;
			l--;
			r--;
			if(l>r)swap(l,r);
			INT ans=origlst[l];
			while(l%zipnum && l<=r){
				ans=max(ans,origlst[l]);
				l++;
			}
			while((l+zipnum)<r){
				ans=max(ans,ziplst[l/zipnum]);
				l+=zipnum;
			}
			while(l<=r){
				ans=max(ans,origlst[l]);
				l++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}