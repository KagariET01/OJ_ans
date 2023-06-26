#include "anj.h"
#include <cassert>
#include <cstdio>

const int MOD = 1000000007;
int fib(int n) {
    if (n == 0)
        return fib0();
    if (n == 1)
        return fib1();
    return (fib(n - 1) + fib(n - 2)) % MOD;
}
void solve() {
    int n;
    char ask[] = "Please input n: ";
    printf("%s", ask);
    assert(1 == scanf("%d", &n));
    fclose(stdin);

    // I received "res is not used" from the compiler, so I just removed it :P
    /* int res = */ fib(n);

    // Oops! Forgot to ouput!
    // printf("%d\n", res);
}
int main() {
    solve();
    fclose(stdout);
    return 0;
}
