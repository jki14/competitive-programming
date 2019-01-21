#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 12
#define nlmt 13

const int maxt=1<<maxn;
const int modd=1000000000;

int n,m,f[nlmt][maxt],a[nlmt];

int allow(int x,int k){
	if(k&a[x])return 0;
	for(;k;k>>=1){
		if((k&3)==3)return 0;
	}
	return 1;
}

int pick(int j,int k){
	return (j&k)==0;
}

void work(){
	int i,j,k,val,T=1<<m;//cout<<"T="<<T<<endl;
	memset(a,0,sizeof(a));memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)for(j=0;j<m;j++){
		scanf("%d",&val);a[i]<<=1;a[i]|=!val;
	}
	f[0][0]=1;
	for(i=0;i<n;i++)
		for(j=0;j<T;j++)if(allow(i,j))
			for(k=0;k<T;k++)if(allow(i+1,k) && pick(j,k)){
				f[i+1][k]+=f[i][j];
				f[i+1][k]%=modd;
				//cout<<" f["<<i+1<<"]["<<k<<"]+=f["<<i<<"]["<<j<<"]"<<endl;
			}
	for(k=val=0;k<T;k++){ val+=f[n][k];val%=modd;}
	printf("%d\n",val%modd);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
