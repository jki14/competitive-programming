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

#define N 1100

int n,ans,mov;
int a[N],f[N],g[N];

int gcd(int x,int y){
	while(y){
		int k=x%y;
		x=y;y=k;
	}
	return x;
}

void work(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(gcd(a[i],a[j])==1){
				f[i]++;f[j]++;
			}else{
				//printf("%d %d\n",i,j);
				g[i]++;g[j]++;
			}
		}

	ans=(n*(n-1)*(n-2))/6;
	mov=0;
	for(int i=0;i<n;i++){
		mov+=f[i]*g[i];
	}
	mov>>=1;ans-=mov;

	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

