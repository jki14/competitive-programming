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

#define N 21000
#define M 310000
#define S 1300000
#define C 26

#define L (i<<1)+1
#define R (i<<1)+2

int n,T;
string a[N];int w[N];

int route[M][C],fail[M],flag[M],num,cnt;
int ev[M],next[M],nbs[M],c[S],ans;
int que[M],lef[M],rig[M],f[N],thepos[N];

char str[M];

void AddEdge(const int &u,const int &v){
	++cnt;ev[cnt]=v;
	next[cnt]=nbs[u];nbs[u]=cnt;
}

void insert(char *key,const int &d){
	int p,k;
	for(p=0;*key;key++){
		k=(*key)-'a';
		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p]=d;thepos[d]=p;
}

void build(){
	int k,p,q,l,r;l=r=0;que[r++]=0;
	memset(fail,0,sizeof(fail));
	for(;l<r;l++){
		p=que[l];
		for(k=0;k<C;k++){
			if(route[p][k]){
				que[r++]=route[p][k];
				if(p){
					for(q=fail[p];q&& !route[q][k];)q=fail[q];
					fail[route[p][k]]=route[q][k];
				}
			}
		}
	}
}

int dfs(const int &u){
	lef[u]=rig[u]=++num;
	for(int i=nbs[u];i;i=next[i])rig[u]=dfs(ev[i]);
	//printf("lef[%d]=%d rig[%d]=%d\n",u,lef[u],u,rig[u]);
	return rig[u];
}

void cov(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		c[i]=max(c[i],d);
		return;
	}
	int mid=(l+r)>>1;
	cov(L,l,  mid,u,v,d);
	cov(R,mid+1,r,u,v,d);
}

int get(const int &i,const int &l,const int &r,const int &x){
	if(x<l || x>r)return 0;
	if(l==r)return c[i];
	int mid=(l+r)>>1;
	return max(c[i],max(get(L,l,  mid,x),get(R,mid+1,r,x)));
}

void work(){
	scanf("%d",&n);ans=0;
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++){
		scanf("%s%d",str,&w[i]);
		insert(str,i);
		a[i]=str;
	}
	memset(nbs,0,sizeof(nbs));cnt=0;
	build();for(int i=1;i<=num;i++)AddEdge(fail[i],i);
	num=0;dfs(0);memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		//printf("thepos[%d]=%d left[%d]=%d right[%d]=%d\n",i,thepos[i],thepos[i],lef[thepos[i]],thepos[i],rig[thepos[i]]);
		f[i]=0;int pos=0,len=a[i].length();
		for(int j=0;j<len;j++){
			pos=route[pos][a[i][j]-'a'];
			f[i]=max(f[i],get(0,1,num,lef[pos]));
		}f[i]+=w[i];
		cov(0,1,num,lef[thepos[i]],rig[thepos[i]],f[i]);
		ans=max(ans,f[i]);
	}
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

