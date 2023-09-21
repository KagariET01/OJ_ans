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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

INT INTsqrt(INT n){
	if(n<=0)return 0;
	INT l=-1,r=n;
	while(l<r){
		INT mnt=(r-l)/2+l;
		INT p=mnt*mnt;
		if(p>n)r=mnt;
		else if(p<n)l=mnt+1;
		else if(p==n)return mnt;
	}
	return r;
}


struct fx{
	INT a,b,c;
};
fx infx(INT a,INT b,INT c){
	fx re;
	re.a=a;
	re.b=b;
	re.c=c;
	return re;
}
struct num{
	INT mom=0;
	INT nn=0;
	INT sq=0;
	bool sqmn=false;
	void fix(){
		INT asq=INTsqrt(sq);
		if(asq*asq==sq){
			if(sqmn){
				nn-=asq;
			}else{
				nn+=asq;
			}
			sq=0;
		}
		INT sqsq=sqrt(sq);
		INT ggcd=__gcd(__gcd(mom*mom,nn*nn),sq);
		
		mom/=ggcd;
		nn/=ggcd;
		if(sq==0)sqmn=0;
	}
};

bool operator<(num a,num b){
	if(a.sqmn!=b.sqmn)return a.sqmn<b.sqmn;
	if(a.mom!=b.mom)return a.mom<b.mom;
	if(a.nn!=b.nn)return a.nn<b.nn;
	return a.sq<b.sq;
}

void printnum(num a){
	cerr<<"mom:"<<a.mom<<" nn:"<<a.nn<<" sqmn:"<<(a.sqmn?1:0)<<" sq:"<<a.sq<<endl;
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n=read(INT);
		fx lst[n];
		set<num> se;
		for(INT i=0;i<n;i++){
			INT a,b,c;
			cin>>a>>b>>c;
			if(a==0){//x^2項為0:一元一次
				if(b==0)continue;//x項為0:常數
				num addit;
				INT ggcd=__gcd(b,c);
				b/=ggcd;
				c/=ggcd;
				addit.nn=-c;
				addit.mom=b;
				addit.fix();
				se.insert(addit);
				DBG printnum(addit);
				continue;

			}
			//正常解法
			INT ggcd=__gcd(__gcd(a,b),c);
			a/=ggcd;
			b/=ggcd;
			c/=ggcd;
			num xa,xb;
			xa.mom=a*2;
			xa.nn=-b;
			xa.sq=b*b-4*a*c;
			xa.fix();

			xb.mom=a*2;
			xb.nn=-b;
			xb.sq=(b*b-4*a*c);
			xb.sqmn=true;
			xb.fix();

			DBG printnum(xa);
			DBG printnum(xb);
			se.insert(xa);
			se.insert(xb);

			if(c==0){
				c=b;
				b=a;
				num addit;
				INT ggcd=__gcd(b,c);
				b/=ggcd;
				c/=ggcd;
				addit.nn=-c;
				addit.mom=b;
				addit.fix();
				se.insert(addit);
				DBG printnum(addit);
				continue;

			}
		}
		cout<<se.size()<<endl;
	}
	return 0;
}
//#endif
