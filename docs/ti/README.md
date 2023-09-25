# [`TIOJ`]
[`back`](../)

> ## `TIOJ 2054` 
> ### `Thinking`
> ```txt
> 農兩個雙指標
> 第一個雙指標在最一開始就建立
> 該雙指標代表選取框的x座標
> 
> 框好之後建第二個雙指標
> 異曲同工，這次是代表y座標的
> ```
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> /*using namespace*/
> using namespace std;
> /*define type*/
> #define ULLI unsigned long long int
> #define LLI long long int
> #define INT LLI
> #define PII pair<INT,INT>
> #define DBG if(debug)
> #define elif else if
> #define read(n) reader<n>()
> bool debug=0;
> bool iofast=true;
> /*fn定義*/
> template<typename TPE>TPE reader(){
> 	TPE a;
> 	cin>>a;
> 	return a;
> }
> 
> bool vser(PII a,PII b){
> 	return a.first<b.first;
> }
> /*main*/
> int main(){
> 	if(!debug&&iofast){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> 	INT t=1;
> 	while(t--){
> 		/*CIN*/
> 		INT n=read(INT);
> 		INT l,w;
> 		cin>>l>>w;
> 		vec.resize(n);
> 		for(INT i=0;i<n;i++){
> 			vec[i]={read(INT),read(INT)};
> 		}
> 		/*solve*/
> 		INT ans=0;
> 		sort(vec.begin(),vec.end(),vser);
> 		INT lx=0;
> 		for(INT rx=0;rx<n;rx++){
> 			while(vec[rx].FIR-vec[lx].FIR>w){
> 				lx++;
> 			}
> 			vector<INT> yvec;
> 			yvec.clear();
> 			for(INT i=lx;i<=rx;i++){
> 				yvec.push_back(vec[i].SEC);
> 			}
> 			sort(yvec.begin(),yvec.end());
> 			INT ly=0;
> 			for(INT ry=0;ry<yvec.size();ry++){
> 				while(yvec[ry]-yvec[ly]>l){
> 					ly++;
> 				}
> 				ans=max(ans,ry-ly+1);
> 			}
> 		}
> 		cout<<ans<<endl;
> 	}
> 	return 0;
> }
> ```
> ### `tag`
> ```txt
> 雙指標
> ```










[`Codeforces`]: /OJ_ans/cf
[`TIOJ`]: /OJ_ans/ti
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC



<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">