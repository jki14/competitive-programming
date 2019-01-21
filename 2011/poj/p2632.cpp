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
#include<set>
#include<map>
using namespace std;

#define maxn 1100
#define K 4
#define len 10

const int dx[K]={ 0,1,0,-1 };
const int dy[K]={ 1,0,-1,0 };

int a[maxn][maxn];
int px[maxn],py[maxn];
int b[maxn];
int X,Y,n,m;

char opt[len];

int cwall(const int &i){
	if(px[i]<=0 || px[i]>X)return 1;
	if(py[i]<=0 || py[i]>Y)return 1;
	return 0;
}

void work(){
	int i,k;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++){
		scanf("%d%d%s",&px[i],&py[i],opt);
		switch(opt[0]){
			case 'N':
				b[i]=0;
				break;
			case 'E':
				b[i]=1;
				break;
			case 'S':
				b[i]=2;
				break;
			case 'W':
				b[i]=3;
				break;
		}
		a[px[i]][py[i]]=i;
	}
	while(m--){
		scanf("%d%s%d",&i,opt,&k);
		while(k--){
			switch(opt[0]){
				case 'L':
					b[i]=(b[i]+3)%K;
					break;
				case 'R':
					b[i]=(b[i]+1)%K;
					break;
				case 'F':
					px[i]+=dx[b[i]];
					py[i]+=dy[b[i]];
					if(cwall(i)){
						printf("Robot %d crashes into the wall\n",i);
						while(m--)scanf("%d%s%d",&i,opt,&k);
						return;
					}
					if(a[px[i]][py[i]]){
						printf("Robot %d crashes into robot %d\n",i,a[px[i]][py[i]]);
						while(m--)scanf("%d%s%d",&i,opt,&k);
						return;
					}
					a[px[i]][py[i]]=i;a[px[i]-dx[b[i]]][py[i]-dy[b[i]]]=0;
			}		
		}
	}
	printf("OK\n");
}

int main(){
	int T;scanf("%d",&T);
	while(T--){scanf("%d%d%d%d",&X,&Y,&n,&m);
		work();
	}
	return 0;
}

