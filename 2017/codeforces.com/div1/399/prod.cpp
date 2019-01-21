#include "bits/stdc++.h"
using namespace std;

#define S 10010
#define N 1010

const long double sg=5.0*1e-9;
const long double eps=1e-14;

int n, m;
long double f[S][N];

int calc(const long double least){
    int lef=0, rig=S-1;
    while(lef<=rig){
        const int mid=(lef+rig)>>1;
        if(f[mid][n]>least){
            if(mid==lef || f[mid-1][n]<least+eps)return mid;
            rig=mid-1;
        }else lef=mid+1;
    }
    assert(false);
    return -1;
}

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                f[i][j]=(i!=0 || j!=0)?0.0L:1.0L;
        for(int i=0; i<S-1; i++){
            for(int j=0; j<=i && j<=n; j++){
                /*if(j==n)
                    printf("f[%d][%d]=%e\n", i, j, f[i][j]);*/
                //MORE ONE KIND
                f[i+1][j+1]+=f[i][j]*(n-j)/n;
                //KEEP
                f[i+1][j]+=f[i][j]*j/n;
            }
        }
        for(int i=0; i<m; i++){
            int p;
            scanf("%d", &p);
            printf("%d\n", calc(p*1.0L/2000-sg));
        }
    }
    return 0;
}
