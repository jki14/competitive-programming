#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_JKI'S_HEADER_

    //TYPEDEF
    typedef long long lld;
    typedef unsigned long long u64;
    typedef pair<int, int> pii;

    //COMPARE
    template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
    template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

    template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
    template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

//TAIL_OF_JKI'S_HEADER

const int inf=0x3f3f3f3f;

int n;
char a[310];

int g[310][310];
int f[310][310][310];

int ans;

int main(){
    int T;scanf("%d", &T);
    for(int _T=1; _T<=T; _T++){
        printf("Case #%d: ", _T);
        scanf("%s", a);
        n=strlen(a);
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                g[x][y]=0;
                while(x+g[x][y]<n && y+g[x][y]<n && a[x+g[x][y]]==a[y+g[x][y]])g[x][y]++;
            }
        }
        memset(f, 0x3f, sizeof(f));
        f[0][0][0]=0;
        for(int p=0; p<n; p++){
            int low=inf;
            for(int c=0; c<=p; c++){
                for(int l=0; c+l<=p; l++){
                    UPDMIN(low, f[p][c][l]);
                }
            }
            for(int c=0; c<=p; c++){
                for(int l=0; c+l<=p; l++){
                    //COPY
                    UPDMIN(f[p][c][l], low+1);
                    //TYPE
                    UPDMIN(f[p+1][c][l], f[p][c][l]+1);
                    //PASTE
                    int cov=MIN(g[c][p], l);
                    if(cov==l)
                        UPDMIN(f[p+cov][c][l], f[p][c][l]+1);
                }
            }
        }
        ans=inf;
        for(int c=0; c<=n; c++){
            for(int l=0; c+l<=n; l++){
                UPDMIN(ans, f[n][c][l]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
