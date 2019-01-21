#include "bits/stdc++.h"
using namespace std;

int n, m, k;
double a[110000];
double sum;

int main(){
    while(scanf("%d%d%d", &n, &m, &k)!=EOF){
        for(int i=0; i<n; i++)scanf("%lf", &a[i]);
        sum=0.0;
        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            sum+=(a[u]+a[v])*0.5;
        }
        printf("%.6f\n", sum*k/m);
    }
    return 0;
}
