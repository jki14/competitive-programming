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

#define maxn 110000
#define maxm 1100000
#define STA 2
#define LEN 10

typedef long long lld;

//const lld inf = 1LL<<60;

struct Edge{
	int u,v;
	Edge(){ u=v=0; }
	Edge(const int &_u,const int &_v){ u=_u;v=_v; }
	bool operator < (const Edge &e) const{
		if(u!=e.u)return u<e.u;
		return v<e.v;
	}
};

map<Edge ,int > m;
map<Edge ,int >::iterator it;

Edge e;

int n;
lld ans;
int eu[maxm],ev[maxm],next[maxm],rev[maxm],nbs[maxn],num;
lld ew[maxm];
int low[maxn],d[maxn],mk[maxn],color,ti;
int lck[maxn],bri[maxm],bu[maxn],bv[maxn],sta[maxn];
lld a[maxn],bw[maxn],f[maxn][STA];
int que[maxn],c[maxn],head,tail;

int min(const int &i,const int &j){ return i<j?i:j; }
int max(const int &i,const int &j){ return i>j?i:j; }

lld min(const lld &i,const lld &j){ return i<j?i:j; }
lld max(const lld &i,const lld &j){ return i>j?i:j; }

/*char ch,cstr[LEN];

int readsigned(){
	int ret,neg;

	do{
		ch = getchar() ;
	}while(ch!='-' && ch<'0');
        
	if ( ch == '-' ){
		neg = 1 ;
                ret = 0 ;
	}else{
		neg=0;
		ret = ch - '0' ;
	}
	while((ch = getchar()) >= '0'){
		ret = ret * 10 + ch - '0' ;
	}
	if (neg)return -ret;
	return ret;
}

void putunsigned(const int &x){
	int k=x,r=0;

	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	while(r--){
		putchar(cstr[r]);
	}
	putchar('\n');
}*/



void AddEdge(int u,int v,const lld &w){
	if(u>v)swap(u,v);
	
	e=Edge(u,v);it=m.find(e);
	
	if(it!=m.end()){
		ew[(*it).second  ]+=w;
		ew[(*it).second+1]+=w;
		return;
	}

	eu[++num]=u;ev[num]=v;ew[num]=w;next[num]=nbs[u];nbs[u]=num;rev[num]=0;
	m.insert(pair<Edge,int>(e,num));
	eu[++num]=v;ev[num]=u;ew[num]=w;next[num]=nbs[v];nbs[v]=num;rev[num]=1;
}

void TarjanBridge(const int &u,const int &p){
	int i,v,s=0;low[u]=d[u]=++ti;mk[u]=-color;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(v==p)continue;
		if(!mk[v]){TarjanBridge(v,u);s++;
			low[u]=min(low[u],low[v]);
			if(low[v]==d[v]){
				bri[i-rev[i]]=1;
			}
		}else low[u]=min(low[u],d[v]);
	}
	mk[u]=color;
}

void MarkBridge(){
	memset(mk,0,sizeof(mk));
	memset(bri,0,sizeof(bri));
	color=ti=0;
	for(int i=1;i<=n;i++)if(!mk[i]){ ++color;TarjanBridge(i,0); }
}

void work(){
	int i,j,k;
	int u,v;
	lld w,tmp;
	
	m.clear();
	memset(nbs,0,sizeof(nbs));num=0;

	for(u=1;u<=n;u++){
		scanf("%lld%lld%d",&a[u],&w,&v);
		/*a[u]=readsigned();
		w=readsigned();
		v=readsigned();*/
		AddEdge(u,v,w);
	}
	MarkBridge();
	
	memset(bu,0   ,sizeof(bu));
	//for(i=1;i<=n;i++)bw[i]=inf;
	for(i=1;i<=num;i++){if(rev[i] || bri[i])continue;
		if(!bu[eu[i]] || bv[eu[i]]>ev[i]){
			bv[eu[i]]=ev[i];
			bw[eu[i]]=ew[i];
		}bu[eu[i]]=1;
	}
	
	ans=0LL;
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	memset(mk,0,sizeof(mk));
	memset(lck,0,sizeof(lck));

	//firDP
	for(k=1;k<=n;k++){if(c[k] || !bu[k])continue;

		//printf("firDP for %d, bv=%d bw=%d\n",k,bv[k],bw[k]);

		tail=0;que[++tail]=k;mk[k]=1;
		for(head=1;head<=tail;head++){u=que[head];
			for(i=nbs[u];i;i=next[i]){v=ev[i];if(mk[v])continue;
				if(u==k && v==bv[k])continue;
				que[++tail]=v;mk[v]=1;
			}
		}

		lck[bv[k]]=1;
		for(sta[bv[k]]=0;sta[bv[k]]<2;sta[bv[k]]++){

			//printf("	sta[%d]=%d\n",bv[k],sta[bv[k]]);

			for(head=tail;head;head--){u=que[head];
				for(j=0;j<2;j++){if(lck[u] && sta[u]!=j)continue;
					f[u][j]=j?a[u]:0LL;
					for(i=nbs[u];i;i=next[i]){v=ev[i];if(!c[v])continue;
						if(u==k && v==bv[k])continue;
						if(lck[v]){
							f[u][j]+=f[v][sta[v]];
							if(sta[v]&j)f[u][j]+=ew[i];
							continue;
						}
						f[u][j]+=max(f[v][0],f[v][1]+((j)?ew[i]:0LL));
					}
					
					//printf("		f[%d][%d]=%d\n",u,j,f[u][j]);

				}
				c[u]=1;
			}
			if(!sta[bv[k]]){

				//printf(" !sta[%d]. f[%d][0]=%d f[%d][1]=%d\n",bv[k],k,f[k][0],k,f[k][1]);

				tmp=max(f[k][0],f[k][1]);
				for(head=1;head<=tail;head++)c[que[head]]=0;
			}
		}
		ans+=max(tmp,max(f[k][0],f[k][1]+bw[k]));
	}
	//secDP
	for(k=1;k<=n;k++){if(c[k])continue;
		tail=0;que[++tail]=k;mk[k]=1;
		for(head=1;head<=tail;head++){u=que[head];
			for(i=nbs[u];i;i=next[i]){v=ev[i];if(mk[v])continue;
				que[++tail]=v;mk[v]=1;
			}
		}
		for(head=tail;head;head--){u=que[head];
			for(j=0;j<2;j++){
				f[u][j]=j?a[u]:0LL;
				for(i=nbs[u];i;i=next[i]){v=ev[i];if(!c[v])continue;
					f[u][j]+=max(f[v][0],f[v][1]+((j)?ew[i]:0LL));
				}
				
				//printf("f[%d][%d]=%d\n",u,j,f[u][j]);

			}
			c[u]=1;
		}
		
		//printf(" secDP f[%d][0]=%d f[%d][1]=%d\n",k,f[k][0],k,f[k][1]);

		ans+=max(f[k][0],f[k][1]);
	}

	printf("%lld\n",ans);
	//putunsigned(ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

