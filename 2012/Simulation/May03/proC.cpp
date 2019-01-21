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

#define K 2
#define N 110000
#define Type 210000

struct SubTree{
	int L,R;
	bool operator < (const SubTree &st) const{
		return (st.L==L) ? st.R<R : st.L<L ;
	}
};

typedef long long lld;

map<SubTree,int> s;
map<SubTree,int>::iterator it;

int n[K];
int lef[K][N],rig[K][N],type[K][N],num;
int list[N],stack[N],vis[K][N],tail,top;
lld cnt[K][Type],ret;

SubTree build(const int &L,const int &R){ SubTree ret;ret.L=L;ret.R=R;return ret; }

void makelist(const int &k){tail=top=0;
	stack[++tail]=1;vis[k][0]=1;
	while(tail){int now=tail;
		if(!vis[k][stack[now]])list[++top]=stack[now];
		vis[k][stack[now]]=1;
		if(!vis[k][lef[k][stack[now]]]){
			stack[++tail]=lef[k][stack[now]];
		}else if(!vis[k][rig[k][stack[now]]]){
			stack[++tail]=rig[k][stack[now]];
		}else tail--;
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--){ret=0LL;
		
		scanf("%d%d",&n[0],&n[1]);num=0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		s.clear();
		for(int k=0;k<K;k++){type[k][0]=0;
			for(int i=1;i<=n[k];i++){
				scanf("%d%d",&lef[k][i],&rig[k][i]);
				if(lef[k][i]==-1)lef[k][i]=0;
				if(rig[k][i]==-1)rig[k][i]=0;
			}
			makelist(k);
			for(;top;top--){int t,p=list[top];
				SubTree now=build(type[k][lef[k][p]],type[k][rig[k][p]]);
				it=s.find(now);if(it==s.end()){ s.insert(pair<SubTree,int>(now,++num));t=num; }else t=(*it).second;
				type[k][p]=t;cnt[k][t]++;
			}
		}
		
		for(int i=1;i<=num;i++)ret+=cnt[0][i]*cnt[1][i];
		printf("%lld\n",ret);
		
	}
	return 0;
}
