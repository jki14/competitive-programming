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

#define S 110000
#define N 100001

#define K 4

struct SP{
	int x,y;
	bool operator <(const SP &a)const {
		if(x!=a.x)return x<a.x;
		return y<a.y;
	}
};

typedef SP TP;

const int dx[K]={ 0,-1,0,1 };
const int dy[K]={ 1,0,-1,0 };

int n,k;
set<TP> s;
set<TP>::iterator it;
TP now,pre;
TP ANS[S];

inline void L(){ k=(k+1) % K; }
inline void R(){ k=(k-1 + K)% K ; }

void init(const int &n){
	//scanf("%d",&n);

	s.clear();
	k=3;now.x=0;now.y=0;
	ANS[0]=now;
	for(int i=1;i<=n;i++){
		it=s.find(now);
		if(it!=s.end()){
			R();s.erase(it);
			now.x+=dx[k];now.y+=dy[k];
		}else{
			L();s.insert(now);
			//printf("k=%d\n",k);
			now.x+=dx[k];now.y+=dy[k];
		}
		ANS[i]=now;
	}

	//printf("%d %d\n",now.x,now.y);
}

void work(){
	scanf("%d",&n);
	printf("%d %d\n",ANS[n].x,ANS[n].y);
}

int main(){
	int t;scanf("%d",&t);
	init(N);
	while(t--)work();
	return 0;
}

