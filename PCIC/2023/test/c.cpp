#include "Egg.h"

//----do not modify above----

long long height_limit(long long M) {
	long long int l=1,r=M+1;
	while(l<r){
		long long int mid=(r-l)/2+l;
		if(is_broken(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return r-1;
}

//----do not modify below----

#ifndef EVAL
#include <cassert>
#include <stdio.h>
#include<cstdlib>

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
#endif // EVAL
