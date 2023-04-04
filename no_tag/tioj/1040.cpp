/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1040

[]

[result]		[AC]
[time]			[3]
[mem]				[3684]
[challenge]	[341795]
[sub time]	[2023/04/02]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>
/*using namespace*/
using namespace std;
/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

void solve(INT p,INT q){
	INT pqgcd=__gcd(p,q);
	p/=pqgcd;
	q/=pqgcd;
	cout<<p/q;//計算整數
	p=p%q;//計算分子
	if(p==0)return;//分子為0，不用寫分數
	else if(p==1){
		cout<<"+1/"<<q;
		return;
	}
	else{
		cout<<"+1/{";
		solve(q,p);
		cout<<"}";
	}
	return;
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*CIN*/
		/*solve*/
		INT p,q;
		cin>>p>>q;
		cout<<p<<"/"<<q<<" = ";
		solve(p,q);
		cout<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
我們先從簡單的開始嘗試
我們先拆一層就好
P/Q=a+?/?
如果P>Q的話，我們是不是能把假分數化為帶分數
下面例子
3/2
=1+1/2
這下知道a是做甚麼用的了嗎
沒錯，就是帶分數的那個常數
所以也是相同的例子
3/2=a+?/?
=1+1/2

那再來一題
5/3=?
以上面的做法來看，應該能寫成
1+2/3
但題目規定分子一定要是1
<下面答案>
那我們可以嘗試化簡
2/3=(2/2)/(3/2)=1/(3/2)
然後，對，有沒有發現一件事
3/2可以寫成1+1/2
那試試看吧
2/3=1/(3/2)=1/{1+1/2}
然後我們再把剛剛的1寫回來
答案就會變成
5+3=1+1/{1+1/2}
這就是我們要的東西，恭喜你完成了


*/
