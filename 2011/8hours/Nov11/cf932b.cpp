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

#define N 110

int f[N],n;

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(f,0,sizeof(f));
		for(int i=0;i<n;i++){
			int val;scanf("%d",&val);
			f[val]++;
		}
		int ans=0;
		for(int i=0;i<N;i++)ans+=f[i]>>1;
		ans>>=1;
		printf("%d\n",ans);
	}
	return 0;
}
