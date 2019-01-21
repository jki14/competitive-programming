#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 310
#define R 3

#define fir ((now-2)%3+3)%3
#define sec ((now-1)%3+3)%3
#define nxt (now+1)%3

int n,m,k,ans,now=0;;
int a[N][N];
int c[N][N][R],r[N][N][R];
int sc[N][N][R],sr[N][N][R];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);k=min(n,m);ans=0;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
		for(int d=0;d<k;d++){now=nxt;
			for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--){
				if(i+d<=n){
					c[i][j][now]=(d-2<0)?1:
						((a[i][j]==a[i+d-1][j] 
					  	&& c[i+1][j][fir])?1:0);
					if(c[i][j][now]){
						sc[i][j][now]=1;
						if(j+1<m && c[i][j+1][now])
							sc[i][j][now]
							  +=sc[i][j+1][now];
					}else sc[i][j][now]=0;
				}
				if(j+d<=m){
					r[i][j][now]=(d-2<0)?1:
						((a[i][j]==a[i][j+d-1]
					  	&& r[i][j+1][fir])?1:0);
					if(r[i][j][now]){
						sr[i][j][now]=1;
						if(i+1<n && r[i+1][j][now])
							sr[i][j][now]
							  +=sr[i+1][j][now];
					}else sr[i][j][now]=0;
				}
				if(i+d<=n && j+d<=m){
					if(sc[i][j][now]>=d 
							&& sr[i][j][now]>=d){
						if(ans<d)ans=d;
					}

					//printf("about %d %d %d:\n",i,j,d);
					//printf("c=%d r=%d sc=%d sr=%d\n",c[i][j][now],r[i][j][now],sc[i][j][now],sr[i][j][now]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
