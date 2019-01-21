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

#define maxnum 110
#define maxchr 4
#define maxlen 110
#define K 4

int n,m;
int route[maxnum][maxchr],fail[maxnum],flag[maxnum],num;
int que[maxnum];

int trans(const char &c){
	switch(c){
		case 'A':return 0;
		case 'G':return 1;
		case 'C':return 2;
		case 'T':return 3;
	}
	return -1;
}

void init(char *key){
	int p,k;
	for(p=0;*key;key++){
		k=trans(*key);
		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p]=1;
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
					flag[route[p][k]]|=flag[route[q][k]];
				}
			}
		}
	}
}

#define state 2

typedef long long lld;
lld a[state][maxnum][maxnum],b[state][maxnum][maxnum],ans;

const lld MOD=100000;

char str[maxlen];

void work(){
	int i,j,k,p,now,pre;
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));
	
	for(i=0;i<n;i++){
		scanf("%s",str);
		init(str);
	}
	build();

	now=0;pre=!now;

	memset(a,0,sizeof(a));
	for(i=0;i<=num;i++)
		a[now][i][i]=1LL;
	
	memset(b,0,sizeof(b));
	for(i=0;i<=num;i++){if(flag[i])continue;
		for(k=0;k<K;k++){p=i;
			while(p && !route[p][k])p=fail[p];
			p=route[p][k];if(flag[p])continue;
			b[now][i][p]+=1LL;
		}
	}
	
	/*for(i=0;i<=num;i++){
		for(j=0;j<=num;j++)printf(" %lld",b[now][i][j]);
		printf("\n");
	}*/

	for(;m;m>>=1){now=pre;pre=!now;
		if(m&1){
			for(i=0;i<=num;i++)
				for(j=0;j<=num;j++){a[now][i][j]=0LL%MOD;
					for(k=0;k<=num;k++)
						a[now][i][j]=(a[now][i][j]+b[pre][i][k]*a[pre][k][j])%MOD;
				}
		}else memcpy(a[now],a[pre],sizeof(a[pre]));

		/*for(i=0;i<=num;i++)printf("...");printf("\n");
		for(i=0;i<=num;i++){
			for(j=0;j<=num;j++)printf(" %2lld",a[now][i][j]);
			printf("\n");
		}*/

		for(i=0;i<=num;i++)
			for(j=0;j<=num;j++){b[now][i][j]=0LL%MOD;
				for(k=0;k<=num;k++)
					b[now][i][j]=(b[now][i][j]+b[pre][i][k]*b[pre][k][j])%MOD;
			}
		
		
		/*printf("b[now]=");for(i=0;i<=num;i++)printf("...");printf("\n");
		for(i=0;i<=num;i++){
			for(j=0;j<=num;j++)printf(" %2lld",b[now][i][j]);
			printf("\n");
		}*/
	}

	ans=0LL;
	for(i=0;i<=num;i++)ans+=a[now][0][i];
	
	ans%=MOD;

	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

