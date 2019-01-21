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

#define S 1100

int n,m,x,y,ansd,ansc;
int ad[S],bd[S],ac[S][S],bc[S][S];

void work(){
	
	ansd=ansc=0;
	memset(ad,0,sizeof(ad));
	memset(bd,0,sizeof(bd));
	memset(ac,0,sizeof(ac));
	memset(bc,0,sizeof(bc));

	for(int i=0;i<n;i++){ scanf("%d%d",&x,&y);ad[y]++;ac[x][y]++; }
	for(int i=0;i<m;i++){ scanf("%d%d",&x,&y);bd[y]++;bc[x][y]++; }

	for(int i=0;i<S;i++) ansd+=min(ad[i],bd[i]);
	for(int i=0;i<S;i++)
		for(int j=0;j<S;j++)
			ansc+=min(ac[i][j],bc[i][j]);

	printf("%d %d\n",ansd,ansc);

}

int main(){
	
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;

}

