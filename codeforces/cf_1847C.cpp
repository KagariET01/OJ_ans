/*
[q]
[math][bit]
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

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
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
		INT n;cin>>n;
		INT a[n];
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
		INT mxa=1<<8;
		vector<bool> vec(mxa);
		vec[0]=1;
		INT nwxor=0;
		INT ans=0;
		for(INT i=0;i<n;i++){
			nwxor^=a[i];
			for(INT j=0;j<mxa;j++){
				if(vec[j]){
					ans=max(ans,j^nwxor);//j代表0~l的xor，nwxor代表0~r的xor
					//0~i的xor會在j=0時判測
				}
			}
			vec[nwxor]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
