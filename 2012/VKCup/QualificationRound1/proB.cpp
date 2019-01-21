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

#define K 5

int c[K],n,ans;

int main(){

	
	memset(c,0,sizeof(c));

	while(scanf("%d",&n)!=EOF){ans=0;

	
		//printf("n=%d\n",n);

		for(int i=0;i<n;i++){
			int val;scanf("%d",&val);

			//printf("i=%d val=%d\n",i,val);

			c[val]++;
		}
	
		ans+=c[4];c[4]=0;
		ans+=c[3];c[1]-=c[3];c[3]=0;if(c[1]<0)c[1]=0;
		ans+=c[2]/2;c[2]%=2;
		ans+=c[2];c[1]-=c[2]*2;c[2]=0;if(c[1]<0)c[1]=0;
		ans+=c[1]/4;c[1]%=4;
		if(c[1]){ ans++;c[1]=0; }

		printf("%d\n",ans);

	}

	return 0;

}
