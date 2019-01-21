#include "bits/stdc++.h"
using namespace std;

//TYPEDEF
typedef long long lld;
typedef unsigned long long u64;
typedef pair<int, int> pii;

//COMPARE
template<class T> inline T MIN(const T x, const T y) {
    return (x<y)?x:y;
}
template<class T> inline T MAX(const T x, const T y) {
    return (x>y)?x:y;
}

template<class T> inline void UPDMIN(T &x, const T y) {
    if(x>y)x=y;
}
template<class T> inline void UPDMAX(T &x, const T y) {
    if(x<y)x=y;
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        pair<int, int> foo(-1, -1);
        for(int i=0; i<n; i++) {
            int rnk, scr;
            scanf("%d%d", &rnk, &scr);
            UPDMAX(foo, make_pair(rnk, scr));
        }
        printf("%d\n", foo.first+foo.second);
    }
}
