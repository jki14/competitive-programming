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

#define maxn 1500

const int ing=LONG_MIN;

int n,t,m;
int a[maxn];
int f[maxn],g[maxn];

void work(){
	int i,j;
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	f[0]=ing;g[0]=0;
	//cout<<"inf="<<f[1]<<endl;
	for(i=1;i<=m;i++){scanf("%d",&a[i]);
		for(j=1;j<=n && j<=i;j++){
			if(f[i]>=max(f[i-j]+t*2,a[i]+t)){
				f[i]=max(f[i-j]+t*2,a[i]+t);
				g[i]=min(g[i],g[i-j]+1);
			}
		}
	}
	printf("%d %d\n",f[m],g[m]);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&t,&m);
		work();
	}
	return 0;
}

