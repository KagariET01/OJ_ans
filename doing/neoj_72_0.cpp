/*
[Q]https://neoj.sprout.tw/problem/72/
*/
#include<iostream>
using namespace std;
#define INT long long int

const INT mxn=10;
double a[mxn+1],b[mxn+1],c[mxn+1];

double cot(INT i,double t){
    return a[i]*(t-b[i])*(t-b[i])+c[i];
}

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    //cout<<fixed<<setprecision(5);
    INT t;
    cin>>t;
    while(t--){
        INT n;
        cin>>n;
        for(INT i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        double l=0.0,r=300.0;
        double mxl=0,mxr=0;
        INT cnt=100;
        while(cnt--){
            double lmnt=(l*2.0+r)/(double)3.0;
            double rmnt=(r*2.0+l)/(double)3.0;
            cerr<<"lmnt="<<lmnt<<",rmnt="<<rmnt;
            mxl=mxr=0.0;
            for(INT i=0;i<n;i++){
                mxl=max(mxl,cot(i,lmnt));
                mxr=max(mxr,cot(i,rmnt));
            }
            if(mxr>mxl)r=rmnt;
            else l=lmnt;
            cerr<<",l="<<l<<",r="<<r<<endl;
        }
        cout<<l<<endl;
    }
}