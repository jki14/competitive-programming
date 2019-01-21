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

#define N 2100

double f[N][N],g[N],p1,p2,p3,p4;
int n,m,k;

const double eps=1e-8;

void work(){
	/* Init */
	scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
	if(fabs(p1+p2-1.0)<eps){
		printf("%.5f\n",0.0);
		return;
	}
	/* Core */
	memset(f,0,sizeof(f));
	double sum=p2+p3+p4;
	p2/=sum;p3/=sum;p4/=sum;
	g[0]=1.0;for(int i=1;i<=n;i++)g[i]=g[i-1]*p2;
	f[1][1]=p4/(p3+p4);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1){
				f[i][1]=p4;
				for(int p=1;p<i;p++){
					if (p>=i+1-k)
						f[i][1]+=g[p]*p4+g[p]*p3*f[i-1][i-p];
				        else
						f[i][1]+=g[p]*p3*f[i-1][i-p];
				}
				f[i][1]/=(1.0-g[i]);
			}else{
				if(j<=k)
					f[i][j]=f[i][j-1]*p2+f[i-1][j-1]*p3+p4;
				else
					f[i][j]=f[i][j-1]*p2+f[i-1][j-1]*p3;
			}
		}
	}
	printf("%.5f\n",f[n][m]);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
		work();
	return 0;
}


