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

#define N 110000
#define M 210000

const int inf=0x3ffffff;

int n,mov,suc,a[N];
int pos[N],bak[N];
int optx[M],opty[M],num;
int que[N],tail,mk[N];

int check(int x){
	if(x==0)return x;
	for(;x;x/=10){
		int k=x%10;
		if(k!=4 && k!=7)return 0;
	}
	return 1;
}

int cmp(const int &i,const int &j){ return a[i]<a[j]; }

void work(){
	for(int i=0;i<n;i++)scanf("%d",&a[pos[i]=i]);a[n]=inf;
	sort(pos,pos+n,cmp);for(int i=0;i<n;i++)bak[pos[i]]=i;

	/*printf("bak:");
	for(int i=0;i<n;i++)printf(" %d",bak[i]);
	printf("\n");*/

	mov=-1;suc=1;
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1])suc=0;
		if(check(a[i]))mov=i;
	}
	
	if(suc){
		printf("0\n");
		return;
	}else{
		if(mov==-1){
			printf("-1\n");
			return;
		}
	}
	
	//printf("work work!\n");

	num=0;memset(mk,0,sizeof(mk));
	for(int i=0;i<n;i++){
		if(pos[i]==i || mk[i])continue;
		tail=0;int src=-1;
		for(int j=i;!mk[j];j=bak[j]){
			mk[j]=1;que[tail++]=j;
			if(check(a[j]))src=tail-1;
		}
		
		/*printf("src=%d\nque:",src);
		for(int j=0;j<tail;j++)printf(" %d",que[j]);
		printf("\n");*/

		if(src==-1){
			++num;optx[num]=mov;opty[num]=que[tail-1];
			for(int j=tail-1;j>0;j--){
				++num;optx[num]=que[j];opty[num]=que[j-1];
			}
			++num;optx[num]=mov;opty[num]=que[0];
		}else{
			for(int j=src;((j-1+tail)%tail)!=src;j=(j-1+tail)%tail){
				//printf("j=%d que[%d]=%d\n",j,j,que[j]);
				++num;optx[num]=que[j];opty[num]=que[(j-1+tail)%tail];
				if(optx[num]==mov)
					mov=opty[num];
				else if(opty[num]==mov)
					mov=optx[num];
			}
		}
	}

	if(num>n*2)while(1);

	printf("%d\n",num);
	for(int i=1;i<=num;i++)
		printf("%d %d\n",optx[i]+1,opty[i]+1);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

