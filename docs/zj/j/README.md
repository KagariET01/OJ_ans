<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">


[`back`](../)

> ## [`ZJ J242`] `NHSPC 111N P1A` 111 北二 1a.自然數的平方根
> [`ZJ J242`]: https://zerojudge.tw/ShowProblem?problemid=j242
> ### `C++`
>
> ```c++
> #include<bits/stdc++.h>
>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> #define min(a,b) (a<b?a:b)
> #define max(a,b) (a>b?a:b)
> #define mins(a,b) a=min(a,b)
> #define maxs(a,b) a=max(a,b)
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
>
> const INT mxn=1e5;
> INT lca[mxn+1][30];
> INT n;
> vector<INT> tre[mxn];
> INT deep[mxn];
>
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
>
> 	//function<int(INT)> solve=[](INT casenum){
> 	auto solve=[](INT casenum){
> 		INT n;
> 		if(!(cin>>n)){
> 			return -1;
> 		}
> 		for(INT i=sqrt(n);i>=2;i--){
> 			if(n%(i*i)==0){
> 				if(n/(i*i)==1){
> 					cout<<i<<endl;
> 					return 0;
> 				}
> 				cout<<i<<" sqrt("<<n/(i*i)<<")"<<endl;
> 				return 0;
> 			}
> 		}
> 		cout<<"sqrt("<<n<<")"<<endl;
> 		return 0;
> 	};
> 	bool one_case=1;
> 	bool ynans=0;
> 	bool eof=1;
> 	string yes="YES";
> 	string no="NO";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		INT re=solve(i);
> 		if(eof && re==-1){
> 			return 0;
> 		}else if(ynans){
> 			if(re==1){
> 				cout<<yes<<endl;
> 			}else if(re==0){
> 				cout<<no<<endl;
> 			}else{
> 				return re;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```
