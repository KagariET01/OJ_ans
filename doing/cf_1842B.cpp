/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1842&P=B
[BIT]
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
vector<bool> vbit;
vector<bool> nwbit;
bool checker(vector<bool> *a,vector<bool> *b){
	INT n=(*a).size();
	INT m=(*b).size();
	if(b>a)return 0;
	for(INT i=0;i<m;i++){
		if((*b)[i] && !(*a)[i])return 0;
	}
	return 1;
}
void merge(vector<bool> *a,vector<bool> *b){
	INT n=min((*a).size(),(*b).size());
	for(INT i=0;i<n;i++){
		(*a)[i]=(*a)[i]|(*b)[i];
	}
}
void mkbit(INT v,vector<bool> *bitl){
	(*bitl).clear();
	while(v){
		(*bitl).push_back(v%2);
		v/=2;
	}
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,x;
		cin>>n>>x;
		INT nw=0;
		
		for(INT i=0;i<3;i++){
			bool stop=0;
			for(INT j=0;j<n;j++){
				INT inin=read(INT);
				if(!stop && ((nw|inin)|x)==x){
					nw=nw|inin;
				}else stop=1;
			}
		}
		if(nw==x){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
//#endif
