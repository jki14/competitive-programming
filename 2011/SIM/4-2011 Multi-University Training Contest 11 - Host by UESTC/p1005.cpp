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

typedef long long lld;

#define maxk 11000
#define maxp 2000
#define K 10000

int T;

int n,m,k,ret;
int sum,num,tra[maxk];
int mk[maxk],prm[maxk];

vector<int> f[maxp];

int inverse(const int &a,const int &b){
	int k;
	int x1,x2,x3;
	int y1,y2,y3;
	int t1,t2,t3;
	if(!a || !b)return 1;
	x1=1;x2=0;x3=a;
	y1=0;y2=1;y3=b;
	if(x3<y3)swap(x3,y3);
	for(t3=x3%y3;t3!=0;t3=x3%y3){
		k=x3/y3;

		t1=x1-k*y1;
		t2=x2-k*y2;

		x1=y1;x2=y2;x3=y3;
		y1=t1;y2=t2;y3=t3;
	}
	if(y3!=1)return 1;
	return (y2%b+b)%b;
}

void getprm(){
	int i,j;num=sum=0;
	int s,e=(int)(sqrt((double)K)+1);
	memset(mk,0,sizeof(mk));
	prm[++num]=2;mk[0]=mk[1]=1;
	for(i=4;i<K;i+=2)mk[i]=1;
	for(i=3;i<e;i+=2)if(!mk[i]){
		prm[++num]=i;
		for(s=i*2,j=i*i;j<K;j+=s)mk[j]=1;
	}
	for(;i<K;i+=2)if(!mk[i])prm[++num]=i;
}

void init(){
	int i,j;
	getprm();
	
	for(i=1;i<=num;i++){tra[prm[i]]=i;
		f[i].clear();for(j=0;j<prm[i];j++)f[i].push_back(0);
		
		f[i][0]=0%prm[i];
		f[i][1]=1%prm[i];

		for(j=2;j<prm[i];j++){
			f[i][j]=(f[i][j-1]*j)%prm[i];
			//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	}		

	/*for(i=1;i<=num;i++)sum+=prm[i];
	printf("num=%d top=%d sum=%d\n",num,prm[num],sum);*/
}

void work(){if(m>(n>>1))m=n-m;n++;

	ret=0%k; 
	
	if(n<k)ret=f[tra[k]][n];
	//printf("f[%d][%d]=%d\n",k,n,ret);

	if(n-m<k)ret=(ret*inverse(f[tra[k]][n-m],k))%k;
	//printf("ret*inv[%d][%d](f=%d)=%d\n",k,n-m,f[k][n-m],ret);

	if(m<k)ret=(ret*inverse(f[tra[k]][m],k))%k;
	//printf("ret*inv[%d][%d](f=%d)=%d\n",k,m,f[k][m],ret);

	printf("C(%d,%d) mod %d=%d\n",n,m,k,ret);
	ret+=n-m-1;ret%=k;
	printf("Case #%d: %d\n",T,ret);
}

int main(){
	init();T=1;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		work();
		T++;
	}
	return 0;
}

