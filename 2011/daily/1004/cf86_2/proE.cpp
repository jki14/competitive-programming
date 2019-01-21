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

#define N 8
#define M 50
#define K 210 

int n,m,ans,ful;
int bit[N],cov[N],f[M][K][K];
int nex[K],sta[K],opt[K],num;

void init(){num=0;
	for(int i=0;i<n;i++)bit[i]=1<<i;
	for(int i=0;i<n;i++){
		cov[i]=bit[i];
		if(i    )cov[i]|=bit[i-1];
		if(i+1<n)cov[i]|=bit[i+1];
	}
	int e=1<<n;
	for(int i=0;i<e;i++){
		nex[num]=sta[num]=opt[num]=0;
		for(int j=0;j<n;j++){
			if(i&bit[j]){
				nex[num]|=bit[j];
				sta[num]|=cov[j];
				opt[num]++;
			}
		}
		num++;
	}
}

void work(){
	if(n>m)swap(n,m);
	init();ans=LONG_MAX;ful=(1<<n)-1;
	//printf("full=%d\n",full);
	memset(f,0x3f,sizeof(f));f[0][0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<num;j++){
			for(int k=0;k<=ful;k++){
				for(int p=0;p<num;p++){
					if(((nex[p]|sta[j])|k)<ful)continue;
					for(int q=0;q<=ful;q++){
						if((nex[j]&q)!=q)continue;
						f[i][j][k]=min(f[i][j][k],f[i-1][p][q]+opt[j]);
					}
				}
			}
		}
	}
	for(int i=0;i<num;i++)
		ans=min(ans,f[m][i][0]);
	ans=n*m-ans;
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

