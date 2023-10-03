/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1845&P=A
[]
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
		INT n,k,x;
		cin>>n>>k>>x;
		if(x!=1){
			cout<<"YES"<<endl;
			cout<<n<<endl;
			for(INT i=0;i<n;i++){
				if(i)cout<<" ";
				cout<<1;
			}
			cout<<endl;
			continue;
		}else if(x==1){
			if(k==1){
				cout<<"NO"<<endl;
				continue;
			}else{
				if(n%2){
					if(n>=3 && k>=3){
						cout<<"YES"<<endl;
						cout<<((n-3)/2+1)<<endl;
						for(INT i=0;n>3;i++,n-=2){
							cout<<"2 ";
						}
						cout<<"3"<<endl;
						continue;
					}else{
						cout<<"NO"<<endl;
						continue;
					}
				}else{
					cout<<"Yes"<<endl;
					cout<<(n/2)<<endl;
					for(INT i=0;i<n/2;i++){
						if(i)cout<<" ";
						cout<<"2";
					}
					cout<<endl;
					continue;
				}
			}
		}
	}
	return 0;
}
//#endif
