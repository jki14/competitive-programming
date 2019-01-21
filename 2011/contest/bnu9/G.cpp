#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 1100
#define maxm 11000

int n,m;
int a[maxn];
vector<int> b[maxm];

void work(){
	int i,j,k,l;
	for(i=0;i<m;i++)
		b[i].clear();
	for(i=0;i<n;i++){
		scanf("%d",&k);
		k%=m;a[i]=k;
		b[k].push_back(i);
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			l=m-(a[i]+a[j])%m;l%=m;
			for(k=0;k<(int)b[l].size();k++){
				if(b[l][k]!=i && b[l][k]!=j){
					printf("%d %d %d\n",i+1,j+1,b[l][k]+1);
					return;
				}
			}
		}
	printf("-1\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

