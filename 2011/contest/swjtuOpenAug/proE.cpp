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

#define maxlen 110
#define maxsta 60000
#define K 4

const int dk[K]={ -1,1,-2,2 };
const int kp[K]={  1,0, 3,2 };

int T;

int n,f[maxsta],k[maxsta],skp[maxsta];
char sta[maxsta][maxlen];

int succ(char *state){
	int k=0;
	for(;*state;state++){
		if(k==0 && (*state)=='B')k=1;
		if(k==1 && (*state)=='W')k=2;
		if(k==2 && (*state)=='B')return 0;
	}
	return 1;
}

int work(){
	int i,j,head,tail;
	n=strlen(sta[0]);
	for(i=0;i<n;i++)if(sta[0][i]=='F')k[0]=i;
	head=tail=0;
	f[0]=0;skp[0]=-1;
	for(;head<=tail;head++){
		
		//printf("f[%s]===%d\n",sta[head],f[head]);

		if(succ(sta[head]))return f[head];
		if(f[head]==9)continue;
		for(i=0;i<K;i++){if(skp[head]==i)continue;
			if(k[head]+dk[i]<0 || k[head]+dk[i]>=n)continue;
			f[++tail]=f[head]+1;k[tail]=k[head]+dk[i];skp[tail]=kp[i];
			for(j=0;j<=n;j++)sta[tail][j]=sta[head][j];
			swap(sta[tail][k[head]],sta[tail][k[tail]]);
			if(i>1)sta[tail][k[head]]=(sta[tail][k[head]]=='W')?'B':'W';
		}
	}
	return -1;
}

int main(){T=0;
	while(scanf("%s",sta[0])!=EOF && sta[0][0]!='-'){T++;
		printf("%d. %d\n",T,work());
	}
	return 0;
}


