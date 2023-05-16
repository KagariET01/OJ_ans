/*
[Q]https://neoj.sprout.tw/problem/398/
[AC]
*/
#ifndef EVAL
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}
const double eps=1e-10;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n=read(INT);
		double lst[n];
		for(INT i=0;i<n;i++){
			lst[i]=read(double);
		}
		INT ans=0;
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n;j++){
				double tot=lst[i]+lst[j];
				for(INT k=0;k<n;k++){
					if(fabs(tot-lst[k])<=eps){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#endif