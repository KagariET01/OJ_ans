<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 448`<br>Codeforces Round 256 (Div. 2)
[`back`](../)

> ## `CF 448 PD`<br>Multiplication Table
> ### `c++`
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
> INT mod=998244353;
> 
> INT n,m,k;
> 
> INT checker(INT mx){
> 	INT r=m;
> 	INT re=0;
> 	for(INT i=1;i<=n;i++){
> 		while(i*r>mx)r--;
> 		re+=r;
> 		if(r==0)break;
> 	}
> 	return re;
> }
> 
> INT BITsearch(INT l,INT r){
> 	while(l<r){
> 		INT mnt=(r-l)/2+l;
> 		if(checker(mnt)>=k){
> 			r=mnt;
> 		}
> 		else l=mnt+1;
> 	}
> 	return r;
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	auto solve=[](INT casenum){
> 		cin>>n>>m>>k;
> 		cout<<BITsearch(1,n*m+1)<<endl;
> 		return 0;
> 	};
> 	bool one_case=1;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```
> ### `Tag`  
> ```txt
> Binary Search
> ```





[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC

<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">