#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

#define hea 1
#define tai gir+gem+2

#define girb gem+1
#define gemb 1

#define maxn 21000
#define maxm 1100000
#define eps 0

typedef long long lld;

const lld inf=1LL<<60;

struct node {
    int next, other;
	lld c,f;
}a;

vector<node>map[maxn];
vector<int>lever_map[maxn];
int que[maxn], lever[maxn], pre[maxn], hash[maxn];
lld d[maxn];
int n,m,i,j;

int timer;

int gir,gem;

lld minn(lld x,lld y){return x<(y-eps)?x:y;}

void AddEdge(int u, int v, lld c) {
    a.next = v; a.c = c; a.other = map[v].size();a.f = 0;
    map[u].push_back(a);
    a.next = u; a.c = 0; a.other = map[u].size()-1;a.f = 0;
    map[v].push_back(a);
}

bool bulid(int s,int t) {
    int head = 0, tail = 0, cur, i;
    for(i = s; i <= t; i++) lever_map[i].clear();
    memset(lever, -1, sizeof(lever));
    que[tail++] = s;
    lever[s] = 0;
    while(head < tail) {
        cur = que[head++];
        for(i = 0; i < (int)map[cur].size();i++) {
            a= map[cur][i];
            if(a.c > a.f+eps) {
                if(lever[a.next] == -1){
                	que[tail++] = a.next;
                	lever[a.next] = lever[cur] + 1;
                }
                if(lever[a.next] == lever[cur] + 1) {
                	lever_map[cur].push_back(i);
            	}
            }
        }
    }
    return lever[t]!=-1;
}

lld Dinic(int s,int t) {
    int i, j , len;
	lld ans=0,tmp;
    while(bulid(s,t)) {
        memset(hash, 0, sizeof(hash));
        while(!hash[s]) {
            d[s] = inf;
            pre[s] = -1;
            for(i = s ; i!= t && i!= -1; i = j) {
                len = lever_map[i].size();
                while(len && hash[map[i][lever_map[i][len-1]].next])
                { lever_map[i].pop_back();len--;}
                if(!len) {
                    hash[i] = 1;
                    j = pre[i];
                    continue;
                }
                j = map[i][lever_map[i][len-1]].next;
                pre[j] = i;
                d[j] = minn(d[i], map[i][lever_map[i][len - 1]].c - map[i][lever_map[i][len-1]].f);
            }
            if(i == t) {
                ans += d[t];
                tmp = d[t];
                while(i != s) {
                    j = pre[i];
                    len = lever_map[j][lever_map[j].size()-1];
                    map[j][len].f += tmp;
                    if(map[j][len].f == map[j][len].c)
                        lever_map[j].pop_back();
                    map[i][map[j][len].other].f -= tmp;
                    i = j;
                }
            }
        }
    }
    return ans;
}

void work(){
	int i,v,k;
	for(i=hea;i<=tai;i++)map[i].clear();
	lld flowmax,total=0,ans;
	scanf("%d%d",&gir,&gem);
	for(i=1;i<=gir;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&v);
			AddEdge(gemb+v,girb+i,inf);
		}
		scanf("%d",&v);AddEdge(girb+i,tai,(lld)v);total+=(lld)v;
	}
	for(i=1;i<=gem;i++){
		scanf("%d",&v);AddEdge(hea,gemb+i,(lld)v);
	}
	flowmax=Dinic(hea,tai);
	//cout<<"Total="<<total<<"  MaxFlow="<<flowmax<<endl;
	ans=total-flowmax;
	printf("Case %d: %lld\n",timer,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(timer=1;timer<=t;timer++)
		work();
	return 0;
}

