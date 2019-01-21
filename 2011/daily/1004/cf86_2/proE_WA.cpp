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

#define N 110
#define K 4

#define xx x+dx[i]
#define yy y+dy[i]

const int dx[K]={ -1,0,1,0 };
const int dy[K]={ 0,1,0,-1 };

int n,m,num,ans;
int a[N][N];

struct state{
	int x,y;
}s[N];

int count(const state &sta){
	int ret=0;
	for(int i=0;i<K;i++){
		int x=sta.x+dx[i],y=sta.y+dy[i];
		if(x && x<=n && y && y<=m && a[x][y]>0)ret++;
	}
	if(a[sta.x][sta.y]==0)ret--;
	return ret;
}

int cmp(const state &x,const state &y){
	return count(x)>count(y);
}

void work(){
	memset(a,0x7f,sizeof(a));
	
	
	ans=num=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			s[num].x=i;s[num].y=j;num++;
		}

	while(1){
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				printf("%c",a[i][j]?'X':' ');
			printf("\n");
		}*/
		sort(s,s+num,cmp);

		/*cout<<"SORT"<<endl;
		for(int i=0;i<num;i++)printf(" %d,%d===%d\n",s[i].x,s[i].y,count(s[i]));*/

		if(count(s[0])==0)break;
		//printf(" X %d,%d\n",s[0].x,s[0].y);
		ans+=count(s[0]);
		int x=s[0].x,y=s[0].y;a[x][y]=-1;
		for(int i=0;i<K;i++)if(xx && xx<=n && yy && yy<=m && a[xx][yy]){
			//printf(" 	C %d,%d\n",xx,yy);
			a[xx][yy]=0;
		}
		
		///ans--;	
	}	
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

