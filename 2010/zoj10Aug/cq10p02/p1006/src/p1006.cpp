#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define left st[st[i].l]
#define right st[st[i].r]

const int maxn=410000,maxt=4,maxp=210000;

struct item
{
	int x,y,k,p;
};

struct segTree
{
	int x,y,k,l,r,s;
};

segTree st[maxp];
int x[maxt],y[maxt];
int n,m,miny,maxy;
long long ans;
item a[maxn];

void sTgetsum(const int &i)
{
	if(st[i].k)
		st[i].s=st[i].y-st[i].x+1;
	else
		st[i].s=(st[i].l)?left.s+right.s:0;
}

void sTupdate(const int &i,const int &x,const int &y,const int &k)
{
	if((st[i].y<x)||(st[i].x>y))return;
	if((x<=st[i].x)&&(y>=st[i].y))
		st[i].k+=k;
	else
	{
		if(st[i].l==0)
		{
			st[i].l=i<<1;
			left.x=st[i].x;
			left.y=(st[i].x+st[i].y)>>1;
			left.k=0;left.s=0;
			st[i].r=(i<<1)+1;
			right.x=((st[i].x+st[i].y)>>1)+1;
			right.y=st[i].y;
			right.k=0;right.s=0;
		}
		sTupdate(st[i].l,x,y,k);
		sTupdate(st[i].r,x,y,k);
	}
	sTgetsum(i);
}

void init(int x1,int y1,int x2,int y2)
{
	if((x[x1]>=x[x2])||(y[y1]>=y[y2]))return;
	if(y[y1]+1<miny)miny=y[y1]+1;
	if(y[y2]>maxy)maxy=y[y2];
	a[n].x=y[y1]+1;a[n].y=y[y2];a[n].k=1;a[n++].p=x[x1];
	a[n].x=y[y1]+1;a[n].y=y[y2];a[n].k=-1;a[n++].p=x[x2];
}

void itemsort(const int &l,const int &r)
{
	int i=l,j=r;
	item mid=a[(l+r)>>1],t;
	do
	{
		while(a[i].p<mid.p)i++;
		while(a[j].p>mid.p)j--;
		if(i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	while(i<=j);
	if(i<r)itemsort(i,r);
	if(l<j)itemsort(l,j);
}

bool doit()
{
	scanf("%d",&m);
	if(!m)return false;
	int i,p;
	ans=0;n=0;
	miny=LONG_MAX;
	maxy=LONG_MIN;
	while(m--)
	{
		for(i=0;i<maxt;i++)
			scanf("%d %d",&x[i],&y[i]);
		init(0,0,2,3);
		init(0,3,3,1);
		init(3,2,1,1);
		init(2,0,1,2);
	}
	itemsort(0,n-1);
	memset(st,0,sizeof(st));
	st[1].x=miny;
	st[1].y=maxy;
	p=a[0].p;
	for(i=0;i<n;i++)
	{
		if(a[i].p>p)
		{
			ans+=(long long)st[1].s*(long long)(a[i].p-p);
			p=a[i].p;
		}
		sTupdate(1,a[i].x,a[i].y,a[i].k);
	}
	printf("%I64d\n",ans);
	return true;
}

int main()
{
	while(doit());
	return 0;
}
