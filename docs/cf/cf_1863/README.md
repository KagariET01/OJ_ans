<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1863`<br>Pinely Round 2 (Div. 1 + Div. 2)
[`back`](../)

> ## `CF 1863 PC`<br>MEX Repetition
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
> 	INT t=read(int);
> 	while(t--){
> 		INT n,k;
> 		cin>>n>>k;
> 		INT lst[n+1]={};
> 		bool isit[n+1]={};
> 		for(INT i=0;i<n;i++){
> 			cin>>lst[i];
> 			isit[lst[i]]=1;
> 		}
> 		for(INT i=0;i<=n;i++){
> 			if(!isit[i]){
> 				lst[n]=i;
> 				isit[i]=1;
> 				break;
> 			}
> 		}
> 		INT mv=k%(n+1);
> 		for(INT i=0;i<n;i++){
> 			if(i)cout<<" ";
> 			cout<<lst[(i-mv+(n+1))%(n+1)];
> 		}
> 		cout<<endl;
> 	}
> 	return 0;
> }
> ```
>
> ### `Tag`
> ```txt
> math,觀察
> ```


