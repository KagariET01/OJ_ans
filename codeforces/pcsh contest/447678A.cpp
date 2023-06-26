/*
[q]
[]
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
/*
string toBinary(INT n,INT inin){
	string re="";
	while(n){
		re+=n%inin+'0';
		n>>=1;
	}
	return (re==""?"0":re);
}

struct str{
	vector< pair<map<double,double>,map<double,double>> > lst(1000000)[1000000];
};
*/
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(INT);
	//cout<<t%2+1<<endl;
	//return 0;
	cout<<t%100+1<<endl;
	return 0;
}
//#enif
