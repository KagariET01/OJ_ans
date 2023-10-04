/*
[Q]https://codeforces.com/contest/1814/problem/B
[AC]
[但這好像有點假解]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

INT uper(INT a,INT b){//除法+無條件進位
	return a/b+(a%b?1:0);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT a,b;
		cin>>a>>b;
		if(a==b && a==1){
			cout<<2<<endl;
			continue;
		}
		INT hl=1,hr=max(a,b);//對角長進行二分搜
		
		INT ans=a+b+1;
		while(hr-hl>2){
			INT hlmnt=(hl*2+hr)/3;
			INT hrmnt=(hr*2+hl)/3;

			INT mlans=hlmnt+uper(a,hlmnt)+uper(b,hlmnt);
			INT mrans=hrmnt+uper(a,hrmnt)+uper(b,hrmnt);
			ans=min(ans,min(mlans,mrans));

			if(mlans<mrans)hr=hrmnt;
			else if(mlans>mrans) hl=hlmnt;
			else break;
		}
		
		hl=max((INT)1,hl-1);
		hr++;
		for(INT i=hl;i<=hr;i++){
			ans=min(ans,i+uper(a,i)+uper(b,i));
		}
		cout<<ans-1<<endl;
	}
	return 0;
}