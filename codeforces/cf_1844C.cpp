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
		INT mx=-1e9;
		INT odd=0,even=0;
		bool oddc=0,evenc=0;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			mx=max(mx,inin);
			if(inin<=0)continue;
			if(i%2){
				odd+=inin;
				oddc=1;
			}else{
				even+=inin;
				evenc=1;
			}
		}
		if(oddc){
			mx=max(mx,odd);
		}if(evenc){
			mx=max(mx,even);
		}
		cout<<mx<<endl;
	}
	return 0;
}
//#endif
