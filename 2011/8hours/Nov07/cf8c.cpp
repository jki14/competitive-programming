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

/* 你妹才一样 */

#define N 110
#define K 2
#define pre now^1
#define L 11

map<int, int> f[K];
map<int, int>::iterator it;

map<int, string> g[K];

char tmp[L];

int n,bit[N];
int x[N],y[N],d[N][N],now=0;

int dist(const int &i,const int &j){ return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]); }

void work(){
	//Init
	f[now].clear();g[now].clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			d[i][j]=dist(i,j);
	f[now].insert(pair<int,int>(0,0));
	g[now].insert(pair<int,string>(0,"0"));
	//Core
	for(int i=1;i<=n;i++){now=pre;f[now].clear();g[now].clear();
		for(it=f[pre].begin();it!=f[pre].end();it++){
			int presta=(*it).first;
			int preval=(*it).second;
			string preopt=g[pre][presta];
			
			if(presta&bit[i]){
				//connect prev
				int newsta=presta^bit[i];
				int newval=preval;
				map<int, int>::iterator it=f[now].find(newsta);
				if(it==f[now].end() || (*it).second>newval){
					f[now][newsta]=newval;
					string newopt=preopt;
					g[now][newsta]=newopt;

					/*printf("update [%d]:\n",i);
					printf("	sta=%d	val=%d	opt=%s\n",newsta,newval,newopt.c_str());*/

				}
			}else{
				//connect next
				for(int pos=i;pos<=n;pos++){
					if(presta&bit[pos])continue;
					int newsta=presta|bit[pos];
					newsta&=~bit[i];
					int newval=preval+d[0][i]+d[i][pos]+d[pos][0];
					//printf("pos=%d newsta=%d newval=%d\n",pos,newsta,newval);
					map<int, int>::iterator it=f[now].find(newsta);
					if(it==f[now].end() || (*it).second>newval){
						f[now][newsta]=newval;
						sprintf(tmp,"%d",i);
						string newopt=preopt+' '+tmp;
						if(pos!=i){
							sprintf(tmp,"%d",pos);
							newopt=newopt+' '+tmp;
						}
						newopt=newopt+' '+'0';
						g[now][newsta]=newopt;
						
						/*printf("update [%d]:\n",i);
						printf("	sta=%d	val=%d	opt=%s\n",newsta,newval,newopt.c_str());*/

					}
				}
			}
		}
	}
	//Output
	printf("%d\n%s\n",f[now][0],g[now][0].c_str());
}

int main(){
	for(int i=0;i<30;i++)bit[i]=1<<i;
	while(scanf("%d%d",&x[0],&y[0])!=EOF)
		work();
	return 0;
}

