#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG{
		cerr<<"=====DBG mod====="<<endl;
	}
	INT n,m;
	cin>>n>>m;
	INT a[n][m];
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	INT lastw[n*m+1];
	INT cnt[n*m+1];
	INT ans=0;
	for(INT i=0;i<=n*m;i++){
		lastw[i]=1000;
		cnt[i]=0;
	}

	for(INT i=0;i<n;i++){

		for(INT j=0;j<m;j++){
			if(lastw[a[i][j]]==i-1){
				cnt[a[i][j]]++;
			}else{
				cnt[a[i][j]]=1;
			}
			lastw[a[i][j]]=i;
			ans=max(ans,cnt[a[i][j]]);
		}
	}
	cout<<ans<<endl;
}