/*
[q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define read(n) reader<n>()
#define dbg if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

INT bitpow(INT n,INT m){
	TPE re=n;
	m--;
	TPE xx=n;
	while(m){
		if(m&1){
			re=re*xx;
		}
		xx=xx*xx;
		m>>=1;
	}
	return re;
}

INT hash(vector<INT> vec,INT mod,INT c=10){
	INT re=0;
	INT n=vec.size();
	INT cxx=bitpow(c,n-1);
	for(INT i:vec){
		re+=i*cxx;
		re%=mod;
		cxx/=c;
	}
	return re;
}

INT hash_merge(INT s,INT p,INT c,INT b){//最後的結果應該會是sp，c代表此為c進位，b代表p的位數
	return s*bitpow(c,b)+p;
}

INT hash_del_back(INT s,INT c,INT b){//s為hash值，c為c進位，b為要保留的位數
	INT mn=s/bitpow(c,b);
	mn*=bitpow(c,b);
	return s-mn;
}
INT hash_del_front(INT s,INT c,INT b){//s為hash值，c為c進位，b為要刪除的位數
	INT mn=s%bitpow(c,b);
	return (s-mn)/bitpow(c,b);
}



int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=read(int);
	while(t--){
	}
	return 0;
}

