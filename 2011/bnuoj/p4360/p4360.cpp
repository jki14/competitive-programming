#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define maxn 1100

#define ii i+dx[k]
#define jj j+dy[k]

#define xx (x+k-1)
#define yy (y+k-1)

typedef pair<int,int> PII;

const int dx[4]={ -1,0,1,0 };
const int dy[4]={ 0,1,0,-1 };

int a[maxn][maxn],n,res;
int v[maxn][maxn][4],c[maxn][maxn][2];
vector<PII> list;
PII p;
char stmp[maxn];

void work(){
	scanf("%d",&n);res=0;
	int i,j,k,x,y;
	memset(v,0,sizeof(v));
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++){
		scanf("%s",stmp);
		for(j=0;j<n;j++)
			a[i+1][j+1]=(stmp[j]=='1')?1:0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]){
					k=3;
					if(a[ii][jj])
							v[i][j][k]=v[ii][jj][k]+1;
					else
						v[i][j][k]=1;
					k=0;	
					if(a[ii][jj])
							v[i][j][k]=v[ii][jj][k]+1;
					else
						v[i][j][k]=1;
				
			}
	for(i=n;i>=1;i--)
		for(j=n;j>=1;j--)
			if(a[i][j]){
				for(k=1;k<3;k++){
					if(a[ii][jj])
						v[i][j][k]=v[ii][jj][k]+1;
					else
						v[i][j][k]=1;
				}
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			c[i][j][0]=min(v[i][j][1],v[i][j][2]);
			c[i][j][1]=min(v[i][j][0],v[i][j][3]);
	}
	/*list.clear();
	p.first=1;p.second=1;list.push_back(p);
	for(i=2;i<=n;i++){
		p.first=1;p.second=i;
		list.push_back(p);
		p.first=i;p.second=1;
		list.push_back(p);
	}
	while(list.size()>0){
		i=rand()%(int)list.size();
		x=list[i].first;y=list[i].second;
		list.erase(list.begin()+i);
		for(k=1;xx<=n && yy<=n;k++)
			for(j=c[xx][yy][0];j>res;j--)
				if(c[xx+j-1][yy+j-1][1]>=j)res=j;
	}*/
	for(x=y=1;x<=n && y<=n;x++){
		for(k=1;xx<=n && y<=n;k++)
			for(j=c[xx][yy][0];j>res;j--)
				if(c[xx+j-1][yy+j-1][1]>=j)res=j;
	}
	for(x=1,y=2;x<=n && y<=n;y++){
		for(k=1;xx<=n && y<=n;k++)
			for(j=c[xx][yy][0];j>res;j--)
				if(c[xx+j-1][yy+j-1][1]>=j)res=j;
	}
	printf("%d\n",res);
}

int main(){
	srand(time(0));
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

