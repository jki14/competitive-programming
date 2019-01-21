#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define N 3100
#define M 11000
#define B 2

#define nxt (now^1)

int n,m,ans,now=0;
int id[N],p[N],w[N];
int r[B][M],f[B][M];

void upd(const int &i,const int &x,const int &y){
	if(r[nxt][x]<i){ 
		r[nxt][x]=i;f[nxt][x]=y; 
	}else if(f[nxt][x]<y)f[nxt][x]=y;
}

int cmp(const int &i,const int &j){ return p[i]*w[j]<p[j]*w[i]; }

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){ans=0;
		for(int i=0;i<n;i++){ scanf("%d%d",&p[i],&w[i]);id[i]=i; }
		sort(id,id+n,cmp);memset(r,0xff,sizeof(r));r[nxt][0]=0;f[nxt][0]=0;
		for(int i=0;i<n;i++){
			int k=id[i];now=nxt;
			for(int j=0;j<=m;j++){
				if(r[now][j]<i)continue;
				upd(i+1,j,f[now][j]);
				if(j+p[k]<=m)upd(i+1,j+p[k],f[now][j]+w[k]*(m-j));
			}
		}
		for(int j=0;j<=m;j++)if(r[nxt][j]==n && ans<f[nxt][j])ans=f[nxt][j];
		printf("%d\n",ans);
	}
	return 0;
}
