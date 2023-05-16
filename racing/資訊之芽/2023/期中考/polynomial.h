#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <vector>
#include <algorithm>
#include <iostream>

namespace _internal{
    constexpr int MAXN = 1 << 21;
    template<int MOD, int RT>
        struct Zp {
            static int add(int x, int y) { return (x += y) >= MOD ? x - MOD : x; }
            static int sub(int x, int y) { return (x -= y) < 0 ? x + MOD : x; }
            static int mul(int x, int y) { return int((long long)(x) * y % MOD); }
            static int mpow(int a, int n) {
                int r = 1;
                while (n) {
                    if (n % 2) r = mul(r, a);
                    n /= 2, a = mul(a, a);
                }
                return r;
            }
            static int minv(int a) { return mpow(a, MOD - 2); }
            struct NTT; struct Poly;
            static NTT ntt;
        };
    template<int MOD, int RT>
        struct Zp<MOD, RT>::NTT {
            int w[MAXN];
            NTT() {
                int s = MAXN / 2, dw = mpow(RT, (MOD - 1) / MAXN);
                for (; s; s >>= 1, dw = mul(dw, dw)) {
                    w[s] = 1;
                    for (int j = 1; j < s; ++j) 
                        w[s + j] = mul(w[s + j - 1], dw);
                }
            }
            void apply(int *a, int n, bool inv = 0) { //0 <= a_i < P
                for (int i = 0, j = 1; j < n - 1; ++j) {
                    for (int k = n >> 1; (i ^= k) < k; k >>= 1);
                    if (j < i) std::swap(a[i], a[j]);
                }
                for (int s = 1; s < n; s <<= 1) {
                    for (int i = 0; i < n; i += s * 2) {
                        for (int j = 0; j < s; ++j) {
                            int tmp = mul(a[i + s + j], w[s + j]);
                            a[i + s + j] = sub(a[i + j], tmp);
                            a[i + j] = add(a[i + j], tmp);
                        }
                    }
                }
                if (!inv) return;
                int iv = minv(n); std::reverse(a + 1, a + n);
                for (int i = 0; i < n; ++i) a[i] = mul(a[i], iv);
            }
        };
    template<int MOD, int RT>
        typename Zp<MOD, RT>::NTT Zp<MOD, RT>::ntt;
    using ctx1 = Zp<998244353, 3>;
    int a[MAXN], b[MAXN];
};

std::vector<int> multiply(const std::vector<int> &p, const std::vector<int> &q) {
    if (int(p.size()) > _internal::MAXN / 2 || int(q.size()) > _internal::MAXN / 2) {
        std::cerr << "Both of the polynomials' lengths should be less than " << _internal::MAXN / 2 << "\n";
        exit(1);
    }
    if (p.empty() || q.empty()) return p.empty() ? q : p;
    int L = 1;
    while (L < int(p.size()) + int(q.size()) - 1) L <<= 1;
    std::fill_n(_internal::a, L, 0), std::fill_n(_internal::b, L, 0);
    std::copy(p.begin(), p.end(), _internal::a);
    _internal::ctx1::ntt.apply(_internal::a, L);
    std::copy(q.begin(), q.end(), _internal::b);
    _internal::ctx1::ntt.apply(_internal::b, L);
    for (int i = 0; i < L; ++i) 
        _internal::a[i] = _internal::ctx1::mul(_internal::a[i], _internal::b[i]);
    _internal::ctx1::ntt.apply(_internal::a, L, 1);
    std::vector<int> res(p.size() + q.size() - 1);
    std::copy(_internal::a, _internal::a + p.size() + q.size() - 1, res.begin());
    return res;
}

#endif // __POLYNOMIAL_H__
