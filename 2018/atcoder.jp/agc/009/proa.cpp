#include "bits/stdc++.h"
using namespace std;

long long minimumPress(const vector<int> &a, const vector<int> &b){
    long long foo = 0LL;
    const int n = a.size();
    for(int i=n-1; i>=0; i--){
        foo += (a[i]*1LL+foo+b[i]*1LL-1LL)/b[i]*b[i]-a[i]*1LL-foo;
    }
    return foo;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(int i=0; i<n; i++){
            scanf("%d%d", &a[i], &b[i]);
        }
        printf("%lld\n", minimumPress(a, b));
    }
    return 0;
}
