<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# [`CF 1825`] Codeforces Round 872 (Div. 2)
[`CF 1825`]: https://codeforces.com/contest/1825

[`back`](../)

> ## [`CF 1825 PC`] LuoTianyi and the Show
> [`CF 1825 PC`]: https://codeforces.com/contest/1825/problem/C
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> 
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> #define max(a,b) ((a>b)?a:b)
> #define min(a,b) ((a<b)?a:b)
> #define maxs(a,b) a=max(a,b)
> #define mins(a,b) a=min(a,b)
> #define ifif if
> #define elif else if
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n,m;
> 		cin>>n>>m;
> 		bool seat[m+1]={};
> 		INT pf=0;
> 		INT pb=0;
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			DBG cerr<<"inin="<<inin<<endl;
> 			if(inin==-1){
> 				pf++;
> 			}else if(inin==-2){
> 				pb++;
> 			}else{
> 				seat[inin]=true;
> 			}
> 		}
> 		INT tot=0;
> 		INT alad[m+1];
> 		for(INT i=0;i<=m;i++){
> 			if(seat[i])tot++;
> 			alad[i]=tot;
> 		}
> 		INT ans=0;
> 		ans=max(min(m,pf+tot),min(m,pb+tot));
> 		DBG cerr<<"pf="<<pf<<" pb="<<pb<<endl;
> 		DBG cerr<<"tot="<<tot<<endl;
> 
> 		for(INT i=1;i<=m;i++){
> 			DBG cerr<<"ans="<<ans<<endl;
> 			if(!seat[i])continue;
> 			INT npf=pf+alad[i-1];
> 			INT npb=pb+alad[m]-alad[i];
> 			mins(npf,i-1);
> 			DBG cerr<<"i-1="<<i-1<<endl;
> 			mins(npb,m-i);
> 			DBG cerr<<"m-1="<<m-1<<endl;
> 			maxs(ans,npf+npb+1);
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
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