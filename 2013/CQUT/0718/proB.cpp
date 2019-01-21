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
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+_bitsize(x&(x-1))); }

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 255
#define M 25
#define F 3
#define W 1100
#define B 2
#define S 1100

#define pre now^1

int n,m,p,ans,now,wys;
int a[N],bit[M],c[F][W],s[F],t[F],_c[F],wht[W];
int mrk[S][S],f[B][S][S];

queue< pii > que[B];

void dfs(const int &p,const int &w){
	if(p>=m){
		if(p==m){
			for(int i=0;i<F;i++)c[i][wys]=_c[i];
			wht[wys++]=w;
		}
		return;
	}
	/* ...
	 * ooo
	 * ooo */
	_c[1]^=(bit[p]|bit[p+1]|bit[p+2]);
	_c[2]^=(bit[p]|bit[p+1]|bit[p+2]);
	dfs(p+3,w+1);
	_c[1]^=(bit[p]|bit[p+1]|bit[p+2]);
	_c[2]^=(bit[p]|bit[p+1]|bit[p+2]);
	/* ooo
	 * ooo
	 * ... */
	//_c[0]^=(bit[p]|bit[p+1]|bit[p+2]);
	//_c[1]^=(bit[p]|bit[p+1]|bit[p+2]);
	//dfs(p+3,w+1);
	//_c[0]^=(bit[p]|bit[p+1]|bit[p+2]);
	//_c[1]^=(bit[p]|bit[p+1]|bit[p+2]);
	/* oo.
	 * oo.
	 * oo. */
	_c[0]^=(bit[p]|bit[p+1]);
	_c[1]^=(bit[p]|bit[p+1]);
	_c[2]^=(bit[p]|bit[p+1]);
	dfs(p+2,w+1);
	_c[0]^=(bit[p]|bit[p+1]);
	_c[1]^=(bit[p]|bit[p+1]);
	_c[2]^=(bit[p]|bit[p+1]);
	//...
	dfs(p+1,w);
}

void init(){
	for(int i=0;i<=m+F;i++)bit[i]=_ni(i);
	memset(_c,0,sizeof(_c));
	wys=0;dfs(0,0);//printf("wys=%d\n",wys);
}

void cover(int &x,const int &y){ x=x^(x&y); }

int check(const int &k){
	for(int i=0;i<F;i++){ if(s[i]&c[i][k])return 0; }
	for(int i=0;i<F;i++){ t[i]=s[i]|c[i][k]; }
	cover(t[1],t[2]);return 1;
}

int main(){
	int _T;scanf("%d",&_T);
	for(int T=1;T<=_T;T++){
		scanf("%d%d%d",&n,&m,&p);init();ans=0;
		memset(a,0,sizeof(a));a[0]=bit[m]-1;
		for(int i=0;i<p;i++){
			int x,y;scanf("%d%d",&x,&y);
			a[x]|=bit[y-1];
		}
		memset(mrk,0xff,sizeof(mrk));now=0;
		while(!que[now].empty())que[now].pop();
		while(!que[pre].empty())que[pre].pop();
		cover(a[0],a[1]);que[now].push(_mkpr(a[0],a[1]));
                f[now][a[0]][a[1]]=0;
		for(int i=2;i<=n;i++){
			for(now=pre;!que[pre].empty();que[pre].pop()){
				s[0]=que[pre].front().first;
				s[1]=que[pre].front().second;
				s[2]=a[i];
				for(int k=0;k<wys;k++){
					if(!check(k))continue;
					if(mrk[t[1]][t[2]]!=i ||
						f[now][t[1]][t[2]]
						<f[pre][s[0]][s[1]]+wht[k]){
						f[now][t[1]][t[2]]=
							f[pre][s[0]][s[1]]
							+wht[k];
						_updmax(ans,
							f[now][t[1]][t[2]]);
						if(mrk[t[1]][t[2]]!=i){
							mrk[t[1]][t[2]]=i;
							que[now].push(
								_mkpr(t[1],t[2])
							);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}
