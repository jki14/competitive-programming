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

#define LEN 11
#define K 4
#define M 21
#define S 30

typedef long long lld;

const lld modulo=1000000007LL;

int n,m;
lld a[K],b[K],bit[S][K];
int tim[M],sta[M],id[M];
lld f[K],g[K],ans;

lld getval(lld a[K],const int &x,const int &y){
	return a[(y-x+K)%K];
}

void init(){
	bit[0][0]=bit[1][1]=bit[1][2]=bit[1][3]=1LL;
	bit[0][1]=bit[0][2]=bit[0][3]=bit[1][0]=0LL;
	for(int i=2;i<S;i++){
		for(int x=0;x<K;x++){bit[i][x]=0LL;
			for(int y=0;y<K;y++)
				bit[i][x]=(bit[i][x]+getval(bit[i-1],0,y)*getval(bit[i-1],y,x))%modulo;
		}
	}
}

int cmp(const int &i,const int &j){ return tim[i]<tim[j]; }

char cstr[LEN];

void work(){
	for(int i=0;i<m;i++){
		scanf("%d%s",&tim[i],cstr);
		sta[i]=cstr[0]-'A';id[i]=i;
	}
	
	sort(id,id+m,cmp);
	if(!m || tim[id[m-1]]!=n){
		m++;id[m-1]=m-1;
		tim[m-1]=n;sta[m-1]=-1;
	}

	if(tim[id[0]]==1){
		f[0]=f[1]=f[2]=f[3]=0LL;
		f[sta[id[0]]]=1LL;
	}else f[0]=f[1]=f[2]=f[3]=1LL;

	int t=1;
	for(int _i=(tim[id[0]]==1)?1:0;_i<m;_i++){int i=id[_i];
		int d=tim[i]-t;t=tim[i];

		memset(a,0,sizeof(a));a[0]=1LL;
		for(int k=1;d;k++){
			if(d&1){
				memcpy(b,a,sizeof(a));
				for(int x=0;x<K;x++){a[x]=0LL;
					for(int y=0;y<K;y++)
						a[x]=(a[x]+getval(b,0,y)*getval(bit[k],y,x))%modulo;
				}
			}
			d>>=1;
		}

		memcpy(g,f,sizeof(f));
		for(int x=0;x<K;x++){f[x]=0LL;
			for(int y=0;y<K;y++)
				f[x]=(f[x]+g[y]*getval(a,x,y))%modulo;
		}

		if(sta[i]==-1)break;
		for(int x=0;x<K;x++)
			if(x!=sta[i])f[x]=0;
	}

	ans=(f[0]+f[1]+f[2]+f[3])%modulo;
	printf("%lld\n",ans);
}

int main(){init();
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

