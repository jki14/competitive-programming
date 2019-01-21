#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100

const int dx[4]={ -1,0,1,0 };
const int dy[4]={ 0,1,-1,0 };

#define ii (i+dx[k])
#define jj (j+dy[k])

#define xx (i+k-1)
#define yy (j+k-1)

struct TPoint{
	int x,y;
};

typedef struct TPoint tp;

int a[maxn][maxn],n,res;
int v[maxn][maxn][4];
int c[maxn][maxn][2];
tp d[maxn*maxn],p[maxn*maxn],tmp;
char s[maxn];

int dcmp(const int &i,const int &j){
	return c[d[i].x][d[i].y][0]>c[d[j].x][d[j].y][0];
}

int pcmp(const int &i,const int &j){
	return c[p[i].x][p[i].y][1]>c[p[j].x][p[j].y][1];
}

void work(){
	int i,j,k;res=0;
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<n;j++)
			a[i+1][j+1]=((s[j]=='1')?1:0);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]==1){
				for(k=0;k<4;k++)
					if(a[ii][jj])
						v[i][j][k]+=v[ii][jj][k];
					else
						v[i][j][k]=1;
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			c[i][j][0]=min(v[i][j][1],v[i][j][2]);
			c[i][j][1]=min(v[i][j][0],v[i][j][3]);
		}
	/*for(i=k=0;i<n;i++)
		for(j=0;j<n;j++){
			tmp.x=i;tmp.y=j;
			d[k]=p[k]=tmp;k++;
		}
	sort(d,d+k,dcmp);
	sort(p,p+k,dcmp);*/
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(a[i][j]){
				for(k=c[i][j][0];k>res;k--){
					if(c[xx][yy][1]>=k){ res=k;break; }
				}
			}
		}
	cout<<"!"<<c[1][1][0]<<"  "<<c[3][3][1]<<endl;
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

