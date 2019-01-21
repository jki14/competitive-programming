#include "bits/stdc++.h"
using namespace std;

int check(const int n, const long long a, const long long b, const long long c, const long long d){
    for(int i=0; i<=n; i++){
        const int lef=i;
        const int rig=n-i;
        const long long low=-d*lef+c*rig;
        const long long hig=-c*lef+d*rig;
        if(b-a>=low && b-a<=hig){
            //fprintf(stderr, "lef=%d rig=%d low=%lld hig=%lld\n", lef, rig, low, hig);
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, a, b, c, d;
    while(scanf("%d%d%d%d%d", &n, &a, &b, &c, &d)!=EOF){
        if(check(n-1, a*1LL, b*1LL, c*1LL, d*1LL)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
