/*
[q]
[AC]
*/
//#ifndef eval
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

string one[]={
	"  _____  ",
	" /     \\ ",
	"|_______|",
	" \\     / ",
	"  \\   /  ",
	"   \\ /   ",
	"    -    "
};

string st[]{
	"  _____  ",
	" /     \\ ",
	"|       |",
	" \\_____/ "
};

string med[]{
	" /     \\ ",
	"|       |",
	" \\_____/ "
};

string ed[]={
	" /     \\ ",
	"|_______|",
	" \\     / ",
	"  \\   /  ",
	"   \\ /   ",
	"    -    "
};


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
		if(n==1){
			for(string str:one){
				cout<<str<<endl;
			}
		}else{
			for(string str:st){
				cout<<str<<endl;
			}
			for(INT i=0;i<n-2;i++){
				for(string str:med){
					cout<<str<<endl;
				}
			}
			for(string str:ed){
				cout<<str<<endl;
			}
		}
	}
	return 0;
}
//#endif
