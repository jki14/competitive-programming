#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 1100
#define maxc 1100
#define maxk 4
#define maxb 3

const int inf=1<<30;

int T;
int L,t,n,c,K;
int s[maxc],res;
int f[maxn][maxk];
int sum[maxn];
void work(){
	int i,j,k,d,dis;
	scanf("%d%d%d%d",&L,&t,&n,&c);
	for(i=0;i<c;i++)scanf("%d",&s[i]);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;sum[0]=0;
	for(i=1;i<=n;i++){d=s[(i-1)%c];sum[i]=sum[i-1]+d;
		for(k=0;k<=L;k++)f[i][k]=min(f[i][k],f[i-1][k]+d*2);
		//speed-up
		for(k=1;k<=L;k++)
			f[i][k-1]=min(f[i][k-1],f[i-1][k]+d);
		//cool-down
		for(j=i;j>=0;j--){
			dis=(sum[i]-sum[j])*2;
			for(k=0;k<L;k++){
				if(dis>=t)
					f[i][k+1]=min(f[i][k+1],f[j][k]+dis);
			}
		}
		//debug
		for(k=0;k<=L;k++){
			cout<<"f["<<i<<"]["<<k<<"]="<<f[i][k]<<endl;
		}
	}
	res=inf;
	for(k=0;k<=L;k++)res=min(res,f[n][k]);
	printf("Case #%d: %d\n",T,res);
}

int main(){
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

