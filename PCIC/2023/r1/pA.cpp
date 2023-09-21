#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=0;
bool iofast=1;

template<typename TPE>TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read( n ) reader< n >()

int main(){
	if(iofast){ET01}
	INT t=1;
	while(t--){
		INT n=read(INT);
		vector<INT> vec;
		vec.reserve(n);
		for(INT i=0;i<n;i++){
			vec.push_back(read(INT));
		}
		sort(vec.begin(),vec.end());
		bool ans=0;
		for(INT i=1;i<n-1 && !ans;i++){
			if(vec[i]+vec[i-1]>vec[i+1]){
				ans=1;
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