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

#define K 110
#define S 11000

int k,n,m;
int a[K],f[S];

int getSG(const int &x){
	if(f[x]>=0)return f[x];
	
	int v[K]={ 0 };
	for(int i=0;i<k;i++){
		int val=x-a[i];
		if(val<0)continue;
		if(f[val]<0)getSG(val);
		v[f[val]]=1;
	}

	//for(ret=0;!v[ret];)ret++;if(ret)ret--;
	for(f[x]=0;v[f[x]];f[x]++)f[x]++;
	return f[x];
}

void work(){

	memset(f,0x8f,sizeof(f));

	for(int i=0;i<k;i++)scanf("%d",&a[i]);
	scanf("%d",&m);

	while(m--){
		int ans=0;scanf("%d",&n);
		for(int i=0;i<n;i++){
			int val;scanf("%d",&val);
			ans^=getSG(val);
			//printf("ans=%d\n",ans);
		}
		if(ans)printf("W");else printf("L");
	}

	printf("\n");
}

int main(){
	while(scanf("%d",&k)!=EOF && k)
		work();
	return 0;
}


