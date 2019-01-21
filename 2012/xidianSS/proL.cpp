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

#define S 110

int s[S],n;

int main(){
	int T;scanf("%d",&T);
	s[0]=0;for(int i=1;i<10;i++)s[i]=s[i-1]+i;	
	while(T--){int ans=0;
		scanf("%d",&n);if(n<10)ans++;
		for(int i=1;i<9;i++)
			for(int j=i;j<9;j++)
				if(((s[j]-s[i-1])*2+j+1)==n)ans++;
		printf("%d\n",ans);
	}
	return 0;
}
