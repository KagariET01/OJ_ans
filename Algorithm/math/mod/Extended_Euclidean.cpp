/*
[擴展歐幾里得]https://zh.wikipedia.org/wiki/扩展欧几里得算法#算法和举例
*/

#include<iostream>

template<typename TPE>std::pair<TPE,std::pair<TPE,TPE>> Extended_Euclidean(TPE a,TPE b){
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
	re=(re%b+b)%b
	return re;
}

int main(){
	int a,b;
	std::cin>>a>>b;
	std::pair<int,std::pair<int,int>> ans=Extended_Euclidean(a,b);
	std::cout<<ans.first<<" "<<ans.second.first<<" "<<ans.second.second<<std::endl;
}