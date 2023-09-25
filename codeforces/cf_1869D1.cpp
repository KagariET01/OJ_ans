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


	auto solve=[](INT icase){
		INT n=read(INT);
		INT a[n];
		INT tot=0;
		for(INT i=0;i<n;i++){cin>>a[i];tot+=a[i];}
		if(tot%n)return 0;
		INT cen=tot/n;
		vector<INT> vec;
		vec.resize(64);
		auto lowbit=[](INT n){
			return n&(-n);
		};
		for(INT i=0;i<n;i++){
			if(a[i]==cen)continue;
			INT mx=abs(a[i]-cen);//距離平均的距離
			INT cnv=lowbit(mx);//要其他人給i的
			INT tot=mx+cnv;//i先給出多少給別人
			if(__builtin_popcount(tot)==1){//i先給出去的數量應該要是2^n
				if(a[i]>cen){
					vec[__lg(tot)]++;
					vec[__lg(cnv)]--;
				}else{
					vec[__lg(tot)]--;
					vec[__lg(cnv)]++;
				}
			}else return 0;
		}
		for(INT i:vec){
			if(i)return 0;
		}
		return 1;
	};
	bool one_case=0;
	bool ynans=1;
	string yes="yes";
	string no="no";
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=(one_case?1:read(int));
	for(INT i=0;i<t;i++){
		if(!ynans){
			solve(i);
		}else{
			if(solve(i)){
				cout<<yes<<endl;
			}else{
				cout<<no<<endl;
			}
		}
	}
	return 0;
}
