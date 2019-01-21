#include "bits/stdc++.h"
using namespace std;

int sumXor(const vector<int> &a, const vector<int> &b){
    int foo = 0;
    int n = a.size();
    vector<int> c(n, 0);
    for(int k=0; k<=28; k++){
        const int msk = (1<<(k+1))-1;
        for(int i=0; i<n; i++){
            c[i] = b[i] & msk;
        }
        sort(c.begin(), c.end());
        for(int i=0; i<n; i++){
            const int sup = a[i] & msk;
            if((distance(lower_bound(c.begin(), c.end(), (1<<k)-sup), lower_bound(c.begin(), c.end(), (1<<(k+1))-sup)) + distance(lower_bound(c.begin(), c.end(), (3<<k)-sup), c.end())) & 1){
                //fprintf(stderr, "k=%d, a[i]=%d, cnt=%ld\n", k, a[i], (distance(lower_bound(c.begin(), c.end(), (1<<k)-sup), lower_bound(c.begin(), c.end(), (1<<(k+1))-sup)) + distance(lower_bound(c.begin(), c.end(), (3<<k)-sup), lower_bound(c.begin(), c.end(), (1<<(k+2))-sup))));
                foo ^= 1<<k;
            }
        }
    }
    return foo;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(int i=0; i<n; i++)scanf("%d", &a[i]);
        for(int i=0; i<n; i++)scanf("%d", &b[i]);
        printf("%d\n", sumXor(a, b));
    }
    return 0;
}
