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

#define maxn 10
#define maxm 20

const int inf=0x3ffffff;

map<char,int> s;
map<char,int>::iterator it;

int T;

int n,m,ans;
int a[2][maxn],.;
char c[2][maxn];

void work(){
	int i,j,k,l,p;
	
	scanf("%d",&n);
	scanf("%s",c[0]);scanf("%s",c[1]);
	s.clear();m=0;
	for(i=0;i<2;i++)
		for(j=0;j<n;j++){
			s.insert(pair<char,int>(c[i][j],0));
		}
	for(it=s.begin();it!=s.end();it++){ (*it).second=m++; }
	
	memset(f,0x3f,sizeof(f));
	for(i=0;i<2;i++)for(j=0;j<n;j++)for(p=0;p<m;p++)f[i][j][j][p]=2;
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){it=s.find(c[i][j]);a[i][j]=(*it).second;
			f[i][j][j][a[i][j]]=1;
			printf("%d",a[i][j]);
		}
		printf("\n");
	}

	for(l=1;l<n;l++)
		for(i=0;i<2;i++)
			for(j=0;j+l<n;j++){
				for(k=j;k<j+l;k++)
					for(p=0;p<m;p++){
						f[i][j][j+l][p]=min(f[i][j][j+l][p],f[i][j][k][p]+f[i][k+1][j+l][p]-1-(l>1 && a[i][k]==a[i][k+1]));
						printf("f[%d][%d][%d][%d]=%d f[%d][%d][%d][%d]=%d ",i,j,k,p,f[i][j][k][p],
								i,k+1,j+l,p,f[i][k+1][j+l][p]);
						printf("f[%d][%d][%d][%d]=%d\n",i,j,j+l,p,f[i][j][j+l][p]);
					}
			}

	for(l=0;l<n;l++)
		for(j=0;j+l<n;j++){
			for(p=0;p<m;p++){
				f[2][j][j+l][p]=f[0][j][j+l][p]+f[1][j][j+l][p]-1;
				if(l){
					for(k=j;k<j+l;k++)
						f[2][j][j+l][p]=min(f[2][j][j+l][p],f[2][j][k][p]+f[2][k+1][j+l][p]-1);
				}
			}
		}

	ans=inf;
	for(p=0;p<m;p++)ans=min(ans,f[2][0][n-1][p]);
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

