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

#define N 11000
#define M 110

int n,m;
int u[N],v[N];

inline int cross(const int &l,const int &r,const int &u,const int &v){
	if(v<l ||u>r)return 0;
	return 1;
}

void work(){
	for(int i=0;i<n;i++){
		int src,des,sta,dur;
		scanf("%d%d%d%d",&src,&des,&sta,&dur);
		u[i]=sta;v[i]=sta+dur-1;
	}
	for(int i=0;i<m;i++){
		int sta,dur,tai,ans=0;
		scanf("%d%d",&sta,&dur);tai=sta+dur-1;
		for(int j=0;j<n;j++)if(cross(sta,tai,u[j],v[j]))ans++;
		printf("%d\n",ans);
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && (n || m))
		work();
	return 0;
}


