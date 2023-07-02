/*
[q]
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

vector<INT> getF(string str){
	INT n=str.size();
	vector<INT> re(n,-1);
	for(INT i=1;i<n;i++){
		if(re[i-1]==-1){//上一個位置沒找到F值
				if(str[i]==str[0]){
			re[i]=0;
				}else{
			re[i]=-1;
				}
		}else{
				INT k=re[i-1]+1;
				re[i]=k;
				while(k>=0 && str[k]!=str[i]){
			k=re[k];
			re[i]=k;
				}
		}
	}
	return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n;
		string s;
		cin>>n>>s;
		vector<INT> F=getF(s);
		INT i=0,j=-1;
		bool ans=0;
		for(i=1;i<n&& !ans;i++){
			while(j>=0 && s[i]!=s[j+1]){
				j=F[j];
			}
			DBG cerr<<"DBG i="<<i<<" j="<<j<<endl;
			if(s[i]==s[j+1]){
				j++;
				if((i+1)/2<=(j)){
					ans=1;
					break;
				}

			}else if(s[j+1]<s[i]){
				ans=1;
				break;
			}
		}
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
//#endif
