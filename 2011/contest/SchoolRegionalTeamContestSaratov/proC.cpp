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

#define N 110

int a[N];
int n,m;
int res;

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){res=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(3*m<a[i])
				res+=a[i]-3*m;
			else
				res+=a[i]%m;
		}
		printf("%d\n",res);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


