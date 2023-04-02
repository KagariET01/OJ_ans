/*
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=b430
*/


/*include*/
#include<iostream>
using namespace std;
#define INT long long int

INT moder(INT a,INT b,INT n){
	INT re=0;
	a%=n;
	b%=n;
	while(b>0){
		if(b&1){
			re+=a;
			if(re>=n){
				re-=n;
			}
		}
		a<<=1;
		if(a>=n){
			a-=n;
		}
		b>>=1;
	}
	return re;
}

/*main*/
int main(){
	INT a,b,n;
	while(cin>>a>>b>>n){
		/*CIN*/
		cout<<moder(a,b,n)<<endl;
		/*solve*/
	}
	return 0;
}


