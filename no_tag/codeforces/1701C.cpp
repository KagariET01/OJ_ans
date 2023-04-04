
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>
using namespace std;

//#define int long long
#define st first
#define nd second
#define ll long long
#define elif else if
#define O_O ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0)
#define m_p make_pair
#define pii pair<int, int>
#define p_b push_back
#define pp_b pop_back
//#define ull unsigned ll
//#define nd second.st
//#define rd second.second
//#define vvi vector<vector<int>>

//const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int work[N], a[N];

signed main(){
	O_O;
	int n, m;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < m; i++)
			cin >> work[i];
		sort(work, work + m);
		int left;
		int l = 1, r = 2 * m, mid;
		while(l != r){
			left = 0;
			fill(a, a + n + 4, 0);
			mid = (l + r) >> 1;
			for(int i = 0; i < m; i++){
				if(a[work[i]] < mid)
					a[work[i]]++;
				else
					left++;
			}
			int now = 1;
			while(left){
				if(a[now] >= mid - 1){
					now++;
					if(now > n){
						l = mid + 1;
						break;
					}
				}
				a[now] += 2;
				left--;
			}
			if(!left)
				r = mid;
		}
		cout << r << '\n';
	}
}

// g++ -o run D:\TEST_Coding\TEST_C++\TEST2.cpp