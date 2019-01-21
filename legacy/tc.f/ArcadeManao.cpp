#line 106 "ArcadeManao.cpp"

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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

//HEAD_OF_TEMPLATE_BY_JKI14

	//TYPEDEF
	
	typedef long long lld;
	typedef double dou;
	typedef pair<int,int> pii;

	//COMPARE
	
	inline int min(const int &x, const int &y){ return x<y?x:y; }
	inline lld min(const lld &x, const lld &y){ return x<y?x:y; }
	inline dou min(const dou &x, const dou &y){ return x<y?x:y; }

	inline int max(const int &x, const int &y){ return x>y?x:y; }
	inline lld max(const lld &x, const lld &y){ return x>y?x:y; }
	inline dou max(const dou &x, const dou &y){ return x>y?x:y; }

	template<class T> inline void _updmin(T &x,const T &y){ if(x>y)x=y; }
	template<class T> inline void _updmax(T &x,const T &y){ if(x<y)x=y; }

	//STL
	
	#define _size(x) ((int)(x.size()))
	#define _mkpr(x,y) make_pair(x,y)

	//BIT
	
	#define _ni(x) (1<<(x))
	#define _niL(x) (1LL<<(x))
	#define _has(s,x) ((s&(_ni(x)))!=0)
	#define _hasL(s,x) ((s&(_niL(x)))!=0LL)

	template<class T> inline T _lowbit(const T &x){ return (x^(x-1))&x; }
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+bitsize(x&(x-1))); }


//TAIL_OF_TEMPLATE_BY_JKI14

#define N 3100
#define M 1100000

int n,m,src,tar;
int vst[N],nbs[N],nxt[M],dst[M],wht[M],num,code;

int p2i(const int &x,const int &y){ return x*m+y; }

void addEdge(const int &u,const int &v,const int &w){
	nxt[++num]=nbs[u];nbs[u]=num;dst[num]=v;wht[num]=w;
}

int able(const int &u,const int &lmt){
	if(u==src)++code;vst[u]=code;
	for(int i=nbs[u];i;i=nxt[i]){int v=dst[i],w=wht[i];
		if(vst[v]==code)continue;
		if(w>lmt)continue;
		if(v==tar)return 1;
		if(able(v,lmt))return 1;
	}
	return 0;
}

int find(){
	int lef=0,rig=n-1;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(able(src,mid)){
			if(!able(src,mid-1))return mid;
			rig=mid-1;
		}else lef=mid+1;
		//printf("lef=%d rig=%d\n",lef,rig);
	}
	return 0;
}

class ArcadeManao {
	public:
	int shortestLadder(vector <string> _c, int dx, int dy) {
		n=_size(_c);m=_size(_c[0]);dx--;dy--;
		src=p2i(n-1,0);tar=p2i(dx,dy);
		memset(nbs,0,sizeof(nbs));num=0;
		memset(vst,0,sizeof(vst));code=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(_c[i][j]!='X')continue;
				if(j>0   && _c[i][j-1]=='X')addEdge(p2i(i,j),p2i(i,j-1),0);
				if(j+1<m && _c[i][j+1]=='X')addEdge(p2i(i,j),p2i(i,j+1),0);
				if(i==n-1)continue;
				int lev=i+1;while(_c[lev][j]!='X')lev++;
				int dis=lev-i;
				addEdge(p2i(i  ,j),p2i(lev,j),dis);
				addEdge(p2i(lev,j),p2i(i  ,j),dis);
			}
		}
		return find();
	}
};


// Powered by FileEdit


//Powered by [KawigiEdit] 2.0!
