/*
[neoj]			[Q]https://neoj.sprout.tw/problem/47

[]

[result]		[RE]
[time]			[120]
[mem]				[10012]
[challenge]	[235768]
[sub time]	[2023/03/16 22:01:27]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>
/*using namespace*/
using namespace std;
/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader< n >()
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}


struct bit_tre{
	INT dta;
	bit_tre *ltre=NULL,*rtre=NULL;
	void insert(INT n){
		if(n<dta){
			if(ltre==NULL){
				ltre=new(bit_tre);
				(*ltre).dta=n;
			}else (*ltre).insert(n);
		}else{
			if(rtre==NULL){
				rtre=new(bit_tre);
				(*rtre).dta=n;
			}else (*rtre).insert(n);
		}
	}
	PII query(bit_tre *nde,INT fnd){
		INT ans1=(*nde).dta;
		INT ans2=(*nde).dta;
		PII l={ans1,ans2};
		if((*nde).ltre!=NULL)l=query((*nde).ltre,fnd);
		PII r={ans1,ans2};
		if((*nde).rtre!=NULL)r=query((*nde).rtre,fnd);
		INT lst[]={l.FIR,l.SEC,r.FIR,r.SEC};
		for(INT i:lst){
			if( abs(i-fnd)<abs(ans1-fnd) ){
				ans1=i;
				ans2=i;
			}elif( abs(i-fnd)==abs(ans1-fnd) ){
				if(ans1 != i){
					ans2=i;
				}
			}
		}
		return make_pair(ans1,ans2);
	}
	bit_tre *find(bit_tre *nde,INT fnd){
		INT &nw=(*nde).dta;
		if((*nde).dta==fnd)return nde;
		elif(nw>fnd)return find((*nde).ltre,fnd);
		else return find((*nde).rtre,fnd);
	}
	bit_tre *fndmin(bit_tre *nde){
		if((*nde).ltre==NULL)return nde;
		else return (*nde).ltre;
	}
	void del(bit_tre *nde,INT fnd){
		bit_tre *repnxt;
		bit_tre *rep;
		bit_tre *del_pnt=find(nde,fnd);
		
		if((*del_pnt).ltre==NULL && (*del_pnt).rtre==NULL){//要刪除的節點世尾節點
			while(true){
				if(fnd<(*nde).dta){
					nde=(*nde).ltre;
				}else{
					nde=(*nde).rtre;
				}
				if(((*nde).ltre)!=NULL && (*((*nde).ltre)).dta==fnd)break;
				if(((*nde).rtre)!=NULL && (*((*nde).rtre)).dta==fnd)break;
			}
			if((*((*nde).ltre)).dta==fnd){
				free((*nde).ltre);
				(*nde).ltre=NULL;
			}else{
				free((*nde).rtre);
				(*nde).rtre=NULL;
			}
			return;
		}elif((*del_pnt).ltre==NULL || (*del_pnt).rtre==NULL){//要刪除的節點只有1個子節點
			rep=del_pnt;
			if((*del_pnt).ltre==NULL){
				repnxt=(*del_pnt).rtre;
			}else{
				repnxt=(*del_pnt).ltre;
			}
		}else{
			rep=fndmin(del_pnt);
			(*del_pnt).dta=(*rep).dta;
			repnxt=(*rep).rtre;

		}
		(*rep).dta=(*repnxt).dta;
		(*rep).ltre=(*repnxt).ltre;
		(*rep).rtre=(*repnxt).rtre;
		free(repnxt);
	}



	void outer(){
		if(ltre!=NULL){
			(*ltre).outer();
		}
		if(rtre!=NULL){
			(*rtre).outer();
		}
		cout<<dta<<endl;
	}
};





/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	bit_tre tre;
	bool dta=false;
	while(t--){
		/*CIN*/
		string str=read(string);
		if(str=="insert"){
			if(dta){
				tre.insert(read(INT));
			}else{
				tre.dta=read(INT);
			}
			dta=true;
		}elif(str=="query"){
			PII re=tre.query((&tre),read(INT));
			if(re.FIR==re.SEC){
				cout<<re.FIR<<endl;
			}else{
				cout<<re.FIR<<" "<<re.SEC<<endl;
			}
		}else{
			tre.del(&tre,read(INT));
		}
		/*solve*/
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
