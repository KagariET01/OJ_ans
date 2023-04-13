/*
[LCA]最近共同祖先
[參考資料]https://yuihuang.com/lowest-common-ancestor/
*/

#include<bits/stdc++.h>
using namespace std;
#define INT long long int

const INT mxn=1e5;

INT dep[mxn];//距離根節點的距離(根節點距離為1)
INT siz[mxn];//子樹節點數(包含自己)
INT p[mxn][35];//p[i][j]表i的第2^i祖先
vector<INT> v[mxn];

int dfs(int node=0 , int d){//計算深度及子樹節點數
	dep[node] = d + 1;//深度
	if (v[node].empty()){//如果沒有子節點
		siz[node] = 1;
		return 1;
	}
	int total = 1;//自己也是一個節點
	for (int i:v[node]){
		total += dfs(i, d+1);
	}
	siz[node] = total;
	return siz[node];
}

void build(INT n){//註1
	// 找出每個節點的 2^i 倍祖先
	// 2^20 = 1e6 > 200000
	for (int i = 1; i < 20; i++){
		for (int j = 1; j <= n; j++){
			p[j][i] = p[p[j][i-1]][i-1];
		}
	}
}


int lca(int a, int b){// 求a和b的LCA（利用倍增法）
    if (dep[b] < dep[a]) swap(a, b);
    if (dep[a] != dep[b]){
        int dif = dep[b] - dep[a];
        for (int i = 0; i < 20; i++){
            if (dif & 1) b = p[b][i];
            dif >>= 1;
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--){
        if (p[a][i] != p[b][i]){
            a = p[a][i];
            b = p[b][i];
        }
    }
    return p[a][0];
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	return 0;
}
/*
註1
為了方便演示，我們這邊生了個測資
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8

我們可以得到下面的圖
0-1-2-3-4-5-6-7-8

開始演示
0	n	n	n	n
1	0	n	n	n
2	1	0	n	n
3	2	1	n	n
4	3	2	0	n
5	4	3	1	n
6	5	4	2	n
7	6	5	3	n
8	7	6	4	0
記得，需預處理j=0(在cin時就處理)，然後空的話可以連到-1
*/