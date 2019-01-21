#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 1100
#define maxm 2
#define maxt 110
#define m 2

typedef long long lld;

map<lld,int, greater<lld> > s;
map<lld,int, greater<lld> >::iterator it;

map<lld,lld, greater<lld> > g;
map<lld,lld, greater<lld> >::iterator jt;

int n,t;
int a[maxn][maxm],p[maxm];
lld f[maxn][maxm][maxt];
lld r[maxn][maxm],lldt;

void update(const int &i,const int &j,const int &k){
	lld now=r[i][j]+((lld)k)-1LL;
	//printf("  update %lld  ",now);
	jt=g.lower_bound(now);
	if(jt!=g.end()){
		//printf("the path of %lld is %lld\n",now,(*jt).first);
		f[i][j][k]=max(f[i][j][k],(*jt).second);
	}
	g.insert(pair<lld,lld>(now,f[i][j][k]));
}

void work(){
	int i,j,k,w;
	lld next;
	int x,y,z;
	s.clear();g.clear();lldt=1LL;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++){
			if(!j)
				s.insert(pair<lld,int>(lldt,i));
			else
				s.insert(pair<lld,int>(lldt,-i));
			r[i][j]=lldt;
			scanf("%d",&a[i][j]);
			lldt+=((lld)a[i][j]);
		}
	//creat n+1,0
	r[n+1][0]=lldt;
	//for(i=1;i<=n+1;i++)for(j=0;j<m;j++)printf("r[%d][%d]=%lld\n",i,j,r[i][j]);
	//DP work
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++)
			for(k=1;k<=a[i][j] && k<=t;k++){update(i,j,k);

				//printf("f[%d][%d][%d]=%lld\n",i,j,k,f[i][j][k]);
				
				w=(a[i][j]-k+1)/t;
				//full cooldown
				f[i+j][j^1][1]=max(f[i+j][j^1][1],f[i][j][k]+((lld)w)*((lld)p[j]));
				update(i+j,j^1,1);
				//printf("FC:f[%d][%d][%d]=%lld\n",i+j,j^1,1,f[i+j][j^1][1]);

				//more one fire
				if(w*t+k-1==a[i][j])continue;w++;
				next=r[i][j]+((lld)k)-2LL+((lld)w)*((lld)t);
				it=s.lower_bound(next);
				x=(*it).second;y=(x<0);x=abs(x);
				next=next-r[x][y]+1LL;if(next>((lld)t))continue;
				z=(int)next;
				f[x][y][z]=max(f[x][y][z],f[i][j][k]+((lld)w)*((lld)p[j]));
				update(x,y,z);

				//printf("MOF:f[%d][%d][%d]=%lld\n",x,y,z,f[x][y][z]);

			}
	//for RESULT
	x=n+1;y=0;z=t;
	update(x,y,z);
	printf("%lld\n",f[x][y][z]);
}

int main(){
	int q;scanf("%d",&q);
	while(q--){scanf("%d%d%d%d",&n,&t,&p[0],&p[1]);
		work();
	}
	return 0;
}
