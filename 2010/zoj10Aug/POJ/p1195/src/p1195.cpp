#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxs 2100

int k,n,x,y,d,xx,yy;
int a[maxs][maxs];

int lowbit(const int &x){
	return x&(x^(x-1));
}

void modify(int x,int y,int d){
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			a[i][j]+=d;
}

int sum(int x,int y){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res+=a[i][j];
	return res;
}

int work(){
	switch(k){
		case 0:
			scanf("%d",&n);n+=5;
			memset(a,0,sizeof(a));
			break;
		case 1:
			scanf("%d%d%d",&x,&y,&d);
			x++;y++;
			modify(x,y,d);
			break;
		case 2:
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			x++;y++;xx++;yy++;
			printf("%d\n",sum(xx,yy)+sum(x-1,y-1)-sum(xx,y-1)-sum(x-1,yy));
			break;
		case 3:
			return 0;
	}
	return 1;
}

int main(){
	while(scanf("%d",&k)!=EOF && work());
	return 0;
}
