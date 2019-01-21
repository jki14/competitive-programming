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

#define N 1100
#define M 14
#define P 3100
#define Q 11000
#define S 4100
#define X 12

#define nowsta qsta.front()
#define nowpos qpos.front()

int n,m,p,q,ans;
int lef[M],rig[M],mov[M],bit[M],cas[M];
int fir[S][N],vis[S][N],f[S][N];
int con[M][X],arr[M];

queue<int> qsta,qpos;

inline int max(const int &x,const int &y){ return x>y?x:y; }
inline int min(const int &x,const int &y){ return x<y?x:y; }

int main(){
	int T;scanf("%d",&T);
	for(int i=0;i<M;i++)bit[i]=1<<i;
	while(T--){
		scanf("%d%d%d%d",&n,&m,&p,&q);ans=0;
		for(int i=1;i<=m;i++)scanf("%d",&cas[i]);
		for(int i=1;i<=m;i++){
			scanf("%d",&con[i][0]);
			lef[i]=rig[i]=mov[i]=0;
			for(int j=1;j<=con[i][0];j++){
				scanf("%d",&con[i][j]);
				mov[i]+=con[i][j];
				lef[i]=min(lef[i],mov[i]);
				rig[i]=max(lef[i],mov[i]);
			}
		}
		while(!qsta.empty())qsta.pop();while(!qpos.empty())qpos.pop();
		memset(fir,0xff,sizeof(fir));memset(vis,0xff,sizeof(vis));
		for(int i=0;i<p;i++){
			int num,scr;scanf("%d%d",&num,&scr);
			for(int j=0;j<num;j++)scanf("%d",&arr[j]);
			qsta.push(0);qpos.push(0);fir[0][0]=i;f[0][0]=q;
			while(!qsta.empty()){

				//printf("f[%d][%d]=%d\n",nowsta,nowpos,f[nowsta][nowpos]);

				vis[nowsta][nowpos]=-1;
				for(int j=0;j<num;j++){

					if(nowpos+lef[arr[j]]<0 || nowpos+rig[arr[j]]>n || f[nowsta][nowpos]<cas[arr[j]])continue;

					//printf("Try!\n");

					int newsta=nowsta|bit[j],newpos=nowpos+mov[arr[j]],newval=f[nowsta][nowpos]-cas[arr[j]];
					if(fir[newsta][newpos]!=i || f[newsta][newpos]<newval){
						fir[newsta][newpos]=i;
						f[newsta][newpos]=newval;

						//printf("f[%d][%d]=%d \n",newsta,newpos,newval);

						if(vis[newsta][newpos]!=i){
							qsta.push(newsta);qpos.push(newpos);vis[newsta][newpos]=i;
						}
					}
				}
				qsta.pop();qpos.pop();
			}
			if(fir[bit[num]-1][n]==i && f[bit[num]-1][n]>=0)ans=max(ans,f[bit[num]-1][n]+scr);
		}
		printf("%d\n",ans);
	}
	return 0;
}
