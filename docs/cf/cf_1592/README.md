# [`Codeforces`] > `Codeforces Round 746 (contest 1592)`

> [`pA`](#pA)  
> [`pB Hemose Shopping`](#pB)  
> [`pC`](#pC)  
> [`pD`](#pD)  
> [`pE`](#pE)  
> [`pF1`](#pF1)  
> [`pF2`](#pF2)  


## pB
`cf 1592_B` Hemose Shopping
```c++
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
	INT t=read(INT);
	for(INT nt=0;nt<t;nt++){
		INT n,x;cin>>n>>x;
		INT b[n+1];
		INT a[n+1];for(INT i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
		DBG cout<<"n x="<<n<<" "<<x<<endl;
		if(n>=2*x|| is_sorted(a+1,a+n+1)){
			cout<<"YES"<<endl;
			continue;
		}else{
			INT cal=n-x+1;
			INT car=x;
			sort(b+1,b+n+1);
			INT ans=1;
			for(INT i=cal;i<=car;i++){
				if(a[i]!=b[i]){
					ans=0;
					break;
				}
			}
			if(ans){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
```


[`Codeforces`]: /cf