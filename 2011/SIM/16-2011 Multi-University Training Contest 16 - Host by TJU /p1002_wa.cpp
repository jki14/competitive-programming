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

#define N 13
#define S 4100
#define T 930

const double eps = 1e-8;

int n,a[N],b[N];
double f[S],g[N];
int id[S],bit[N];

vector<int> vec[N];

int bitnum(int x){
	int ret=0;
	for(;x;x>>=1)
		if(x&1)ret++;
	return ret;
}

void build(){
	//build bit & clear vec
	for(int i=0;i<=n;i++){
		bit[i]=1<<i;
		vec[i].clear();
		if(i)g[i]=g[i-1]*((double)i);else g[i]=1.0;
	}
	//build s & num & id;
	int e=1<<n;
	for(int i=0;i<e;i++)vec[bitnum(i)].push_back(i);
	for(int k=0;k<=n;k++){
		int size=vec[k].size();
		for(int i=0;i<size;i++)id[vec[k][i]]=i;
	}
}

double call(const int &k){
	double ret=0.0;
	for(int i=0;i<n;i++){
		if(a[k]>b[i])
			ret+=3.0;
		else if(a[k]>b[i])ret+=1.0;
	}
	return ret;
}

double C(const int &x,const int &y){
	return g[x]/g[y]/g[x-y];
}

void work(){
	/* Init */
	scanf("%d",&n);build();
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	memset(f,0,sizeof(f));
	/* Core */
	for(int k=1;k<=n;k++){
		int size=vec[k].size();
		for(int i=0;i<size;i++){
			int asta=vec[k][i];
			for(int ah=0;ah<n;ah++){
				if(!(asta&bit[ah]))continue;
				int anex=asta^bit[ah];
				f[asta]=max(f[asta],(f[anex]*C(n,k-1)+call(ah)*C(n-1,k-1))/C(n,k));
			}
			//printf("f[%d]=%.6f\n",asta,f[asta]);
		}
	}
	int full=(1<<n)-1;
	//printf("full=%d\n",full);
	printf("%.6f\n",f[full]+eps);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

