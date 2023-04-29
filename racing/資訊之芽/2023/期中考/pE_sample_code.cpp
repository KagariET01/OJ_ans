#include "polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> p{1, 2}; // 2x + 1
    vector<int> q{3, 4}; // 4x + 3
    vector<int> res = multiply(p, q); // 8x^2 + 10x + 3
    for (int i = 0; i < int(res.size()); ++i)
        cout << res[i] << " \n"[i + 1 == int(res.size())];
}
