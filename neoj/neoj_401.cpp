/*
[Q]
[]
*/
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}
bool debug=0;


/*
	eps=浮點數誤差值
*/
const INT eps=1e-9;//浮點數誤差

/*
	向量Vec
	也可當點使用
*/
struct Vec{//點、向量
	INT x=0,y=0;
	void setv(const INT &a,const INT &b){
		x=a,y=b;
	}
};
Vec make_Vec(const INT &a,const INT &b){
	Vec re;
	re.x=a,re.y=b;
	return re;
}

struct Seg{//線段
	Vec p1,p2;
};

Seg make_Seg(Vec a,Vec b){//將兩點Vec合併成線段Seg
	Seg re;
	re.p1=a;
	re.p2=b;
	return re;
}

/*
	基本運算
*/
Vec operator-(const Vec &a,const Vec &b){
	Vec re;
	re.x=b.x-a.x;
	re.y=b.y-a.y;
	return re;
}
Vec operator+(const Vec &a,const Vec &b){
	Vec re;
	re.x=b.x+a.x;
	re.y=b.y+a.y;
	return re;
}
Vec operator*(const Vec &a,const INT &n){
	return make_Vec(a.x*n,a.y*n);
}
Vec operator*(const INT &n,const Vec &a){
	return a*n;
}
Vec operator/(const Vec &a,const INT &n){
	return make_Vec(a.x/n,a.y/n);
}
Vec operator/(const INT &n,const Vec &a){
	return a/n;
}
bool operator<(const Vec &a,const Vec &b){
	return (a.x*a.x+a.y*a.y)<(b.x*b.x+b.y*b.y);
}
bool operator<=(const Vec &a,const Vec &b){
	return (a.x*a.x+a.y*a.y)<=(b.x*b.x+b.y*b.y);
}
bool operator>(const Vec &a,const Vec &b){
	return (a.x*a.x+a.y*a.y)>(b.x*b.x+b.y*b.y);
}
bool operator>=(const Vec &a,const Vec &b){
	return (a.x*a.x+a.y*a.y)>=(b.x*b.x+b.y*b.y);
}

/*
	內積*
	AB內積=A的長度*B的長度*cos(AB夾角)
	內積=0:兩向量垂直
	內積>0 夾角<90度
	內積<0 夾角>90度
*/
INT Dot(const Vec &a,const Vec &b){
	return a.x*b.x+a.y*b.y;
}
INT operator*(const Vec &a,const Vec &b){
	return Dot(a,b);
}

/*
	外積^
	AB外積=A的長度*B的長度*sin(AB夾角)=OAB三角形面積
	B的長度*sin(AB夾角)=OAB的高(底為OA)

	外積=0:兩向量平行
	外積>0 B 向量在 A 向量的逆時針方向
	外積<0 B 向量在 A 向量的順時針方向
*/
INT cross(const Vec &a,const Vec &b){
	return a.x*b.y-a.y*b.x;
}
INT operator^(const Vec &a,const Vec &b){
	return cross(a,b);
}

/*
	判斷方向ori
	第一行：值取絕對值之後，誤差小於eps就算是0
	o代表旋轉點，a代表點a,b代表點b
	判斷oa轉道ob要轉哪個方向
*/
int sign(INT a){//對INT簡化成-1,0,1
	if(a==0)return 0;
	else return a>0?1:-1;
}
int ori(const Vec &o,const Vec &a,const Vec &b){//判斷方向，0為同向or 180，1為逆時針，-1為順時針
	return sign((a-o)^(b-o));
}

/*
	點C是否在線AB上btw
	以c為中心點，a和b不在同個方向，那答案一定是False
	最後檢查角度，如果角度>90，那就一定是180，也就是C在AB上
	如果角度<90，那就一定是0，就代表C不在AB上
*/
bool btw(const Vec &pa,const Vec &pb,const Vec &pc){//檢測C是否在AB上
	if(ori(pc,pa,pb))return false;
	else return ((pa-pc)*(pb-pc))<=0;
}
bool btw(const Seg &la,const Vec &p){
	return btw(la.p1,la.p2,p);
}

bool havebanana(const Vec &pa,const Vec &pb,const Vec &pc,const Vec &pd){//檢測兩線段是否相交
	int a123=ori(pa,pb,pc);
	int a124=ori(pa,pb,pd);
	int a341=ori(pc,pd,pa);
	int a342=ori(pc,pd,pb);
	if(a123==0 && a124==0){
		return btw(pa,pb,pc)||btw(pa,pb,pd)||btw(pc,pd,pa)||btw(pc,pd,pb);
	}else return a123*a124<=0 && a341*a342<=0;
}
bool havebanana(const Seg &la,const Seg &lb){
	return havebanana(la.p1,la.p2,lb.p1,lb.p2);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(INT);
	while(t--){
		Vec A=make_Vec(read(INT),read(INT));
		Vec B=make_Vec(read(INT),read(INT));
		Vec C=make_Vec(read(INT),read(INT));
		Vec D=make_Vec(read(INT),read(INT));
		Seg L1=make_Seg(A,B);
		Seg L2=make_Seg(C,D);
		bool re=havebanana(L1,L2);
		if(re){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
/*
3
000000000 000000000 200000000 000000000 000000000 100000000 200000000 100000000
000000000 000000000 200000000 000000000 100000000 100000000 100000000 -100000000
000000000 000000000 200000000 000000000 300000000 100000000 300000000 -100000000
*/