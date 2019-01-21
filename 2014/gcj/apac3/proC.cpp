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

#define N 1100000

int n, vid[N], que[N], num[N], stp[N];

int judge(int x){
	int count=0;
	while (x){
		if(vid[x%10])
			count++;
		else return -1;
		x/=10;
	}
	return count;
}

int main() {
	int T=0;scanf("%d", &T);
	for (int _T=1; _T<=T; _T++){
		printf("Case #%d: ", _T);
		for(int i=0; i<10; i++)scanf("%d", &vid[i]);
		scanf("%d", &n);que[0]=0;
		for(int i=1; i<=n; i++) 
			if(n%i==0)que[++que[0]]=i;
		for(int i=1; i<=n; i++)num[i]=judge(i);
		memset(stp, 0xff, sizeof(stp));
		for(int i=1; i<=que[0]; i++) {
			int temp=num[que[i]];
			if (~temp && (!~stp[i] || temp<stp[i]))stp[i]=temp;
			if (!~stp[i]) continue;
			for (int j=i+1; j<=que[0]; j++){
				if (que[j]%que[i] == 0){
					temp=num[que[j]/que[i]];
					if (~temp && (!~stp[j] || stp[i]+temp+1<stp[j])) 
					stp[j]=stp[i]+temp+1;
				}
			}	
		}
		if(!~stp[que[0]])
			printf("Impossible\n");
		else printf("%d\n", stp[que[0]]+1);
	}
	return 0;
}
