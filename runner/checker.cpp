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

INT mod=998244353;

int main(int argc,char** argv){
	string outf;
	string ansf;
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(i==0)outf=nwstr;
		else if(i==1)ansf=nwstr;
	}
	ifstream outstr;
	ifstream ansstr;
	outstr.open(outf);
	ansstr.open(ansf);
	bool ans=1;
	cout<<"check start"<<endl;
	while(true){
		string nwout;
		string nwans;
		getline(outstr,nwout);
		getline(ansstr,nwans);
		cout<<nwout<<" | "<<nwans<<endl;
		bool outb=outstr.eof();
		bool ansb=ansstr.eof();
		if(outb!=ansb){
			ans=0;
			cout<<"WA"<<endl;
			break;
		}
		if(!outb && !ansb){
			cout<<"CHECK!"<<endl;
			break;
		}
		if(nwout!=nwans){
			ans=0;
			cout<<"WA"<<endl;
			break;
		}
	}
	return 0;
}
