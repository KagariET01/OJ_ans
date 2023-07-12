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

string c1[]={
	"+",
	"-",
	"*",
	"/"
};
INT c1s=4;

INT maxa=100;//設定a的最大值
INT mina=0;//設定a的最小值

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	srand( time(NULL) );
	int t=5;//t筆測資
	while(t--){
		int a=rand()%maxa+mina;
		string b=c1[rand()%c1s];
		if(t==0)b="";
		cout<<a<<b;
	}
	return 0;
}
//#endif
