/*
[q]https://neoj.sprout.tw/problem/265/
[AC]
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

vector<INT> KMS(string s,string t){//回傳一vector，代表S在T的哪些地方
    vector<INT> f=getF(s);
    INT ss=s.size();
    INT ts=t.size();
    vector<INT> re;
    INT p=-1;//表s的開頭要在t的哪裡
    for(INT i=0;i<ts;i++){
	while(p>=0 && s[p+1]!=t[i]){//重複移動p直到字串S前綴和字串T重疊
	    p=f[p];
	}
	if(s[p+1]==t[i]){
	    p++;
	}
	if(p+1==ss){
	    re.push_back(i-p);
	    p=f[p];
	}
    }
    return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=1;
	while(t--){
		string s,t;
		cin>>s>>t;
		vector<INT> vec=KMS(s,t);
		INT n=vec.size();
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	return 0;
}
//#endif