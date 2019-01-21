#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1100000
#define maxl 10

int n,m;
int f[maxn],d[maxn],s[maxn];

char str[maxl];

int find(int x){
	int i,v,r=0;
	for(i=x;f[i]!=i;i=f[i])s[++r]=i;v=i;
	for(r--;r>0;r--){
		d[s[r]]^=d[s[r+1]];f[s[r]]=v;
	}
	return f[x];
}

void work(){
	int i,u,v;memset(d,0,sizeof(d));
	for(i=1;i<=n;i++)f[i]=i;
	while(m--){
		scanf("%s%d%d",str,&u,&v);
		switch(str[0]){
			case 'D':
				i=find(u);if(i==find(v))continue;
				d[i]^=(d[u]^1);f[i]=v;
				break;
			case 'A':
				if(find(u)!=find(v))
					printf("Not sure yet.\n");
				else{
					if(d[u]==d[v])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				}
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		work();
	}
	return 0;
}
