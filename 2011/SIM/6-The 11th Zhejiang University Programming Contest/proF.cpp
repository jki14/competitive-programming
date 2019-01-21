#include <iostream>

#include <stdio.h>

#include <algorithm>

#include <cmath>

#include <string.h>

using namespace std;

 

typedef long long lld;

 

const double eps=1e-6;

inline double Max(double a,double b){return a>b?a:b;}

inline int sgn(double a){return a>eps?1:(a<-eps?-1:0);}

const int maxn=110;

double f[maxn][maxn];

int g[maxn][maxn];

int n,m,a[maxn];

lld mood,c0;

int id[maxn];

double dt[maxn][maxn];

int main()

{

#ifdef _DEBUG

         freopen("in.in","r",stdin);

#endif

         int cass;

         for (scanf("%d",&cass);cass--;)

         {

                   int i,j,k;

                   scanf("%d%d",&n,&m);

                   scanf("%lld",&mood);

                   for (i=0;i<n;i++) scanf("%d",a+i);

                   for (i=0;i<n;i++) id[i]=i;

                   for (i=0;i<n;i++)

                            for (j=i+1;j<n;j++)

                                     if (a[i]>a[j]||(a[i]==a[j]&&id[i]>id[j]))

                                     {

                                               swap(a[i],a[j]);

                                               swap(id[i],id[j]);

                                     }

                   j=0;

                   for (i=1;i<n;i++)

                            if (a[i]==a[i-1])

                                     j++;

                            else

                            {

                                     a[i-j]=a[i];

                                     id[i-j]=id[i];

                            }

                   n-=j;

                  

                   if (n<m)

                   {

                            puts("0");

                            for (i=1;i<m;i++) printf("0 ");

                            puts("0");

                            continue;

                   }

                   memset(f,0,sizeof(f));

                   memset(g,-1,sizeof(g));

                   for (i=0;i<n;i++)

                            for (j=i+1;j<n;j++)

                                     dt[i][j]=log((double)a[j]-(double)a[i]);

                  

                   for (i=n-2;i>=0;i--)

                   {

                            f[i][2]=dt[i][n-1];

                            g[i][2]=n-1;

                   }

                   for (j=3;j<=m;j++)

                            for (i=n-j;i>=0;i--)

                                     for (k=i+1;k+j-1<=n;k++)

                                               if (g[i][j]==-1||

                                                        sgn(f[i][j]-(f[k][j-1]+dt[i][k]))<0||

                                                        (sgn(f[i][j]-(f[k][j-1]+dt[i][k]))==0 && id[g[i][j]]>id[k])

                                                        )

                                               {

                                                        f[i][j]=f[k][j-1]+dt[i][k];

                                                        g[i][j]=k;

                                               }

                   int res[maxn];

                   i=0;

                   for (k=0;k<n;k++) if (sgn(f[i][m]-f[k][m])<0||(sgn(f[i][m]-f[k][m])==0&&id[i]>id[k]))

                            i=k;

                   for (j=m;j>=1;j--)

                   {

                            res[m-j]=i;

                            i=g[i][j];

                   }

                   c0=1;

                   for (j=0;j+1<m;j++)

                            c0=c0*(a[res[j+1]]-a[res[j]])%mood;

                   printf("%lld\n",c0);

                   for (i=0;i+1<m;i++)

                            printf("%d ",id[res[i]]);

                   printf("%d\n",id[res[i]]);

         }

         return 0;

}
