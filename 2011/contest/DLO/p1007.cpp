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
#include<set>
#include<map>
using namespace std;

#define maxn 1100

map<int,int> s;
map<int,int>::iterator it;

int n,m,ans;
int x[maxn],y[maxn];
int rgx[4][2],rgy[4][2];

void work(){
	int i,j,k,ret;ans=0;
	rgx[0][0]=-m;rgy[0][0]=-m;
	rgx[1][0]=-m;rgy[1][0]= 0;
	rgx[2][0]= 0;rgy[2][0]=-m;
	rgx[3][0]= 0;rgy[3][0]= 0;
	rgx[0][1]= 0;rgy[0][1]= 0;
	rgx[1][1]= 0;rgy[1][1]= m;
	rgx[2][1]= m;rgy[2][1]= 0;
	rgx[3][1]= m;rgy[3][1]= m;

	for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
	for(i=0;i<n;i++){
		for(k=0;k<4;k++){ret=0;
			for(j=0;j<n;j++){
				if((x[j]>=x[i]+rgx[k][0] && x[j]<=x[i]+rgx[k][1])
				&& (y[j]>=y[i]+rgy[k][0] && y[j]<=y[i]+rgy[k][1]))ret++;
			}
			ans=max(ans,ret);
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

