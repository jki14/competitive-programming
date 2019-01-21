#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

#define N 110000
#define M 210000

const int inf=0x3f3f3f3f;

int n, m, ans;
int nbs[N], nxt[M], dst[M], enm;
int que[N], vst[N], mrk[N], cnt[N], stt[N], msk;
int buf_x[N], buf_y[N], buf_z[N], idx[N], til;
//vector<pii> a[N];
int hea[N], nex[N], fir[N], sec[N], rig;

void add_edge(const int u, const int v){
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;
}

inline int buf_cmp(const int x, const int y){ return buf_z[x]<buf_z[y]; }

void call(const int u){
	til=0;msk++;
	vst[0]=msk;cnt[0]=0;
	stt[u]=0;mrk[u]=msk;
	//for(vector<pii>::iterator it=a[u].begin();it!=a[u].end();it++){
	for(int k=hea[u];k;k=nex[k]){
		buf_x[til]=u;
		buf_y[til]=sec[k];
		buf_z[til]=fir[k];
		idx[til]=til;
		til++;
	}
	for(int i=nbs[u];i;i=nxt[i]){
		int v=dst[i];
		//for(vector<pii>::iterator it=a[v].begin();it!=a[v].end();it++){
		for(int k=hea[v];k;k=nex[k]){
			buf_x[til]=v;
			buf_y[til]=sec[k];
			buf_z[til]=fir[k];
			idx[til]=til;
			til++;
		}
		cnt[0]++;
	}
	sort(idx,idx+til,buf_cmp);
	for(int k=0;k<til;k++){
		int i=idx[k];
		int x=buf_x[i];
		int y=buf_y[i];
		int z=buf_z[i];
		int f=(mrk[x]==msk)?stt[x]:0;
		mrk[x]=msk;stt[x]=y;
		if(vst[y]!=msk){vst[y]=msk;cnt[y]=0;}
		if(x==u){
			que[z]+=cnt[f];
			que[z]-=cnt[y];
		}else{
			cnt[f]--;cnt[y]++;
			if(f==stt[u])que[z]++;
			if(y==stt[u])que[z]--;
		}
	}
}

int main(){
	memset(vst,0,sizeof(vst));
	memset(mrk,0,sizeof(mrk));
	msk=0;
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		printf("Case #%d:\n",_T);
		scanf("%d",&n);
		//memset(nbs,0,sizeof(nbs));enm=0;
		for(int i=0;i<n;i++)nbs[i]=0;enm=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			add_edge(u,v);
		}
		//for(int i=0;i<n;i++)a[i].clear();
		//memset(hea,0,sizeof(hea));rig=0;
		for(int i=0;i<n;i++)hea[i]=0;rig=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int k;scanf("%d",&k);
			if(k==1){
				que[i]=inf;
			}else{
				que[i]=0;
				int x,y;
				scanf("%d%d",&x,&y);
				x--;
				//a[x].push_back(MP(i,y));
				nex[++rig]=hea[x];hea[x]=rig;fir[rig]=i;sec[rig]=y;
			}
		}
		for(int i=0;i<n;i++)call(i);
		ans=1;
		for(int i=0;i<m;i++){
			if(que[i]==inf){
				printf("%d\n", ans);
			}else{
				//printf("que[%d]=%d\n",i,que[i]);
				ans+=que[i]/2;
			}
		}
	}
	return 0;
}

