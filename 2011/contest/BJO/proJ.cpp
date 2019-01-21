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

#define N 11
#define M 11
#define S 1100

const int inf=0x3fffffff;
const int low=-inf;

int n,m,ans;
int d[M],a[N][M],c[N][N];
int s[S][M],f[S][S];
int pn[N][S],pm[M][S];
int bit[N],mk[S];

void init(){ for(int i=1;i<N;i++)bit[i]=1<<(i-1);bit[0]=0; }

void getp(){
	int i,j,k;
	int state;

	memset(mk,0,sizeof(mk));
	pn[0][pn[0][0]=1]=0;mk[0]=1;
	for(i=0;i<n;i++){pn[i+1][0]=0;
		for(j=1;j<=pn[i][0];j++){
			for(k=1;k<=n;k++){
				if(pn[i][j] & bit[k])continue;
				state=pn[i][j]|bit[k];
				if(mk[state])continue;
				mk[state]=1;pn[i+1][++pn[i+1][0]]=state;
			}
		}
	}
	
	memset(mk,0,sizeof(mk));
	pm[0][pm[0][0]=1]=0;mk[0]=1;
	for(i=0;i<m;i++){pm[i+1][0]=0;
		for(j=1;j<=pm[i][0];j++){
			for(k=1;k<=m;k++){
				if(pm[i][j] & bit[k])continue;
				state=pm[i][j]|bit[k];
				if(mk[state])continue;
				mk[state]=1;pm[i+1][++pm[i+1][0]]=state;
			}
		}
	}
}

void gets(){
	int state,i,x,y;

	memset(s,0,sizeof(s));

	for(state=0;state<=pn[n][1];state++){
		for(i=1;i<=m;i++){
			for(x=1;x<=n;x++)if(state & bit[x])s[state][i]+=a[x][i];
			for(x=1;x<=n;x++)
				for(y=x+1;y<=n;y++){
					if(!(state & bit[x]))continue;
					if(!(state & bit[y]))continue;
					s[state][i]+=c[x][y];
				}
		}
	}
}

void fref(){
	memset(f,0,sizeof(f));ans=0;
	
	for(int state=0;state<=pn[n][1];state++)
		for(int i=1;i<=pm[m][1];i++)f[state][i]=low;
}

void data(){
	for(int i=1;i<=m;i++)scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			a[i][j]-=d[j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&c[i][j]);
}

void work(){
	data();getp();gets();fref();

	int in,jn,im,jm;
	int i,j;
	int stat,arrv;
	int sta,arr,val;

	for(in=0;in<n;in++)for(jn=1;jn<=pn[in][0];jn++){stat=pn[in][jn];
		for(im=0;im<m;im++)for(jm=1;jm<=pm[im][0];jm++){arrv=pm[im][jm];
			/*for(i=0;i<=n;i++)*/{i=0;
				if(i && (stat & bit[i]))continue;
				sta=stat|bit[i];
				if(f[sta][arrv]<f[stat][arrv])f[sta][arrv]=f[stat][arrv];
				for(j=1;j<=m;j++){
					if(arrv & bit[j])continue;
					arr=arrv|bit[j];
					val=f[stat][arrv]+s[sta][j];
					if(f[sta][arr]<val){
						ans=max(ans,val);
						f[sta][arr]=val;
					}
					break;
				}
			}
		}
	}

	if(ans)
		printf("%d\n",ans);
	else
		printf("STAY HOME\n");
}

int main(){init();
	while(scanf("%d%d",&n,&m)!=EOF && (n || m))
		work();
	//printf("\n");
	return 0;
}

