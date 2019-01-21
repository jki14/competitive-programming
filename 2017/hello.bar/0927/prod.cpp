#include "bits/stdc++.h"
using namespace std;

const int inf=0x3f3f3f3f;

int n, m, k;
int g[310][310];
int a[310];
int f[16][310];

inline void updmin(int &x, const int y){
    if(x>y)x=y;
}

int main(){
    while(scanf("%d%d%d", &k, &n, &m)!=EOF){
        memset(g, 0x3f, sizeof(g));
        //for(int i=0; i<n+k; i++)g[i][i]=0;
        for(int i=0; i<n; i++)g[i][i]=0;
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            /*g[n+a[i]][i]=0;
            g[i][n+a[i]]=0;*/
        }
        for(int i=0; i<m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(g[u][v]>w)g[u][v]=w;
        }
        /*for(int r=0; r<k; r++){
            for(int p=0; p<n; p++)
                for(int u=0; u<n+k; u++)
                    for(int v=0; v<n+k; v++)
                        if(g[u][v]>g[u][p]+g[p][v])
                            g[u][v]=g[u][p]+g[p][v];
        }*/
        for(int p=0; p<n; p++)
            for(int u=0; u<n; u++)
                for(int v=0; v<n; v++)
                    updmin(g[u][v], g[u][p]+g[p][v]);
        /*for(int i=0; i<n+k; i++){
            for(int j=0; j<n+k; j++){
                fprintf(stderr, "%12d", g[i][j]);
            }
            fprintf(stderr, "\n");
        }*/
        /*int ans=0;
        for(int i=1; i<k; i++){
            if(g[n+i-1][n+i]<inf){
                ans+=g[n+i-1][n+i];
            }else{
                ans=-1;
                break;
            }
        }*/
        memset(f, 0x3f, sizeof(f));
        for(int j=0; j<n; j++)
            if(a[j]==0)
                f[0][j]=0;
        for(int i=1; i<k; i++){
            for(int j=0; j<n; j++){
                if(a[j]!=i)continue;
                for(int k=0; k<n; k++){
                    updmin(f[i][j], f[i-1][k]+g[k][j]);
                }
            }
        }
        int ans=inf;
        for(int j=0; j<n; j++)updmin(ans, f[k-1][j]);
        if(ans==inf)ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
