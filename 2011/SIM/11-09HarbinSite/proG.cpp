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

#define maxn 310000
#define maxm 310
#define LEN 13
#define maxnum 3100
#define K 26
#define chr 30
#define T 3

int n,m,k;
int route[maxnum][chr],fail[maxnum],flag[maxnum][maxm],num;
int que[maxnum],vis[maxm];

char a[maxn][LEN],b[maxm][LEN];
int ret[maxm],d[maxm];

int f[LEN][T][maxnum],mk[LEN][T][maxnum];

void init(char *key,const int &d){
	int p,k;
	for(p=0;*key;key++){
		k=(*key)-'a';
		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p][++flag[p][0]]=d;
	//printf("flag[%d]=%d\n",p,d);
}

void build(){
	int k,p,q,l,r;l=r=0;que[r++]=0;
	memset(fail,0,sizeof(fail));
	for(;l<r;l++){
		p=que[l];
		for(k=0;k<K;k++){
			if(route[p][k]){
				que[r++]=route[p][k];
				if(p){
					for(q=fail[p];q && !route[q][k];)q=fail[q];
					fail[route[p][k]]=route[q][k];
				}
			}
		}
	}
}

void work(){
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));
	memset(ret,0,sizeof(ret));

	for(int i=0;i<n;i++){ scanf("%s",a[i]); }
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s%d",b[i],&d[i]);
		init(b[i],i);
	}build();

	memset(vis,0x8f,sizeof(vis));
	memset(mk,0x8f,sizeof(mk));
	for(k=0;k<n;k++){
		for(int i=0;i<LEN;i++)for(int j=0;j<T;j++)f[i][j][0]=0;
		f[0][0][0]=1;f[0][0][1]=0;mk[0][0][0]=k;vis[0]=k;
		int len=strlen(a[k]);
		for(int i=0;i<len;i++){
			for(int j=0;j<T;j++){
				for(int x=1;x<=f[i][j][0];x++){
					int p=f[i][j][x];

					//printf("p=%d\n",p);

					//del
					if(j+1<T && mk[i+1][j+1][p]!=k){
						mk[i+1][j+1][p]=k;
						f[i+1][j+1][++f[i+1][j+1][0]]=p;
					}

					//no change
					int y=p,c=a[k][i]-'a';
					while(y && !route[y][c])y=fail[y];y=route[y][c];

					//printf("nochange y=%d,flag[y]=%d j=%d\n",y,flag[y],j);

					if(mk[i+1][j][y]!=k){
						mk[i+1][j][y]=k;
						f[i+1][j][++f[i+1][j][0]]=y;
					}
					for(int pos=y;pos /*&& vis[pos]!=k*/;pos=fail[pos]){
						//vis[pos]=k
						for(int v=1;v<=flag[pos][0];v++){int s=flag[pos][v];
							if(s && vis[s]!=k && j<=d[s]){
								//printf("%d++\n",flag[pos]);
								ret[s]++;
								vis[s]=k;
							}
						}
					}
					//change char
					if(j+1<T)for(int c=0;c<K;c++){
						int y=p;
						while(y && !route[y][c])y=fail[y];y=route[y][c];
						if(mk[i+1][j+1][y]!=k){
							mk[i+1][j+1][y]=k;
							f[i+1][j+1][++f[i+1][j+1][0]]=y;
						}
						for(int pos=y;pos /*&& vis[pos]!=k*/;pos=fail[pos]){
							//vis[pos]=k
							for(int v=1;v<=flag[pos][0];v++){int s=flag[pos][v];
								if(s && vis[s]!=k && j+1<=d[s]){
									//printf("%d++\n",flag[pos]);
									ret[s]++;
									vis[s]=k;
								}
							}
						}
						
					}
						
					//add char
					if(j+1<T)for(int c=0;c<K;c++){
						int y=p;
						while(y && !route[y][c])y=fail[y];y=route[y][c];
						if(mk[i][j+1][y]!=k){
							mk[i][j+1][y]=k;
							f[i][j+1][++f[i][j+1][0]]=y;
						}
						for(int pos=y;pos /*&& vis[pos]!=k*/;pos=fail[pos]){
							//vis[pos]=k
							for(int v=1;v<=flag[pos][0];v++){int s=flag[pos][v];
								if(s && vis[s]!=k && j+1<=d[s]){
									//printf("%d++\n",flag[pos]);
									ret[s]++;
									vis[s]=k;
								}
							}
						}	
					}

				}
			}
		}
	}

	for(int i=1;i<=m;i++)printf("%d\n",ret[i]);

}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

