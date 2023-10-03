/*
[q]
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
		string s,l,r;
		INT m;
		cin>>s>>m>>l>>r;
		INT i=-1;//現在最佳解中，i在哪
		for(INT j=0;j<m;j++){//維護目前跑到的位置
			INT nwmxi=i;
			for(char nm=l[j];nm<=r[j];nm++){//暴力枚舉num，尋找該位數的最佳解
				INT nwi=i+1;
				while(nwi<s.size() && nm!=s[nwi])nwi++;//greedy檢查選這個值，i可以增加到多少
				nwmxi=max(nwi,nwmxi);
			}
			i=nwmxi;
			if(i>=s.size())break;
		}
		if(i>=s.size()){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
//#endif
