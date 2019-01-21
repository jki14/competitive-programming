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

#define N 55
#define M 55
#define S 11000

struct RES{
	int x1,x2,y1,y2;
	bool operator < (const RES &a)const {
		if((y2-y1+1)*(x2-x1+1)!=(a.y2-a.y1+1)*(a.x2-a.x1+1))
			return (y2-y1+1)*(x2-x1+1)>(a.y2-a.y1+1)*(a.x2-a.x1+1);
		if(x1!=a.x1) return x1<a.x1;
		return y1<a.y1;
	}
};

int n,m,num,id[S];
int a[N][M],b[N][M],d[N][M];
int c[N][M],f[N][M],g[N][M];

int lowbit[N];

set<RES> ANS;
set<RES>::iterator it;
RES r,result[S];

void CAdd(const int &x,const int &y){
	for(int i=x;i<=n+1;i+=lowbit[i])
		for(int j=y;j<=m+1;j+=lowbit[j])
			c[i][j]++;
}

void FAdd(const int &x,const int &y){
	for(int i=x;i<=n+1;i+=lowbit[i])
		for(int j=y;j<=m+1;j+=lowbit[j])
			f[i][j]++;
}

int CQue(const int &x,const int &y){int ret=0;
	for(int i=x;i>0;i-=lowbit[i])
		for(int j=y;j>0;j-=lowbit[j])
			ret+=c[i][j];
	return ret;
}

int FQue(const int &x,const int &y){int ret=0;
	for(int i=x;i>0;i-=lowbit[i])
		for(int j=y;j>0;j-=lowbit[j])
			ret+=f[i][j];
	return ret;
}

int CSum(const int &x1,const int &y1,const int &x2,const int &y2){
	return CQue(x2,y2)+CQue(x1-1,y1-1)-CQue(x1-1,y2)-CQue(x2,y1-1);
}

int FSum(const int &x1,const int &y1,const int &x2,const int &y2){
	return FQue(x2,y2)+FQue(x1-1,y1-1)-FQue(x1-1,y2)-FQue(x2,y1-1);
}

int bSame(const int &x1,const int &y1,const int &x2,const int &y2){
	if(CSum(x1-1,y1-1,x2+1,y1-1))return 0;
	if(CSum(x1-1,y1-1,x1-1,y2+1))return 0;
	if(CSum(x2+1,y1-1,x2+1,y2+1))return 0;
	if(CSum(x1-1,y2+1,x2+1,y2+1))return 0;
	return 1;
}

void F(const RES &r){
	for(int i=r.x1;i<=r.x2;i++)
		for(int j=r.y1;j<=r.y2;j++){
			if(d[i][j] && !g[i][j]){
				FAdd(i,j);
				g[i][j]=1;
			}
		}
}

int nocov(const RES &r){
	for(int i=r.x1;i<=r.x2;i++)
		for(int j=r.y1;j<=r.y2;j++){
			if(g[i][j]==1)return 0;
			g[i][j]=1;
		}
	return 1;
}

int cmp(const int &i,const int &j){
	if(result[i].x1!=result[j].x1)
		return result[i].x1<result[j].x1;
	return result[i].y1<result[j].y1;
}

void work(){
	int i,j,dx,dy;

	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	ANS.clear();num=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
			d[i][j]=(a[i][j]!=b[i][j]);
			if(d[i][j])CAdd(i,j);
		}

	/*for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)printf("%d",d[i][j]);
		printf("\n");
	}*/

	for(dx=0;dx<n;dx++)for(dy=0;dy<m;dy++){
		for(i=1;i+dx<=n;i++)for(j=1;j+dy<=m;j++){

			/*printf("For (%d,%d)->(%d,%d)\n",i,j,i+dx,j+dy);
			printf("	FSum=%d\n",FSum(i,j,i+dx,j+dy));
			printf("	CSum=%d\n",CSum(i,j,i+dx,j+dy));
			printf("	bSame=%d\n",bSame(i,j,i+dx,j+dy));*/

			if(!CSum(i,j,i+dx,j+dy))continue;
			if(FSum(i,j,i+dx,j+dy)==CSum(i,j,i+dx,j+dy))continue;
			if(bSame(i,j,i+dx,j+dy)){
				
				//printf("	GET ANS!!!\n");

				r.x1=i   ;r.y1=j;
				r.x2=i+dx;r.y2=j+dy;
				ANS.insert(r);F(r);
			}
		}
	}

	memset(g,0,sizeof(g));
	for(it=ANS.begin();it!=ANS.end();it++){
		if(nocov(*it)){
			result[num]=(*it);
			id[num]=num;
			num++;
		}
	}

	sort(id,id+num,cmp);

	printf("%d\n",num);
	for(j=0;j<num;j++){i=id[j];
		printf("%d %d %d %d\n",result[i].x1,result[i].y1,result[i].x2,result[i].y2);
	}
}

void init(){
	for(int i=0;i<N;i++)lowbit[i]=i&(-i);
}

int main(){init();
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

