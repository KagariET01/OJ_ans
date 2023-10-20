<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1876` `CF 1877`<br>Codeforces Round 902 (Div.1, Div. 2, based on COMPFEST 15 - Final Round)

[`back`](../)

> ## `CF 1877 PA`<br>Goals of Victory
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
> 		INT n=read(INT)-1;
> 		INT ans=0;
> 		while(n--){
> 			ans+=read(INT);
> 		}
> 		cout<<(-ans)<<endl;
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
>
> ### `Tag`
> ```txt
> 基本輸出輸入
> ```

> ## `CF 1876 PA` `CF 1877 PB`<br>Helmets in Night Light
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
> 	function<int(INT)> solve=[](INT casenum){
> 		struct dta{
> 			INT a,b;
> 		};
> 		function<bool(dta,dta)> vser=[](dta a,dta b){
> 			if(a.b==b.b)return a.a>b.a;
> 			return a.b<b.b;
> 		};
> 		INT n,p;
> 		cin>>n>>p;
> 		INT ans=0;
> 		INT hve=0;
> 		dta lst[n];
> 		for(INT i=0;i<n;i++){
> 			cin>>lst[i].a;
> 		}
> 		for(INT i=0;i<n;i++){
> 			cin>>lst[i].b;
> 		}
> 		sort(lst,lst+n,vser);
> 		for(INT i=0;i<n;i++){
> 			if(hve==i){
> 				hve++;
> 				ans+=p;
> 			}
> 			ans+=min(lst[i].a,n-hve)*min(lst[i].b,p);
> 			hve+=min(lst[i].a,n-hve);
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


> ## `CF 1877`<br>Joyboard
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
> 		INT n,m,k;
> 		cin>>n>>m>>k;
> 		if(k==1){
> 			cout<<1<<endl;
> 			return 0;
> 		}else if(k==2){
> 			cout<<(min(n-1,m)+m/n)<<endl;
> 			return 0;
> 		}else if(k==3){
> 			m-=n;
> 			m=max(m,(INT)0);
> 			cout<<m-m/n<<endl;
> 			return 0;
> 		}else{
> 			cout<<0<<endl;
> 		}
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