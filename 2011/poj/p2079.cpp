#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

struct SPoint{
	double x,y;
};

typedef struct SPoint TPoint;

#define maxn 51000

const double eps=1e-4;
const double pi=-acos(-1.0);

int n,m;
TPoint pin[maxn],ch[maxn];
TPoint bp;
double res;

double sqr(const double &x){ return x*x; }

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
	return fabs(p1.x-p2.x)<eps && fabs(p1.y-p2.y)<eps;
}

int PolarCmp(const TPoint &p1,const TPoint &p2){
	double crs=cross(bp,p1,p2);
	return crs>eps || ( crs>-eps && dis2(bp,p1)+eps<dis2(bp,p2) );
}

void GrahamScan(){
	int i,j,k;
	memcpy(ch,pin,sizeof(pin));
	for(i=k=0;i<n;i++){
		if(ch[i].y+eps<ch[k].y ||
			(fabs(ch[i].y-ch[k].y)<eps && ch[i].x+eps<ch[k].x ))
			k=i;
	}
	bp=ch[k];
	sort(ch,ch+n,PolarCmp);
	n=unique(ch,ch+n,PointEqual)-ch;
	if(n<=1){ m=n;return; }
	if(fabs(cross(ch[0],ch[1],ch[n-1]))<eps){
		m=2;ch[1]=ch[n-1];return;
	}
	ch[n++]=ch[0];
	for(i=1,j=2;j<n;j++){
		while(i>0 && cross(ch[i-1],ch[i],ch[j])<eps)i--;
		ch[++i]=ch[j];
	}
	m=i;
}

double Area(const TPoint &p0,const TPoint &p1,const TPoint &p2){
	return fabs(p0.x*p1.y+p1.x*p2.y+p2.x*p0.y
		-p0.y*p1.x-p1.y*p2.x-p2.y*p0.x)*0.5;
}

void work(){
	int i,j,k;
	for(i=0;i<n;i++)scanf("%lf%lf",&pin[i].x,&pin[i].y);
	GrahamScan();ch[m]=ch[0];res=0.0;
	for(i=0;i<m;i++){
		j=(i+1)%m;
		k=(j+1)%m;
		while(i!=k){
			for(;k!=i;k=(k+1)%m){
				if(Area(ch[i],ch[j],ch[k])+eps>Area(ch[i],ch[j],ch[k+1]))break;
			}
			//cout<<"k="<<k<<endl;
			if(k==i)break;
			//printf("T: %d %d %d\n",i,j,k);
			res=max(res,Area(ch[i],ch[j],ch[k]));
			j=(j+1)%m;if(j==i)break;
			if(j==k)k++;
		}
	}
	printf("%.2f\n",res);
}

int main(){
	while(scanf("%d",&n)!=EOF && n!=-1)
		work();
	return 0;
}

