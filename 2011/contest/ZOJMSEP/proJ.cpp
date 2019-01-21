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

#define M 11
#define K 4
#define LEN 11
#define S 4
#define B 30

typedef long long lld;

struct SNC{
	int tim,sta;
	bool operator < (const SNC &a) const{
		return tim<a.tim;
	}
};

struct SMatrix{
	lld val[K][K];
};

typedef struct SNC noc;
typedef struct SMatrix mat;

const lld modulo=1000000007;

int n,m,ans;
mat a,b,bit[B];
lld f[K],g[K],pre;
noc arr[M];

char str[LEN];

void init(){

	for(int i=0;i<K;i++)
		for(int j=0;j<K;j++){
			if(i==j){
				bit[0].val[i][j]=1LL;
				bit[1].val[i][j]=0LL;
			}else{
				bit[0].val[i][j]=0LL;
				bit[1].val[i][j]=1LL;
			}
		}

	for(int i=2;i<B;i++){
		for(int x=0;x<K;x++)
			for(int y=0;y<K;y++){
				bit[i].val[x][y]=0LL;
				for(int z=0;z<K;z++)
					bit[i].val[x][y]+=bit[i-1].val[x][z]*bit[i-1].val[z][y];
				bit[i].val[x][y]%=modulo;
			}
	}
}


void work(){
	int i,j,k,t;
	int x,y,z;
	
	for(i=0;i<m;i++){
		scanf("%d%s",&arr[i].tim,str);
		arr[i].sta=str[0]-'A';
	}
	sort(arr,arr+m);
	for(i=0;i<m;i++){
		while(i<m-1 && arr[i].tim==arr[i+1].tim){
			if(arr[i].sta!=arr[i+1].sta){
				printf("0\n");
				return;
			}
			m--;
			for(j=i;j<m;j++)arr[j]=arr[j+1];
		}
	}
	
	if(arr[0].tim==1){
		f[0]=f[1]=f[2]=f[3]=0LL;
		f[arr[0].sta]=1LL;
		m--;
		for(j=0;j<m;j++)arr[j]=arr[j+1];
	}else f[0]=f[1]=f[2]=f[3]=1LL;
	k=1;

	//for(i=0;i<m;i++) printf("Arr %d %d\n",arr[i].tim,arr[i].sta);

	for(i=0;i<m;i++){
		
		t=arr[i].tim-k;k=arr[i].tim;

		//printf("t=%d\n",t);

		a=bit[0];
		
		/*for(i=0;i<K;i++){
			for(j=0;j<K;j++)
				printf("%3lld",a.val[i][j]);
			printf("\n");
		}*/

		for(j=1;t;){
			if(t&1){
				b=a;	
				for(x=0;x<K;x++)
					for(y=0;y<K;y++){
						a.val[x][y]=0LL;
						for(z=0;z<K;z++)
							a.val[x][y]+=b.val[x][z]*bit[j].val[z][y];
						a.val[x][y]%=modulo;
					}
			}
			t>>=1;j++;
		}

		/*for(x=0;x<K;x++){
			for(y=0;y<K;y++)
				printf("%3lld",a.val[x][y]);
			printf("\n");
		}*/

		//printf("arr[%d].sta=%d\n",i,arr[i].sta);

		f[arr[i].sta]=((f[0]*a.val[arr[i].sta][0]%modulo)
				+(f[1]*a.val[arr[i].sta][1]%modulo)
				+(f[2]*a.val[arr[i].sta][2]%modulo)
				+(f[3]*a.val[arr[i].sta][3]%modulo))%modulo;

		for(j=0;j<K;j++)if(j!=arr[i].sta)f[j]=0LL;
		
		//printf("F[]={%lld %lld %lld %lld}\n",f[0],f[1],f[2],f[3]);	

	}

	if(k<n){
		t=n-k;k=n;

		//printf("t=%d\n",t);

		a=bit[0];
		for(j=1;t;){
			if(t&1){
				b=a;	
				for(x=0;x<K;x++)
					for(y=0;y<K;y++){
						a.val[x][y]=0LL;
						for(z=0;z<K;z++)
							a.val[x][y]+=b.val[x][z]*bit[j].val[z][y];
						a.val[x][y]%=modulo;
					}
			}
			t>>=1;j++;
		}
		
		/*for(i=0;i<K;i++){
			for(j=0;j<K;j++)
				printf("%3lld",a.val[i][j]);
			printf("\n");
		}*/

		memcpy(g,f,sizeof(f));
		for(i=0;i<K;i++){f[i]=0LL;
			for(j=0;j<K;j++)f[i]=(f[i]+g[j]*a.val[i][j])%modulo;
		}
		//printf("F[]={%lld %lld %lld %lld}\n",f[0],f[1],f[2],f[3]);	

	}

	pre=(f[0]+f[1]+f[2]+f[3]) % modulo;
	ans=(int)pre;

	printf("%d\n",ans);
}

int main(){init();
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

