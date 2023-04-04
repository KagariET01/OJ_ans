/*
[求反模逆元 a^(-1) mod n]https://zh.wikipedia.org/wiki/模反元素#求模反元素
*/

#include<iostream>

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
	INT re=ans.second.first;
	re=(re%b+b)%b;
	if(ans.first==1)return re;
	else return -1;
}


int main(){
	int a,b;
	std::cin>>a>>b;
	int ans=Modular_multiplicative_inverse(a,b);
	std::cout<<ans<<std::endl;
}

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a289
*/