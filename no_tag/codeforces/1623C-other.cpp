#include<bits/stdc++.h>
using namespace std;
int T,n,i,l,r,mid,ans,a[200010],b[200010];
bool check(int x){
    int d;
    for(int i=n;i>=3;i--){
        if(a[i]<x)return 0;//负数肯定是不行的
        d=min(a[i]-x,b[i])/3;
        //a[i]-x为可以给前面的，b[i]是原有的，取min保证不会将后面位置给的再给前面
        a[i-2]+=2*d;a[i-1]+=d;a[i]-=d*3;
    }
    return a[1]>=x&&a[2]>=x;//判断前两个位置是否符合条件
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
        l=1;r=1e9;
        while(l<=r){//二分答案
            mid=(l+r)>>1;
            if(check(mid))l=mid+1,ans=mid;
                else r=mid-1;
            for(i=1;i<=n;i++)a[i]=b[i];//check中改变了a数组，还原
        }
        cout<<ans<<'\n';
    }
    return 0;
}