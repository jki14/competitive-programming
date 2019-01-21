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

int n,ans;
int f[N][N];
int r[N][N][N];
char s[N];

void build(){
	memset(r,0,sizeof(r));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){	
			for(int k=1;i+k-1<=n && j+k-1<=n;k++){
				if(k>1 && r[i][j][k-1]!=0){
					r[i][j][k]=r[i][j][k-1];
					continue;
				}
				if(s[i+k-2]!=s[j+k-2])
					r[i][j][k]=(s[i+k-2]>s[j+k-2])?1:-1;
				else 
					r[i][j][k]=0;
			}
		}
	}
}

int cmp(int x1,const int &y1,int x2,const int &y2,const int &k){
	
	while(x1<y1 && s[x1-1]=='0')x1++;
	while(x2<y2 && s[x2-1]=='0')x2++;
	
	int ret,len=y1-x1+1;
	if(len != y2-x2+1)
		ret = len > (y2-x2+1);
	else{
		if(!r[x1][x2][len])return 0;
		ret = (r[x1][x2][len]==1)?1:0;
	}
	ret^=(k&1);
	return ret;
}

void work(){
	/* Init */
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		if(i&1)
			memset(f[i],0x3f,sizeof(f[i]));
		else
			memset(f[i],0xff,sizeof(f[i]));
	}
	for(int j=1;j<=n;j++)f[1][j]=j;
	build();
	/* Core */ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]<0 || f[i][j]>n)continue;
			for(int k=j+1;k<=n;k++){
				if(cmp(j-f[i][j]+1,j,j+1,k,i)){
					if(i&1)
						f[i+1][k]=max(f[i+1][k],k-j);
					else
						f[i+1][k]=min(f[i+1][k],k-j);
					//printf("f[%d][%d]=%d\n",i+1,k,f[i+1][k]);
				}
			}
		}
		if(f[i][n]>0 && f[i][n]<=n)ans=i-1;
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

