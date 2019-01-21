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

#define getmax(x, y) (x)>(y)?(x):(y)
struct node { int d, next; };
#define N 1000010
int fst[N], snd[N], rd[N], seq[N], pre[N], wn[N];
node wy[N];
bool vst[N], done, s[N];
int n, m, est, wst, cut, np, rc;

void input()
{
	int i, v, u;
	memset(rd, 0, sizeof(rd)); rc = 0;
	for (i = 0; i < m; ++i) {
		scanf("%d%d", &v, &u);
		rc++; wy[rc].d = u; wy[rc].next = rd[v]; rd[v] = rc;
		rc++; wy[rc].d = v; wy[rc].next = rd[u]; rd[u] = rc;
	}
	scanf("%d", &np); memset(s, 0, sizeof(s));
	for (i = 0; i < np; ++i) { scanf("%d", &v); s[v] = true; }
}

void conduct()
{
	int i, head, tail, u, v;
	int ans,deb=0;
	memset(vst, 0, sizeof(vst)); memset(pre, 0, sizeof(pre)); cut = 0; done = false;pre[1]=0;
	for (vst[seq[head = tail = 0] = 1]=true; head <= tail; ++head) {
		if (!done && n-seq[head]<wst) { cut = seq[head]; done = true; } 
		if(n-seq[head]<wst)deb++;
		for (i = rd[seq[head]]; i; i = wy[i].next) if (!vst[wy[i].d]) {
			vst[wy[i].d] = true; pre[wy[i].d] = seq[head]; seq[++tail] = wy[i].d;
		}
	}
	//if(deb!=wst){ while(1)printf("\n"); }
	memset(wn, 0, sizeof(wn));
	for (i = tail; i >= 0; --i){
	       	wn[pre[seq[i]]] += wn[seq[i]] + (n-seq[i] < wst ? 1 : 0);
	}
	for (; wn[cut] != deb; cut = pre[cut])if(!cut)cut=0/0;
	memset(vst, 0, sizeof(vst)); fst[0] = snd[0] = 0; vst[cut] = true; pre[cut] = 0;
	for (seq[head = tail = 0] = cut; head <= tail; ++head) {
		v = seq[head]; if (s[v]) fst[++fst[0]] = pre[v]; if (n-v<wst) snd[++snd[0]] = pre[v];
		for (i = rd[v]; i; i = wy[i].next) if (!vst[wy[i].d]) {
			vst[wy[i].d] = true; pre[wy[i].d] = pre[v]+1; seq[++tail] = wy[i].d;
		}
	}
	std::sort(fst+1, fst+np+1); std::sort(snd+1, snd+snd[0]+1);
	for (i = 2; i <= np; ++i) if (fst[i] <= fst[i-1]) fst[i] = fst[i-1] + 1;
        ans = 0; for (i = 1; i <= np; ++i) ans = getmax(ans, snd[np-i+1] + fst[i]);
	printf("%d\n", ans);
}	

int main()
{
	while (scanf("%d%d%d%d", &n, &m, &est, &wst) != EOF) {
		if(m!=n-1)break;
		input();
		conduct();
	}
	return 0;
}
