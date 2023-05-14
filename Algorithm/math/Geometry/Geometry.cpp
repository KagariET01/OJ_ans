/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()

bool debug=0;


/*
	eps=浮點數誤差值
*/
const double eps=1e-9;

/*
	向量Vec
	也可當點使用
*/
struct Vec{
	long long x=0,y=0;
	void setv(const long long &a,const long long &b){
		x=a,y=b;
	}
};
Vec make_Vec(const long long &a,const long long &b){
	Vec re;
	re.x=a,re.y=b;
	return re;
}

/*
	線段轉向量
	提供兩點座標，即可算出兩點向量
	a連到b
*/
Vec Line_Vec(const Vec &a,const Vec &b){
	Vec re;
	re.x=b.x-a.x;
	re.y=b.y-a.y;
	return re;
}
Vec operator-(const Vec &a,const Vec &b){
	return Line_Vec(a,b);
}

/*
	向量轉線段
	提供向量及點，即可算出延伸出去的點
	a為起始點，b為向量
	a和b交換不會有差
*/
Vec Vec_Pnt(const Vec &a,const Vec &b){
	Vec re;
	re.x=b.x+a.x;
	re.y=b.y+a.y;
	return re;
}
Vec operator+(const Vec &a,const Vec &b){
	return Vec_Pnt(a,b);
}

/*
	內積*
	AB內積=A的長度*B的長度*cos(AB夾角)
	內積=0:兩向量垂直
	內積>0 夾角<90度
	內積<0 夾角>90度
*/
double Dot(const Vec &a,const Vec &b){
	return a.x*b.x+a.y*b.y;
}
double operator*(const Vec &a,const Vec &b){
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
double cross(const Vec &a,const Vec &b){
	return a.x*b.y-a.y*b.x;
}
double operator^(const Vec &a,const Vec &b){
	return cross(a,b);
}

/*
	多邊形Polygon
	裡面存的是點
*/
struct Polygon{
	vector<Vec> vec;
	void push_back(Vec a){
		vec.push_back(a);
	}
	long long int size(){
		return vec.size();
	}
};

/*
	面積Area
	將O(0,0)視為開始點
	連線向量O->P_1和O->P_2......
	對向量V1和V2計算三角形面積
	全部總和即為所求
*/
double Area(Polygon Pol){
	double re=0;
	long long int Polsz=Pol.size();
	if(Polsz==0)return 0;
	for(INT i=0;i<Polsz;i++){
		re+=Pol.vec[i]^Pol.vec[(i+1)%Polsz];
	}
	return re/2;
}

/*
	判斷方向ori
	第一行：值取絕對值之後，誤差小於eps就算是0
	o代表旋轉點，a代表點a,b代表點b
	判斷oa轉道ob要轉哪個方向
*/
int ori(const Vec &o,const Vec &a,const Vec &b){
	return sign((a-o)^(b-o));
}
int sign(double a){
	if(fabs(a)<eps)return 0;
	else return a>0?1:-1;
}


int main(){
	cout<<sign(Pol)<<endl;
	return 0;
}