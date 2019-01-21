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

#define N 10
#define L 30

int T;

map<string , int> n2i;
map<string , int>::iterator it;
string i2n[N],nam;

int a[N][N],n;
int p[N],q[N],pk[N],qk[N];
char s[L];

int comp(){
	int i,j;i=j=0;
	while(i<n && j<n){
		if(a[q[j]][p[i]])
			i++;
		else
			j++;
	}

	/*printf("COMP:\n		");
	for(int i=0;i<n;i++)printf(" %d",p[i]);printf("    ~    ");
	for(int i=0;i<n;i++)printf(" %d",q[i]);printf(" RES=%d\n",i!=n);*/

	if(i==n)return 0;
	return 1;
}

int dfs2(const int &k){
	if(k==n){
		return comp();
	}
	for(q[k]=1;q[k]<=n;q[k]++){
		if(qk[q[k]])continue;
		qk[q[k]]=1;
		if(!dfs2(k+1)){
			qk[q[k]]=0;
			return 0;
		}
		qk[q[k]]=0;
	}
	return 1;
}

int dfs1(const int &k){
	if(k==n){
		return dfs2(0);
	}
	for(p[k]=1;p[k]<=n;p[k]++){
		if(pk[p[k]])continue;
		pk[p[k]]=1;
		if(dfs1(k+1))return 1;
		pk[p[k]]=0;
	}
	return 0;
}

void work(){
	n2i.clear();printf("Case %d: ",T);

	int i;

	for(i=1;i<=n;i++){
		scanf("%s",s);nam=s;
		n2i.insert(pair<string,int>(nam,0));
	}
	for(i=0,it=n2i.begin();it!=n2i.end();it++){
		(*it).second=++i;
		i2n[i]=(*it).first;
	}

	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++){
		int k;scanf("%d",&k);
		while(k--){
			scanf("%s",s);nam=s;
			it=n2i.find(nam);
			a[i][(*it).second]=1;
		}
	}

	memset(pk,0,sizeof(pk));
	memset(qk,0,sizeof(qk));
	if(dfs1(0)){
		printf("Yes\n");
		for(i=0;i<n;i++){
			if(i)printf(" ");
			printf("%s",i2n[p[i]].c_str());
		}
		printf("\n");
	}else printf("No\n");
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d",&n);
		work();
	}
	return 0;
}
