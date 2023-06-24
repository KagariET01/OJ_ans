#include "anj.h"
#include <cassert>
#include <cstdio>
#include<iostream>
using namespace std;
const int MOD = 1000000007;
int fib0(){/*cout<<0<<endl;*/return 0;}
int fib1(){/*cout<<1<<endl;*/return 1;}
int fib(int n) {
	int lst[n+1];
	lst[0]=fib0();
	lst[1]=fib1();
	for(int i=2;i<=n;i++){
		lst[i]=lst[i-1]+lst[i-2];
		lst[i]%=MOD;
	}
	return lst[n];
}
void solve() {
    int n;
	cin>>n;
    // I received "res is not used" from the compiler, so I just removed it :P
    /* int res = */ fib(n);
	cout<<fib(n)<<endl;
    // Oops! Forgot to ouput!
    // printf("%d\n", res);
}
int main() {
    solve();
    return 0;
}
