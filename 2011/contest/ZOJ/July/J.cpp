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

#define maxn 510
#define maxm 1100

multiset<int> a;
multiset<int>::iterator it;

int n,m,res;

void work(){
	int i,k;res=m;
	a.clear();
	for(i=0;i<n;i++){
		scanf("%d",&k);
		a.insert(k);
	}
	for(i=0;i<n;i++){
		it=a.upper_bound(res);
		if(it!=a.end()){
			res+=2;
			a.erase(it);
		}else{
			res+=n-i;
			break;
		}
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

