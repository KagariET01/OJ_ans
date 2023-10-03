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
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

struct dta{
	INT t=0;
	INT a=0;
	INT id=0;
};

bool vser(dta a,dta b){
	if(a.a!=b.a) return a.a>b.a;
	else return a.id<b.id;
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
	INT t=read(int);
	while(t--){
		INT n,k;
		cin>>n>>k;
		vector<dta> vec(n);
		for(INT i=0;i<n;i++){
			cin>>vec[i].a;
			vec[i].id=i;
			vec[i].a%=k;
			if(!vec[i].a)vec[i].a=k;
		}
		sort(vec.begin(),vec.end(),vser);
		DBG{
			for(INT i=0;i<n;i++){
				cout<<"id:"<<vec[i].id<<" a:"<<vec[i].a<<" t:"<<vec[i].t<<endl;
			}
		}

		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<vec[i].id+1;
		}
		
		cout<<endl;
	}
	return 0;
}
//#endif
