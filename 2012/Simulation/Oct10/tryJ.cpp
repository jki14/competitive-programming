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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define M 10
#define N 50

#define L (i<<1)
#define R (i<<1)+1

int a[N],mk[N],res;
int d,n;

int tree(){
	for(int i=1;i<=n;i++)if(!mk[i])return 0;
	for(int i=(1<<(d-1));i<(1<<d);i++)
		if(a[i])return 1;
	return 0;
}

int check(const int &i,const int &top){
	if(!a[i] || i>=top)return -1;
	int lef=check(L,top),rig=check(R,top);
	if(!lef || !rig)return 0;
	if(lef!=-1 && rig!=-1 && lef>rig)return 0;
	int res=a[i];
	res=max(res,lef);
	res=max(res,rig);
	//printf("res=%d\n",res);
	return res;
}

void build(const int &i,const int &top){
	if(i==top){
	
		//printf("{");for(int j=1;j<top;j++)printf(" %d",a[j]);printf(" }\n");

		if(tree() && check(1,top))res++;

		return;
	}
	if(!a[i>>1]){
		a[i]=0;
		build(i+1,top);
	}else{
		for(a[i]=0;a[i]<=n;a[i]++){
			if(a[i] && mk[a[i]])continue;
			mk[a[i]]=1;
			build(i+1,top);
			mk[a[i]]=0;
		}
	}
	
}

int main(){
	memset(mk,0,sizeof(mk));a[0]=0x3fffffff;
	for(d=1;d<=4;d++)
		for(n=d;n<(1<<d);n++){
			res=0;
			build(1,1<<d);
			printf("<%d,%d>==%d\n",n,d,res);
		}
}
