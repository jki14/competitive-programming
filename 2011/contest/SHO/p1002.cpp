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

struct TB{
	int x,y;
};

typedef struct TB tarb;

struct XComp{
	bool operator() (const tarb &a,const tarb &b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	}
};

struct YComp{
	bool operator() (const tarb &a,const tarb &b){
		if(a.y!=b.y)return a.y<b.y;
		return a.x<b.x;
	}
};

const int low = LONG_MIN;

mulitmap<tarb,int,XComp> xs;
multimap<tarb,int,XComp>::iterator xit,dx;
multimap<tarb,int,YComp> ys;
multimap<tarb,int,YComp>::iterator yit,dy;

int n,m;
tarb p;

void work(){
	int x,y,c,ret;
	
	xs.clear();ys.clear();
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		p.x=x;p.y=y;
		xs.insert(pair<tarb,int>(p,1));
		ys.insert(pair<tarb,int>(p,1));
	}

	for(int i=0;i<m;i++){
		scanf("%d",&c);ret=0;
		if(!c){scanf("%d",&x);
			p.x=x;p.y=low;
			xit=xs.upper_bound(p);
			while((*xit)!=xs.end() && (*xit).first.x==x){
				p=(*xit).first;ret++;
				yit=ys.lower_bound(p);
				dx=xit;xit++;xs.erase(dx);
				ys.erase(yit);
			}
			printf("%d\n",ret);
		}else{scanf("%d",&y);
			p.x=low;p.y=y;
			yit=ys.upper_bound(p);
			while((*yit)!=ys.end() && (*yit).first.y==y){
				p=(*yit).first;ret++;
				xit=xs.lower_bound(p);
				dy=yit;yit++;ys.erase(dy);
				xs.erase(xit);
			}
			printf("%d\n",ret);
		}
	}
	printf("\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}

