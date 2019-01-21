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

#define N 51000
#define L 110

int T;

int n,m;
int lowbit[N];
int c[N],a[N],b[N];

char cstr[L];

void modify(int x,const int &d){
	//printf("M %d += %d\n",x,d);
	for(;x<=n;x+=lowbit[x])c[x]+=d;
}

int  sum(int x){int ret=0;
	for(;x>0;x-=lowbit[x])ret+=c[x];
	return ret;
}

int  querry(const int &x,const int &y){
	if(x>y)return 0;
	return sum(y)-sum(x-1);
}

void init(){
	for(int i=0;i<N;i++)lowbit[i]=i&(-i);
}

int rud(){
	int ret;char ch;
	do{
		ch = getchar() ;
	}while(ch<'0');
	ret = ch - '0' ;
	while((ch = getchar()) >= '0'){
		ret = ret * 10 + ch - '0' ;
	}
	return ret;
}

void pd(const int &x){
	int k=(x<0)?-x:x,r=0;
	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	if(x<0)putchar('-');
	while(r--){
		putchar(cstr[r]);
	}
	putchar('\n');
}

void work(){
	int i,opt,t,u,v;
	char chr;
	
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));

	//scanf("%d%d",&n,&m);chr=getchar();
	n=rud();m=rud();
	for(i=1;i<=n;i++){
		chr=getchar();
		//printf("chr=%c\n",chr);
		a[i]=(chr=='b');
	}a[0]=1;a[n+1]=1;

	for(i=1;i<=n;i++){
		if(a[i] && !a[i-1] && !a[i+1]){
			b[i]=1;
			modify(i,1);
		}
	}

	printf("Case %d:\n",T);
	for(i=1;i<=m;i++){
		opt=rud();
		if(opt){
			u=rud();u++;
			//chr=getchar();
			chr=getchar();
			t=(chr=='b');
			if(a[u]==t)continue;

			if(b[u-1]){ b[u-1]=0;modify(u-1,-1); }
			if(b[u]  ){ b[u  ]=0;modify(u  ,-1); }
			if(a[u+1]){ b[u+1]=0;modify(u+1,-1); }

			a[u]=t;
			if(a[u-1] && !a[u] && !a[u-2]){ b[u-1]=1;modify(u-1,1); }
			if(a[u] && !a[u-1] && !a[u+1]){ b[u  ]=1;modify(u  ,1); }
			if(a[u+1] && !a[u] && !a[u+2]){ b[u+1]=1;modify(u+1,1); }
		}else{
			u=rud();v=rud();u++;v++;
			//printf("%d\n",querry(u+1,v-1));
			pd(querry(u+1,v-1));
		}
	}

}

int main(){init();//int t;while(scanf("%d",&t)!=EOF){
	int t;t=rud();
	for(T=1;T<=t;T++)work();
	//}
	printf("\n");
	return 0;
}

