/*
[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[35% RE]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
//#include<cmath>
//#include<string>
//#include<sstream>
//#include<vector>
//#include<queue>
//#include<deque>
//#include<map>
//#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT short
#define UINT unsigned INT
#define UU unsigned
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	UU int n;
	cin>>n;
	INT s[n];
	for(UU int i=0;i<n;i++){
		cin>>s[i];
	}
	/*solve*/
	sort(s,s+n);
	cout<<s[n/2]<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
