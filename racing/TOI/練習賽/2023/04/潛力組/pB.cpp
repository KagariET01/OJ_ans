/*
[AC]
*/
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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n,k;cin>>n>>k;
		INT lst[n];
		INT ans=0;
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}

		INT l=0,r=0;
		set<INT> se;//紀錄boss數量及名稱
		map<INT,INT> bsadd;//紀錄該boss有幾塊地
		for(r=0;r<n;r++){
			se.insert(lst[r]);
			bsadd[lst[r]]++;
			while(se.size()>k){
				bsadd[lst[l]]--;
				if(bsadd[lst[l]]==0)se.erase(lst[l]);
				l++;
			}
			ans=max(ans,r-l+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}