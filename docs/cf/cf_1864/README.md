<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1864`<br>Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
[`back`](../) [`CF 1864`](https://codeforces.com/contest/1864)

> ## `CF 1864 PA`<br>Increasing and Decreasing
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
> INT lowbit(INT n){
> 	return n&(-n);
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=read(int);
> 	while(t--){
> 		INT x,y,n;
> 		cin>>x>>y>>n;
> 		n--;
> 		INT mnx=(n+1)*n/2;
> 		if(y-x>=mnx){
> 			INT nw=x;
> 			cout<<nw;
> 			nw+=n+y-x-mnx;
> 			for(INT i=n-1;i>=1;i--){
> 				cout<<" "<<nw;
> 				nw+=i;
> 			}
> 			cout<<" "<<nw<<endl;
> 		}else{
> 			cout<<-1<<endl;
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1864 PB`<br>Swap and Reverse
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
> INT lowbit(INT n){
> 	return n&(-n);
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=read(int);
> 	while(t--){
> 		INT n,k;
> 		cin>>n>>k;
> 		string s=read(string);
> 		if(k%2){
> 			string a[2];
> 			a[0].reserve(n/2+1);
> 			a[1].reserve(n/2);
> 			for(INT i=0;i<n;i++){
> 				a[i%2].push_back(s[i]);
> 			}
> 			sort(a[0].begin(),a[0].end());
> 			sort(a[1].begin(),a[1].end());
> 			s="";
> 			s.reserve(n);
> 			for(INT i=0;i<a[0].size() || i<a[1].size();i++){
> 				if(i<a[0].size())
> 					s.push_back(a[0][i]);
> 				if(i<a[1].size())
> 					s.push_back(a[1][i]);
> 			}
> 		}else{
> 
> 			sort(s.begin(),s.end());
> 		}
> 		cout<<s<<endl;
> 	}
> 	return 0;
> }
> ```

> ## `CF 1864 PC`<br>Divisor Chain
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
> INT lowbit(INT n){
> 	return n&(-n);
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=read(int);
> 	while(t--){
> 		INT n;
> 		cin>>n;
> 		vector<INT> ans;
> 		ans.push_back(n);
> 		while(n>1){
> 			DBG cerr<<"DBG "<<n<<endl;
> 			INT ln=lowbit(n);
> 			if(ln==n)ln>>=1;
> 			n-=ln;
> 			ans.push_back(n);
> 		}
> 		cout<<ans.size()<<endl;
> 		for(INT i=0;i<ans.size();i++){
> 			if(i)cout<<" ";
> 			cout<<ans[i];
> 		}
> 		cout<<endl;
> 	}
> 	return 0;
> }
> ```



