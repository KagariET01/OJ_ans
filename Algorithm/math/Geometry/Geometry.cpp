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

template<typename TPE> struct ETmath{
	/*
		向量Vec
		也可當點使用
	*/
	struct Vec{
		TPE x=0,y=0;
		void setv(const TPE &a,const TPE &b){
			x=a,y=b;
		}
	};
	Vec make_Vec(const TPE &a,const TPE &b){
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
	TPE Dot(const Vec &a,const Vec &b){
		return a.x*b.x+a.y*b.y;
	}
	TPE operator*(const Vec &a,const Vec &b){
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
	TPE cross(const Vec &a,const Vec &b){
		return a.x*b.y-a.y*b.x;
	}
	TPE operator^(const Vec &a,const Vec &b){
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
	TPE Area(const Polygon Pol){
		TPE re=0;
		long long int Polsz=Pol.size();
		for(INT i=0;i<Polsz;i++){
			re+=Pol.vec[i]^Pol.vec[(i+1)%Polsz];
		}
		return re/2;
	}
};
