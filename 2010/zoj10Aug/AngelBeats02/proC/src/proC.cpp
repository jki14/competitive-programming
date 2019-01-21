#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxl 60
#define maxd 1100000

struct point{
	int x,y,z;
	point(){ }
	point(int v0,int v1,int v2){
		x=v0;y=v1;z=v2;
	}
	bool operator != (const point v0) const {
		return (v0.x!=x || v0.y!=y || v0.z!=z);
	}
	bool operator <  (const point v0) const {
		if(v0.x!=x)return v0.x<x;
		if(v0.y!=y)return v0.y<y;
		return v0.z<z;
	}
};

point s[maxd];
map<char,int> axis;

int n,m,k0,k1,tot,res;
char str[maxl],c0,c1;

void eli(int x,int y,int z){
	int sx,sy,sz,tx,ty,tz;
	sx=tx=x;sy=ty=y;sz=tz=z;
	if(!x){ sx=1;tx=n; }
	if(!y){ sy=1;ty=n; }
	if(!z){ sz=1;tz=n; }
	for(x=sx;x<=tx;x++)
		for(y=sy;y<=ty;y++)
			for(z=sz;z<=tz;z++){
				//s.insert(pair<point,int>(point(x,y,z),0));
				//cout<<"insert "<<x<<","<<y<<","<<z<<endl;
				s[tot++]=point(x,y,z);
			}
}

void work(){
	axis.clear();tot=1;
	s[0]=point(0,0,0);
	for(int i=0;i<m;i++){
		axis['X']=0;axis['Y']=0;axis['Z']=0;
		scanf("%s",str);sscanf(str,"%c=%d,%c=%d",&c0,&k0,&c1,&k1);
		//cout<<c0<<" = "<<k0<<" "<<c1<<" = "<<k1<<endl;
		if(k0<1 || k0>n || k1<1 || k1>n)continue;
		axis[c0]=k0;axis[c1]=k1;
		eli(axis['X'],axis['Y'],axis['Z']);
	}
	sort(s,s+tot);res=0;
	for(int i=1;i<tot;i++){
		if(s[i]!=s[i-1])res++;
	}
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		work();
	}
	return 0;
}
