<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# [`AT ABC325`] KEYENCE Programming Contest 2023 Autumn (AtCoder Beginner Contest 325)

[`AT ABC325`]: https://atcoder.jp/contests/abc325

[`back`](../)

## [`AT ABC325 PA`] Takahashi san

[`AT ABC325 PA`]: https://atcoder.jp/contests/abc325/tasks/abc325_a

### `C++`

```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		cout<<read(string)<<" san"<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=0;
	string yes="YES";
	string no="NO";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(!ynans){
			if(re==-1)return 0;
		}else{
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
```

### `Tag`

```txt
基本輸出輸入
```
