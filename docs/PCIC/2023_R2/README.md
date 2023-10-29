<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `PCIC 2023_R2`

[`back`](../)

> [題目](./R2_All.pdf)

> ## `PCIC 2023_R2 PA` 戀愛家教(Edward)
>
> ### `Score`
>
> ```diff
> + 100/100
> ```
>
> ### `C++`
>
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
> 	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> 	INT t=read(INT);
> 	INT ans=0;
> 	while(t--){
> 		string str;
> 		INT a;
> 		cin>>str>>a;
> 		INT bg=0;
> 		for(char c:str){
> 			if('A'<=c && c<='Z')bg++;
> 		}
> 		if(bg*2>=str.size()){
> 			ans+=a;
> 		}
> 	}
> 	cout<<ans<<endl;
> 	return 0;
> }
> ```

> ## `PCIC 2023_R2 PB` 有限阿貝爾群(Finite Abelian Group)
>
> ### `Score`
>
> ```diff
> + 100/100
> ```
>
> ### `C++`
>
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
>
> int swmp[4][4]={
> 	{0,1,2,3},
> 	{1,3,0,2},
> 	{2,0,3,1},
> 	{3,2,1,0}
> };
>
> char rp(char a,char b){
> 	return 'a'+swmp[a-'a'][b-'a'];
> }
>
> string str;
> INT p;
> INT n;
>
>
> char solve(INT deep=0){
> 	char bef='0';
> 	for(;p<n;){
> 		char nw='0';
> 		if(str[p]=='('){
> 			p++;
> 			nw=solve(deep+1);
> 		}else if(str[p]==')'){
> 			return bef;
> 		}else if(str[p]=='*'){
> 			p++;
> 			continue;
> 		}else{
> 			nw=str[p];
> 		}
>
> 		if(bef=='0'){
> 			bef=nw;
> 			p++;
> 			continue;
> 		}else{
> 			bef=rp(bef,nw);
> 			p++;
> 			continue;
> 		}
> 	}
> 	return bef;
> }
>
> int main(int argc,char** argv){
> 	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> 	cin>>str;
> 	p=0;
> 	n=str.size();
> 	cout<<solve()<<endl;
> 	return 0;
> }
> ```

> ## `PCIC 2023_R2 PC` 山道猴子(Road Monkey)
>
> ### `Score`
>
> ```diff
> + 100/100
> ```
>
> ### `C++`
>
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
> 	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> 	INT t=1;
> 	while(t--){
> 		INT n,x,y,t;
> 		cin>>n>>x>>y>>t;
> 		n+=1;
> 		PII lst[n+1];
> 		lst[0]={0,0};
> 		for(INT i=1;i<n;i++){
> 			cin>>lst[i].first>>lst[i].second;
> 		}
> 		lst[n]={t,x*t+5};
> 		// INT finalrun=0;
> 		// finalrun=t-lst[n-1].first;
> 		// finalrun*=x;
> 		INT basicsp=0;//到最後一個測站時的速度
> 		for(INT i=0;i<n;i++){
> 			INT road=lst[i+1].first-lst[i].first;
> 			basicsp=basicsp+road*x;
> 			basicsp=min(basicsp,lst[i+1].second);
> 		}
>
> 		cout<<basicsp<<endl;;
> 	}
> 	return 0;
> }
> ```

> ## `PCIC 2023_R2 PD` 魔法之域(Magic Realm)
>
> ### `Score`
>
> ```diff
> + 100/100
> ```
>
> ### `C++`
>
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
> struct superfloat{
> 	INT up;
> 	INT dn;
> 	void fix(){
> 		INT xx=__gcd(up,dn);
> 		up/=xx;
> 		dn/=xx;
> 	}
> };
> bool operator<(superfloat a,superfloat b){
> 	INT xx=__gcd(a.dn,b.dn);
> 	INT ax=b.dn/xx;
> 	INT bx=a.dn/xx;
> 	INT aa=a.up*ax;
> 	INT bb=b.up*bx;
> 	return aa<bb;
> }
>
> bool operator==(superfloat a,superfloat b){
> 	return a.up==b.up && a.dn==b.dn;
> }
>
> int main(int argc,char** argv){
> 	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> 	INT n=read(INT);
> 	superfloat lst[n];
> 	for(INT i=0;i<n;i++){
> 		cin>>lst[i].up;
> 	}
> 	for(INT i=0;i<n;i++){
> 		cin>>lst[i].dn;
> 		lst[i].fix();
> 	}
> 	sort(lst,lst+n);
> 	INT ans=0;
> 	INT xx=0;
> 	for(INT i=n-1;i>=0;i--){
> 		xx++;
> 		if(!(lst[i]==lst[i-1])){
> 			ans+=i*xx;
> 			xx=0;
> 		}
> 	}
> 	cout<<ans<<endl;
> 	return 0;
> }
> ```

> ## `PCIC 2023_R2 PE` 魔數師(Magician)
>
> `052/100` > **_下方兩隻程式皆須上傳，才可得到 52 分_**
>
> ### `035/100`
>
> > #### `Score`
> >
> > ```diff
> >   035/100
> > =========
> > + 000/000
> > + 004/004
> > + 004/004
> > + 004/004
> > - 000/017
> > + 023/023
> > - 000/021
> > - 000/027
> > ```
> >
> > #### `C++`
> >
> > ```c++
> > #include<bits/stdc++.h>
> > using namespace std;
> > #define INT long long int
> > #define endl "\n"
> > #define read(n) reader<n>()
> > #define DBG if(debug)
> > #define PII pair<INT,INT>
> > bool debug=0;
> > bool noTLE=1;
> > template<typename tpe>tpe reader(){
> > 	tpe re;cin>>re;return re;
> > }
> >
> > const INT mxn=1e5;
> > INT n;
> > INT lst[mxn+5];
> > void doA(){
> > 	INT cpy[n];
> > 	for(INT i=0;i<n;i++){
> > 			cpy[i]=lst[i];
> > 	}
> > 	for(INT i=0;i<n;i++){
> > 		lst[i]=cpy[n-i-1];
> > 	}
> > }
> > void doB(){
> > 	INT cpy[n];
> > 					for(INT i=0;i<n;i++){
> > 							cpy[i]=lst[i];
> > 					}
> > 	for(INT i=0;i<n;i++){
> > 		lst[i]=n-cpy[i]+1;
> > 	}
> > }
> > void doAB(){
> > 	doA();
> > 	doB();
> > }
> > void doC(){
> > 	INT cpy[n];
> > 					for(INT i=0;i<n;i++){
> > 							cpy[i]=lst[i];
> > 					}
> > 	for(INT i=0;i<n;i++){
> > 		lst[cpy[i]-1]=i+1;
> > 	}
> > }
> >
> > int main(int argc,char** argv){
> > 	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> > 	INT t=1;
> > 	while(t--){
> > 		cin>>n;
> > 		for(INT i=0;i<n;i++){
> > 			cin>>lst[i];
> > 		}
> > 		INT q;
> > 		cin>>q;
> > 		deque<INT> dq;
> > 		while(q--){
> > 			INT inin=read(INT);
> > 			dq.push_back(inin);
> > 		}
> > 		deque<INT> doit;
> > 		while(dq.size()>=2){
> > 			INT b=dq.back();
> > 			dq.pop_back();
> > 			INT a=dq.back();
> > 			dq.pop_back();
> > 			DBG cerr<<"a="<<a<<" b="<<b<<" ";
> > 			if(a==b){DBG cerr<<"delet ";}
> > 			else if(a==1 && b==2){dq.push_back(4);DBG cerr<<"merge ";}
> > 			else if(a==4 && b==1){dq.push_back(2);DBG cerr<<"to2   ";}
> > 			else if(a==4 && b==2){dq.push_back(1);DBG cerr<<"to1   ";}
> > 			else if(b==4 && a==1){dq.push_back(2);DBG cerr<<"to2   ";}
> > 			else if(b==4 && a==2){dq.push_back(1);DBG cerr<<"to1   ";}
> > 			else{
> > 				dq.push_back(a);
> > 				doit.push_back(b);
> > 			}
> > 			DBG{
> > 				for(INT i:dq){
> > 					cerr<<i<<" ";
> > 				}
> > 				cerr<<endl;
> > 			}
> > 		}
> > 		while(!dq.empty()){
> > 			INT b=dq.back();
> > 			dq.pop_back();
> > 			doit.push_back(b);
> > 		}
> > 		while(!doit.empty()){
> > 			INT b=doit.back();
> > 			doit.pop_back();
> > 			if(b==1)doA();
> > 			else if(b==2)doB();
> > 			else if(b==3)doC();
> > 			else doAB();
> > 		}
> >
> > 		for(INT i=0;i<n;i++){
> > 			if(i)cout<<" ";
> > 			cout<<lst[i];
> > 		}
> > 		cout<<endl;
> > 	}
> > 	return 0;
> > }
> > ```
>
> ### `029/100`
>
> > #### `Score`
> >
> > ```diff
> >   029/100
> > =========
> > - 000/000
> > + 004/004
> > + 004/004
> > + 004/004
> > + 017/017
> > - 000/023
> > - 000/021
> > - 000/027
> > ```
> >
> > #### `C++`
> >
> > ```c++
> > #include<bits/stdc++.h>
> > using namespace std;
> > #define INT long long int
> > #define endl "\n"
> > #define read(n) reader<n>()
> > #define DBG if(debug)
> > #define PII pair<INT,INT>
> > bool debug=0;
> > bool noTLE=1;
> > template<typename tpe>tpe reader(){
> > 	tpe re;cin>>re;return re;
> > }
> > int main(int argc,char** argv){
> > 	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
> > 	INT t=1;
> > 	while(t--){
> > 		INT n;
> > 		cin>>n;
> > 		INT lst[n];
> > 		for(INT i=0;i<n;i++){
> > 			cin>>lst[i];
> > 		}
> > 		INT q;
> > 		cin>>q;
> > 		bool filp[4]={0,0,0,0};
> > 		INT que[4]={};
> > 		while(q--){
> > 			INT inin=read(INT);
> > 			filp[inin]^=true;
> > 			if(filp[inin]){
> > 				INT i=0;
> > 				while(que[i])i++;
> > 				que[i]=inin;
> > 			}else{
> > 				INT i=0;
> > 				while(que[i]!=inin)i++;
> > 				for(;i<3;i++){
> > 					que[i]=que[i+1];
> > 				}
> > 			}
> > 		}
> > 		for(INT i:que){
> > 			if(i==1){
> > 				INT cpy[n];
> > 								for(INT i=0;i<n;i++){
> > 										cpy[i]=lst[i];
> > 								}
> > 				for(INT i=0;i<n;i++){
> > 					lst[i]=cpy[n-i-1];
> > 				}
> > 			}
> > 			if(i==2){
> > 				INT cpy[n];
> > 								for(INT i=0;i<n;i++){
> > 										cpy[i]=lst[i];
> > 								}
> > 				for(INT i=0;i<n;i++){
> > 					lst[i]=n-cpy[i]+1;
> > 				}
> > 			}
> > 			if(i==3){
> > 				INT cpy[n];
> > 								for(INT i=0;i<n;i++){
> > 										cpy[i]=lst[i];
> > 								}
> > 				for(INT i=0;i<n;i++){
> > 					lst[cpy[i]-1]=i+1;
> > 				}
> > 			}
> > 		}
> >
> > 		for(INT i=0;i<n;i++){
> > 			if(i)cout<<" ";
> > 			cout<<lst[i];
> > 		}
> > 		cout<<endl;
> > 	}
> > 	return 0;
> > }
> > ```
