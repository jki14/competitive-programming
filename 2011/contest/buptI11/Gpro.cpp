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
#include<set>
#include<map>
using namespace std;

#define maxn 110000
#define maxk 30

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=LONG_MAX;

int n,m,p,xuxu;
int val,c[maxn][maxk];
int a[maxn],b[maxn];
int low[maxn],hig[maxn];

void modify(const int &i,const int &l,const int &r,const int &x,const int &y){
	if(x<l || x>r)return;
	if(b[x]){
		c[i][b[x]]--;
		//printf("c[%d][%d]-- { %d->%d\n",i,b[x],l,r);
	}
	c[i][y]++;

	//printf("c[%d][%d]++ { %d->%d\n",i,y,l,r);

	if(l<r){
		int mid=(l+r)>>1;
		modify(L,l,  mid,x,y);
		modify(R,mid+1,r,x,y);
	}else b[x]=y;
}

int que(const int &i,const int &l,const int &r,const int &u,const int &v,const int &k){
	if(u>v || v<l || u>r)return 0;
	if(u<=l && r<=v){
		
		//printf("Que(%d,%d,%d,%d,%d,%d)=%d\n",i,l,r,u,v,k,c[i][k]);
		//printf("c[3][1]=%d\n",c[3][1]);
		return c[i][k];
	}
	int mid=(l+r)>>1;
	return que(L,l,  mid,u,v,k)+que(R,mid+1,r,u,v,k);
}

void work(){
	int i,k,top,x,y;val=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	top=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);y++;
		
		//printf("A[%d]=%d B[%d]=%d\n",i,k,i,b[i]);

		modify(0,1,n,i,y);
		if(x<=p){
			a[i]=1;top=i;low[i]=i-1;
		}else{
			low[i]=top;
		}
	}
	top=inf;
	for(i=n;i>=1;i--){
		if(a[i]){
			top=i;hig[i]=i+1;
		}else
	 		hig[i]=top;
	}
	//printf("c[3][1]=%d\n",c[0][1]);
	for(i=1;i<=n;i++){
		val+=que(0,1,n,1,low[i],b[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&k);
		if(k==1){
			printf("%d\n",val);
		}else{
			scanf("%d%d",&x,&y);y++;

			//printf("x=%d y=%d\n",x,y);

			val+=que(0,1,n,1,low[x],y)-que(0,1,n,1,low[x],b[x]);
			val+=que(0,1,n,hig[x],n,y)-que(0,1,n,hig[x],n,b[x]);
			modify(0,1,n,x,y);
		}
	}
}

int main(){
	//int t;scanf("%d",&t);
	//while(t--){
		scanf("%d%d%d%d",&n,&m,&xuxu,&p);
		work();
	//}
	return 0;
}
