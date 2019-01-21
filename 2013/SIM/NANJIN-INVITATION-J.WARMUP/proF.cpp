#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define N 310
#define M 21000

const int src=0;
const int des=300;

int n,m,_s,full;
int ec[M],ef[M],eu[M],ev[M],ope[M],nxt[M],num;
int nbs[N],cur[N],dis[N],sud[N],pre[N];

int fir[N],sec[N],f[N],g[N];
double ans[M],rnk[M],d[N][N],cap,x[N],y[N],z[N];

const double eps=1e-9;
const int inf=0x3f3f3f3f;

void addEdge(const int &u,const int &v,const int &cc,const double &dd){
	nxt[++num]=nbs[u];if(!nbs[u])_s++;nbs[u]=num;ope[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;rnk[num]=dd;
	nxt[++num]=nbs[v];if(!nbs[v])_s++;nbs[v]=num;ope[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0 ;ef[num]=0;rnk[num]=dd;
}

int SAP(const int &s,const int &t,const int &n){
	memset(sud,0,sizeof(sud));
	memset(cur,0xff,sizeof(cur));
	memset(dis,0,sizeof(dis));
	sud[0]=n;pre[s]=s;
	int res=0,now=s,mod=inf;
	while(dis[s]<n){
		int flag=0;
		if(now==s)mod=inf;
		if(cur[now]<0)cur[now]=nbs[now];
		for(int &i=cur[now];i;i=nxt[i]){int v=ev[i];
			if(rnk[i]>cap+eps)continue;
			if(i<ope[i] && dis[now]==dis[v]+1 && ef[i]<ec[i]){
				flag=1;pre[v]=now;now=v;
				if(mod>ec[i]-ef[i])mod=ec[i]-ef[i];
				break;
			}
			if(i>ope[i] && dis[now]==dis[v]+1 && ef[i]>0){
				flag=1;pre[v]=now;now=v;
				if(mod>ef[i])mod=ef[i];
				break;
			}
		}
		if(now==t){
			res+=mod;
			while(now!=s){
				now=pre[now];
				if(cur[now]<ope[cur[now]]){
					ef[cur[now]]+=mod;ef[ope[cur[now]]]+=mod;
				}else{
					ef[cur[now]]-=mod;ef[ope[cur[now]]]-=mod;
				}
			}
		}
		if(flag)continue;
		cur[now]=-1;
		int mnd=n;
		for(int i=nbs[now];i;i=nxt[i]){ int v=ev[i];
			if(rnk[i]>cap+eps)continue;
			if(i<ope[i] && dis[v]<mnd && ef[i]<ec[i])mnd=dis[v];
			if(i>ope[i] && dis[v]<mnd && ef[i]>0)mnd=dis[v];
		}
		sud[dis[now]]--;
		if(sud[dis[now]]==0)dis[s]=n;
		sud[dis[now]=mnd+1]++;
		now=pre[now];
	}
	return res;
}

int able(const double &x){
	if(x<-eps)return 0;
	cap=x;for(int i=0;i<=num;i++)ef[i]=0;
	return SAP(src,des,_s)==full;
}

void core(){
	int lef=1,rig=m-1;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(able(ans[mid])){
			if(!able(ans[mid-1])){
				printf("%.7f\n",ans[mid]);
				return;
			}
			rig=mid-1;
		}else lef=mid+1;
	}
	printf("-1\n");
}

double dist(const int &i,const int &j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(nbs,0,sizeof(nbs));full=num=m=_s=0;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%d%d",&x[i],&y[i],&z[i],&f[i],&g[i]);
			fir[i]=i;sec[i]=n+i;
			if(i==1){ 
				f[i]=0;g[i]=inf; 
			}else full+=f[i];
		}
		memset(d,0,sizeof(d));for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){ ans[m++]=d[i][j]=dist(i,j); }
		ans[m++]=-1.0;ans[m++]=0.0;sort(ans,ans+m);
		for(int i=1;i<=n;i++)addEdge(src,fir[i],f[i],0.0);
		for(int i=1;i<=n;i++)addEdge(fir[i],sec[i],g[i],0.0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				addEdge(sec[i],fir[j],inf,(i<j)?d[i][j]:d[j][i]);
			}
		}
		addEdge(sec[1],des,inf,0.0);
		core();
	}
	return 0;
}
