# [`Codeforces`] > `cf 1870`<br>CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!)

> [`cf 1870 PA` MEXanized Array](#pA)  
> ~~[`cf 1870 PB`](#pB)~~  
> ~~[`cf 1870 PC`](#pC)~~  
> ~~[`cf 1870 PD`](#pD)~~  
> ~~[`cf 1870 PE`](#pE)~~  
> ~~[`cf 1870 PF`](#pF)~~  
> ~~[`cf 1870 PG`](#pG)~~  
> ~~[`cf 1870 PH`](#pH)~~  

## pA
`cf 1870 PA` MEXanized Array
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,k,x;
		cin>>n>>k>>x;
		if(n<k || x+1<k){
			cout<<-1<<endl;
			continue;
		}else{
			INT fir=(0+k-1)*k/2;
			if(x==k)x--;
			INT sec=x*max((INT)0,n-k);
			cout<<fir+sec<<endl;
		}
	}
	return 0;
}
```



[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC