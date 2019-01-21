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

#define N 110
#define M 110
#define C 110

typedef long long lld;

int n,m,g[N][M][C],h[N][M][C];
int resx[N];
lld d,resy[N];
lld a[M],b[M],c[M];
lld f[N][M][C];

void work(){
	for(int i=1;i<=m;i++){
		//scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
		cin>>a[i]>>b[i]>>c[i];
	}

	/* init4 DP */
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));memset(h,0,sizeof(h));
	for(int j=1;j<=m;j++){
		int des=(int)(b[j]-a[j]);
		for(int k=0;k<=des;k++){
			f[1][j][k]=a[j]+(lld)k;
		}
	}

	/* Core DP */
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int des=(int)(b[j]-a[j]);
			for(int k=0;k<=des;k++){
				if(!f[i][j][k])continue;
				for(int p=1;p<=m;p++){
					if(c[p]<=c[j])continue;
					lld sta=a[j]+(lld)k,state;
					//+++
					state=sta+d;
					if(state>=a[p] && state<=b[p]){
						int pos=(int)(state-a[p]);
						if(f[i+1][p][pos]<f[i][j][k]+state){
							f[i+1][p][pos]=f[i][j][k]+state;
							g[i+1][p][pos]=j;h[i+1][p][pos]=k;
						}
					}
					//***
					state=sta*d;
					if(state>=a[p] && state<=b[p]){
						int pos=(int)(state-a[p]);
						if(f[i+1][p][pos]<f[i][j][k]+state){
							f[i+1][p][pos]=f[i][j][k]+state;
							g[i+1][p][pos]=j;h[i+1][p][pos]=k;
						}
					}
				}
			}
		}
	}

	/* For Result */
	int pos,sta;pos=sta=0;
	for(int j=1;j<=m;j++){
		int des=(int)(b[j]-a[j]);
		for(int k=0;k<=des;k++){
			if(f[n][j][k]>f[n][pos][sta]){ pos=j;sta=k; }
		}
	}
	if(!f[n][pos][sta]){
		//printf("NO\n");
		cout<<"NO"<<endl;
		return;
	}
	//printf("YES\n");
	cout<<"YES"<<endl;
	int i=n,top=0;

	for(;pos;i--){
		resx[++top]=pos;
		resy[  top]=a[pos]+(lld)sta;
		int tmppos=pos,tmpsta=sta;
		pos=g[i][tmppos][tmpsta];
		sta=h[i][tmppos][tmpsta];
	}

	/* Print Out */
	for(;top;top--){
		//printf("%d%I64d\n",resx[top],resy[top]);
		cout<<resx[top]<<" "<<resy[top]<<endl;
	}
}

int main(){
	//while(scanf("%d%d%I64d",&n,&m,&d)!=EOF)
	while(cin>>n>>m>>d)
		work();
	return 0;
}

