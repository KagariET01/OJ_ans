/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

const INT mxn=2147483649;
INT lst[mxn];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	vector<INT> ans;
	INT n;
	INT i=2;
	while(cin>>n){
		for(;i<=n;i++){
			if(!lst[i]){
				ans.push_back(i);
			}
			for(INT j:ans){
				if(i*j>mxn)break;
				lst[i*j]=j;
				if(j==lst[i])break;
			}
		}
		if(lst[i]){
			cout<<"非質數"<<endl;
		}else cout<<"質數"<<endl;
	}
	return 0;
}

/*
2147483647
*/