<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1879`<br>Educational Codeforces Round 155 (Rated for Div. 2)
[`back`](../)

> ## `CF 1879 PA`<br>Rigged!
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
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		INT aa,ab;
> 		bool ans=1;
> 		for(INT i=0;i<n;i++){
> 			if(i){
> 				INT a=read(INT);
> 				INT b=read(INT);
> 				if(a>=aa && b>=ab)ans=0;
> 			}else{
> 				aa=read(INT);
> 				ab=read(INT);
> 			}
> 		}
> 		if(ans)cout<<aa<<endl;
> 		else cout<<-1<<endl;
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
> greedy
> ```

> ## `CF 1879 PB`<br>Chips on the Board
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
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		INT atot=0,amin=1e9+7;
> 		INT btot=0,bmin=1e9+7;
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			atot+=inin;
> 			amin=min(amin,inin);
> 		}
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			btot+=inin;
> 			bmin=min(bmin,inin);
> 		}
> 		INT aans=atot+bmin*n;
> 		INT bans=btot+amin*n;
> 		cout<<min(aans,bans)<<endl;
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
> greedy
> ```


