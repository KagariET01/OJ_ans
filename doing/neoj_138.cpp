/*
[Q]https://neoj.sprout.tw/problem/138/
[矩陣快速密]
[TLE]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

struct lst{
	INT a[2][2]={
		{0,0},
		{0,0}
	};
};

lst operator*(lst a,lst b){
	lst re;
	for(INT i=0;i<2;i++){
		for(INT j=0;j<2;j++){
			for(INT k=0;k<2;k++){
				re.a[i][j]+=a.a[i][k]*b.a[k][j];
			}
		}
	}
	return re;
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;cin>>t;
	while(t--){
		INT n;cin>>n;
		lst ans;
		ans.a[0][0]=3;
		ans.a[0][1]=2;

		lst xx;
		xx.a[0][0]=3;
		xx.a[1][0]=1;
		xx.a[1][1]=1;
		n/=2;
		n--;
		while(n){
			if(n&1){
				ans=ans*xx;
			}
			xx=xx*xx;
			n>>=1;
		}
		cout<<ans.a[0][0]<<endl;
	}
	return 0;
}