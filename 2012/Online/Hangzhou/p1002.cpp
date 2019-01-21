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

const int MAXN = 150;
const int inf = 0x3fffffff;

#define _clr(x) memset(x,0xff,sizeof(x))

#define min(x,y) ((x<y)?x:y)

int num,mat[MAXN][MAXN],match1[MAXN],match2[MAXN];

int KM(){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<num;i++)
		for (l1[i]=-inf,j=0;j<num;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<num;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<num;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<num&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j];t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p){
							match2[j]=k=t[j];
							p=match1[k];
							match1[k]=j;
						}
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<num;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<num;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<num;i++)
		ret+=mat[i][match1[i]];
	return ret;
}

int n,m,k,ans;
int c[MAXN][MAXN];

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF && !(n==0 && m==0 && k==0)){
		memset(c,0x3f,sizeof(c));ans=0x3fffffff;
		for(int i=0;i<m;i++){ int u,v,len;scanf("%d%d%d",&u,&v,&len);c[u][v]=c[v][u]=min(c[u][v],len); }
		for(int p=0;p<=n;p++)
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
					c[i][j]=min(c[i][j],c[i][p]+c[p][j]);
	
		memset(mat,0x80,sizeof(mat));//printf("%d",mat[0][0]);
		num=n;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				mat[i-1][j-1]=-c[i][j];

		for(int i=0;i<k;i++){++num;
			for(int i=1;i<=n;i++)mat[num-1][i-1]=mat[i-1][num-1]=-c[0][i];	
			ans=min(ans,-KM());
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
