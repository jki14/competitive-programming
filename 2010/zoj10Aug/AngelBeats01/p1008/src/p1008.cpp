#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define x i+px[k]
#define y j+py[k]

const int maxn=300,px[4]={-1,1,0,0},py[4]={0,0,-1,1},limit=1000000;

int timer;
int n,m,vp,vs,vt,sr,sc,tr,tc;
int g[maxn][maxn],f[maxn][maxn];
bool v[maxn][maxn];
char s[maxn];


void doit(){
    memset(v,0,sizeof(v));
    memset(f,0x7F,sizeof(f));
    int i,j,k;
    scanf("%d%d%d",&vp,&vs,&vt);
    for(i=0;i<n;i++){
        scanf("%s",s);
        for(j=0;j<m;j++){
            if(s[j]=='T')
                g[i][j]=vt;
            else if(s[j]=='.')
                g[i][j]=vs;
            else if(s[j]=='#')
                g[i][j]=vp;
            else g[i][j]=limit;
        }
    }
    scanf("%d%d%d%d",&sr,&sc,&tr,&tc);
    v[sr][sc]=true;f[sr][sc]=0;
    bool ctn=true;
    while(ctn){
        ctn=false;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(v[i][j]){
                    v[i][j]=false;
                    for(k=0;k<4;k++)
                        if(f[x][y]>f[i][j]+g[x][y]){
                            f[x][y]=f[i][j]+g[x][y];
                            v[x][y]=true;
                            ctn=true;
                        }
                }
    }
    /*//Debug
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            if(g[i][j]<limit)printf("%4d",g[i][j]);else printf("   x");
        printf("\n");
    }
    printf(".........................\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            if(f[i][j]<limit)printf("%4d",f[i][j]);else printf("   x");
        printf("\n");
    }*/

    if(f[tr][tc]>limit)f[tr][tc]=-1;
    printf("Case %d: %d\n",timer++,f[tr][tc]);
}

int main(){
    timer=1;
    while(scanf("%d%d",&n,&m)!=EOF)doit();
    return 0;
}
