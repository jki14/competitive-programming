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

struct item{
	int s,t,d;
	bool operator < (const item &a)const{
		return a.t-a.d>t-d;
	}
};

int timer;

int n,m,T;
item a[maxn],que[maxn];

multimap<item,int> s;
multimap<item,int>::iterator it,dt;

int max(const int &x,const int &y){ return (x>y)?x:y; }

int cmp(const item &x,const item &y){
	return x.s<y.s;
}

void work(){
	int i,r,t;T=0;
	for(i=0;i<n;i++){
		scanf("%d%d%d",&a[i].d,&a[i].s,&a[i].t);
		T=max(T,a[i].t);
	}
	sort(a,a+n,cmp);
	//for(i=0;i<n;i++)printf("item %d->%d cost %d\n",a[i].s,a[i].d,a[i].t);
	s.clear();
	for(t=i=0;t<=T;t++){

		//printf("At %d:\n",t);

		while(i<n && a[i].s==t)s.insert(pair<item,int>(a[i++],1));
		for(r=0,it=s.begin();it!=s.end() && r<m;r++){
			que[r]=(*it).first;
			dt=it;it++;s.erase(dt);
		}
		if(r && que[0].t-que[0].d<t-1){
			printf("Case %d: No\n\n",timer);
			return;
		}
		for(r--;r>=0;r--){
			
			//printf("  work for %d->%d ~ %d\n",que[r].s,que[r].t,que[r].d);

			que[r].d--;
			if(que[r].d)s.insert(pair<item,int>(que[r],1));
		}
	}
	if(s.size()>0){
		printf("Case %d: No\n\n",timer);
		return;
	}
	printf("Case %d: Yes\n\n",timer);
}

int main(){
	int t;scanf("%d",&t);timer=0;
	while(t--){scanf("%d%d",&n,&m);
		//if(timer)printf("\n");
		timer++;work();
	}
	return 0;
}

