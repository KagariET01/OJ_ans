<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1882` Codeforces Round 899 (Div. 2)

[`back`](../) [`CF 1882`](https://codeforces.com/contest/1882)

> ## `CF 1882 PA` Increasing Sequence
>
> ### `C++`
>
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
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		INT ans=1;
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			if(ans==inin)ans++;
> 			ans++;
> 		}
> 		cout<<ans-1<<endl;
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
>
> ### `Tag`
>
> ```txt
> greedy
> ```

> ## `CF 1882 PB` Sets and Union
>
> ### `C++`
>
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
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		set<INT> vec[55];//哪些人有i
> 		vector<INT> se[n];//第i人有什麼
> 		set<INT> allse;
> 		for(INT i=0;i<n;i++){
> 			INT sz=read(INT);
> 			for(INT j=0;j<sz;j++){
> 				INT inin=read(INT);
> 				se[i].push_back(inin);
> 				vec[inin].insert(i);
> 				allse.insert(inin);
> 			}
> 		}
> 		set<INT> nw;
> 		INT ans=0;
> 		for(INT i:allse){
> 			nw.clear();
> 			for(INT j=0;j<n;j++){
> 				if(vec[i].count(j))continue;
> 				for(INT k:se[j]){
> 					nw.insert(k);
> 				}
> 			}
> 			ans=max(ans,(INT)(nw.size()));
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
>
> ### `Tag`
>
> ```txt
> greedy
> 模擬constructive algorithms
> ```

> ## `CF 1882 PC` Card Game
>
> ### `C++`
>
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
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		INT lst[n+1]={};
> 		INT ans=0;
> 		for(INT i=0;i<n;i++){
> 			cin>>lst[i];
> 		}
> 		if(n<=2){
> 			cout<<max((INT) 0,max(lst[0],lst[1]+lst[0]))<<endl;
> 			return 0;
> 		}
> 		INT i=0;
> 		while(i<n){
> 			if(lst[i]>=0){
> 				ans+=lst[i];
> 				i++;
> 				while(i<n && lst[i]<0)i++;
> 			}
> 			else if(i+1<n && lst[i]+lst[i+1]>=0){
> 				ans+=lst[i]+lst[i+1];
> 				i+=2;
> 				while(i<n && lst[i]<0)i++;
> 			}
> 			else{
> 				i+=2;
> 				while(i<n && lst[i]<0)i++;
> 			}
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
>
> ### `Tag`
>
> ```txt
> greedy
> ```
