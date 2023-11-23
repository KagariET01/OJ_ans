#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define FN function<INT(INT,INT)>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

vector<INT> seg;//線段數
vector<INT> seg_mark_add;//懶人標記，紀錄區間加值
vector<INT> arr;//原始數列
INT m;//操作編號
INT n;//數列長度
INT q;//詢問次數

/*線段數模板*/
FN merge=[](INT a,INT b){/*兩數合併函數*/
		return a+b;
};

void build(INT l,INT r,INT index,FN merge){//建樹
	if(l==0 and r==n-1){
		seg.clear();
		seg.resize(4*n);
		seg_mark_add.clear();
		seg_mark_add.resize(4*n);
	}
	if(l==r){
			seg[index]=arr[l];
			return;
	}
	INT mid=(r-l)/2+l;
	build(l,mid,index*2,merge);
	build(mid+1,r,index*2+1,merge);
	seg[index]=merge(seg[index*2],seg[index*2+1]);
	return;
};

void modify(INT x,INT v,INT l,INT r,INT index,FN merge){/*單點改值（a=b）*/
	if(l==x && r==x){
		seg[index]=v;
		return;
	}else{
		INT mid=(r-l)/2+l;
		if(x<=mid){
			modify(x,v,l,mid,index*2,merge);
		}else{
			modify(x,v,mid+1,r,index*2+1,merge);
		}
		seg[index]=merge(seg[index*2],seg[index*2+1]);
	}
	return;
};

void modify_add(INT x,INT v,INT l,INT r,INT index,FN merge){/*單點改值（a+=b）*/
	if(l==x && r==x){
		seg[index]=+v;
		return;
	}else{
		INT mid=(r-l)/2+l;
		if(x<=mid){
			modify_add(x,v,l,mid,index*2,merge);
		}else{
			modify_add(x,v,mid+1,r,index*2+1,merge);
		}
		seg[index]=merge(seg[index*2],seg[index*2+1]);
	}
	return;
};

void loop_modify_add(INT ml,INT mr,INT v,INT l,INT r,INT index,FN merge){/*區間加值（a+=b）*/
	if(ml<=l && r<=mr){
		seg_mark_add[index]+=v;
		return;
	}else{
		INT mid=(r-l)/2+l;
		if(ml<=mid){
			loop_modify_add(ml,mr,v,l,mid,index*2,merge);
		}
		if(mid+1<=mr){
			loop_modify_add(ml,mr,v,mid+1,r,index*2+1,merge);
		}
	}
}

INT query(INT ql,INT qr,INT l,INT r,INT index,FN merge){//區間查詢
	DBG cerr<<"ql="<<ql<<" qr="<<qr<<" l="<<l<<" r="<<r<<" seg="<<seg_mark_add[index]<<endl;
	if(seg_mark_add[index]){
		if(l==r){
			seg[index]+=seg_mark_add[index];
			seg_mark_add[index]=0;
		}else{
			INT nw=r-l;
			INT ad=seg_mark_add[index];
			INT res=seg_mark_add[index];
			while(nw){
				if(nw&1){
					res=merge(res,ad);
				}
				ad=merge(ad,ad);
				nw>>=1;
			}
			seg[index]+=res;
			DBG cerr<<"add"<<res<<endl;

			seg_mark_add[index*2]+=seg_mark_add[index];
			seg_mark_add[index*2+1]+=seg_mark_add[index];
			seg_mark_add[index]=0;
		}
	}
	if(ql<=l && r<=qr){
		return seg[index];
	}else{
		INT mid=(r-l)/2+l;
		INT ans=0;
		if(ql<=mid && mid+1<=qr){
			ans=merge(query(ql,qr,l,mid,index*2,merge),query(ql,qr,mid+1,r,index*2+1,merge));
		}else if(ql<=mid){
			ans=query(ql,qr,l,mid,index*2,merge);
		}else if(mid+1<=qr){
			ans=query(ql,qr,mid+1,r,index*2+1,merge);
		}
		return ans;
	}
};

FN sum=[](INT a,INT b){return a+b;};
FN maxn=[](INT a,INT b){return max(a,b);};
FN minn=[](INT a,INT b){return min(a,b);};
FN xorr=[](INT a,INT b){return a^b;};
FN andd=[](INT a,INT b){return a&b;};
FN orr=[](INT a,INT b){return a|b;};

FN MERGE[6]={
	sum,
	maxn,
	minn,
	xorr,
	andd,
	orr
};

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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	m=2;
	cin>>n;
	cin>>q;
	arr.reserve(n+1);
	for(INT i=0;i<n;i++){
		INT inin;
		cin>>inin;
		arr.push_back(inin);
	}
	build(0,n-1,1,MERGE[m]);
	while(q--){
		DBG{
			INT cnt=1;
			INT nw=0;
			bool first=1;
			for(INT i:seg){
				if(first){
					first=0;
					continue;
				}
				cout<<i<<' ';
				nw++;
				if(nw==cnt){
					cnt<<=1;
					nw=0;
					cout<<endl;
				}
			}
			cout<<endl;
		}
		INT op=read(INT);
		switch(op){
			case 1:{
				INT x,v;
				cin>>x>>v;
				x--;
				modify(x,v,0,n-1,1,MERGE[m]);
				break;
			}
			case 2:{
				INT l,r;
				cin>>l>>r;
				l--,r--;
				cout<<query(l,r,0,n-1,1,MERGE[m])<<endl;
				break;
			}
		}
	}
	return 0;
}

/*
[INPUT]
{M}
N
a1...aN
Q
{action_1}
...
{action_Q}

[action]
1 x v
(edit node x to v)
2 x v
(add v to node x)
3 l r v
(add v to node l to r)
4 l r
(query of node l to r)

{M}
0
get sum
1
get max
2
get min
3
get xor
4
get and
5
get or
*/











/**/