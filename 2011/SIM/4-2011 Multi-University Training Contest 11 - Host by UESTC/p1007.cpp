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

#define maxn 11000
#define maxa 1100

int T;

int n,m,bnum,snum,ans;
int book[maxn],staff[maxn];
int b[maxn],s[maxn];
int f[maxa][maxa],odd,rem;

int cmp(const int &x,const int &y){ return x>y; }

void work(){
	int i,j,x,y;
	ans=0;

	if(m&1)swap(n,m);odd=(m&1);rem=m%3;
	
	for(i=0;i<bnum;i++)scanf("%d",&book[i]);
	for(i=0;i<snum;i++)scanf("%d",&staff[i]);
	sort(book ,book +bnum,cmp);
	sort(staff,staff+snum,cmp);
	for(b[0]=i=0;i<bnum;i++)b[i+1]=b[i]+ book[i];
	for(s[0]=i=0;i<snum;i++)s[i+1]=s[i]+staff[i];
	
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++){
			if(!j){
				if(i)
					f[i][j]=f[i-1][m];
				else f[i][j]=0;
				continue;
			}
			f[i][j]=f[i][j-1];
			if(j>3)f[i][j]=max(f[i][j],f[i][j-3]+1);
			if(j<=rem && i%3==2)f[i][j]+=j;
		}

	x=(n*m)>>1;i=0;j=odd;y=f[i][j];
	do{
		ans=max(ans,b[min(bnum,x)]+s[min(snum,y)]);
		x--;j+=2;
		while(j>=m){ j-=m;i++;}
		y=f[i][j];
	}while(x>=0);
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){scanf("%d%d%d%d",&n,&m,&bnum,&snum);
		work();
	}
	return 0;
}

