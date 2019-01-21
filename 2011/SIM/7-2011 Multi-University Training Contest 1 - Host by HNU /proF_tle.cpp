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

#define maxn 11000

set<int> s;
set<int>::iterator it;

int n;
int a[maxn],v[maxn];

void work(){
	int i,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(v,0,sizeof(v));
	s.clear();s.insert(a[1]);v[a[1]]=1;
	for(i=2;i<n;i++){
		v[a[i]]=1;
		for(it=s.begin();it!=s.end();it++){
			if((*it)>=a[i]*2)break;
			k=a[i]*2-(*it);
			if(k>0 && k<=n && k!=(*it) && !v[k]){
				printf("Y\n");
				return;
			}
		}
		s.insert(a[i]);
	}
	printf("N\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}


