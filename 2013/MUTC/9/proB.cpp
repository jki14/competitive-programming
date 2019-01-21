#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define N 110
#define M 1100
#define S 1100

int n,m,src[M],dst[M];
int match[N],ans;

const int MAXN = 100;
struct Edge {
	int from, to;
	Edge * next;
} *head[MAXN],EdgePool[S],*cur;

int aug(int n, Edge * list[], int * match, int * v, int now) {
	int t, ret = 0;
	Edge * e;
	v[now] = 1;
	for (e = list[now]; e; e = e->next) {
		if (!v[t = e->to]) {
			if (match[t] < 0) {
				match[now] = t;
				match[t] = now;
				ret = 1;
			} else {
				v[t] = 1;
				if (aug(n, list, match, v, match[t])) {
					match[now] = t;
					match[t] = now;
					ret = 1;
				}
			}
			if (ret) {
			break;
			}
		}
	}
	v[now] = 0;
	return ret;
}

int graphMatch(int n, Edge * list[], int * match) {
	int v[MAXN], i, j;
	for (i = 0; i < n; i++) {
		v[i] = 0, match[i] =- 1;
	}
	for (i = 0, j = n; i < n && j >= 2;) {
		if (match[i] < 0 && aug(n, list, match, v, i)) {
			memset(v, 0, sizeof(v));
			i = 0;
			j -= 2;
		} else {
			i++;
		}
	}
	for (i = j = 0; i < n; i++) {
		j += (match[i] >= 0);
	}
	return j / 2;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)head[i]=0;cur=EdgePool;
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);u--;v--;
			cur->from=u;cur->to=v;cur->next=head[u];head[u]=cur++;
			src[i]=u;dst[i]=v;
		}
		graphMatch(n,head,match);
		ans=0;
		for(int i=0;i<m;i++)if(match[src[i]]!=dst[i])ans++;
		printf("%d\n",ans);int fir=1;
		for(int i=0;i<m;i++){
			if(match[src[i]]==dst[i])continue;
			if(!fir)printf(" ");fir=0;
			printf("%d",i+1);
		}printf("\n");
	}
	return 0;
}

