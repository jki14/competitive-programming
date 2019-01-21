#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, ans;
    while(scanf("%d%d", &n, &m)!=EOF){
        ans=((n+1)>>1)*((m+1)>>1);
        printf("%d\n", ans);
    }
    return 0;
}

