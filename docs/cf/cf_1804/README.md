<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `OJ CID`<br>N
[`back`](../)

> ## `CF 1804 PA`<br>Lame King
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
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	auto solve=[](INT casenum){
> 		INT x,y;
> 		cin>>x>>y;
> 		x=abs(x);
> 		y=abs(y);
> 		INT sn=min(x,y);
> 		INT mr=max(x,y)-sn;
> 		mr=max((INT)0,mr*2-1);
> 		cout<<sn*2+mr<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="yes";
> 	string no="no";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		if(!ynans){
> 			if(solve(i)==-1)return 0;
> 		}else{
> 			if(solve(i)==1){
> 				cout<<yes<<endl;
> 			}else if(solve(i)==0){
> 				cout<<no<<endl;
> 			}else{
> 				return 0;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1804 PB`<br>Vaccination
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
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	auto solve=[](INT casenum){
> 		INT n,k,d,w;
> 		cin>>n>>k>>d>>w;
> 		INT lsttme=-1e9;
> 		INT nw=0;
> 		INT ans=0;
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			if(nw && (inin-lsttme)<=d){
> 				nw--;
> 			}else{
> 				lsttme=inin+w;
> 				nw=k-1;
> 				ans++;
> 			}
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="yes";
> 	string no="no";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		if(!ynans){
> 			if(solve(i)==-1)return 0;
> 		}else{
> 			if(solve(i)==1){
> 				cout<<yes<<endl;
> 			}else if(solve(i)==0){
> 				cout<<no<<endl;
> 			}else{
> 				return 0;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```





