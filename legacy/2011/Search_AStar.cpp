//============================================================================
// Name        : AStar
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 求第K短路
//============================================================================

//变量申明

const int inf=1<<30;

int n,m,len,num,rnum;
int next[maxe],ev[maxe],ew[maxe],rnext[maxe],rev[maxe],rew[maxe];
int dist[maxv],mk[maxv],nbs[maxv],rnbs[maxv];
int ps[maxv],heap[maxv];

//功能函数

void update(int r){
	int q=ps[r],p=q>>1;
	while(p && dist[heap[p]]>dist[r]){
		ps[heap[p]]=q;heap[q]=heap[p];
		q=p;p=q>>1;
	}
	heap[q]=r;ps[r]=q;
}

int getmin(){
	int ret=heap[1],p=1,q=2,r=heap[len--];
	while(q<=len){
		if(p<len && dist[heap[q+1]]<dist[heap[q]])q++;
		if(dist[heap[q]]<dist[r]){
			ps[heap[q]]=p;heap[p]=heap[q];
			p=q;q=p<<1;
		}else break;
	}
	heap[p]=r;ps[r]=p;
	return ret;
}

struct Path{
	int x,f;
	Path(){ }
	Path(const int &v0,const int &v1){ x=v0;f=v1; }
	bool operator < (const Path &a) const{
		return a.f+dist[a.x]<f+dist[x];
	}
};

void AddEdge(int u,int v,int w){
	next[++num]=nbs[u];nbs[u]=num;ev[num]=v;ew[num]=w;
	rnext[++rnum]=rnbs[v];rnbs[v]=rnum;rev[rnum]=u;rew[num]=w;
}

void InitDist(int dst){
	int i,u,v;
	memset(mk,0,sizeof(mk));memset(ps,0,sizeof(ps));
	memset(dist,0x3f,sizeof(dist));dist[dst]=0;
	heap[len=1]=dst;ps[dst]=1;
	while(1){
		if(!len)return;
		u=getmin();mk[u]=1;
		for(i=rnbs[u];i;i=rnext[i]){
			v=rev[i];if(!mk[v] && dist[u]+rew[i]<dist[v]){
				if(!ps[v]){ heap[++len]=v;ps[v]=len; }
				dist[v]=dist[u]+rew[i];update(v);
			}
		}
	}
}

int aStar(int src,int dst,int w){
	InitDist(dst);
	int u,v,i,f;
	priority_queue<Path> pq;
	memset(mk,0,sizeof(mk));pq.push(Path(src,0));
    while (!pq.empty()){
    	u=pq.top().x;f=pq.top().f;pq.pop();
	    mk[u]++;if(mk[u]>=w)return f+dist[u];
	    for(i=nbs[u];i;i=next[i]){
	    	v=ev[i];
	    	pq.push(Path(v,f+ew[i]));
	    }
	}
	return -1;
}

//初始化
memset(nbs,0,sizeof(nbs));
msmset(rnbs,0,sizeof(rnbs));
num=rnum=0;
