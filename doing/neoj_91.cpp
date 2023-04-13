/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  INT t;cin>>t;
  while(t--){
    INT n;cin>>n;
    if(n==1){
      cout<<1<<endl;
      continue;
    }
    if(n==0){
      cout<<0<<endl;
      continue;
    }
    INT numc[10];
    memset(numc,0,sizeof(numc));
    INT nm[8]={9,8,6,4,3,2,5,7};
    for(INT i=0;i<8;i++){
      while(n%nm[i]==0){
        numc[nm[i]]++;
        n/=nm[i];
      }
    }
    if(n>1){
      cout<<-1<<endl;
      continue;
    }
    else{
      for(INT i=0;i<10;i++){
        while(numc[i]--){
          cout<<i;
        }
      }
    }
    cout<<endl;
  }
	return 0;
}