/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1841&P=B
[模擬]
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
		INT bef=0;
		INT st=-1;
		bool swap=false;
		for(INT i=0;i<n;i++){
			INT a=read(INT);
			if(i==0){
				st=a;
				bef=a;
				cout<<1;
				continue;
			}else{
				if(!swap){
					if(bef<=a){
						bef=a;
						cout<<1;
					}else{
						if(a<=st){
							swap=true;
							bef=a;
							cout<<1;
						}else{
							cout<<0;
						}
					}
				}else{
					if(bef<=a && a<=st){
						bef=a;
						cout<<1;
					}else{
						cout<<0;
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
//#endif
