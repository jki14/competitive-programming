#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        vector<int> foo(n, 0);
        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            foo[u]^=1;
            foo[v]^=1;
        }
        int sum=0;
        for(const int x : foo){
            sum+=x;
        }
        if(!sum){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
