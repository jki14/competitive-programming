#include "bits/stdc++.h"
using namespace std;

typedef long long lld;

inline lld paraRayLen(const lld a, const lld b){
    if(a>b){
        return paraRayLen(b, a);
    }else if(a==0LL){
        return -b;
    }else{
        return 2LL*a*(b/a)+paraRayLen(a, b%a);
    }
}

lld calculate(const lld n, const lld x){
    return n+paraRayLen(x, n-x);
}

int main(){
    lld n, x;
    while(scanf("%lld%lld", &n, &x)!=EOF){
        printf("%lld\n", calculate(n, x));
    }
    return 0;
}
