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

typedef pair<int,int> PII;

int n,m,sum,i;
/*queue<PII> q;
PII state,next;*/

void work(){
	scanf("%d%d",&n,&m);
	//printf("n=%d m=%d\n",n,m);
	if(n==0){ printf("YES\n");return; }
	/*state.first=0;state.second=1;
	while(!q.empty())q.pop();
	q.push(state);
	while(!q.empty()){
		state=q.front();q.pop();
		//++
		next=state;
		next.first+=next.second;
		//printf("Next State: %d,%d\n",next.first,next.second);
		if(next.first==n){ printf("YES\n");return; }
		next.second++;
		if(next.second<=m){
			q.push(next);
		}
		//--
		next=state;
		next.first-=next.second;
		if(next.first==n){ printf("YES\n");return; }
		next.second++;
		if(next.second<=m){
			q.push(next);
		}
	}
	printf("NO\n");*/
	/*sum=(1+m)*m/2;
	for(int i=0;i<=sum;i++){
		if(sum-(i<<1)==n){
			printf("YES\n");
			return;
		}
	}*/
	for(i=sum=0;i<=m;i++){sum+=i;
		if(sum>=n && (((sum-n)&1)==0) && ((sum-n)>>1)<sum){
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

