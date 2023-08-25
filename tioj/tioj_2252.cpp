/*
[Q]
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}


/*
	eps=浮點數誤差值
*/
const double eps=1e-8;//浮點數誤差

/*
	向量Vec
	也可當點使用
*/
struct Vec{//點、向量
	double x=0,y=0;
	void setv(const double &a,const double &b){
		x=a,y=b;
	}
};
Vec make_Vec(const double &a,const double &b){
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
Vec operator*(const Vec &a,const double &n){
	return make_Vec(a.x*n,a.y*n);
}
Vec operator*(const double &n,const Vec &a){
	return a*n;
}
Vec operator/(const Vec &a,const double &n){
	return make_Vec(a.x/n,a.y/n);
}
Vec operator/(const double &n,const Vec &a){
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
bool operator==(const Vec &a,const Vec &b){
	return (a.x==b.x && a.y==b.y);
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
struct Polygon{//建立多邊形Polygon
	vector<Vec> vec;
	void push_back(Vec a){
		vec.push_back(a);
	}
	void push_back(double x,double y){
		vec.push_back(make_Vec(x,y));
	}
	long long int size(){
		return vec.size();
	}
	Vec back(){
		return vec.back();
	}
	bool empty(){
		return vec.empty();
	}
	void pop_back(){
		vec.pop_back();
	}
	void pop_front(){
		vec.erase(vec.begin());
	}
	Vec front(){
		return vec.front();
	}
	vector<Vec>::iterator begin(){
		return vec.begin();
	}
	vector<Vec>::iterator end(){
		return vec.end();
	}
	Vec operator[](unsigned long long int n){
		return vec[n];
	}
};

/*
	面積Area
	將O(0,0)視為開始點
	連線向量O->P_1和O->P_2......
	對向量V1和V2計算三角形面積
	全部總和即為所求
*/
double Area(Polygon Pol){//對Polygon計算面積
	double re=0;
	long long int Polsz=Pol.size();
	if(Polsz==0)return 0;
	for(INT i=0;i<Polsz;i++){
		re+=Pol.vec[i]^Pol.vec[(i+1)%Polsz];
	}
	return fabs(re/2);
}

/*
	判斷方向ori
	第一行：值取絕對值之後，誤差小於eps就算是0
	o代表旋轉點，a代表點a,b代表點b
	判斷oa轉道ob要轉哪個方向
*/
int sign(double a){//對double簡化成-1,0,1
	if(fabs(a)<eps)return 0;
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

/*
	檢測是否相交Banana
	考慮下面幾種情況

	    C
	    |
	  A-+-B
	    |
	    D

	  A---B
	    C
	    |
	    D

	我們可以發現，以A為中心，連到B,C,D
	可以發現C一定要在B的逆時針方向(or順時針)
	而D則在B的另一方向
	同理，其他點也一樣
	將方向改成數值表示
	一個一定會是-1
	另一個一定會是1
	相乘就是-1
	我們只要判斷相乘是不是<0即可
	
	另一種情況

	  A-C-B
	    |
	    D
	如果有一個點(C)在線上(AB)
	那另外一個點(D)在哪都行(可-1可1)
	對於剛剛的判斷式，只要把<0改成<=0即可
	那還有另一種情況如下

	  A-C=B-D
	
	

*/
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

/*
	取得交點getbanana
		考慮下面幾種情況

	    C
	   /|\
	  A-E-B
	   \|/
	    D
	求AB和CD交點
	AE:EB=CAD:CBD
	E=(A*CBD+B*CAD)/(CAD+CBD)
*/
pair<bool,Vec> getbanana(const Vec &pa,const Vec &pb,const Vec &pc,const Vec &pd){
	pair<bool,Vec> re;
	re.first=havebanana(pa,pb,pc,pd);
	if(!re.first)return re;
	double CBD=fabs((pc-pb)^(pd-pb));
	double CAD=fabs((pc-pa)^(pd-pa));
	re.second=(pa*CBD+pb*CAD)/(CAD+CBD);
	return re;
}
pair<bool,Vec> getbanana(const Seg &la,const Seg &lb){
	return getbanana(la.p1,la.p2,lb.p1,lb.p2);
}

/*
	角度弧度轉換器
	弧度沒單位
	2pi=360度
	(2pi是弧度)
	同理，pi=180度
	1=180/pi度
	pi/180=1度
*/
double deg_rad(double angle){//角度轉弧度
	return angle*M_PI/180;
}
double rad_deg(double angle){//弧度轉角度
	return angle*180/M_PI;
}

Vec abs(Vec P){//對向量取絕對值
	P.x=fabs(P.x);
	P.y=fabs(P.y);
	return P;
}
double lng(Vec P){
	P=abs(P);
	return sqrt(P.x*P.x+P.y*P.y);
}

/*
	點到線段距離
	考慮下面幾種情況
	C
	    A-B
	我們可以知道角BAC是鈍角時，C和AB的最短距離就是CA
	同理，當ABC為鈍角時，答案即為BC
*/
double Pnt_to_Lne(const Vec &P,const Vec &A,const Vec &B){//計算點到線最近距離
	int BAP=sign((B-A)*(P-A));
	int ABP=sign((A-B)*(P-B));
	if(sign(lng(A-B))==0)return lng(P-A);//如果A==B
	if(BAP>=0 && ABP>=0){
		return fabs(((A-P)^(B-P))/lng(A-B));
	}else return lng(min(abs(A-P),abs(B-P)));
}
double Pnt_to_Lne(const Vec &P,const Seg  la){
	return Pnt_to_Lne(P,la.p1,la.p2);
}

bool sorta(Vec a,Vec b){//先以x降序排序，再以y升序排序
	if(a.x==b.x)return a.y>b.y;
	else return a.x<b.x;
}
bool sortb(Vec a,Vec b){//先以x升序排序，再以y降序排序
	if(a.x==b.x)return a.y<b.y;
	else return a.x>b.x;
}

Polygon convex(Polygon Pol){
	Polygon re;
	sort(Pol.vec.begin(),Pol.vec.end(),sorta);
	re.vec.push_back(Pol.vec[0]);
	long long int n=Pol.vec.size();
	for(INT i=1;i<n;i++){
		if(re.vec.empty()){
			re.push_back(Pol.vec[i]);
			continue;
		}else if(re.vec.back()==Pol.vec[i]){
			continue;
		}
		while(re.vec.empty() || ori(re.vec.back(),*(re.vec.end()-1),Pol.vec[i])>=0){
			re.vec.pop_back();
		}
		re.vec.push_back(Pol.vec[i]);
	}
	sort(Pol.vec.begin(),Pol.vec.end(),sortb);
	for(INT i=0;i<n;i++){
		if(re.vec.empty()){
			re.vec.push_back(Pol.vec[i]);
			continue;
		}else if(re.vec.back()==Pol.vec[i]){
			continue;
		}
		while(re.vec.empty() || ori(re.vec.back(),*(re.vec.end()-1),Pol.vec[i])>=0){
			re.vec.pop_back();
		}
		re.push_back(Pol.vec[i]);
	}
	return re;
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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
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
	INT t=1;
	while(t--){
		INT x,y,n;
		cin>>x>>y>>n;
		n++;
		Vec root;
		root.setv(x,y);
		double ans=1e9;
		Vec pnt[n];
		for(INT i=0;i<n;i++){
			INT xin=read(INT);
			INT yin=read(INT);
			
			pnt[i].setv(xin,yin);
		}

		for(INT i=0;i<n;i++){
			double xx=abs(x-pnt[i].x);
			double yy=abs(y-pnt[i].y);
			double nw=sqrt(xx*xx+yy*yy);
			if(ans>nw){
				ans=nw;

				DBG cerr<<"Aans change,i="<<i<<" ans="<<ans<<endl;
				cerr<<"root=("<<root.x<<","<<root.y<<")"<<endl;
				cerr<<"stop=("<<pnt[i].x<<","<<pnt[i].y<<")"<<endl;
			}
			ans=min(ans,nw);
		}
		for(INT i=1;i<n;i++){
			double nw=Pnt_to_Lne(root,pnt[i],pnt[i-1]);
			if(ans>nw){
				DBG cerr<<"Bans change,i="<<i<<" ans="<<ans<<endl;
			}
			ans=min(ans,nw);
		}
		cout<<fixed<<setprecision(8)<<ans<<endl;
	}
	return 0;
}

