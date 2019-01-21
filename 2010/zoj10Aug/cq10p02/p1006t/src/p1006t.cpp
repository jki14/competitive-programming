// HDU 3265 Posters
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;
#define N 300000

typedef long long LL;

struct EVENT {
#define IN 1
#define OUT -1
    int x, y1, y2, type;
    EVENT() {
    }
    EVENT(int x, int y1, int y2, int type) :
        x(x), y1(y1), y2(y2), type(type) {
    }
    bool operator <(const EVENT &e) const {
        return x < e.x;
    }
};

struct segTree
{
	int x,y;
	int k;
	struct segTree *left,*right;
	segTree()
	{
		k=0;
		left=NULL;
		right=NULL;
	}
};

segTree *st,*newNode;
EVENT E[N];
int n;

void sTupdate(segTree *a,const int &x,const int &y,const int &k)
{
	if((a->y<x)||(a->x>y))return;
	if((x<=a->x)&&(y>=a->y)&&(a->left==NULL))
	{
		a->k+=k;
		return;
	}
	if(a->left==NULL)
	{
		newNode=new segTree;
		newNode->x=a->x;
		newNode->y=(a->x+a->y)>>1;
		newNode->k=a->k;
		a->left=newNode;
		newNode=new segTree;
		newNode->x=((a->x+a->y)>>1)+1;
		newNode->y=a->y;
		newNode->k=a->k;
		a->right=newNode;
	}
	sTupdate(a->left,x,y,k);
	sTupdate(a->right,x,y,k);
}

int sTsum(segTree *a)
{
	if(a->left==NULL)
		return (a->y-a->x+1)*((a->k>0)?1:0);
	return sTsum(a->left)+sTsum(a->right);
}

void solve() {
    int i, cnt = 0, maxy = 0;
    LL ans = 0;
    for (i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        maxy = max(maxy, y2);
        if (x1 != x3 && y1 != y2) E[cnt++] = EVENT(x1, y1+1, y2, IN), E[cnt++] = EVENT(x3, y1+1, y2, OUT);
        if (x3 != x4 && y1 != y3) E[cnt++] = EVENT(x3, y1+1, y3, IN), E[cnt++] = EVENT(x4, y1+1, y3, OUT);
        if (x3 != x4 && y2 != y4) E[cnt++] = EVENT(x3, y4+1, y2, IN), E[cnt++] = EVENT(x4, y4+1, y2, OUT);
        if (x4 != x2 && y1 != y2) E[cnt++] = EVENT(x4, y1+1, y2, IN), E[cnt++] = EVENT(x2, y1+1, y2, OUT);
    }
    sort(E, E + cnt);
    st=NULL;
    newNode=new segTree;
    newNode->x=0;
    newNode->y=maxy;
    st=newNode;
    sTupdate(st,E[0].y1,E[0].y2,E[0].type);
    for (i = 1; i < cnt; i++) {
        LL dx = E[i].x - E[i - 1].x;
        if(dx)ans += dx * sTsum(st);
        sTupdate(st,E[i].y1,E[i].y2,E[i].type);
    }
    printf("%I64d\n", ans);
}
int main() {
    //    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) && n)
        solve();
    return 0;
}
