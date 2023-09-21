#include "Egg.h"

#include <cassert>
#include <stdio.h>
#include <stdlib.h>

namespace {
    long long M, h;
    int count;
    void wa(const char* msg) {
        printf("Wrong Answer: %s\n", msg);
        exit(0);
    }
}

int is_broken(long long k) {
    ++count;
    if (count > 60)
        wa("too many queries");
    if (k <= 0 || k > M)
        wa("invalid broken query");
    return k > h;
}

int main() {
    assert(2 == scanf("%lld %lld", &M, &h));
    long long rt = height_limit(M);
    if (rt == h)
        printf("Accepted: %d\n", count);
    else
        wa("incorrect height");
}
