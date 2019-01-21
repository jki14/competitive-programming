#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define n 8
#define cp p[5]

const double eps=1e-4;

struct TPoint { int x,y,z; };

TPoint bc;
int br,v6,s2,h;
TPoint a[n];
TPoint p[n];
bool res;

int Volume6(TPoint a,TPoint b,TPoint c,TPoint d){
	int vol,bdx,bdy,bdz,cdx,cdy,cdz;
	bdx = b.x-d.x; bdy = b.y-d.y; bdz = b.z-d.z;
	cdx = c.x-d.x; cdy = c.y-d.y; cdz = c.z-d.z;
	vol = (a.z-d.z) * (bdx *cdy -bdy *cdx)
		 +(a.y-d.y) * (bdz *cdx -bdx *cdz)
		 +(a.x-d.x) * (bdy *cdz -bdz *cdy);
	return abs(vol);
}

int Area2(TPoint a,TPoint b,TPoint c){
	return abs(a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x);
}

int dcmp(double x){
	if(x<-eps)return -1;
	return x>eps;
}

double cross(TPoint p0,TPoint p1,TPoint p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dot(TPoint p0,TPoint p1,TPoint p2){
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

int pons(TPoint p0,TPoint p1,TPoint p2){
	return dcmp(cross(p0,p1,p2))==0 && dcmp(dot(p0,p1,p2))<=0;
}

bool pinp(){
	int i,k,d1,d2,wn=0;
	p[0]=p[4];
	for(i=0;i<4;i++){
		if(pons(p[i],p[i+1],cp))return true;
		k = dcmp( cross(p[i],p[i+1],cp) );
		d1 = dcmp( p[i+0].y - cp.y);
		d2 = dcmp( p[i+1].y - cp.y);
		if(k>0 && d1<=0 && d2>=0)wn++;
		if(k<0 && d2<=0 && d1>=0)wn--;
	}
	return wn!=0;
}

bool pins(TPoint a,TPoint b,TPoint c,TPoint d){
	int minx=LONG_MAX,maxx=LONG_MIN,miny=LONG_MAX,maxy=LONG_MIN,minz=LONG_MAX,maxz=LONG_MIN;
	if(minx>a.x)minx=a.x;if(minx>b.x)minx=b.x;if(minx>c.x)minx=c.x;if(minx>d.x)minx=d.x;
	if(miny>a.y)miny=a.y;if(miny>b.y)miny=b.y;if(miny>c.y)miny=c.y;if(miny>d.y)miny=d.y;
	if(minz>a.z)minz=a.z;if(minz>b.z)minz=b.z;if(minz>c.z)minz=c.z;if(minz>d.z)minz=d.z;
	if(maxx<a.x)maxx=a.x;if(maxx<b.x)maxx=b.x;if(maxx<c.x)maxx=c.x;if(maxx<d.x)maxx=d.x;
	if(maxy<a.y)maxy=a.y;if(maxy<b.y)maxy=b.y;if(maxy<c.y)maxy=c.y;if(maxy<d.y)maxy=d.y;
	if(maxz<a.z)maxz=a.z;if(maxz<b.z)maxz=b.z;if(maxz<c.z)maxz=c.z;if(maxz<d.z)maxz=d.z;
	if(minx==maxx){
		p[5].x=bc.y;p[5].y=bc.z;
		p[1].x=miny;p[1].y=minz;
		p[2].x=miny;p[2].y=maxz;
		p[3].x=maxy;p[3].y=maxz;
		p[4].x=maxy;p[4].y=minz;
	}else if(miny==maxy){
		p[5].x=bc.x;p[5].y=bc.z;
		p[1].x=minx;p[1].y=minz;
		p[2].x=minx;p[2].y=maxz;
		p[3].x=maxx;p[3].y=maxz;
		p[4].x=maxx;p[4].y=minz;
	}
	else if(minz==maxz){
		p[5].x=bc.x;p[5].y=bc.y;
		p[1].x=minx;p[1].y=miny;
		p[2].x=minx;p[2].y=maxy;
		p[3].x=maxx;p[3].y=maxy;
		p[4].x=maxx;p[4].y=miny;
	}
	return pinp();
}

void doit(){
	int i,j,k,l;res=false;
	for(i=0;i<n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	scanf("%d%d%d%d",&bc.x,&bc.y,&bc.z,&br);
	//cout<<":::Br:"<<br<<endl;
	for(i=0;i<n;i++)for(j=i+1;j<n;j++)for(k=j+1;k<n;k++)for(l=k+1;l<n;l++)
		if((a[i].x==a[j].x && a[j].x==a[k].x && a[k].x==a[l].x)
					||(a[i].y==a[j].y && a[j].y==a[k].y && a[k].y==a[l].y)
					||(a[i].z==a[j].z && a[j].z==a[k].z && a[k].z==a[l].z)){
				v6=Volume6(a[i],a[j],a[k],bc);
				s2=Area2(a[i],a[j],a[k]);
				//cout<<"V6="<<v6<<" S2="<<s2<<endl;
				if(!v6){
					if(br && pins(a[i],a[j],a[k],a[l]))res=true;
				}else{
					if(s2*br>v6)res=true;
				}
			}
	if(res)
		printf("Yes\n");
	else
		printf("No\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
