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

vector<INT> vec;
vector<INT> seg_tree;
INT n;
INT build(INT l,INT r,INT p=1){//將vec建成seg_tree
    if(l==r){
	seg_tree[p]=vec[l];
    }else{
	INT mnt=(l+r)/2;
	INT lp=build(l,mnt,p<<1);
	INT rp=build(mnt+1,r,p<<1|1);
	seg_tree[p]=lp+rp;
    }
    return seg_tree[p];
}

void call_build(INT n){
    build(0,n);
}

INT edit(INT e,INT v,INT l,INT r,INT p=1){//單點編輯
    if(l==r){
	if(l==e){
	    vec[e]=v;
	    seg_tree[p]=v;
	}
    }else{
	INT mnt=(l+r)/2;
	INT lp=edit(e,v,l,mnt,p<<1);
	INT rp=edit(e,v,mnt+1,r,p<<1|1);
	seg_tree[p]=lp+rp;
    }
    return seg_tree[p];
}

void call_edit(INT e,INT v,INT n){
    edit(e,v,0,n);
}

bool invs(INT la,INT ra,INT lb,INT rb){//檢測兩區間是否有重疊
    INT l=max(la,lb);
    INT r=min(ra,rb);
    return l<=r;
}

INT search(INT sl,INT sr,INT l,INT r,INT p=1){//求區間和
    if(sl<l)sl=l;
    if(r<sr)sr=r;
    if(sl==l && sr==r && l<=r){
	return seg_tree[p];
    }else{
	INT mnt=(l+r)/2;
	bool lbl=invs(l,mnt,sl,sr);
	bool rbl=invs(mnt+1,r,sl,sr);
	if(lbl && rbl){
	    INT l=search(sl,sr,l,mnt,p<<1);
	    INT r=search(sl,sr,mnt+1,r,p<<1|1);
	    return l+r;
	}else if(lbl){
	    INT l=search(sl,sr,l,mnt,p<<1);
	    return l;
	}else if(rbl){
	    INT r=search(sl,sr,mnt+1,r,p<<1|1);
	    return r;
	}else{
	    return 0;
	}
	
    }

    
}

INT call_search(INT sl,INT sr,INT n){
    return search(sl,sr,0,n);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
	    n=read(INT);
	    vec.resize(n);
	    seg_tree.resize(n*4);
	    for(INT i=0;i<n;i++){
		vec[i]=read(INT);	
	    }
	    n--;
	    call_build(n);

	    INT m=read(INT);
	    while(m--){
		INT doid=read(INT);
		if(doid==1){
		    INT e,v;
		    cin>>e>>v;
		    call_edit(e,v,n);
		}else{
		    INT l,r;
		    cin>>l>>r;
		    cout<<call_search(l,r,n)<<endl;
		}
	    }
	}
	return 0;
}
//#endif
