/*
[Q]https://neoj.sprout.tw/problem/72/
*/
#include<bits/stdc++.h>
using namespace std;
#define double float
double a[12],b[12],c[12];
int n;
double d(double t,int i){
    return a[i]*(t-b[i])*(t-b[i])+c[i];
}
double s(double t){
    double re=0;
    for(int i=0;i<n;i++){
        re=max(re,d(t,i));
    }
    return re;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
   cout<<fixed<<setprecision(5);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i]>>b[i]>>c[i];}
        double l=0,r=300;
        double mxl=0,mxr=0,nl,nr;
        int cnt=10000;
        while(cnt--){
            nl=(2*l+r)/3;
            nr=(2*r+l)/3;
           
            mxl=s(nl);
            mxr=s(nr);
            if(mxr>mxl)r=nr;
            else l=nl;
        }
        cout<<mxl<<endl;
    }
    return 0;
}