#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define N 5100
#define P 4

#define xx now.x+dx[i]
#define yy now.y+dy[i]
#define ww (now.w+((c[now.x+dx[i]][now.y+dy[i]]=='*')?k:0))

struct state{
    int x,y,w;
    state(){}
    state(const int &_x,const int &_y,const int &_w){ x=_x;y=_y;w=_w; }
}cs,ys;

struct point{ int x,y;
    point(){}
    point(const int &_x,const int &_y){ x=_x;y=_y; }
    bool operator < (const point &sp) const{
        return sp.x!=x?sp.x<x:sp.y<y;
    }
};

const int inf=0x3f3f3f3f;

const int dx[P]={ 0,0,-1,1 };
const int dy[P]={ 1,-1,0,0 };

int n,m,k;
int cd,yd,ans;
//int f[N][N];
map<point, int> f;
map<point, int>::iterator it;
set<point> mrk;
set<point>::iterator jt;

char c[N][N];

queue<state> que;

inline int min(const int &x,const int &y){ return x<y?x:y; }
inline void updmin(int &x,const int &y){ if(x>y)x=y; }

int Core(const state &src,const state &dst,int &wht){
    while(!que.empty())que.pop();f.clear();mrk.clear();
    que.push(src);mrk.insert(point(src.x,src.y));
    for(;!que.empty();que.pop()){state now=que.front();
        //if(c[now.x][now.y]==c[dst.x][dst.y])return now.w;
        for(int i=0;i<P;i++){
            if(xx<0 || xx>=n)continue;
            if(yy<0 || yy>=m)continue;
            if(c[xx][yy]=='#')continue;
            if(c[xx][yy]=='P'){ updmin(wht,ww);/*continue;*/ }
            it=f.find(point(xx,yy));
            //if(ww<f[xx][yy]){ f[xx][yy]=ww;que.push(state(xx,yy,ww)); }
            if(it!=f.end()){
                if((*it).second>ww){
                    (*it).second=ww;
                    jt=mrk.find(point(xx,yy));
                    if(jt==mrk.end()){
                        que.push(state(xx,yy,ww));
                        mrk.insert(point(xx,yy));
                    }
                }
            }else{
                f.insert(make_pair(point(xx,yy),ww));
                jt=mrk.find(point(xx,yy));
                if(jt==mrk.end()){
                    que.push(state(xx,yy,ww));
                    mrk.insert(point(xx,yy));
                }
            }
        }
        jt=mrk.find(point(now.x,now.y));mrk.erase(jt);
    }
    it=f.find(point(dst.x,dst.y));
    int ret=(it!=f.end())?(*it).second:inf;
    return ret;
}

int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",c[i]);
            for(int j=0;j<m;j++){
                if(c[i][j]=='C'){ cs=state(i,j,0); }
                if(c[i][j]=='Y'){ ys=state(i,j,0); }
            }
        }
        
        /*memset(f,0x3f,sizeof(f));*/
        /*f.clear();*/cd=yd=inf;
        ans=Core(cs,ys,cd);Core(ys,cs,yd);
	updmin(ans,cd+yd);

        if(ans==inf){
            printf("Damn teoy!\n");
        }else printf("%d\n",ans);
    }
    return 0;
}
