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

#define N 20
#define M 1100

map< string, int> s;
map< string, int>::iterator it;

int n,m,num,ans,top;
int fail[M],bit[N];

char str[M];
string nam,su,sv;

void init(){
	for(int i=0;i<N;i++)bit[i]=1<<i;
}

int bitnum(int x){
	int ret=0;
	for(;x;x>>=1)if(x&1)ret++;
	return ret;
}

int failed(int x){
	for(int i=0;i<m;i++)
		if((x&fail[i])==fail[i])return  1;
	return 0;
}

void work(){
	s.clear();num=0;
	
	for(int i=0;i<n;i++){
		scanf("%s",str);nam=str;
		s.insert(pair< string, int>( nam, 0));
	}
	for(it=s.begin();it!=s.end();it++){
		(*it).second=num++;
	}
	for(int i=0;i<m;i++){
		scanf("%s",str);su=str;
		scanf("%s",str);sv=str;
		int u=s[su],v=s[sv];
		fail[i] = bit[u] | bit[v];
	}

	ans=0;top=bit[n];
	for(int k=0;k<top;k++){

		//printf("k=%d\n",k);

		if(failed(k)){
			//printf("failed\n");
			continue;
		}
		//printf("succ\n");
		if(bitnum(k)>bitnum(ans))ans=k;
	}

	printf("%d\n",bitnum(ans));
	for(it=s.begin();it!=s.end();it++){
		if(ans&1)printf("%s\n",(*it).first.c_str());
		ans>>=1;
	}
}

int main(){init();
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

