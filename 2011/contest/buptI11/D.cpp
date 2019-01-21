#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long lld;

#define maxn 1100
#define maxT 110
#define m 2

const int zero=0;

const lld inf=1LL<<60LL;

int timer;

int n;
int x,y,z;
int a[maxn][m],t;
lld f[maxn][m][maxT],T;
lld c[m],p2t[maxn][m],res;

void find(const lld &now){
	int l=1,r=n+1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(p2t[mid][0]<=now && p2t[mid+1][0]>now){
			x=mid;
			y=(now>=p2t[x][1]);
			lld tmp=now-p2t[x][y]+1LL;
			z=(int)tmp;
			return;
		}
		if(l==r)mid=zero/zero;
		if(p2t[mid][0]<=now)
			l=mid+1;
		else
			r=mid-1;
	}
}

void work(){
	int i,j,k;
	lld now,top,w;
	now=1LL;T=(lld)t;res=0LL;
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			p2t[i][j]=now;
			now+=((lld)a[i][j]);
		}
	p2t[n+1][0]=now;p2t[n+2][0]=inf;
	a[n+1][0]=t;
	p2t[n+1][1]=now+T;
	memset(f,0,sizeof(f));top=0LL;
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++){if(a[i][j]==0)continue;
			for(k=1;k<=t && k<=a[i][j];k++){
				f[i][j][k]=max(f[i][j][k],top);
				//Druing Self
				w=((lld)(a[i][j]-k+1))/T;
				now=p2t[i][j]+((lld)a[i][j]);find(now);
				if(z!=1)i=zero/zero;
				f[x][y][z]=max(f[x][y][z],f[i][j][k]+w*c[j]);
				res=max(res,f[x][y][z]);
				//Else
				if(p2t[i][j]+((lld)k)-2LL+w*T<p2t[i][j]+((lld)a[i][j])-1LL){w+=1LL;
					now=p2t[i][j]+((lld)k)-1LL;
					now+=w*T;
					find(now);
					f[x][y][z]=max(f[x][y][z],f[i][j][k]+w*c[j]);
					res=max(res,f[x][y][z]);
				}
				top=max(top,f[i][j][k]);
			}
		}
	printf("Case %d: %lld\n",timer,res);
}

int main(){
	int q;scanf("%d",&q);
	for(timer=1;timer<=q;timer++){scanf("%d%d%lld%lld",&n,&t,&c[0],&c[1]);
		work();
	}
	return 0;
}

