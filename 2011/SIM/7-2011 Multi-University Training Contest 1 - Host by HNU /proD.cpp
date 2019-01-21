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

#define maxlen 510
#define maxc 60

const int inf=0x3fffffff;

int n,m,c;
char a[maxlen],b[maxlen];
int f[maxlen][maxlen][maxc];
int g[maxlen][maxlen];

char s[maxc];

void init(){
	char i;c=0;s[c++]='?';
	for(i='A';i<='Z';i++)s[c++]=i;
	for(i='a';i<='z';i++)s[c++]=i;
}

void work(){
	int i,j,k,cost,suf;
	scanf("%s",b);
	n=strlen(a);m=strlen(b);
	//for(i=0;i<n;i++)if(a[i]<='Z')a[i]+='a'-'A';
	//for(i=0;i<n;i++)if(b[i]<='Z')a[i]+='a'-'A';

	//printf("%s\n",a);
	//printf("%s\n",b);

	//printf("c=%d\n",c);

	a[n]=b[m]='$';
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	/*g[n][m]=1;f[n][m][0]=0;
	for(k=1;k<c;k++)f[n][m][k]=1;
	for(i=0;i<n;i++)for(k=0;k<c;k++)f[i][m][k]=n-i+(k>0);
	for(i=0;i<m;i++)for(k=0;k<c;k++)*/
	for(i=0;i<=n;i++){
		for(k=0;k<c;k++)f[i][m][k]=n-i+(k>0);
		g[i][m]=f[i][m][1];
	}
	for(j=0;j<=m;j++){
		for(k=0;k<c;k++)f[n][j][k]=m-j+(k>0);
		g[n][j]=f[n][j][1];
	}

	
	//printf("n=%d m=%d\n",n,m);
	for(i=n-1;i>=0;i--)
		for(j=m-1;j>=0;j--){
			for(k=0;k<c;k++){cost=1;suf=1;
				
				//printf("a[%d]=%c b[%d]=%c f[%d][%d][%c]===\n",i,a[i],j,b[j],i,j,s[k]);
				
				if((k && s[k]==b[j]) || (!k && a[i]==b[j]))cost=0;
				if(!k)suf=0;
				
				if(f[i][j][k]>g[i+1][j+1]+cost+suf){
					//printf("	path g[%d][%d](%d)+cost(%d)+suf(%d)\n",i+1,j+1,g[i+1][j+1],cost,suf);
					f[i][j][k]=g[i+1][j+1]+cost+suf;
				}
				
				if(f[i][j][k]>g[i+1][j]+1+suf){
					//printf("	path g[%d][%d](%d)+1+suf(%d)\n",i+1,j,g[i+1][j],suf);
					f[i][j][k]=g[i+1][j]+1+suf;
				}
				
				if(f[i][j][k]>g[i][j+1]+1+suf){
					//printf("	path g[%d][%d](%d)+1+suf(%d)\n",i,j+1,g[i][j+1],suf);
					f[i][j][k]=g[i][j+1]+1+suf;
				}
				
				if(f[i][j][k]>f[i+1][j+1][k]+cost){
					//printf("	path f[%d][%d][%c](%d)+cost(%d)\n",i+1,j+1,s[k],f[i+1][j+1][k],cost);
					f[i][j][k]=f[i+1][j+1][k]+cost;
				}
				
				if(f[i][j][k]>f[i+1][j][k]+1){
					//printf("	path f[%d][%d][%c](%d)+1\n",i+1,j,s[k],f[i+1][j][k]);
					f[i][j][k]=f[i+1][j][k]+1;
				}
				
				if(f[i][j][k]>f[i][j+1][k]+1){
					//printf("	path f[%d][%d][%c](%d)+1\n",i,j+1,s[k],f[i][j+1][k]);
					f[i][j][k]=f[i][j+1][k]+1;
				}

				//printf("	f[%d][%d][%c]=%d\n",i,j,s[k],f[i][j][k]);

				if(k)g[i][j]=min(g[i][j],f[i][j][k]);
			}
		}

	printf("%d\n",min(g[0][0],f[0][0][0]));
}

int main(){
	init();
	while(scanf("%s",a)!=EOF && a[0]!='#')work();
	return 0;
}

