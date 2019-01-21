#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 210

#define min(x,y) (x<y?x:y)

const double eps=1e-8;

int n,l,k;
int a[N],nec;
double p[N],ans;
double f[N][N][N],g[N][N][N];

int main(){
	scanf("%d%d%d",&n,&l,&k);k=min(k,n);
	for(int i=0;i<n;i++){ scanf("%lf",&p[i]);p[i]/=100.0; }
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	f[0][0][k]=1.0;nec=n;ans=0.0;
	for(int fin=0;fin<n;fin++){nec--;
		for(int win=0;win<=fin;win++){
			for(int spa=0;spa<=n;spa++){
				//printf("f[%d][%d][%d]=%.6f nec=%d\n",fin,win,spa,f[fin][win][spa],nec);
				if(f[fin][win][spa]>0.0){
					if(spa+a[fin]>=0){
						f[fin+1][win+1][min(spa+a[fin],nec)]+=f[fin][win][spa]*p[fin];
					}else g[fin+1][win+1][-(spa+a[fin])]+=f[fin][win][spa]*p[fin];
					f[fin+1][win][min(spa,nec)]+=f[fin][win][spa]*(1.0-p[fin]);
				}
				//printf("g[%d][%d][%d]=%.6f\n",fin,win,spa,g[fin][win][spa]);
				if(g[fin][win][spa]>0.0){
					if(a[fin]-spa>=0){
						f[fin+1][win+1][min(a[fin]-spa,nec)]+=g[fin][win][spa]*p[fin];
					}else g[fin+1][win+1][spa-a[fin]]+=g[fin][win][spa]*p[fin];
					g[fin+1][win][spa]+=g[fin][win][spa]*(1.0-p[fin]);
				}
			}
		}	
	}
	for(int win=l;win<=n;win++)ans+=f[n][win][0];
	printf("%.6f\n",ans);
	return 0;
}
