/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1843&P=B
[greedy]
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
		INT n;
		cin>>n;
		INT lst[n];
		INT fixlst[n];
		INT abstt=0;
		for(INT i=0;i<n;i++){
			cin>>lst[i];
			abstt+=abs(lst[i]);
			if(lst[i]<0)fixlst[i]=-1;
			else if(lst[i]==0)fixlst[i]=0;
			else fixlst[i]=1;
		}
		INT adfilp=1;
		INT mnfilp=0;
		INT bef=0;
		for(INT i=0;i<n;i++){
			if(fixlst[i]==0)continue;
			if(!bef){
				bef=fixlst[i];
				if(fixlst[i]<0){
					mnfilp++;
				}else if(fixlst[i]>0){
					adfilp++;
				}
			}else{
				if(bef!=fixlst[i]){
					bef=fixlst[i];
					if(fixlst[i]<0){
					    mnfilp++;
					}else if(fixlst[i]>0){
					    adfilp++;
					}
				}
			}
		}
		cout<<abstt<<" "<<min(adfilp,mnfilp)<<endl;

	}
	return 0;
}
//#endif
