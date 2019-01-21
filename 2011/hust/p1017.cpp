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

#define N 1100
#define M 1100
#define S 1100000

int a[N][M];
int head[S],l[S],r[S],u[S],d[S],idx[S];
int root,res[N],num[M];
int n,m;

void clear(){
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(u,0,sizeof(u));
	memset(d,0,sizeof(d));
	memset(head,0,sizeof(head));
	memset(idx,0,sizeof(idx));
	memset(res,0,sizeof(res));
	memset(num,0,sizeof(num));
	for(int i=1;i<=m+1;i++){
		head[i]=i;
		r[i]=i+1;l[i]=i-1;
		u[i]=i;d[i]=i;
	}
	l[0]=r[0]=u[0]=d[0]=m+1;
	l[1]=m+1;r[m+1]=1;root=m+1;
}

void remove(const int &x){
	l[r[x]]=l[x];r[l[x]]=r[x];
	for(int i=d[x];i!=x;i=d[i]){
		for(int j=r[i];j!=i;j=r[j]){
			u[d[j]]=u[j];d[u[j]]=d[j];
			num[head[j]]--;
		}
	}
}

void resume(const int &x){
	for(int i=d[x];i!=x;i=d[i]){
		for(int j=r[i];j!=i;j=r[j]){
			u[d[j]]=j;d[u[j]]=j;
			num[head[j]]++;
		}
	}
	l[r[x]]=x;r[l[x]]=x;
}

int dfs(const int &x){
	if(r[root]==root)return 1;
	int k=r[root];
	for(int i=r[root];i!=root;i=r[i]){
		if(num[i]<num[k])k=i;
	}
	remove(k);
	for(int i=d[k];i!=k;i=d[i]){
		res[0]++;res[res[0]]=idx[i];
		for(int j=r[i];j!=i;j=r[j])remove(head[j]);
		if(dfs(x+1))return 1;
		for(int j=l[i];j!=i;j=l[j])resume(head[j]);
		res[0]--;
	}
	resume(k);
	return 0;
}

void work(){
	/* input & build */
	clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++)scanf("%d",&a[i][j]);

		for(int j=r[0]+1;j<=r[0]+a[i][0];j++){
			idx[j]=i;
			r[j]=j+1;l[j]=j-1;
			head[j]=a[i][j-r[0]];
			u[j]=u[head[j]];d[j]=head[j];
			u[d[j]]=d[u[j]]=j;
			num[head[j]]++;
		}
		l[r[0]+1]=r[0]+a[i][0];r[r[0]+a[i][0]]=r[0]+1;
		l[0]+=a[i][0];r[0]+=a[i][0];u[0]+=a[i][0];d[0]+=a[i][0];
	}

	/* simple check */
	for(int i=1;i<=m;i++){
		if(num[head[i]]==0){
			printf("NO\n");
			return;
		}
	}

	/* core & output */
	if(dfs(0)){
		printf("%d",res[0]);
		for(int i=1;i<=res[0];i++)printf(" %d",res[i]);
		printf("\n");
	}else printf("NO\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();	
	return 0;
}

