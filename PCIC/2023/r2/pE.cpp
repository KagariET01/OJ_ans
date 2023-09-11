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

const INT mxn=1e5;
INT n;
INT lst[mxn+5];
void doA(){
	INT cpy[n];
	for(INT i=0;i<n;i++){
			cpy[i]=lst[i];
	}
	for(INT i=0;i<n;i++){
		lst[i]=cpy[n-i-1];
	}
}
void doB(){
	INT cpy[n];
					for(INT i=0;i<n;i++){
							cpy[i]=lst[i];
					}
	for(INT i=0;i<n;i++){
		lst[i]=n-cpy[i]+1;
	}
}
void doAB(){
	doA();
	doB();
}
void doC(){
	INT cpy[n];
					for(INT i=0;i<n;i++){
							cpy[i]=lst[i];
					}
	for(INT i=0;i<n;i++){
		lst[cpy[i]-1]=i+1;
	}
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
	INT t=1;
	while(t--){
		cin>>n;
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		INT q;
		cin>>q;
		deque<INT> dq;
		//1=1
		//2=2
		//3=3
		//4=1+2
		while(q--){
			INT inin=read(INT);
			dq.push_back(inin);
		}
		deque<INT> doit;
		while(dq.size()>=2){
			INT b=dq.back();
			dq.pop_back();
			INT a=dq.back();
			dq.pop_back();
			DBG cerr<<"a="<<a<<" b="<<b<<" ";
			if(a==b){DBG cerr<<"delet ";}
			else if(a==1 && b==2){dq.push_back(4);DBG cerr<<"merge ";}
			else if(a==4 && b==1){dq.push_back(2);DBG cerr<<"to2   ";}
			else if(a==4 && b==2){dq.push_back(1);DBG cerr<<"to1   ";}
			else if(b==4 && a==1){dq.push_back(2);DBG cerr<<"to2   ";}
			else if(b==4 && a==2){dq.push_back(1);DBG cerr<<"to1   ";}
			else{
				dq.push_back(a);
				doit.push_back(b);
			}
			DBG{
				for(INT i:dq){
					cerr<<i<<" ";
				}
				cerr<<endl;
			}
		}
		while(!dq.empty()){
			INT b=dq.back();
			dq.pop_back();
			doit.push_back(b);
		}
		while(!doit.empty()){
			INT b=doit.back();
			doit.pop_back();
			if(b==1)doA();
			else if(b==2)doB();
			else if(b==3)doC();
			else doAB();
		}

		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<lst[i];
		}
		cout<<endl;
	}
	return 0;
}


/*
3 3 1 2 2 1 3
> 2 1 3
5 1 2 3 4 5 4 1 2 3 1
> 5 4 3 2 1
15 8 6 9 1 5 13 3 7 15 10 12 14 11 4 2 10 
2 1 3 2 3 1 3 2 1 2
> 12 1 9 2 11 14 8 15 13 6 3 5 10 4 7

15 8 6 9 1 5 13 3 7 15 10 12 14 11 4 2 2 3 1

2 1 3 2 3 1 3 1

1 3 1 3 2 3 1 2
*/
