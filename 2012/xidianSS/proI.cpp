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

#define M 250001
#define S 1000010

int prm[S],is[S],num;
int f[S],r[S],key;

void getprm(const int &n){num=1;prm[0]=1;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x7f,sizeof(is));
	prm[num++]=2;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[num++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[num++]=i;
}


int main(){

	getprm(M);memset(f,0,sizeof(f));
	for(int i=1;i<num;i++){
		for(int j=i;j<num;j++){
			if(((double)S)/((double)prm[j])<((double)prm[i]))break;
			f[prm[i]*prm[j]]=1;
			printf("f[%d]=1\n",prm[i]*prm[j]);
		}
	}
	r[0]=0;
	for(int i=1,k=0;i<S;i++){
		while(k<M && !f[k])k++;
		r[i]=r[i-1];
		if(k<M && (k*4+1)==i){
			r[i]++;k++;
		}
	}
	int n;while(scanf("%d",&n)!=EOF && n){
		printf("%d %d\n",n,r[n]);
	}
	return 0;
}
