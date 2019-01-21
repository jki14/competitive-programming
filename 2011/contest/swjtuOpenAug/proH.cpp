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

#define maxn 110000
#define maxm 11
#define K 2

#define H1 que[head]
#define H2 que[head+1]

#define T1 que[tail-1]

const int inf=0x3fffffff;

int T;

int n,m,num,ans,bnd;
int x[maxn],y[maxn],id[maxn];
int a[maxn],que[maxn],head,tail;
int f[maxn][maxm],g[maxn][maxm];

int cmpX(const int &i,const int &j){ return x[i]<x[j]; }
int cmpY(const int &i,const int &j){ return y[i]<y[j]; }

int gcd(int x,int y){
	while(y){
		int k=x%y;
		x=y;y=k;
	}
	return x;
}

void work(){T++;
	int i,j,k,t,size;ans=inf;
	int head,tail;
	for(i=0;i<n;i++){
		id[i]=i;
		scanf("%d%d",&x[i],&y[i]);
	}
	
	for(t=0;t<2;t++){
		if(t)sort(id,id+n,cmpX);else sort(id,id+n,cmpY);
		num=0;a[0]=0;k=-1;
		for(j=0;j<n;j++){i=id[j];
			if((t && x[i]!=k) || (!t && y[i]!=k)){k=(t)?x[i]:y[i];
				++num;
				a[num]=a[num-1];
			}
			a[num]+=m;
		}
		memset(f,0x3f,sizeof(f));f[0][0]=0;
		memset(g,0x3f,sizeof(g));g[0][0]=0;

		//printf("a[]={ ");
		//for(i=1;i<=num;i++)printf("%4d",a[i]-a[i-1]);printf(" }\n");
		
		size=min(m,num);
		for(j=1;j<=size;j++){	
			head=tail=0;que[tail++]=0;
			for(i=1;i<=num;i++){
				while(head+1<tail && max(g[H1][j-1],a[i]-a[H1])>max(g[H2][j-1],a[i]-a[H2]))head++;
				g[i][j]=max(g[H1][j-1],a[i]-a[H1]);
				f[i][j]=f[H1][j-1]+abs(a[i]-a[H1]-n);

				//printf("[%d][%d]~g=%d~f=%d\n",i,j,g[i][j],f[i][j]);

				while(head<tail && max(g[T1][j-1],a[j]-a[T1])>g[i][j-1])tail--;
				que[tail++]=i;
			}
		}
		ans=min(ans,f[num][size]+(m-size)*n);
	}

	bnd=m*m;
	if(ans==0)
		bnd=1;
	else{
		k=gcd(ans,bnd);
		ans/=k;
		bnd/=k;
	}

	printf("%d. %d/%d\n",T,ans,bnd);
}

int main(){T=0;
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}

