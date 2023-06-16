/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a289
[模逆元]
*/

#include<iostream>
using namespace std;
#define INT long long

template<typename TPE>std::pair<TPE,std::pair<TPE,TPE>> Extended_Euclidean(TPE a,TPE b){//擴展歐幾里得
	TPE lst[3][3]={
		{a,1,0},
		{b,0,1},
		{0,0,0}
	};
	int i=2;
	for(i=2;lst[(i+2)%3][0];i=(i+1)%3){
		TPE q=lst[(i+1)%3][0]/lst[(i+2)%3][0];
		lst[i][0]=lst[(i+1)%3][0]-lst[(i+2)%3][0]*q;
		lst[i][1]=lst[(i+1)%3][1]-lst[(i+2)%3][1]*q;
		lst[i][2]=lst[(i+1)%3][2]-lst[(i+2)%3][2]*q;
	}
	i=(i+1)%3;
	std::pair<TPE,std::pair<TPE,TPE>> re={lst[i][0],{lst[i][1],lst[i][2]}};
	return re;
}

template<typename TPE>TPE Modular_multiplicative_inverse(TPE a,TPE n){//用擴展歐幾里得求模逆元
	std::pair<TPE,std::pair<TPE,TPE>> ans=Extended_Euclidean(a,n);
	if(ans.first==1){
		TPE re=ans.second.first;
		if(re<0)re+=n;
		return re;
	}else return -1;
}


int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	INT a,b;
	while(cin>>a>>b){
		if(b==1){
			cout<<"No Inverse"<<endl;
			continue;
		}
		INT ans=Modular_multiplicative_inverse(a,b);
		if(ans==-1){
			cout<<"No Inverse"<<endl;
		}else cout<<ans<<endl;
	}
}

