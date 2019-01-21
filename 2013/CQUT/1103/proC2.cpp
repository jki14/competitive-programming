#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

#define N 310
#define P 4

struct state{
	int x,y,p;
	state(const int &_x,const int &_y,const int &_p){ x=_x;y=_y;p=_p; }
};

queue<state> que;

const int dx[P]={ 0,1,0,-1 };
const int dy[P]={ 1,0,-1,0 };

typedef long long lld;

const int inf = 0x3f3f3f3f;

map<lld, int> xs,ys;
map<lld, int>::iterator it;

lld _sx,_sy,_tx,_ty;
lld _ax[N],_ay[N],_bx[N],_by[N];

int n,ans,X,Y;
int sx,sy,tx,ty;
int ax[N],ay[N],bx[N],by[N];

int f[N][N][P],g[N][N][P],c[N][N];

int able(const int &x,const int &y,const int &p){
	if(x==0 || x==X-1 || y==0 || y==Y-1)return 1;
	if(!c[x][y])return 1;
	int p1=(p+1)%P,p2=(p+3)%P;
	if(!c[x+dx[p1]][y+dy[p1]])return 1;
	if(!c[x+dx[p2]][y+dy[p2]])return 1;
	return 0;
}

int main(){
	while(scanf("%I64d%I64d%I64d%I64d",&_sx,&_sy,&_tx,&_ty)!=EOF
		&& !(_sx==0LL && _sy==0LL && _tx==0LL && _ty==0LL)){
		xs.clear();ys.clear();
		xs[_sx]=0;xs[_tx]=0;ys[_sy]=0;ys[_ty]=0;
		scanf("%d",&n);for(int i=0;i<n;i++){
			scanf("%I64d%I64d%I64d%I64d",&_ax[i],&_ay[i],&_bx[i],&_by[i]);
			//scanf("%lld%lld%lld%lld",&_ax[i],&_ay[i],&_bx[i],&_by[i]);
			xs[_ax[i]]=0;xs[_ax[i]-1LL]=0;xs[_ax[i]+1LL]=0;
			ys[_ay[i]]=0;ys[_ay[i]-1LL]=0;ys[_ay[i]+1LL]=0;
			xs[_bx[i]]=0;xs[_bx[i]-1LL]=0;xs[_bx[i]+1LL]=0;
			ys[_by[i]]=0;ys[_by[i]-1LL]=0;ys[_by[i]+1LL]=0;
		}
		X=0;for(it=xs.begin();it!=xs.end();it++)(*it).second=X++;
		Y=0;for(it=ys.begin();it!=ys.end();it++)(*it).second=Y++;
		sx=xs[_sx];sy=ys[_sy];tx=xs[_tx];ty=ys[_ty];
		for(int i=0;i<n;i++){ 
			ax[i]=xs[_ax[i]];ay[i]=ys[_ay[i]];
			bx[i]=xs[_bx[i]];by[i]=ys[_by[i]];
	       	}
		//for(int i=0;i<X;i++)for(int j=0;j<Y;j++){ d[i][j]=c[i][j]=inf; }
		memset(c,0,sizeof(c));memset(g,0,sizeof(g));
		for(int i=0;i<n;i++){
			//printf("block (%d,%d)->(%d,%d)\n",ax[i],ay[i],bx[i],by[i]);
			for(int x=ax[i];x<=bx[i];x++){
				for(int y=ay[i];y<=by[i];y++){
					c[x][y]=1;
					//printf("c[%d][%d]=1\n",x,y);
				}
			}
		}
		//printf("X=%d Y=%d (%d,%d)->(%d,%d)\n",X,Y,sx,sy,tx,ty);

		/*printf("\n");
		for(int x=0;x<X;x++){
			for(int y=0;y<Y;y++){
				if(x==sx && y==sy)
					printf("S");
				else if(x==tx && y==ty)
					printf("T");
				else if(c[x][y])
					printf("#");
				else printf(".");
			}
			printf("\n");
		}*/

		memset(f,0x3f,sizeof(f));while(!que.empty())que.pop();
		for(int i=0;i<P;i++){ f[sx][sy][i]=0;g[sx][sy][i]=1;que.push(state(sx,sy,i)); }
		for(ans=inf;!que.empty();que.pop()){
			int x=que.front().x,y=que.front().y,p=que.front().p;
			int w=f[x][y][p];g[x][y][p]=0;
			if(x==tx && y==ty && ans>w)ans=w;
			for(int i=0;i<P;i++){
				int xx=x+dx[i],yy=y+dy[i],ww=w+(i==p?0:1);
				if(xx<0 || xx>=X || yy<0 || yy>=Y || !able(xx,yy,i))continue;
				if(f[xx][yy][i]>ww){
					f[xx][yy][i]=ww;
					if(!g[xx][yy][i]){
						que.push(state(xx,yy,i));
						g[xx][yy][i]=1;
					}
				}
			}
		}
		if(ans==inf)
			printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}

