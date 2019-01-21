#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 1100
#define maxm 1100

const int a=28;
const int b=15;

int n,m,q,ans;
int c[maxn][maxm];
int l[maxn],r[maxn],u[maxn],d[maxn];

int lowbit(const int &x){
	return x&(x^(x-1));
}

void add(int x,int y){
	if(x==0 || y==0)return;
	int i,j;
	for(i=x;i<=n;i+=lowbit(i))
		for(j=y;j<=m;j+=lowbit(j))
			c[i][j]+=1;
}

int sum(int x,int y){
	int i,j,res=0;
	for(i=x;i>0;i-=lowbit(i))
		for(j=y;j>0;j-=lowbit(j))
			res+=c[i][j];
	return res;
}

void work(){
	memset(c,0,sizeof(c));
	scanf("%d",&q);
	int i,j,x,y,k;
	for(i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	memset(l,0x3f,sizeof(l));
	memset(r,0x3f,sizeof(r));
	memset(u,0x3f,sizeof(u));
	memset(d,0x3f,sizeof(d));
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++){
			if(i+a<=n && j+b<=m){
				k=sum(i+a-1,j+b-1)-sum(i,j+b-1)-sum(i+a-1,j)+sum(i,j);
				l[i+a]=min(l[i+a],k);
				r[i]=min(r[i],k);
				u[j+b]=min(u[j+b],k);
				d[j]=min(d[j],k);
			}
			if(i+b<=n && j+a<=m){
				k=sum(i+b-1,j+a-1)-sum(i,j+a-1)-sum(i+b-1,j)+sum(i,j);
				l[i+b]=min(l[i+b],k);
				r[i]=min(r[i],k);
				u[j+a]=min(u[j+a],k);
				d[j]=min(d[j],k);
			}
		}
	ans=LONG_MAX;
	for(i=1;i<=n;i++)l[i]=min(l[i],l[i-1]);
	for(i=n-1;i>=0;i--)r[i]=min(r[i],r[i+1]);
	for(i=1;i<=m;i++)u[i]=min(u[i],u[i-1]);
	for(i=m-1;i>=0;i--)d[i]=min(d[i],d[i+1]);
	for(i=0;i<=n;i++){
		//if(ans>l[i]+r[i])cout<<"update ans at L->R="<<i<<endl;
		ans=min(ans,l[i]+r[i]);
	}
	for(i=0;i<=m;i++){
		//if(ans>u[i]+d[i])cout<<"update ans at U->D="<<i<<endl;
		ans=min(ans,u[i]+d[i]);
	}
	//cout<<"l[0]="<<l[0]<<endl;
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}
