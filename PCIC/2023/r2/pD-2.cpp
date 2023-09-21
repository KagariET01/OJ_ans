/*
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

struct dta{
	INT up;
	INT dn;
};
bool operator<(dta a,dta b){
	INT xx=__gcd(a.dn,b.dn);
	INT ax=b.dn/xx;
	INT bx=a.dn/xx;
	INT aa=a.up*ax;
	INT bb=b.up*bx;
	return aa<bb;
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n;
	cin>>n;
	dta lst[n];
	for(INT i=0;i<n;i++){
		cin>>lst[i].up;
	}
	for(INT i=0;i<n;i++){
		cin>>lst[i].dn;
		//fix
		INT m=__gcd(lst[i].up,lst[i].dn);
		lst[i].up/=m;
		lst[i].dn/=m;
	}
	sort(lst,lst+n);
	INT ans=0;
	INT xx=0;//計算有幾個人同分
	for(INT i=n-1;i>=0;i--){
		xx++;
		if(lst[i].up!=lst[i-1].up || lst[i].dn!=lst[i-1].dn){//兩數不相同
			ans+=i*xx;
			xx=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}



