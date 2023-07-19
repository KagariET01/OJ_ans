/*
[q]
[math]
[generalized Euclidean]
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

INT solve(INT a,INT b){
	if(a==0)return 2;
	if(a<b)return 1+solve(b,abs(a-b));
	if(b==0)return 0;
	INT k=a/b;
	INT r=a%b;
	INT ad=k+(k-1)/2;
	k%=2;
	if(k==0)k=2;
	DBG cerr<<"a:"<<a<<" b:"<<b<<" r:"<<r<<" k:"<<k<<endl;
	//DBG cerr<<k<<" + ";
	if(k==1){
		return k+solve(b,r)%3;
	}else{
		return k+solve(r+b,r)%3;
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n=read(INT);
		INT k[n];//-1表永恆0
		INT allk=-1;
		bool ans=1;
		INT al[n];
		INT bl[n];
		for(INT i=0;i<n;i++){
			cin>>al[i];
		}
		for(INT i=0;i<n;i++){
			cin>>bl[i];
		}
		for(INT i=0;i<n;i++){
			INT a,b;
			a=al[i];b=bl[i];
			if(!ans)continue;
			if(a==0 && b==0)k[i]=-1;
			else k[i]=solve(a,b)%3;

			if(allk==-1){
				allk=k[i];
			}else if(k[i]!=-1 && allk != k[i]){
				ans=0;
			}
			DBG cerr<<endl;
			//DBG cerr<<k[i]<<" ";
		}
		DBG cerr<<endl;
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
//#endif
