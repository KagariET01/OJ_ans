<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1850`<br>Codeforces Round 886 (Div. 4)
[`back`](../)

> ## [`CF 1850 PA`]<br>To My Critics
> [`CF 1850 PA`]: https://codeforces.com/contest/1850/problem/A
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
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
> 		INT a,b,c;
> 		cin>>a>>b>>c;
> 		INT d,e,f;
> 		d=a+b;
> 		e=b+c;
> 		f=a+c;
> 		if(d>=10 || e>=10 || f>=10){
> 			cout<<"Yes"<<endl;
> 		}else{
> 			cout<<"NO"<<endl;
> 		}
> 	}
> 	return 0;
> }
> ```

> ## [`CF 1850 PB`]<br>Ten Words of Wisdom
> [`CF 1850 PB`]: https://codeforces.com/contest/1850/problem/B
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
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
> 		INT n;
> 		cin>>n;
> 		INT mx=0;
> 		INT mxid=0;
> 		for(INT i=1;i<=n;i++){
> 			INT a,b;
> 			cin>>a>>b;
> 			if(a>10)continue;
> 			if(b>mx){
> 				mx=b;
> 				mxid=i;
> 			}
> 		}
> 		cout<<mxid<<endl;
> 	}
> 	return 0;
> }
> ```

> ## [`CF 1850 PC`]<br>Word on the Paper
> [`CF 1850 PC`]: https://codeforces.com/contest/1850/problem/C
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
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
> 		string ans="";
> 		INT findj=-1;
> 		for(INT i=0;i<8;i++){
> 			string inin=read(string);
> 			if(findj==-1){
> 				for(INT j=0;j<8;j++){
> 					if(inin[j]=='.')continue;
> 					findj=j;
> 					ans+=inin[j];
> 					break;
> 				}
> 			}else if(inin[findj]!='.'){
> 				ans+=inin[findj];
> 			}
> 		}
> 		cout<<ans<<endl;
> 	}
> 	return 0;
> }
> ```

> ## [`CF 1850 PD`]<br>Balanced Round
> [`CF 1850 PD`]: https://codeforces.com/contest/1850/problem/D
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
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
> 		INT a[n];
> 		for(INT i=0;i<n;i++){
> 			cin>>a[i];
> 		}
> 		sort(a,a+n);
> 		INT last=0;
> 		INT mxu=0;
> 		for(INT i=1;i<n;i++){
> 			if(a[i]-a[i-1]>k){
> 				mxu=max(mxu, i-last);
> 				last=i;
> 			}
> 		}
> 		mxu=max(mxu,n-last);
> 		cout<<n-mxu<<endl;
> 	}
> 	return 0;
> }
> ```

> ## [`CF 1850 PE`]<br>We Were Both Children
> [`CF 1850 PE`]: https://codeforces.com/contest/1850/problem/F
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
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
> 		INT n=read(INT);
> 		INT a[n+1];
> 		memset(a,0,sizeof(a));
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			if(inin<=n)a[inin]++;
> 		}
> 		INT ans=0;
> 		for(INT i=1;i<=n;i++){
> 			vector<INT> vec;
> 			for(INT j=1;j<=i;j++){
> 				if(j>i/j)break;
> 				if(i%j)continue;
> 				vec.push_back(j);
> 				if(j!=i/j){
> 					vec.push_back(i/j);
> 				}
> 			}
> 			INT nw=0;
> 			for(INT j:vec){
> 				nw+=a[j];
> 			}
> 			ans=max(ans,nw);
> 		}
> 		cout<<ans<<endl;
> 	}
> 	return 0;
> }
> ```



