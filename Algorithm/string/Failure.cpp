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
#define dbg if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

vector<INT> getF(string str){
    INT n=str.size();
    vector<INT> re(n,-1);
    for(INT i=1;i<n;i++){
	if(re[i-1]==-1){
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
	int t=read(int);
	while(t--){
	    string s;
	    cin>>s;
	    vector<INT> vec=getF(s);
	    for(INT i:vec){
		cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
//#endif
