#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false), cin.tie(0);
#define endl "\n"
#define ll long long
//#define int long long
//#pragma GCC optimize ("O2")
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
#define debug(x) cerr<<#x<<":"<<x<<endl;
#define debuq(x) cerr<<"debug:"<<x<<endl;
using namespace std;
int t, a[7];
int i, k, s;
void f(){ // side length 6
        s=a[6];
        a[6] = 0;
}
void e(){ // side length 5
    s+=a[5];
    a[1] = max(a[1] - a[5] * 11, 0) ;
}
void d(){// side length 4
    s+=a[4];
    a[2] = a[2] - a[4] * 5;
}
void c(){// side length 3
    s+=a[3] / 4;//(6*6)=(3*3)*4
    a[3]%=4;// 保留起來等等給1用
    if( a[3] ){
        s++;
        if(a[3]==1){
            a[2] = a[2] - 5;
            a[1] = max(a[1] - 7, 0);
            }
        if(a[3]==2){
            a[2] = max(a[2] - 3, 0);
            a[1] = max(a[1] - 6, 0);
            }
        if(a[3]==3){
            a[2] = max(a[2]  -1, 0);
            a[1] = max(a[1] - 5, 0);
            }
    }
}
void b(){// side length 2
        /**/
    if(a[2] > 0){
        s+= a[2] / 9;
        if(a[2]%9)
            s++;
        a[2] %= 9;
        a[1] = max(a[1] - a[2] *4 ,0);
    }else if(a[2]<0){
			a[2]=-a[2];
			a[1]-=a[2]*4;
		}
}
void first(){   // side length 1
    if(a[1]>0){
        s+=a[1] / 36;
        a[1]%=36;
        if(a[1] )
            s++;
    }
}
int32_t main(){
        cin >> t;
        while(t--){
                s = 0;
                a[7] = { };
                for(i=1; i<7; i++){
                    cin >> a[i];
                }
                f();
                e();
                d();
                c();
                b();
                first();
                cout << s <<endl;
        }
}