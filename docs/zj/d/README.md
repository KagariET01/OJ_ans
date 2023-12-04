# `ZJ d___`

[`back`](../)

## `ZJ d418` Product of digits
### [`c++`](https://gist.github.com/KagariET01/71fc9f5ab81f127943bb917f114d8d0a)
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define PIPII pair<INT,PII>
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
bool debug=0;
bool noTLE=1;

bool one_case=0;
bool ynans=0;
bool eof=0;
string yes="Yes";
string no="No";

function<int(INT)> solve=[](INT casenum){
	INT n=read(INT);
	string ans="";
	for(INT i=9;i>=2;i--){
		while(n%i==0){
			n/=i;
			char ad=i+'0';
			ans=ad+ans;
		}
	}
	if(n>1)cout<<-1<<endl;
	else if(ans=="")cout<<1<<endl;
	else cout<<ans<<endl;
	return 0;
};

int main(int argc,char** argv){
	{cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
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
greedy
```


<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">
