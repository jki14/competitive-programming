#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100

int n,cast;
int lowbit[maxn];
int c[maxn][maxn];

void modify(const int &x,const int &y,const int &val){
	//printf("Modify (%d,%d)+=%d\n",x,y,val);
	for(int i=x;i<=n;i+=lowbit[i])
		for(int j=y;j<=n;j+=lowbit[j])
			c[i][j]+=val;
}

int sum(const int &x,const int &y){
	int ret=0;
	for(int i=x;i>0;i-=lowbit[i])
		for(int j=y;j>0;j-=lowbit[j])
			ret+=c[i][j];
	return ret;
}

void work(){
	int x,y,xx,yy,val;
	for(x=1;x<=n;x++)lowbit[x]=x&(-x);
	while(1){scanf("%d",&cast);
		//cout<<"cast="<<cast<<endl;
		if(cast==3)return;
		if(cast==1){
			scanf("%d%d%d",&x,&y,&val);
			x++;y++;
			modify(x,y,val);
		}else{
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			x++;y++;xx++;yy++;
			printf("%d\n",sum(xx,yy)-sum(xx,y-1)-sum(x-1,yy)+sum(x-1,y-1));
		}
	}
}

int main(){
	while(scanf("%d",&cast)){
		if(cast==0){
			memset(c,0,sizeof(c));
			scanf("%d",&n);
			work();
		}else break;
	}
	return 0;
}
