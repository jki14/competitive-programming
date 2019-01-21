#include "bits/stdc++.h"
using namespace std;

long long maximumBlackSum(const vector<int> &a, const int k){
    const int n = a.size();
    long long lef = 0LL;
    long long mid = 0LL;
    for(int i=0; i<k; i++){
        mid += a[i]*1LL;
    }
    long long rig = 0LL;
    for(int i=n-1; i>=k; i--){
        rig += max(a[i], 0)*1LL;
    }
    long long foo = 0LL;
    for(int i=0; i<=n-k; i++){
        foo = max(foo, lef+rig+max(mid, 0LL));
        if(i!=n-k){
            lef += max(a[i], 0)*1LL;
            mid += (a[i+k]-a[i])*1LL;
            rig -= max(a[i+k], 0)*1LL;
        }
    }
    return foo;
}

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k)!=EOF){
        vector<int> a(n, 0);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        printf("%lld\n", maximumBlackSum(a, k));
    }
    return 0;
}
