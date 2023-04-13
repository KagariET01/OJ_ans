/*
[Q]https://neoj.sprout.tw/problem/78/
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  INT t;cin>>t;
  while(t--){
    INT bx[7];
    for(INT i=1;i<=6;i++){
      cin>>bx[i];
    }
    //size=6的禮物需要單獨一個袋子
    INT ans=bx[6];
    bx[6]=0;

    //size=5 可搭配11個size=1
    ans+=bx[5];
    bx[1]-=bx[5]*11;
    bx[5]=0;
    
    //size=4 可搭配5個size=2
    ans+=bx[4];
    bx[2]-=bx[4]*5;
    bx[4]=0;

    //size=3的一次可以放4個
    ans+=(bx[3]/4);
    bx[3]%=4;
    if(bx[3]>0)ans++;//再拿出一個箱子裝剩下的size=3
    if(bx[3]==1){//如果剩1個size=3
        bx[2]-=5;
        bx[1]-=7;
    }
    else if(bx[3]==2){
        bx[2]-=3;
        bx[1]-=6;
    }
    else if(bx[3]==3){
        bx[2]-=1;
        bx[1]-=5;
    }
    bx[3]=0;

    if(bx[2]>0){
      ans+=bx[2]/9;
      bx[2]%=9;
      if(bx[2]){
        ans++;
        bx[2]-=9;
      }
    }
    
    
    if(bx[2]<0){
      bx[2]*=-1;
      bx[1]-=bx[2]*4;
      bx[2]=0;
    }
    if(bx[1]>0){
      ans+=bx[1]/36;
      bx[1]%=36;
      if(bx[1]){
        ans++;
      }
    }

    cout<<ans<<endl;
  }
	return 0;
}