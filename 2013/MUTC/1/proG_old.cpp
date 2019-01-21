#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

/* SEGX */
int  cross(int a,int b,int c,int d){
	return a*b-c*d;
}

int segx0(const seg &i,const seg &j){
	return (min(i.u.x,i.v.x)<max(j.u.x,j.v.x)&&min(j.u.x,j.v.x)<max(i.u.x,i.v.x)
		&&min(i.u.y,i.v.y)<max(j.u.y,j.v.y)&&min(j.u.y,j.v.y)<max(i.u.y,i.v.y))
		?1:0;
}

int segx1(const seg &i,const seg &j){
	return	((cross(i.u.x-j.u.x, i.u.y-i.v.y, i.u.y-j.u.y, i.u.x-i.v.x)
		 *cross(i.u.x-i.v.x, i.u.y-j.v.y, i.u.y-i.v.y, i.u.x-j.v.x))>=0 
	      && (cross(j.u.x-i.u.x, j.u.y-j.v.y, j.u.y-i.u.y, j.u.x-j.v.x)
	         *cross(j.u.x-j.v.x, j.u.y-i.v.y, j.u.y-j.v.y, j.u.x-i.v.x))>=0)
	 	?1:0;
}

int segx(const seg &i,const set &j){	 return (segx0(i,j)&&segx1(i,j))?1:0; }

/* DIJKSTRA */
void update(const int &r){
	int q=ps[r],p=q>>1;
	while(p && d[heap[p]]>d[r]){
		ps[heap[p]]=q; heap[q]=heap[p];
		q=p; p=q>>1;
	}
	heap[q]=r;ps[r]=q;
}

int getmin(){
	int ret=heap[1],p=1,q=2,r=heap[len--];
	while(q<=len){
		if(q<len && d[heap[q+1]]<d[heap[q]])q++;
		if(d[heap[q]]<d[r]){
			ps[heap[q]]=p;heap[p]=heap[q];
			p=q;q=p<<1;
		}else break;
	}
	heap[p]=r;ps[r]=p;
	return ret;
}

void dijkstra(const int &src){
	for(int i=1;i<=n;i++){ c[src][i]=inf;mrk[i]=ps[i]=0; }
	c[src][src]=0;heap[len=1]=src;ps[src]=1;
	while(true){
		if(len==0)return;
		int u=getmin();mk[u]=1;
		for(j=nbs[u];j;j=next[j]){int v=ev[j];
			if(!mk[v] && d[u]+ew[j]<d[v]){
				if(!ps[v]){ heap[++len]=v;ps[v]=len; }
				d[v]=d[u]+ew[j];update(v);
			}
		}
	}
}

/* MAFFLOW */
void AddEdge(const int &u,const int &v,const int &cc){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
}

int SAP(const int &s,const int &t,const int &n){
	memset(sud,0,sizeof(sud));
	memset(cur,0xff,sizeof(cur));
	memset(dis,0,sizeof(dis));
	sud[0]=n; pre[s]=s;
	int res=0, now=s, mod=inf;
	while(dis[s]<n){
		int flag = 0;
		if(now == s)mod=inf;
		if(cur[now]<0)cur[now]=nbs[now];
		for(int &i=cur[now];i;i=next[i]){int v=ev[i];
			if(i<be[i] && dis[now]==dis[v]+1 && ef[i]<ec[i]){
				flag=1; pre[v]=now; now=v;
				mod=mymin(mod,ec[i]-ef[i]);
				break;
			}
			if(i>be[i] && dis[now]==dis[v]+1 && ef[i]>0){
				flag=1; pre[v]=now; now=v;
				mod=mymin(mod,ef[i]);
				break;
			}
		}
		if(now==t){
			res+=mod;
			while(now !=s){
				now=pre[now];
				if(cur[now]<be[cur[now]]){
					ef[cur[now]]+=mod;ef[be[cur[now]]]+=mod;
				}else{
					ef[cur[now]]-=mod;ef[be[cur[now]]]-=mod;
				}
			}
		}
		if(flag)continue;
		cur[now]=-1;
		int mnd=n;
		for(int i=nbs[now];i;i=next[i]){int v=ev[i];
			if(i<be[i] && dis[v]<mnd && ef[i]<ec[i])mnd=dis[v];
			if(i>be[i] && dis[v]<mnd && ef[i]>0)mnd=dis[v];
		}
		sud[dis[now]]--;
		if(sud[dis[now]]==0)dis[s]=n;
		sud[dis[now]=mnd+1]++;
		now=pre[now];
	}
	return res;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&p);
		/* INIT */
		for(int i=0;i<n;i++)scanf("%d%d",&cx[i],&cy[i]);
		for(int i=0;i<m;i++){
			scanf("%d%d",&ux[i],&uy[i]);
			scanf("%d%d",&vx[i],&vy[i]);
		}
		for(int i=0;i<n;i++){ scanf("%d",s[i]);s[i]--; }
		/* CALCULATE DISTANSES */
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=0;i<n+m+m;i++)
			for(int j=i+1;j<n+m+m;j++)
				if(able(i,j))
					addEdge(i,j,dis(i,j),0);
		memset(c,0x3f,sizeof(c));
		for(int i=0;i<n;i++)dijkstra(i);
		/* BUILD FLOW-MAP */
		memset(nbs,0,sizeof(nbs));num=0;dset.clear();
		_updmin(p,n);
		addEdge(src,_src,p,0);
		for(int i=0;i<n;i++){
			addEdge(_src,fsrc(i),1,0);
			addEdge(fsrc(i),fdst(i),1,0);
			addEdge(fdst(i),dst,1,0);
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				addEdge(fdst(s[i]),fsrc(s[j]),1,c[s[i]][s[j]]);
		/* CORE */
		mnt=0;for(it=dset.begin();it!=dset.end();it++)ans[++mnt]=(*it);
		printf("%.2f\n",sqrt((double)core()));
	}
	return 0;
}

