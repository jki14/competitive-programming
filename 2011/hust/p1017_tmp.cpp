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
#define maxn 1100
#define maxm maxn*maxn
#define clr(x) memset(x,0,sizeof(x));
int u[maxm],d[maxm],l[maxm],r[maxm],head[maxm],bl[maxm];
int root,ans[maxn],num[maxn];
int m,n;
void init(){
	clr(u);clr(d);clr(l);clr(r);clr(head);
	clr(ans);clr(num);clr(bl);
	int i;
	for(i=1;i<=n+1;i++)
	{
		head[i]=i;
		r[i]=i+1;l[i]=i-1;
		u[i]=i;d[i]=i;
	}
	r[0]=n+1;l[0]=n+1;u[0]=n+1;d[0]=n+1;
	l[1]=n+1;r[n+1]=1;root=n+1;
}
void reading(){
	int i,j,a[maxn];
	for(j=1;m>=j;j++){
		a[0]=1;
		for(i=0;i<=a[0];i++)
			scanf("%d",&a[i]);
		for(i=r[0]+1;i<=r[0]+a[0];i++){
			bl[i]=j;
			r[i]=i+1;l[i]=i-1;
			head[i]=a[i-r[0]];
			u[i]=u[head[i]];d[i]=head[i];
			u[d[i]]=i;d[u[i]]=i;
			num[head[i]]++;
		}
		l[r[0]+1]=r[0]+a[0];r[r[0]+a[0]]=r[0]+1;
		r[0]+=a[0];d[0]+=a[0];l[0]+=a[0];u[0]+=a[0];
	}
}
void remove(int i){
	l[r[i]]=l[i];r[l[i]]=r[i];
	int j,k;
	for(j=d[i];j!=i;j=d[j]){
		for(k=r[j];k!=j;k=r[k]){
			u[d[k]]=u[k];
			d[u[k]]=d[k];
			num[head[k]]--;
		}
	}
}
void resume(int i){
	int j,k;
	for(j=d[i];j!=i;j=d[j]){
		for(k=r[j];k!=j;k=r[k]){
			u[d[k]]=k;d[u[k]]=k;
			num[head[k]]++;
		}
	}
	l[r[i]]=i;r[l[i]]=i;
}
bool dfs(int i){
	if(r[root]==root){
		return true;
	}
	int j,k,x;k=r[root];
	for(j=r[root];j!=root;j=r[j])
		if(num[j]<num[k])
			k=j;
	remove(k);
	for(j=d[k];j!=k;j=d[j]){
		ans[0]++;ans[ans[0]]=bl[j];
		for(x=r[j];x!=j;x=r[x])
			remove(head[x]);
		if(dfs(i+1)==true)
			return true;
		else 
		{
			for(x=l[j];x!=j;x=l[x])
				resume(head[x]);
			ans[0]--;
		}
	}
	resume(k);
	return false;
}
int main(){
	/*freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);*/

	while(scanf("%d%d",&m,&n)!=EOF){
		init();int i;
		reading();
		for(i=1;i<=n;i++)
			if(num[head[i]]==0)
			{
				printf("NO\n");
				return 0;
			}	
		if(dfs(0))
		{
			sort(&ans[1],&ans[ans[0]+1]);
			for(i=0;i<ans[0];i++)
				printf("%d ",ans[i]);
			printf("%d\n",ans[ans[0]]);
		}
		else printf("NO\n");
	}
	return 0;
}
