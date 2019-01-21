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

typedef long long lld;

struct Tmed{
	lld f,d;
	bool operator < (const Tmed &a)const{
		return (a.f!=f)?(a.f<f):(a.d>d);
	}
};

multiset<Tmed> s;
multiset<Tmed>::iterator it;

int n;
lld ans,dat;
Tmed med;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);s.clear();ans=dat=0LL;
		for(int i=0;i<n;i++){
			scanf("%lld%lld",&med.f,&med.d);
			s.insert(med);
		}

		/*printf("sort\n");
		for(it = s.begin();it!=s.end();it++){
			printf("%lld %lld\n",(*it).f,(*it).d);
		}*/

		while(!s.empty()){dat+=1LL;
			it=s.begin();med=(*it);s.erase(it);
			
			//if(!T)printf("med.f=%lld med.d=%lld\n",med.f,med.d);

			if(dat>med.d)continue;
			ans+=med.f;med.f--;
			if(med.f>0LL)s.insert(med);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

