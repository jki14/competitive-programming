#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;

#define maxn 110
#define maxp 11000
#define prev now^1

#define rx (x+routex[j])
#define ry (y+routey[j])
#define rrx (x+routex[j]*2)
#define rry (y+routey[j]*2)

const int routex[9]={ -1,-1,-1,0,0,0,1,1,1 };
const int routey[9]={ -1,0,1,-1,0,1,-1,0,1 };

int n,m,p,sx,sy;
int a[maxn][maxn],rock[maxn][maxn],mon[maxn][maxn];//0-free,1-die,2-can't stay
int tar[maxn][maxn],mr[maxn],mx[maxn][maxn],my[maxn][maxn],ag[maxn];
int lsx[2][maxp],lsy[2][maxp],t[2],v[maxn][maxn];

char str[maxn];

int allow(const int &x,const int &y){
	if(x<0 || x>=n)return 0;
	if(y<0 || y>=n)return 0;
	return 1;
}

void rebuild(const int &t){
	memcpy(a,rock,sizeof(rock));
	for(int i=0;i<p;i++){
		int x=mx[i][t%mr[i]],y=my[i][t%mr[i]];
		//cout<<"x="<<x<<" y="<<y<<endl;
		a[x][y]=1;
		if(ag[i])for(int j=0;j<9;j++){
			if(!allow(rx,ry))continue;		
			a[rx][ry]=1;
		}
		x=mx[i][(t+1)%mr[i]];y=my[i][(t+1)%mr[i]];
		if(!a[x][y])a[x][y]=2;
		if(ag[i])for(int j=0;j<9;j++){
			if(!allow(rx,ry))continue;
			if(!a[rx][ry])a[rx][ry]=2;
		}
	}
}

void work(){
	int i,j,now,res;
	memset(a,0,sizeof(a));
	memset(rock,0,sizeof(rock));
	memset(mon,0,sizeof(mon));
	memset(tar,0,sizeof(tar));
	for(i=0;i<n;i++){
		scanf("%s",str);
		for(j=0;j<m;j++){
			switch(str[j]){
				case '#':
					rock[i][j]=1;
					break;
				case 't':
					tar[i][j]=1;
					break;
				case 'p':
					sx=i;sy=j;
					break;
				case 'a':
					mon[i][j]=1;
					break;
			}
		}
	}
	scanf("%d",&p);
	for(i=0;i<p;i++){
		scanf("%d",&mr[i]);
		for(j=0;j<mr[i];j++){
			scanf("%d%d",&mx[i][j],&my[i][j]);
			mx[i][j]--;my[i][j]--;
		}
		ag[i]=mon[mx[i][0]][my[i][0]];
	}
	res=now=0;
	t[now]=1;
	lsx[now][1]=sx;lsy[now][1]=sy;
	while(true){
		res++;if(res>100)break;
		rebuild(res);now=prev;
		t[now]=0;
		memset(v,0,sizeof(v));
		for(;t[prev];t[prev]--){
			int x=lsx[prev][t[prev]],y=lsy[prev][t[prev]];
			for(j=0;j<9;j++){
				if(!allow(rx,ry))continue;
				if(!a[rx][ry]){
					if(!v[rx][ry]){
						t[now]++;lsx[now][t[now]]=rx;lsy[now][t[now]]=ry;
						v[rx][ry]=1;
						//cout<<rx<<","<<ry<<" "<<a[rx][ry]<<endl;
					}
				}
				if(a[rx][ry]!=1){
					if(tar[rx][ry]){ printf("%d\n",res);return; }
					if(!allow(rrx,rry))continue;
					if(a[rrx][rry]!=1 && tar[rrx][rry]){ printf("%d\n",res);return; }
					if(!a[rrx][rry]){
						if(!v[rrx][rry]){
							t[now]++;lsx[now][t[now]]=rrx;lsy[now][t[now]]=rry;
							v[rrx][rry]=1;
							//cout<<rrx<<","<<rry<<endl;
						}
					}
				}
			}
		}
		/*/put out a-----------------------------------
		cout<<endl<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(!v[i][j])
					printf("%d",a[i][j]);
				else
					printf("x");
			}
			printf("\n");
		}
		cout<<endl<<endl;
		//--------------------------------------------*/	
	}
	printf("impossible\n");
}

int main(){
	int fir=1;
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0)){
		if(!fir)printf("\n");
		work();
		fir=0;
	}
	return 0;
}

