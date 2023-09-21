//[AC]
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}


int swmp[4][4]={
	{0,1,2,3},
	{1,3,0,2},
	{2,0,3,1},
	{3,2,1,0}
};

char rp(char a,char b){
	return 'a'+swmp[a-'a'][b-'a'];
}

string str;
INT p;
INT n;


char solve(INT deep=0){
	char bef='0';
	for(;p<n;){
		DBG{
			for(INT i=0;i<deep;i++){
				cout<<"|";
			}
		}
		char nw='0';
		if(str[p]=='('){
			p++;
			nw=solve(deep+1);
		}else if(str[p]==')'){
			DBG cout<<bef<<endl;
			return bef;
		}else if(str[p]=='*'){
			p++;
			DBG cout<<endl;
			continue;
		}else{
			nw=str[p];
		}

		if(bef=='0'){
			bef=nw;
			DBG cout<<bef<<endl;
			p++;
			continue;
		}else{
			bef=rp(bef,nw);
			DBG cout<<bef<<endl;
			p++;
			continue;
		}
	}
	return bef;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	cin>>str;
	p=0;
	n=str.size();
	cout<<solve()<<endl;
	return 0;
}

/*
a*((b*d)*c)
(a*b*c*(c*d*(a*(c*c*a)*b))*d)

a*(b*c)

*/

