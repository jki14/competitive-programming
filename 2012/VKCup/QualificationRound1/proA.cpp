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

int n,k,ans,pre;

int main(){

	while(scanf("%d%d",&n,&k)!=EOF){ans=pre=0;
		
		for(int i=0;i<n;i++){

			int val;scanf("%d",&val);
			
			//printf("ans=%d val=%d pre=%d\n",ans,val,pre);

			if(!val)continue;
			
			if(ans<k){
				ans++;
				pre=val;
			}else if(val==pre)ans++;

		}

		printf("%d\n",ans);
	}

	return 0;
}
