#

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 51000

struct SPoint{
	double x,y;
};

typedef struct SPoint TPoint;

const double eps=1e-8;
const double pi=acos(-1.0);

int n,m;
TPoint pin[maxn],ch[maxn];
TPoint bp;

double sqr(const double &x){ return x*x; }

int dcmp(const double &x){
	if(x<-eps)return -1;
	return (x>eps);
}

double cross(const TPoint &p0,const TPoint &p1,const TPoint &p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dis(const TPoint &p1,const TPoint &p2){
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

double dis2(const TPoint &p1,const TPoint &p2){
	return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}

int PointEqual(const TPoint &p1,const TPoint &p2){
	return dcmp(p1.x-p2.x)==0 && dcmp(p1.y-p2.y)==0;
}

int PolarCmp(const TPoint &p1,const TPoint &p2){
	int u=dcmp(cross(bp,p1,p2));
	return u>0 || (u==0 && dcmp(dis2(bp,p1)-dis2(bp,p2))<0);
}

void GrahamScan(){
	int i,j,k,u,v;
	memcpy(ch,pin,sizeof(pin));
	for(i=k=0;i<n;i++){
		u=dcmp(ch[i].x-ch[k].x);
		v=dcmp(ch[i].y-ch[k].y);
		if(v<0 || (v==0 && u<v))k=i;
	}
	bp=ch[k];
	sort(ch,ch+n,PolarCmp);
	n=unique(ch,ch+n,PointEqual)-ch;
	if(n<=1){ m=n;return; }
	if(dcmp(cross(ch[0],ch[1],ch[n-1]))==0){
		m=2;ch[1]=ch[n-1];
		return;
	}
	ch[n++]=ch[0];
	for(i=1,j=2;j<n;j++){
		while(i>0 && dcmp(cross(ch[i-1],ch[i],ch[j]))<=0)i--;
		ch[++i]=ch[j];
	}
	m=i;
}

double Diameter(){
	if(m<=1)return 0.0;
	if(m==2)return dis2(ch[0],ch[1]);
	int u,nu,v,nv,k;
	double ret=0.0;
	for(u=0,v=1;u<m;u=nu){
		nu=u+1;
		while(1){
			nv=(v+1)%m;
			k=dcmp((ch[nu].x-ch[u].x)*(ch[nv].y-ch[v].y)
					-(ch[nv].x-ch[v].x)*(ch[nu].y-ch[u].y));
			if(k<=0)break;
			v=nv;
		}
		ret=max(ret,dis2(ch[u],ch[v]));
		if(k==0)ret=max(ret,dis2(ch[u],ch[nv]));
	}
	return ret;
}

void work(){
	int i;
	for(i=0;i<n;i++)scanf("%lf%lf",&pin[i].x,&pin[i].y);
	GrahamScan();
	printf("%.2lf\n",Diameter());
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;

}
