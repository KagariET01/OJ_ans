/*
[q]https://tioj.ck.tp.edu.tw/problems/1281
[加密密鑰 (Key)]
[二分搜][string algorithm]
[WA]
*/

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
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=1;
	while(t--){
		string str=read(string);
		INT n=str.size();
		vector<INT> vec;
		vec.reserve(12);
		INT r=min((INT)11,n),l=0,count=5;
		string fndstr=str.substr(1,n-1);
		while(l<r && count){
			count--;
			INT mid=(r+l)/2;
			string nwstr=str.substr(0,mid);
			DBG cerr<<nwstr<<endl;
			if(fndstr.find(nwstr)!=string::npos){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		for(INT i=0;i<r;i++){
			cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}

