/*
[q]https://codeforces.com/contest/1676/problem/H2
[WA]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

INT n;
vector<INT> vec;
vector<INT> BIT;

INT low_bit(INT x){
	return x&(-x);
}

INT getsum(INT x){//求1~x的值
	INT re=0;
	while(x>0){
		re+=BIT[x];
		x-=low_bit(x);
	}
	return re;
}

void update(INT x,INT m){//單點加值
	while(x<=m){
		BIT[x]+=1;
		x+=low_bit(x);
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		cin>>n;
		vec.resize(n+1);
		BIT.resize(n+1);
		for(INT i=1;i<=n;i++){
			cin>>vec[i];
		}
		INT ans=0;
		for(INT i=n;i>=1;i--){
			ans+=getsum(vec[i]-1);
			update(vec[i],1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
