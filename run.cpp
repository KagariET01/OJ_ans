#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(),s.end()
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,d,h;
        cin>>n>>d>>h;
        ll y[n+1];
        double ans=(double)h*d/2;
        for(ll i=1;i<=n;i++){
            cin>>y[i];
        }
        for(ll i=1;i<n;i++){
            ll dif=y[i+1]-y[i];
            if(dif>=h){
                ans+=(double)h*d/2;
            }
            else{
                dif=h-dif;
                double mul=(double)(h*h-dif*dif)/(h*h);
                ans+=(double)h*d/2*mul;
            }
        }
        printf("%.10f\n",ans);
    }
}