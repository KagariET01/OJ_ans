#include<bits/stdc++.h>
using namespace std;
 
//#define int long long
typedef long long ll;
//typedef unsigned long long ull;
#define elif else if
#define O_O ios::sync_with_stdio(0), cin.tie(0)
#define pii pair<int, int>
#define m_p make_pair
#define p_b push_back
#define pp_b pop_back
#define st first
#define nd second
//const short dxy[] = {0, 1, 0, -1, 0};
 
//const int N = 2e5 + 5;
//const int MOD = 998244353;

void solve(){
    int n, m;
    ll k;
    cin >> n >> m >> k;
    ll l = 1, r = n * m + 1, mid, check;
    while(l < r){
        mid = (l + r) >> 1;
        check = 0;
        for(int i = 1; i <= n; ++i) check += min(mid / i, 1ll * m);
        if(check >= k) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return;
}
signed main(){
	O_O;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}