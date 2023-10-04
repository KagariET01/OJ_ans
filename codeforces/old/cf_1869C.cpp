#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,m;
		cin>>n>>m;
		if(m==1){
			cout<<0<<endl;
			for(INT i=0;i<n;i++){
				cout<<0<<endl;
			}
		}else{
			cout<<min(n+1,m)<<endl;
			INT mp[n][m];
			for(INT i=0;i<n;i++){
				INT mv=i%(m-1);
				for(INT j=0;j<m;j++){
					if(j)cout<<" ";
					mp[i][j]=(m?(j+mv)%m:0);
					cout<<mp[i][j];
				}
				cout<<endl;
			}
		}
		
	}
	return 0;
}
