/*
[q]
[water]
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
	INT t=1;
	while(t--){
		INT n,m;
		cin>>n>>m;
		INT p[n];
		bool f[n][m+1];memset(f,0,sizeof(f));
		for(INT i=0;i<n;i++){
			INT c;
			cin>>p[i]>>c;
			while(c--){
				f[i][read(INT)]=true;
			}
		}

		bool findans=0;

		for(INT i=0;i<n;i++){
			for(INT j=i+1;j<n;j++){
				INT wl=0;
				bool ans=1;
				for(INT k=1;k<=m;k++){
					if(f[i][k]==f[j][k])continue;
					else if(f[i][k]>f[j][k]){
						if(wl==0 || wl==1){
							wl=1;
						}else{
							ans=0;
							break;
						}
					}
					else if(f[i][k]<f[j][k]){
						if(wl==0 || wl==-1){
							wl=-1;
						}else{
							ans=0;
							break;
						}
					}
				}
				if(!ans)continue;
				if(wl==0){
					if(p[i]!=p[j]){
						findans=1;
						break;
					}
				}else if(wl==1){
					if(p[i]<=p[j]){
						findans=1;
						break;
					}
				}else if(wl==-1){
					if(p[i]>=p[j]){
						findans=1;
						break;
					}
				}
			}
			if(findans)break;
		}
		if(findans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
//#endif
