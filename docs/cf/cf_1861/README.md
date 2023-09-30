<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1861`<br>Educational Codeforces Round 154 (Rated for Div. 2)
[`back`](../)

> ## `CF 1861 PA`<br>Prime Deletion
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
> vector<INT> prime;
> void build_prime(INT n){
> 	INT lst[n+1]={};
> 	for(INT i=2;i<=n;i++){
> 		if(!lst[i]){
> 			prime.push_back(i);
> 		}
> 		for(INT j:prime){
> 			if(i*j>n)break;
> 			lst[i*j]=j;
> 			if(j==i)break;
> 		}
> 	}
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	build_prime(1000);
> 	auto solve=[](INT casenum){
> 		string str=read(string);
> 		for(INT i:prime){
> 			if(i<10)continue;
> 			string nw="";
> 			INT ii=i;
> 			while(ii){
> 				nw+=('0'+ii%10);
> 				ii/=10;
> 			}
> 			reverse(nw.begin(),nw.end());
> 			INT j=0;
> 			for(char c:nw){
> 				while(j<10 && str[j]!=c)j++;
> 				j++;
> 			}
> 			if(j>10){continue;}
> 			else{cout<<i<<endl;return 0;}
> 		}
> 		cout<<-1<<endl;
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


> ## `CF 1861 PB`<br>Two Binary Strings
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
> 		string a=read(string);
> 		string b=read(string);
> 		INT n=a.size();
> 		for(INT i=0;i+1<n;i++){
> 			if(a[i]==b[i] && a[i]=='0' && a[i+1]==b[i+1] && b[i+1]=='1')return 1;
> 		}
> 		return 0;
> 		//return 0;
> 
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
> 	string yes="YES";
> 	string no="NO";
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






