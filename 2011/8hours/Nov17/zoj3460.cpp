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

#define N 55 
#define M 55
#define S 2560
#define L 128000

const double eps = 1e-8;
const double top = 1700000.0;
const double one = 0.0000001;

int n,m,size,num;
int vis[S],pnt[S],cnt;
double t1,t2,v,que[L];
double srcx[N],srcy[N];
double tarx[M],tary[M];
double g[M][S],c[M][N];

int find(const int &u,const double &ret,const int &msk){
	if(vis[u]==msk)return 0;vis[u]=msk;
	for(int v=0;v<size;v++){
		if(g[u][v]>ret+eps)continue;
		if(pnt[v]<0 || find(pnt[v],ret,msk)){
			pnt[v]=u;return 1;
		}
	}return 0;
}

int test(const double &ret){
	memset(vis,0xff,sizeof(vis));
	memset(pnt,0xff,sizeof(pnt));
	for(int i=0;i<m;i++){cnt=0;
		if(!find(i,ret,i))return 0;
	}
	return 1;
}

void work(){
	/* Init */

	if(fabs(v)<eps)while(1);t1/=60.0;
	for(int i=0;i<m;i++)scanf("%lf%lf",&tarx[i],&tary[i]);
	for(int i=0;i<n;i++)scanf("%lf%lf",&srcx[i],&srcy[i]);
	for(int i=0;i<m;i++)for(int j=0;j<n;j++)
		c[i][j]=sqrt((tarx[i]-srcx[j])*(tarx[i]-srcx[j])+(tary[i]-srcy[j])*(tary[i]-srcy[j]));
	for(int i=num=0;i<m;i++){size=0;
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++){
				g[i][size++]=((double)k)*t2+((double)(k+1))*t1+c[i][j]/v;
				que[num++]=g[i][size-1];
				//printf("g[%d][%d]=%.6f\n",i,size-1,g[i][size-1]);
			}
	}
	sort(que,que+num);
	/* Core */
	/*double lef=0.0,rig=top;
	while(lef<rig+eps){

		//printf("lef=%.6f rig=%.6f\n",lef,rig);

		double mid = (lef+rig)/2.0;
		if(test(mid)){
			if(!test(mid-one)){
				printf("%.6f\n",mid+eps);
				return;
			}else rig=mid-one;
		}else lef=mid+one;
	}*/
	int lef=0,rig=num-1;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(test(que[mid])){
			if(!mid || !test(que[mid-1])){
				printf("%.6f\n",que[mid]);
				return;
			}else rig=mid-1;
		}else lef=mid+1;
	}
}

int main(){
	while(scanf("%d%d%lf%lf%lf",&n,&m,&t1,&t2,&v)!=EOF)
		work();
	return 0;
}

