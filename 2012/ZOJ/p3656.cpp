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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define N 1100
#define M 2100000

#define p seq[i]

int ev[M],next[M],nbs[N],num;
int seq[N],col[N],pnt[N],cnt;
int mrk[N];

void addEdge(const int &u,const int &v){ ev[++num]=v;next[num]=nbs[u];nbs[u]=num; }

void dfs(const int &u){mrk[u]=1;
	for(int i=nbs[u];i;i=next[i]){int v=ev[i];
		if(!mrk[v])dfs(v);
	}
	seq[++cnt]=u;
}

void df2(const int &u,const int &c){
	mrk[u]=1;col[u]=c;
	for(int i=nbs[pnt[u]];i;i=next[i]){int v=ev[i];
		if(!mrk[pnt[v]])df2(pnt[v],c);
	}
}

int dsat(int n){
	memset(mrk,0,sizeof(mrk));cnt=0;
	for(int i=0;i<n;i++)if(!mrk[i])dfs(i);
	memset(mrk,0,sizeof(mrk));cnt=0;
	for(int i=n;i>0;i--)if(!mrk[p])df2(p,++cnt);
	
	for(int i=0;i<n;i++)if(col[i]==col[pnt[i]])return 0;
	return 1;
}

#define S 510
#define K 31

int mat[S][S],bit[K],n;

int mat_able(){
	for(int i=0;i<n;i++)if(mat[i][i]!=0)return 0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(mat[i][j]!=mat[j][i])return 0;
	return 1;
}

int main(){
	for(int i=0;i<K;i++)bit[i]=1<<i;
	while(scanf("%d",&n)!=EOF){int flag=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mat[i][j]);
		if(!mat_able()){ printf("NO\n");continue; }
		for(int i=0;i<n;i++){ pnt[i]=i+n;pnt[i+n]=i; }
		for(int i=0;i<K;i++){
			memset(nbs,0,sizeof(nbs));num=0;
			for(int x=0;x<n;x++){
				for(int y=x+1;y<n;y++){
					if( (x&1)==1 && (y&1)==1 ){//-OR
						if(mat[x][y]&bit[i]){
							addEdge(x+n,y);addEdge(y+n,x);
						}else{
							addEdge(x,x+n);addEdge(y,y+n);
						}
					}else if( (x&1)==0 && (y&1)==0 ){//-AND
						if(mat[x][y]&bit[i]){
							addEdge(x+n,x);addEdge(y+n,y);
						}else{
							addEdge(x,y+n);addEdge(y,x+n);
						}
					}else{//-XOR
						if(mat[x][y]&bit[i]){
							addEdge(x,y+n);addEdge(y,x+n);
							addEdge(x+n,y);addEdge(y,x+n);
						}else{
							addEdge(x,y);addEdge(y,x);
							addEdge(x+n,y+n);addEdge(y+n,x+n);
						}
					}
				}
			}
			if(!dsat(n<<1)){ flag=0;break; }
		}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

