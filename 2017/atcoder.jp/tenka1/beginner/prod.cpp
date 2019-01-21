#include "bits/stdc++.h"
using namespace std;

typedef long long lld;

int n, k;
int a[110000], b[110000];

lld ans;

lld calc(const int k){
    lld res=0LL;
    for(int i=0; i<n; i++){
        if((a[i]&~k)==0){
            res+=b[i];
        }
    }
    return res;
}

int main() {
    while(scanf("%d%d", &n, &k)!=EOF) {
        for(int i=0; i<n; i++)scanf("%d%d", &a[i], &b[i]);
        ans=calc(k);
        for(int h=(1<<30); h; h>>=1){
            if(k&h){
                ans=max(ans, calc((k^h)|(h-1)));
            }
        }
        printf("%lld\n", ans);
    }
}
