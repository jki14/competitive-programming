#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define P 4
#define L 110

const int dy[P]={ 0,1,0,-1 };
const int dx[P]={ 1,0,-1,0 };

int n,k;
int xs,xt,xk,xx,xy;
int ys,yt,yk,yx,yy;

char cs[L];

inline void _adj(int &x){ if(x<1)x=2-x;if(x>n)x=2*n-x; }

inline void adj(int &x,int &y,int &k){ 
	int _x=x,_y=y;
	_adj(x);_adj(y); 
	if(x!=_x || y!=_y)k=(k+2)%P;
}

inline int c2int(const char &c){
	if(c=='N')return 0;
	if(c=='E')return 1;
	if(c=='S')return 2;
	return 3;
}

int main(){
	while(scanf("%d",&n)!=EOF && n){
		scanf("%s%d%d",cs,&xs,&xt);xk=c2int(cs[0]);xx=1;xy=1;
		scanf("%s%d%d",cs,&ys,&yt);yk=c2int(cs[0]);yx=n;yy=n;
		scanf("%d",&k);
		for(int t=1;t<=k;t++){
			xx+=dx[xk]*xs;xy+=dy[xk]*xs;adj(xx,xy,xk);
			yx+=dx[yk]*ys;yy+=dy[yk]*ys;adj(yx,yy,yk);
			//printf("t=%d (%d,%d) (%d,%d)\n",t,xx,xy,yx,yy);
			if(xx==yx && xy==yy){
				swap(xk,yk);
				continue;
			}
			if(!(t%xt))xk=(xk+1)%P;
			if(!(t%yt))yk=(yk+1)%P;
		}
		printf("%d %d\n",xx,xy);
		printf("%d %d\n",yx,yy);
	}
	return 0;
}
