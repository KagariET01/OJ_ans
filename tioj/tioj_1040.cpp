/*
[Q]https://tioj.ck.tp.edu.tw/problems/1040
[math]
[遞迴]
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define INT int

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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT t;
	cin>>t;
	while(t--){
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
