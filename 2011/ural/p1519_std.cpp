#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define cf(x) bit[x]
#define M 30
using namespace std;
const int key=10003;
const int INF=0x7FFFFFFF;
typedef long long LL;
struct gtp{int y,next;}g[1000000];
int m,n,ng,pg,e,mx,my;
char c[13][13];
LL fl[2][20000],ans;
int sl[2][20000];
int tot[2],ls[key];
int bit[M];

inline void init(){e=0;memset(ls,0,sizeof(ls));}
inline void addedge(int x,int y){e++; g[e].y=y; g[e].next=ls[x]; ls[x]=e;}
inline int ChaTou(int t1,int t2){
    if (!t1 && !t2) return 0;
    if (t1) return 1;
    return 2;
}   


void add(int s,LL f){

	printf("add (%d,%lld)\n",s,f);

    int st=s%key; 
    for (int t=ls[st];t;t=g[t].next)
      if (sl[ng][g[t].y]==s){
          fl[ng][g[t].y]+=f;
          return;
      }
    sl[ng][++tot[ng]]=s;
    fl[ng][tot[ng]]=f;
    addedge(st,tot[ng]);
}   

void input(){
    ng=1; pg=0; ans=0;
    scanf("%d%d",&m,&n);
    int i,j;
    for (i=0;i<m;i++)
      for (j=0;j<n;j++)
        for (c[i][j]=getchar();c[i][j]!='*'&&c[i][j]!='.';c[i][j]=getchar());
    if (c[0][0]=='*') add(0,1);
                 else add(1+cf(n*2+1),1);
    mx=0; my=0;
    for (i=0;i<m;i++)
      for (j=0;j<n;j++)
        if (c[i][j]=='.'){
            mx=i;
            my=j;
        } 
   //printf("mx=%d my=%d\n",mx,my); 
}   

void No(int j){
    int k,t1,t2;
    for (k=1;k<=tot[pg];k++){
        int s=sl[pg][k];
        if ((s&cf(j*2))||(s&cf(j*2+1))||(cf(n*2)&s)||(cf(n*2+1)&s)) continue;
        add(s,fl[pg][k]);
    }   
}

void Yes(int I,int j){

	//printf("pas(%d,%d)\n",I,j);

    int k,lct,uct,ts,i,top,ct;
    for (k=1;k<=tot[pg];k++){
        int s=sl[pg][k];
        LL f=fl[pg][k];

	//printf("sta=%d val=%lld\n",s,f);

        uct=ChaTou(s&cf(j*2),s&cf(j*2+1));
        lct=ChaTou(s&cf(n*2),s&cf(n*2+1));
        if (!j && lct) continue;
        //ts=(INF-cf(j*2)-cf(j*2+1)-cf(n*2)-cf(n*2+1))&s;
	ts=(~(cf(j*2)|cf(j*2+1)|cf(n*2)|cf(n*2+1)))&s;

	printf("s=%d x=%d y=%d uct=%d lct=%d ts=%d\n",s,I,j,uct,lct,ts);

	switch (lct){
            case 0:
                switch (uct){
                    case 0:
                        add(ts|cf(j*2)|cf(n*2+1),f);
                        break;
                    case 1:
                        add(ts|cf(j*2),f);
                        add(ts|cf(n*2),f);
                        break;
                    case 2:
                        add(ts|cf(j*2+1),f);
                        add(ts|cf(n*2+1),f);
                        break;
                }   
                break;
            case 1:
                switch (uct){
                    case 0:
                        add(ts|cf(j*2),f);
                        add(ts|cf(n*2),f);
                        break;
                    case 1:
                        top=0;
                        for (i=j;;i++){
                            ct=ChaTou(s&cf(i*2),s&cf(i*2+1));
                            if (ct==1) top++;
                            if (ct==2) top--;
                            if (top==0) break;
                        }
                        add((ts^cf(i*2+1))|cf(i*2),f);
                        break;
                    case 2:
                        if (I==mx && j==my && ts==0) ans+=f;
                        break;
                }   
                break;
            case 2:
                switch (uct){
                    case 0:
                        add(ts|cf(j*2+1),f);
                        add(ts|cf(n*2+1),f);
                        break;
                    case 1:
                        add(ts,f);
                        break;
                    case 2:
                        top=0;
                        for (i=j;i>=0;i--){
                            ct=ChaTou(s&cf(i*2),s&cf(i*2+1));
                            if (ct==1) top++;
                            if (ct==2) top--;
                            if (top==0) break;
                        }   
                        add((ts^cf(i*2))|cf(i*2+1),f);
                        break;
                }   
                break;
        }   
    }   
}            

void dp(){
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++){
          if (!i && !j) continue;
          ng=1-ng;
          pg=1-pg;
          tot[ng]=0;
          init();
          if (c[i][j]=='*') No(j);
                       else Yes(i,j);
      }
}   

int main(){
	for(int i=0;i<M;i++)bit[i]=1<<i;
    input();
    dp();
    cout << ans << endl;
    return 0;   
}   
