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

#define N 1100
#define S 1100000

#define p id[i]

const double eps=1e-8;

int n,m;
int f[N],id[S],u[S],v[S],num,k;
double x[N],y[N],z[N];
double rec[S],ans;

double dis(const int &i,const int &j){	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);	}

int cmp(const int &i,const int &j){ return rec[i]<rec[j]; }

int find(const int &x){ if(f[x]!=x)f[x]=find(f[x]);return f[x]; }

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){k=n;num=0;
		for(int i=0;i<n;i++){ scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);f[i]=i; }
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				u[num]=i;v[num]=j;
				rec[num]=dis(i,j);
				id[num]=num;
				num++;
			}
		}
		sort(id,id+num,cmp);ans=rec[id[0]];
		for(int i=0;k>m;i++){

			//printf("remove %d->%d %.6f\n",u[p],v[p],rec[p]);

			if(find(u[p])!=find(v[p])){
				f[f[v[p]]]=f[u[p]];
				k--;
			}
			if(k==m){
				while(find(u[p])==find(v[p])){

					//printf("remove %d->%d %.6f\n",u[p],v[p],rec[p]);
					
					i++;

				}
				ans=rec[p];
			}
		}
		printf("%.6f\n",ans+eps);
	}
	return 0;	
}
