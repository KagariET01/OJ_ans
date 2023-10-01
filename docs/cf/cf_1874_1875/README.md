<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1874` `CF 1875`<br>Codeforces Round 901 (Div. 1, Div. 2)
[`back`](../) [`CF 1874`](https://codeforces.com/contest/1874) [`CF 1875`](https://codeforces.com/contest/1875)

> ## `CF 1875 PA`<br>Jellyfish and Undertale
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
> 		INT a,b,n;
> 		cin>>a>>b>>n;
> 		INT ans=b;
> 		a--;
> 		for(INT i=0;i<n;i++){
> 			ans+=min(read(INT),a);
> 		}
> 		cout<<ans<<endl;
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

> ## `CF 1875 PB` `CF 1874 PA`<br>Jellyfish and Game
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
> 		INT a,b,n;
> 		cin>>a>>b>>n;
> 		n=min(n,(INT)100+n%2);
> 		multiset<INT> sea;
> 		multiset<INT> seb;
> 		for(INT i=0;i<a;i++){
> 			sea.insert(read(INT));
> 		}
> 		for(INT i=0;i<b;i++){
> 			seb.insert(read(INT));
> 		}
> 		for(INT i=1;i<=n;i++){
> 			if(i%2){
> 				auto eedd=seb.end();
> 				eedd--;
> 				sea.insert(*(eedd));
> 				seb.erase((eedd));
> 				seb.insert(*(sea.begin()));
> 				sea.erase((sea.begin()));
> 			}else{
> 				auto eedd=sea.end();
> 				eedd--;
> 				seb.insert(*(eedd));
> 				sea.erase((eedd));
> 				sea.insert(*(seb.begin()));
> 				seb.erase((seb.begin()));
> 			}
> 			DBG{
> 				cerr<<"a:";
> 				for(INT i:sea)cerr<<" "<<i;
> 				cerr<<endl;
> 				cerr<<"b:";
> 				for(INT i:seb)cerr<<" "<<i;
> 				cerr<<endl<<endl;
> 			}
> 		}
> 		INT ans=0;
> 		for(INT i:sea){
> 			ans+=i;
> 		}
> 		cout<<ans<<endl;
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

> ## `CF 1875 PC`<br>Jellyfish and Green Apple
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
> INT lowbit(INT n){
> 	return n&(-n);
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	auto solve=[](INT casenum){
> 		INT a,b;
> 		cin>>a>>b;
> 		INT c=a,d=b;
> 		c/=__gcd(a,b);
> 		d/=__gcd(a,b);
> 		if(d-lowbit(d)){
> 			cout<<-1<<endl;
> 			return 0;
> 		}
> 		a%=b;
> 		INT ans=0;
> 		while(a){
> 			ans+=a;
> 			a*=2;
> 			a%=b;
> 		}
> 		cout<<ans<<endl;
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

> ## `CF 1875 PD`<br>Jellyfish and Mex
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
> 		INT n;
> 		cin>>n;
> 		INT lst[n+1]={};
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			if(inin<n)lst[inin]++;
> 		}
> 		INT i=0;
> 		while(lst[i])i++;
> 		INT dp[n+1];
> 		fill(dp,dp+n,1e9+7);
> 		dp[i]=0;
> 		for(;i>=0;i--){
> 			for(INT j=i-1;j>=0;j--){
> 				dp[j
> 				]=min(dp[j],
> 					dp[i]+ //從i開始
> 					i*(lst[j]-1)+//但是最後一次例外
> 					j
> 				);
> 			}
> 		}
> 		cout<<dp[0]<<endl;
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
> ### `Tag`
> ```txt
> DP
> ```





