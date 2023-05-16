/*
[Q]https://codeforces.com/group/VEc3guEDmO/contest/431641/problem/D
[AC]
[AC after contest 3min]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
INT mod=1e9+7;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n;cin>>n;
		INT bitc[n+1];
		INT a[n+1];
		INT b[n+1];//b[i]回傳i的位置
		bool ab[n+1];
		ab[n]=0;bitc[n]=0;
		for(INT i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]=i;
			ab[i]=0;
			bitc[i]=0;

		}
		
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=i;j<<=1){
				if(i&j)bitc[i]++;
			}
		}

		bool ans=true;
		INT ansc=0;
		for(INT i=1;i<=n && ans;i++){
			if(a[i]==i)continue;
			if(ab[a[i]] && ab[i])continue;
			else{
				if(bitc[a[i]]!=bitc[b[i]]){
					ans=0;
					break;
				}
				DBG cerr<<"swap:"<<i<<","<<b[i]<<endl;
				//註1
				INT nownum=a[i];//表現在的數字
				INT corrnumadd=b[i];//表答案現在在的位置
				swap(a[i],a[b[i]]);//交換兩者
				b[nownum]=corrnumadd;
				b[i]=i;
				ansc++;
			}
		}
		if(ans){
			cout<<ansc<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
/*
8
2 4 5 8 6 3 7 1
假設現在在i，答案在j
現在我們把答案換過去
nownum為待會要去j的數字
corrnumadd為那邊的座標
b[nownum]=corrnumadd代表把nownum移到corrnumadd

*/