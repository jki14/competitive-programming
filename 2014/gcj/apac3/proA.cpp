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

#define N 345

#define ii i+di[k]
#define jj j+dj[k]
#define cool (ii>=0 && ii<n && jj>=0 && jj<n)

const int di[8]={ -1,1,0,0,-1,-1,1,1 };
const int dj[8]={ 0,0,-1,1,-1,1,-1,1 };

const int inf = 0x3f3f3f3f;

char a[N][N];
int n, ans, c[N][N], mrk[N][N];

void dfs(const int &i, const int &j){
	if(mrk[i][j])return;
	mrk[i][j]=1;
	if(c[i][j]!=0)return;
	for(int k=0;k<8;k++)
		if(cool)dfs(ii, jj);
}

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		printf("Case #%d: ", _T);
		scanf("%d", &n);
		for(int i=0;i<n;i++)scanf("%s", a[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]=='*')
					c[i][j]=inf;
				else c[i][j]=0;
				for(int k=0;k<8;k++)
					if(cool && a[ii][jj]=='*')c[i][j]++;
			}
		}
		ans=0;
		memset(mrk,0,sizeof(mrk));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!c[i][j] && !mrk[i][j]){
					dfs(i, j);
					ans++;
				}
			}
		}
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(a[i][j]!='*' && !mrk[i][j])ans++;
		printf("%d\n", ans);
	}
	return 0;
}

