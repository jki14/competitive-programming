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

map<int, int> xs,ys;
map<int, int>::iterator it;

int n,ans,X,Y;
int sx,sy,tx,ty;
int ax[N],ay[N],bx[N],by[N];

int f[N][N][P],g[N][N][P],c[N][N];

inline void push_point(int &x,int &y){
	x*=3;y*=3;
	xs[x]=0;xs[x-1]=0;xs[x+1]=0;
	ys[y]=0;ys[y-1]=0;ys[y+1]=0;
}

int main(){
	while(scanf("%d%d%d%d",&sx,&sy,&tx,&ty)!=EOF
		&& !(sx==0 && sy==0 && tx==0 && ty==0)){
		xs.clear();ys.clear();
		push_point(sx,sy);push_point(tx,ty);
		scanf("%d",&n);for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&ax[i],&ay[i],&bx[i],&by[i]);
			if(ax[i]>bx[i])swap(ax[i],bx[i]);
			if(ay[i]>by[i])swap(ay[i],by[i]);
			push_point(ax[i],ay[i]);push_point(bx[i],by[i]);
		}
		X=0;for(it=xs.begin();it!=xs.end();it++)(*it).second=X++;
		Y=0;for(it=ys.begin();it!=ys.end();it++)(*it).second=Y++;
		sx=xs[sx];sy=ys[sy];tx=xs[tx];ty=ys[ty];
		for(int i=0;i<n;i++){ 
			ax[i]=xs[ax[i]]+1;ay[i]=ys[ay[i]]+1;
			bx[i]=xs[bx[i]]-1;by[i]=ys[by[i]]-1;
	       	}
		
		memset(c,0,sizeof(c));memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
			for(int x=ax[i];x<=bx[i];x++)
				for(int y=ay[i];y<=by[i];y++)
					c[x][y]=1;
		
		for(int x=1;x<X-1;x++)for(int y=1;y<Y-1;y++){
			if((c[x-1][y] && c[x+1][y]) || (c[x][y-1] && c[x][y+1]))c[x][y]=1;
			if(c[x-1][y-1] && c[x+1][y+1])c[x][y]=1;
			if(c[x-1][y+1] && c[x+1][y-1])c[x][y]=1;
		}
		

	
		memset(f,0x3f,sizeof(f));while(!que.empty())que.pop();
		for(int x=sx-1;x<=sx+1;x++)
			for(int y=sy-1;y<=sy+1;y++)
				for(int i=0;i<P;i++){
				       	//c[x][y]='S';
					f[x][y][i]=0;g[x][y][i]=1;
					que.push(state(x,y,i)); 
				}

		for(int x=tx-1;x<=tx+1;x++)
			for(int y=ty-1;y<=ty+1;y++)
				c[x][y]=2;
	
		/*for(int x=0;x<X;x++){
			for(int y=0;y<Y;y++){
				if(c[x][y]=='S')printf("S");
				else if(c[x][y]=='T')printf("T");
				else if(c[x][y])printf("#");
				else printf(".");
			}
			printf("\n");
		}*/

		for(ans=inf;!que.empty();que.pop()){
			int x=que.front().x,y=que.front().y,p=que.front().p;
			int w=f[x][y][p];g[x][y][p]=0;
			//printf("%c\n",(char)c[x][y]);
			if(c[x][y]==2 && ans>w){ ans=w;continue; }
			for(int i=0;i<P;i++){
				int xx=x+dx[i],yy=y+dy[i],ww=w+(i==p?0:1);
				if(xx<0 || xx>=X || yy<0 || yy>=Y || c[xx][yy]==1)continue;
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

