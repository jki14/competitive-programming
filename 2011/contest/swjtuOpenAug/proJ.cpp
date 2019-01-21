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

struct node { int d, next; };
#define N 2510
#define M 60
int a[M][M], rd[N], ld[N], ati[N], pr[N], trans[M][M];
node w[N*15];
bool vst[N];
int n, m, tot, rc;
const int dr[12] = { -1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 1, 0 };
const int dc[12] = { -2, -1, 1, 2, 2, 1, -1, -2, 0, 1, 0, -1 };

void input()
{
	int i, j;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) scanf("%d", &a[i][j]);
}

bool dfs(int x)
{
	/*int i;
	if (ati[x] == -1) return true;
	for (i = w[pr[ati[x]]].next; i; i = w[i].next) 
		if (vst[w[i].d] && dfs(w[i].d)) {
			ati[w[i].d] = ati[x]; pr[ati[x]] = i; return true;
		} else vst[w[i].d] = false;
	return false;*/
	vst[x]=1;
	for(int i=ld[x];i;i=w[i].next){int v=w[i].d;
		if(vst[v])continue;
		vst[v]=1;
		if(ati[v]==-1 || dfs(ati[v])){
			ati[v]=x;
			return 1;
		}
	}
	return 0;
}

void conduct(int time)
{
	int i, j, k, tr, tc, s, t, ans;
	tot = n * m;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) trans[i][j] = i*m + j;
	memset(ld, 0, sizeof(ld)); rc = 0;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j)
	{
		if (a[i][j] == -1) continue;
		for (k = 0; k < 12; ++k) if (a[i][j] & (1 << k)) {
			tr = i + dr[k]; tc = j + dc[k];
			if (tr < 0 || tr >= n || tc < 0 || tc >= m || a[tr][tc] == -1) continue;
			s = trans[i][j]; t = trans[tr][tc];
			if (((i+j)%2)) {
				rc++; w[rc].d = s; w[rc].next = ld[t]; ld[t] = rc;
			} else {
				rc++; w[rc].d = t; w[rc].next = ld[s]; ld[s] = rc;
			}
		}
	}
	/*for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) if ((i+j) %2) {
		printf("line %d: ", trans[i][j]);
		for (k = ld[trans[i][j]]; k; k = w[k].next) printf("%d ", w[k].d);
		printf("\n");
	} */
	/*memset(pr, 0, sizeof(pr)); memset(ati, -1, sizeof(ati));*/ //memset(vst, -1, sizeof(vst));
	/*for (ans = i = 0; i < tot; ++i) 
		for (pr[i] = ld[i]; pr[i]; pr[i] = w[pr[i]].next) 
			if (vst[w[pr[i]].d] && dfs(w[pr[i]].d)) { ati[w[pr[i]].d] = i; ans++; break;}
			else vst[w[pr[i]].d] = 0;*/
	memset(ati,-1,sizeof(ati));
	for(ans=i=0;i<tot;i++){
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
	}
	printf("%d. %d\n", time, ans);
}

int main()
{
	int time = 0;
	while (scanf("%d%d", &n, &m) != EOF && (n || m)) {
		input(); conduct(++time);
	}
	return 0;
}
