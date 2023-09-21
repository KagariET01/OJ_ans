#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=0;
bool iofast=1;

template<typename TPE> TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read(n) reader<n>()

int main(){
	if(iofast){ET01}
	INT t=1;
	while(t--){
		INT n=read(INT);
		map<string,string> mp;
		while(n--){
			string a=read(string);
			string b=read(string);
			mp[a]=b;
		}
		string nw;
		bool st=0;
		while(cin>>nw){
			if(st)cout<<" ";
			DBG if(nw=="0")break;
			cout<<mp[nw];
			st=1;
		}
		cout<<endl;
	}
	return 0;
}