<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1201`<br>Codeforces Round 577 (Div. 2)

[`back`](../)

> ## [`CF 1201 PC`]<br>Maximum Median
> [`CF 1201 PC`]: https://codeforces.com/contest/1201/problem/C
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n,k;
> 		cin>>n>>k;
> 		INT lst[n];
> 		for(INT i=0;i<n;i++){
> 			cin>>lst[i];
> 		}
> 		sort(lst,lst+n);
> 		INT med=n/2;
> 		INT i=med;
> 		INT ans=lst[med];
> 		for(;k>=(i-med) && i<n;i++){
> 			INT ad=min(k,(lst[i+1]-ans)*(i-med+1))/(i-med+1);
> 			lst[med]+=ad;
> 			ans=lst[med];
> 			k-=ad*(i-med+1);
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=1;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="YES";
> 	string no="NO";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		INT re=solve(i);
> 		if(!ynans){
> 			if(re==-1)return 0;
> 		}else{
> 			if(re==1){
> 				cout<<yes<<endl;
> 			}else if(re==0){
> 				cout<<no<<endl;
> 			}else{
> 				return 0;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```


