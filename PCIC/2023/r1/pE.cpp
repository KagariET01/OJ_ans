#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=0;
bool iofast=1;
//長頸鹿的資料
#define dta map<char,INT>

bool vser_WAL(dta a,dta b){string nwvs="WAL";for(INT i=0;i<3;i++){if(a[nwvs[i]]!=a[nwvs[i]])return a[nwvs[i]]>a[nwvs[i]];}return 1;}
bool vser_WLA(dta a,dta b){string nwvs="WLA";for(INT i=0;i<3;i++){if(a[nwvs[i]]!=a[nwvs[i]])return a[nwvs[i]]>a[nwvs[i]];}return 1;}
bool vser_AWL(dta a,dta b){string nwvs="AWL";for(INT i=0;i<3;i++){if(a[nwvs[i]]!=a[nwvs[i]])return a[nwvs[i]]>a[nwvs[i]];}return 1;}
bool vser_ALW(dta a,dta b){string nwvs="ALW";for(INT i=0;i<3;i++){if(a[nwvs[i]]!=a[nwvs[i]])return a[nwvs[i]]>a[nwvs[i]];}return 1;}
bool vser_LAW(dta a,dta b){string nwvs="LAW";for(INT i=0;i<3;i++){if(a[nwvs[i]]!=a[nwvs[i]])return a[nwvs[i]]>a[nwvs[i]];}return 1;}
bool vser_LWA(dta a,dta b){string nwvs="LWA";for(INT i=0;i<3;i++){if(a[nwvs[i]]!=a[nwvs[i]])return a[nwvs[i]]>a[nwvs[i]];}return 1;}

template<typename TPE> TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read(n) reader<n>()

int main(){
	if(iofast){ET01}
	INT t=1;
	while(t--){
		INT n=read(INT);
		INT a[n];
		for(INT i=0;i<n;i++){
			a[i]=read(INT)-1;
		}

		bool inlove[n]={};//1=in love
		INT eme[n]={};//有eme[i]個人愛i
		for(INT i=0;i<n;i++){
			if(a[a[i]]==i){
				inlove[i]=inlove[a[i]]=1;
			}else{
				inlove[i]=0;
				eme[a[i]]++;
			}
		}
		for(INT i=0;i<n;i++){
			if(inlove[i]){
				cout<<"\\owo/"<<endl;
			}else if(inlove[a[i]]){
				cout<<"\\|/"<<endl;
			}else{
				cout<<eme[a[i]]-1<<endl;
			}
		}


	}
	return 0;
}