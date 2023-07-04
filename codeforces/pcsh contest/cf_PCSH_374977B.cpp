/*
[q]https://codeforces.com/group/VEc3guEDmO/contest/374977/problem/B
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned short
#define endl "\n"
#define read(n) reader<n>()
#define dbg if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

string tmp[]={
"___@@_____@___",
"____@@___@@___",
"_@@@@@@@@@@@@@",
"______@@______",
"__@@@@@@@@@@__",
"______@@______",
"_@@@@@@@@@@@@@",
"______@@______",
"@@@@@@@@@@@@@@",
"_____@@_@@____",
"___@@@___@@@__",
"@@@@_______@@@"
};

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT ans=2000;
	INT sc=0;
	int t=read(INT);
	while(t--){
		INT m=read(INT);
		INT nws=0;
		for(INT i=0;i<12;i++){
			string str=read(string);
			for(INT j=0;j<14;j++){
				if(str[j]==tmp[i][j]){
					nws++;
				}
			}
		}
		if(nws>sc){
		    ans=m;
		    sc=nws;
		}else if(nws==sc){
		    ans=min(ans,m);
		}
	}
	cout<<ans<<endl;
	return 0;
}
//#endif
