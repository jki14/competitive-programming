//============================================================================
// Name        : DLX4Sudoku
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 舞蹈链、hdu4069异构数独（九宫分格部分被修改为按输入要求分割连续9块的9
//个区域）；输出要求输出唯一解、或多组解以及无解结论
//============================================================================

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

#define N 800
#define M 400
#define S 320000
#define L 110
#define K 4

const int n = 729;
const int m = 324;

const int zero = (int)'0';

const int dx[K]={ -1,0,1,0 };
const int dy[K]={ 0,1,0,-1 };

int T;

int wall[9][9][K],a[9][9],c[9][9],bck;
int head[S],l[S],r[S],u[S],d[S],idx[S],idy[S];
int root,res[L],num[N];

int ret,ans[L];

void clear(){
	res[0]=num[0]=0;
	for(int i=1;i<=m+1;i++){
		head[i]=i;
		r[i]=i+1;l[i]=i-1;
		u[i]=i;d[i]=i;
		num[i]=idx[i]=idy[i]=0;
	}
	l[0]=r[0]=u[0]=d[0]=m+1;
	l[1]=m+1;r[m+1]=1;root=m+1;
}

void remove(const int &x){
	l[r[x]]=l[x];r[l[x]]=r[x];
	for(int i=d[x];i!=x;i=d[i]){
		for(int j=r[i];j!=i;j=r[j]){
			u[d[j]]=u[j];d[u[j]]=d[j];
			num[head[j]]--;
		}
	}
}

void resume(const int &x){
	for(int i=d[x];i!=x;i=d[i]){
		for(int j=r[i];j!=i;j=r[j]){
			u[d[j]]=j;d[u[j]]=j;
			num[head[j]]++;
		}
	}
	l[r[x]]=x;r[l[x]]=x;
}

int dfs(const int &x){
	if(r[root]==root){
		ret++;
		if(ret==1)memcpy(ans,res,sizeof(res));
		return ret;
	}
	int k=r[root];
	for(int i=r[root];i!=root;i=r[i]){
		if(num[i]<num[k])k=i;
	}
	remove(k);
	for(int i=d[k];i!=k;i=d[i]){
		//res[0]++;res[res[0]]=idx[i];
		res[idx[i]]=idy[i];
		for(int j=r[i];j!=i;j=r[j])remove(head[j]);
		if(dfs(x+1)==2)return 2;
		for(int j=l[i];j!=i;j=l[j])resume(head[j]);
		//res[0]--;
	}
	resume(k);
	return 0;
}

int pos(const int &i,const int &j,const int &c,const int &k){
	int x=(i-1)/9+1,y=(i-1)%9+1;
	switch(k){
		case 1:
			return x*9-9+j;
		case 2:
			return y*9-9+j+81;
		case 3:
			//return (((x-1)/3)*3+((y-1)/3+1))*9-9+j+162;
			return c*9-9+j+162;
		case 4:
			return i+243;
	}
	return -1;
}

void pt(const int &i,const int &j){
	if(c[i][j])return;
	c[i][j]=bck;
	for(int k=0;k<K;k++){
		if(wall[i][j][k])continue;
		pt(i+dx[k],j+dy[k]);
	}
}

void work(){
	memset(wall,0,sizeof(wall));
	memset(c,0,sizeof(c));bck=ret=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int val;scanf("%d",&val);
			if(val& 16){ wall[i][j][0]=1;val^= 16; }
			if(val& 32){ wall[i][j][1]=1;val^= 32; }
			if(val& 64){ wall[i][j][2]=1;val^= 64; }
			if(val&128){ wall[i][j][3]=1;val^=128; }
			a[i][j]=val;
		}
	}
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)if(!c[i][j]){
			bck++;
			pt(i,j);
		}

	clear();

	for(int x=0;x<9;x++)for(int y=0;y<9;y++){int i=x*9+y+1;
		if(a[x][y]==0){
			for(int val=1;val<=9;val++){
				for(int j=r[0]+1;j<=r[0]+4;j++){
					idx[j]=i;idy[j]=val;
					r[j]=j+1;l[j]=j-1;
					head[j]=pos(i,val,c[x][y],j-r[0]);
					u[j]=u[head[j]];d[j]=head[j];
					u[d[j]]=d[u[j]]=j;
					num[head[j]]++;
				}
				l[r[0]+1]=r[0]+4;r[r[0]+4]=r[0]+1;
				l[0]+=4;r[0]+=4;u[0]+=4;d[0]+=4;
			}
		}else{
			int val=a[x][y];
			for(int j=r[0]+1;j<=r[0]+4;j++){
				idx[j]=i;idy[j]=val;
				r[j]=j+1;l[j]=j-1;
				head[j]=pos(i,val,c[x][y],j-r[0]);
				u[j]=u[head[j]];d[j]=head[j];
				u[d[j]]=d[u[j]]=j;
				num[head[j]]++;
			}
			l[r[0]+1]=r[0]+4;r[r[0]+4]=r[0]+1;
			l[0]+=4;r[0]+=4;u[0]+=4;d[0]+=4;
		}
	}

	printf("Case %d:\n",T);

	/* simple check */
	for(int i=1;i<=m;i++){
		if(num[head[i]]==0){
			printf("No solution\n");
			return;
		}
	}

	dfs(0);
	if(ret==1){
		for(int i=1;i<=81;i++){
			printf("%d",ans[i]);
			if(!(i%9))printf("\n");
		}
	}else{
		if(ret==0)
			printf("No solution\n");
		else
			printf("Multiple Solutions\n");
	}
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)
		work();
	return 0;
}

