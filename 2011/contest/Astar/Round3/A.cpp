#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 3100

typedef long long lld;

int n;
lld f[maxn][maxn];
lld a[maxn],b[maxn];
lld suma[maxn],sumb[maxn];
lld tota[maxn],totb[maxn];

void work(){
	int i,j,k;
	memset(suma,0,sizeof(suma));
	memset(sumb,0,sizeof(sumb));
	memset(tota,0,sizeof(tota));
	memset(totb,0,sizeof(totb));
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		/*suma[i]=a[i];sumb[i]=b[i];
		if(i){
			suma[i]+=suma[i-1];
			sumb[i]+=sumb[i-1];
			tota[i]=tota[i-1]+suma[i];
			totb[i]=totb[i-1]+sumb[i];
		}else{
			tota[i]=suma[i];
			totb[i]=sumb[i];
		}*/
		suma[i]=suma[i-1]+a[i];
		sumb[i]=sumb[i-1]+b[i];
		tota[i]=tota[i-1]+suma[i];
		totb[i]=totb[i-1]+sumb[i];
		//printf("tota[%d]=%d,totb[%d]=%d\n",i,tota[i],i,totb[i]);
	}
	//cout<<tota[3]<<endl;
	memset(f,0,sizeof(f));
	for(i=1;i<=n+1;i++)
		for(j=1;j<=n+1;j++){
			if(i==j){
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}else{
				if(i>j){
					if(i-j>1)
						f[i][j]=max(f[i][j],f[i-1][j]);
					else{
						for(k=0;k<i;k++){
							/*if(f[i][j]<f[k][j]+tota[i-1]-suma[k]*(i-k))
								printf("Path:f[%d][%d] = f[%d][%d]+tota[%d]-suma[%d]*(%d-%d)\n",i,j,k,j,i-1,k,i,k);*/
							f[i][j]=max(f[i][j],f[k][j]+tota[i-1]-tota[k-1]-suma[k]*(i-k));
						}
					}
				}else{
					if(j-i>1)
						f[i][j]=max(f[i][j],f[i][j-1]);
					else{
						for(k=0;k<j;k++){
							f[i][j]=max(f[i][j],f[i][k]+totb[j-1]-totb[k-1]-sumb[k]*(j-k));
						}
					}
				}
			}
			//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	printf("%lld\n",f[n+1][n+1]);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

