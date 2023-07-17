/*
[q]
[water]
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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n=read(INT);
		set<string> se;
		set<string> sea;
		while(n--){
			string str=read(string);
			bool filpe=true;
			INT m=str.size();
			for(INT i=0;i<m/2;i++){
				if(str[i]!=str[m-i-1]){
					filpe=0;
					break;
				}
			}
			if(filpe){
				sea.insert(str);
			}else{
				se.insert(str);
				reverse(str.begin(),str.end());
				se.insert(str);
			}
		}
		cout<<(se.size()/2+sea.size())<<endl;
	}
	return 0;
}
//#endif
