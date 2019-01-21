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

#define maxn 11000
#define len 10

int n;
int head[maxn],worm[maxn];
int leaf[maxn],succ[maxn],fail[maxn];

int s[maxn],f[maxn],c[maxn],r;

char cstr[len];

vector<int> chil[maxn];

double ans;

void dp(int root){
	int i,j,k,chi=(int)chil[root].size();
	int cost,rem;

	//printf("DP %d chi=%d\n",root,chi);

	if(!chi){
		leaf[root]=1;
		succ[root]=0;
		fail[root]=0;
		return;
	}
	leaf[root]=succ[root]=fail[root]=0;
	for(i=0;i<chi;i++){
		dp(chil[root][i]);
		fail[root]+=fail[chil[root][i]]+2;
		succ[root]+=succ[chil[root][i]]+leaf[chil[root][i]];
		leaf[root]+=leaf[chil[root][i]];
		//que[i]=chil[root][i];
		//printf(" que [ %d ] = %d \n",i,que[i]);
	}
	memset(f,0x7f,sizeof(f));
	memset(c,0x7f,sizeof(c));
	f[0]=0;c[0]=leaf[root];
	r=0;s[r++]=0;
	for(i=0;i<r;i++){
		for(j=0;j<chi;j++){
			if((s[i]&(1<<j))!=0)continue;
			k=s[i]|(1<<j);rem=c[s[i]]-leaf[chil[root][j]];
			cost=f[s[i]]+rem*(fail[chil[root][j]]+2);
			
			//printf("Try Update: %d from %d rem=%d cost=%d\n",k,chil[root][j],rem,cost);

			if(f[k]>cost || (f[k]==cost && c[k]>rem)){
				if(f[k]==f[10000])s[r++]=k;
				f[k]=cost;
				c[k]=rem;
			}
		}
	}
	succ[root]+=f[s[r-1]];
	if(worm[root])fail[root]=0;

	//printf("succ[%d]=%d(f[%d]=%d) fail[%d]=%d leaf[%d]=%d\n",root,succ[root],s[r-1],f[s[r-1]],root,fail[root],root,leaf[root]);

}

void work(){
	int i;
	memset(worm,0,sizeof(worm));
	for(i=0;i<=n;i++)chil[i].clear();
	for(i=1;i<=n;i++){
		scanf("%d%s",&head[i],cstr);
		if(head[i]==-1)head[i]++;
		chil[head[i]].push_back(i);
		if(cstr[0]=='Y')worm[i]=1;
	}
	dp(1);
	ans=((double)succ[1])/((double)leaf[1]);
	printf("%.4f\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

