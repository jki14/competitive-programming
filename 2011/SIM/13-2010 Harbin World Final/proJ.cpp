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

#define N 21
#define M 40000

struct SRect{
	int x,y;
	bool operator < (const SRect &a) const{
		if(a.x!=x)return a.x>x;
		return a.y>y;
	}
};

typedef struct SRect rect;

int T;

int n,x,y,full,sum;
int a[N],bit[N];

set<rect> s[M];
set<rect>::iterator it,jt,kt;

vector<int> stalist[N];
int len,sta,pat,low,hash[M];

rect rec;

void dfs(const int &k){

	//printf("sta=%d pat=%d low=%d\n",sta,pat,low);

	if(!k){
		int state=sta|pat;//printf("state=%d\n",state);
		//if(state==3)printf("sta=%d pat=%d\n",sta,pat);
		it=s[sta].begin();jt=s[pat].begin();
		while(it !=s[sta].end() && jt !=s[pat].end()){
			rect L=(*it),R=(*jt);
			//if(state==3)printf("	x	L: %d * %d	R: %d * %d\n",L.x,L.y,R.x,R.y);
			if(L.x==R.x){
				if(L.y+R.y<=y){
					rec.x=L.x;
					rec.y=L.y+R.y;

					/*printf("update state=%d %d * %d\n",state,rec.x,rec.y);
					printf("from sta=%d %d * %d + pat=%d %d * %d\n",sta,L.x,L.y,pat,R.x,R.y);*/

					s[state].insert(rec);
					if(!hash[state]){
						hash[state]=1;
						stalist[len].push_back(state);
					}
				}
				it++;jt++;
			}else{
				if(L.x<R.x)it++;
				else jt++;
			}
		}
		
		it=s[sta].begin();jt=s[pat].begin();
		while(it !=s[sta].end() && jt !=s[pat].end()){
			rect L=(*it),R=(*jt);
			//if(state==3)printf("	y	L: %d * %d	R: %d * %d\n",L.x,L.y,R.x,R.y);
			if(L.y==R.y){
				if(L.x+R.x<=x){
					rec.x=L.x+R.x;
					rec.y=L.y;
					
					/*printf("update state=%d %d * %d\n",state,rec.x,rec.y);
					printf("from sta=%d %d * %d + pat=%d %d * %d\n",sta,L.x,L.y,pat,R.x,R.y);*/
					
					s[state].insert(rec);
					if(!hash[state]){
						hash[state]=1;
						stalist[len].push_back(state);
					}
				}
				it++;jt++;
			}else{
				if(L.y>R.y)it++;
				else jt++;
			}
		}
		return;
	}
	for(int i=low;i<n;i++){
		if(sta&bit[i])continue;
		low=i+1;pat^=bit[i];
		dfs(k-1);
		pat^=bit[i];
	}
}

void work(){T++;
	scanf("%d%d",&x,&y);
	full=(1<<n)-1;memset(hash,0,sizeof(hash));
	for(int i=0;i<=full;i++)s[i].clear();
	for(int i=0;i<=n;i++)stalist[i].clear();
	for(int i=sum=0;i<n;i++){
		scanf("%d",&a[i]);sum+=a[i];
	}
	if(sum!=x*y){
		printf("Case %d: No\n",T);
	}
	for(int i=0;i<n;i++){
		//scanf("%d",&a[i]);
		//printf("for val[%d] = %d\n",i,a[i]);
		bit[i]=1<<i;stalist[1].push_back(bit[i]);
		for(int xx=1;xx<=a[i];xx++){
			if(a[i]%xx)continue;
			int yy=a[i]/xx;
			if(xx>x || yy>y)continue;
			rec.x=xx;rec.y=yy;
			//printf("	%d * %d\n",xx,yy);
			s[bit[i]].insert(rec);
		}
	}

	for(len=2;len<=n;len++){
		for(int lag=(len+1)>>1;lag<n;lag++){
			for(int i=0;i<(int)stalist[lag].size();i++){
				sta=stalist[lag][i];pat=low=0;
				dfs(len-lag);
			}
		}
	}

	if(stalist[n].size()==0)
		printf("Case %d: No\n",T);
	else
		printf("Case %d: Yes\n",T);
}

int main(){T=0;
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

