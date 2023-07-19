/*
[q]
[math]
[AC]
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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n=read(INT);
		INT c=1;
		while(n%c==0)c++;
		char re[n+1];
		for(INT i=0;i<n;i++){
			re[i]='a'+i%c;
		}
		re[n]='\0';
		cout<<re<<endl;
	}
	return 0;
}
//#endif
