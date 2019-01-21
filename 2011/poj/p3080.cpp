#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
using namespace std;

#define maxl 100
#define maxn 21
#define maxm 5000

const int L=60;
const int inf=LONG_MAX;

int n,m,rid;
char s[maxn][maxl];
int subs[maxm],subt[maxm];
int mk[maxm];
int v[maxl][maxl];
int f[maxl][maxl];

int better(const int &x){
	if(rid==-1)return 1;
	if(subt[rid]-subs[rid] < subt[x]-subs[x])return 1;
	if(subt[rid]-subs[rid] > subt[x]-subs[x])return 0;
	int i,j;
	for(i=subs[x],j=subs[rid];i<subt[x];i++,j++){
		if(s[0][i]==s[0][j])continue;
		return s[0][i]<s[0][j];
	}
	return 0;
}

void work(){
	int i,j,k,p,top;m=0;
	for(i=0;i<n;i++)scanf("%s",s[i]);
	memset(v,0,sizeof(v));	
	subs[m]=0;subt[m]=L;mk[m]=0;
	v[subs[m]][subt[m]]=1;m++;
	for(p=1;p<n;p++){
		for(k=0;k<m;k++){
			if(mk[k]>=p)continue;
			memset(f,0,sizeof(f));
			for(i=top=0;i<L;i++)
				for(j=subs[k];j<subt[k];j++){
					if(s[p][i]!=s[0][j])continue;
					if(i-1<0 || j-1<subs[k])f[i][j]=1;
					f[i][j]=f[i-1][j-1]+1;
					f[i-1][j-1]=0;
					top=max(top,f[i][j]);
				}
			if(top<subt[k]-subs[k]){
				mk[k]=inf;
				for(i=0;i<L;i++)
					for(j=subs[k];j<subt[k];j++){
						if(f[i][j]<3)continue;
						subs[m]=j-f[i][j]+1;
						subt[m]=j+1;
						mk[m]=p;
						if(v[subs[m]][subt[m]])continue;
						v[subs[m]][subt[m]]=1;
						m++;
					}
			}
		}
	}
	for(i=0,rid=-1;i<m;i++){
		if(mk[i]==inf)continue;
		if(better(i))rid=i;
	}
	if(rid==-1){
		printf("no significant commonalities\n");
	}else{
		for(i=subs[rid];i<subt[rid];i++)
			printf("%c",s[0][i]);
		printf("\n");
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		work();
	}
	return 0;
}

