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

#define N 2100

int n,a[N],b[N];
int ret[N],rig;

int build(const int &u,const int &v,const int &d){

	//printf("build %d->%d %d;\n",u,v,d);

	ret[u]=ret[v]-d;for(int i=u+1;i<v;i++){
		if(a[i]>v)return 1;
		ret[i]=ret[u]-1;
	}
	for(int i=u+1;i<v;i++){
		if(a[i]!=v && build(i,a[i],((d==0)?1:(d*10))))return 1;
	}
	return 0;
}

int main(){
	int T;scanf("%d",&T);
	for(int tim=1;tim<=T;tim++){printf("Case #%d:",tim);
		memset(b,0,sizeof(b));
		scanf("%d",&n);for(int i=1;i<n;i++){ scanf("%d",&a[i]);if(!b[a[i]])b[a[i]]=i; }
		for(int i=1;i<=n;i++)ret[i]=100000000;int pos=n;
		while(pos){
			while(pos && !b[pos])pos--;
			if(pos && b[pos] && build(b[pos],pos,0)){ printf(" Impossible");break; }
			if(pos)pos--;
		}
		if(!pos){
			for(int i=1;i<=n;i++)printf(" %d",ret[i]);
		}
		printf("\n");
	}
	return 0;
}
