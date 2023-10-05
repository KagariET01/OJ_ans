# [`TIOJ`]
[`back`](../)

> ## `TIOJ 1025`<br>數獨問題
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
> INT mp[9][9];
> bool row[9][10],column[9][10],box[3][3][10];
> INT ans=0;
> void solve(INT x=0,INT y=0){
> 	if(x==0 && y==0){
> 		memset(row,0,sizeof(row));
> 		memset(column,0,sizeof(column));
> 		memset(box,0,sizeof(box));
> 		debug=1;
> 		for(INT i=0;i<9;i++){
> 			for(INT j=0;j<9;j++){
> 				cin>>mp[i][j];
> 				row[i][mp[i][j]]=1;
> 				column[j][mp[i][j]]=1;
> 				box[i/3][j/3][mp[i][j]]=1;
> 			}
> 		}
> 	}
> 	if(y==9){solve(x+1,0);}
> 	else if(x==9){
> 		for(INT i=0;i<9;i++){
> 			for(INT j=0;j<9;j++){
> 				if(j)cout<<" ";
> 				cout<<mp[i][j];
> 			}
> 			cout<<endl;
> 		}
> 		cout<<endl;
> 		ans++;
> 	}
> 	else if(mp[x][y])solve(x,y+1);
> 	else{
> 		for(INT i=1;i<=9;i++){
> 			if(row[x][i] || column[y][i] || box[x/3][y/3][i])continue;
> 			row[x][i] = column[y][i] = box[x/3][y/3][i] = 1;
> 			mp[x][y]=i;
> 			solve(x,y+1);
> 			row[x][mp[x][y]] = column[y][mp[x][y]] = box[x/3][y/3][mp[x][y]] = 0;
> 			mp[x][y]=0;
> 		}
> 		mp[x][y]=0;
> 	}
> 	
> 	if(x==0 && y==0){
> 		cout<<"there are a total of "<<ans<<" solution(s)."<<endl;
> 	}
> }
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	solve();
> 	return 0;
> }
> ```

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