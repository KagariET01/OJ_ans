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
string ans[]={
"ABCCC",
"ABCDC",
"ABBDC",
"DDDDC",
"DCCCC",

"AAABB",
"ACCBD",
"BBCBD",
"DBBBD",
"DDDDD",

"AABBB",
"ACCCB",
"AADCB",
"CDDCB",
"CCCCB",

"AAAAAA",
"ABBBBB",
"ABCCCB",
"ADDDCB",
"ADAACE",
"AAAEEE",

"AAAABB",
"ACCCBA",
"ACDBBA",
"ACDDDA",
"ACCCDA",
"AAAAAA"



};
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	for(string str:ans){
		cout<<str<<endl;
	}
	return 0;
}
//#endif
