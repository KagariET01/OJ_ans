<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1878`<br>Codeforces Round 900 (Div. 3)
[`back`](../) [`CF 1878`](https://codeforces.com/contest/1878)

> ## `CF 1878 PA`<br>How Much Does Daytona Cost?
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
> INT mod=998244353;
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	auto solve=[](INT casenum){
> 		bool re=0;
> 		INT n=read(INT);
> 		INT k=read(INT);
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			re|=(k==inin);
> 		}
> 		
> 		return re;
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
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

> ## `CF 1878 PB`<br>Aleksa and Stack
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
> INT mod=998244353;
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		INT a=1,b=3;
> 		cout<<"1 3";
> 		for(INT i=2;i<n;i++){
> 			INT c=b+1;
> 			DBG cerr<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
> 			while(((3*c)%(b+a))==0)c++;
> 			cout<<" "<<c;
> 			a=b;
> 			b=c;
> 		}
> 		cout<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
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

> ## `CF 1878 PC`<br>Vasilije in Cacak
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
> INT mod=998244353;
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	auto solve=[](INT casenum){
> 		INT n,k,x;
> 		cin>>n>>k>>x;
> 		INT mn=(1+k)*k/2;
> 		INT mx=(n+n-k+1)*k/2;
> 		if(mn<=x && x<=mx)return 1;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
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




