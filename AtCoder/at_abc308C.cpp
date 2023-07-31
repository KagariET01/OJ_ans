/*
[q]https://kagariet01.github.io/swap/?OJ=at&C=abc308&P=C
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
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

struct dta{
	INT ch;
	INT mo;
	INT id;
	void fix(){
		INT ggcd=__gcd(ch,mo);
		ch/=ggcd;
		mo/=ggcd;
	}
};

bool operator<(const dta &a,const dta &b){
	INT A,B;
	INT ggcd=__gcd(a.mo,b.mo);
	A=a.ch*(b.mo/ggcd);
	B=b.ch*(a.mo/ggcd);
	if(A==B)return a.id>b.id;
	return A<B;
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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	INT t=1;
	while(t--){
		INT n=read(INT);
		vector<dta> vec;
		for(INT i=1;i<=n;i++){
			INT a,b;
			cin>>a>>b;
			dta nw;
			nw.ch=a;
			nw.mo=a+b;
			nw.id=i;
			nw.fix();
			vec.push_back(nw);
		}
		sort(vec.begin(),vec.end());
		for(INT i=n-1;i>=0;i--){
			cout<<vec[i].id;
			if(i)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
//#endif
