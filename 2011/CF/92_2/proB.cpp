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

#define N 10
#define K 10

const int inf=LONG_MAX;

int n,k;
int pos[K],v[K],ans;
char s[N][K];
char f[N][K];

void dfspos(const int &x){
	if(x==k){
		int low=inf,hig=-inf,num;
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++)
				f[i][j]=s[i][pos[j]];
			f[i][k]=0;
			sscanf(f[i],"%d",&num);
			low=min(low,num);
			hig=max(hig,num);
		}
		ans=min(ans,hig-low);
	}
	for(pos[x]=0;pos[x]<k;pos[x]++){
		if(v[pos[x]])continue;
		v[pos[x]]=1;
		dfspos(x+1);
		v[pos[x]]=0;
	}
}

void work(){
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	memset(v,0,sizeof(v));
	ans=inf;dfspos(0);
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF)
		work();
	return 0;
}

