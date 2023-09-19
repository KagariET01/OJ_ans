# [`Codeforces`] > `cf 1867`<br>Codeforces Round 897 (Div. 2)

> [`cf 1867 PA` green_gold_dog, array and permutation](#pA)  
> ~~[`cf 1867 PB`](#pB)~~  
> ~~[`cf 1867 PC`](#pC)~~  
> ~~[`cf 1867 PD`](#pD)~~  
> ~~[`cf 1867 PE1`](#pE1)~~  
> ~~[`cf 1867 PE2`](#pE2)~~  
> ~~[`cf 1867 PF`](#pF)~~  

## pA
`cf 1867 PA` green_gold_dog, array and permutation
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
		INT n;
		cin>>n;
		vector<PII> vec;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			vec.push_back({inin,i});
		}
		sort(vec.begin(),vec.end());
		INT ans[n];
		INT cnt=n;
		for(PII i:vec){
			ans[i.second]=cnt;
			cnt--;
		}
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
```
> Tag
> `sort`



[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC