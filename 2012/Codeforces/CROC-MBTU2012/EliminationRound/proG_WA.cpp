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

	//CONST VALUE
	
	const dou _pi=acos(-1.0);
	const dou _eps=1e-5;

	//CALCULATE
	
	template<class T> inline T _sqr(const T &x){ return x*x; }
	
	//NUMBERIC
	template<class T> inline T _gcd(const T &x,const T &y){
		if(x<0)return _gcd(-x,y);
		if(y<0)return _gcd(x,-y);
		return (y==0)?x:_gcd(y,x%y);
	}
	template<class T> inline T _lcm(const T &x,const T &y){
		if(x<0)return _lcm(-x,y);
		if(y<0)return _lcm(x,-y);
		return x*(y/_gcd(x,y));
	}
	template<class T> inline T _euc(const T &a,const T &b,T &x,T &y){ 
		/* a*x+b*y == _euc(); */
		if(a<0){T d=_euc(-a,b,x,y);x=-x;return d;} 
	   	if(b<0){T d=_euc(a,-b,x,y);y=-y;return d;} 
	      	if(b==0){
			x=1;y=0;return a;
		}else{
			T d=_euc(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;
			return d;
		}
	}
	template<class T> inline vector<pair<T,int> > _fac(T n){
		vector<pair<T,int> > ret;for (T i=2;n>1;){
			if (n%i==0){int cnt=0;for (;n%i==0;cnt++,n/=i);ret.push_back(_mkpr(i,cnt));} 
	   		i++;if (i>n/i) i=n;
		}
		if (n>1) ret.push_back(_mkpr(n,1));return ret;
	}
	template<class T> inline int _prm(const T &x){
		if(x<=1)return 0;
		for(T i=2;sqr(i)<=x;i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T _phi(T x){ 
		/* EularFunction:return the number of integers which are the relatively prime number of x and less than x. */
		vector<pair<T,int> > f=_fac(x);T ret=x;
		for(int i=0;i<_size(f);i++)ret=ret/f[i].first*(f[i].first-1);
		return ret;
	}
	template<class T> inline T _inv(T a,T b){
		/* if(k%a==0) (k/a)%b==((k%b)*(_inv()%b))%b */
		/*	original code begin
		T x0=1,y0=0,x1=0,y1=1;
		for(T r=a%b;r!=0;r=a%b){ T k=a/b,dx=x0-k*x1,dy=y0-k*y1;x0=x1;y0=y1;x1=dx;y1=dy;a=b;b=r; }
		if(x1==0)x1=1;return x1;
		original code end	*/
		T x,y;_euc(a,b,x,y);
		if(x==0)x=1;return x;
	}

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 11000
#define M 11000
#define L 1100

//#define ret ans[u]

const int inf=0x3fffffff;

int n,m,ans[N],rat[N];
int nbs[N],ev[M],next[M],num;

string u,v;
char _u[L],_v[L];

map<string, int> s;
map<string, int>::iterator it;

/*set<int> c[N];
set<int>::iterator jt;*/

void addedge(const int &u,const int &v){
	next[++num]=nbs[u];ev[num]=v;nbs[u]=num;
	next[++num]=nbs[v];ev[num]=u;nbs[v]=num;
	//c[u].insert(v);c[v].insert(u);
}

int main(){
	while(scanf("%d",&m)!=EOF){
		memset(nbs,0,sizeof(nbs));num=0;
		n=0;s.clear();
		//for(int i=0;i<N;i++)c[i].clear();
		for(int i=0;i<m;i++){
			scanf("%s%s",_u,_v);u=_u;v=_v;int x,y;
			it=s.find(u);if(it==s.end()){ s.insert(_mkpr(u,x=n++)); }else x=(*it).second;
			it=s.find(v);if(it==s.end()){ s.insert(_mkpr(v,y=n++)); }else y=(*it).second;
			/*if(x==y)continue;
			jt=c[x].find(y);if(jt==c[x].end())*/addedge(x,y);
		}
		//memset(ans,0,sizeof(ans));
		for(int u=0;u<n;u++){ans[u]=0;
			/*memset(rat,0,sizeof(rat));*/
			for(int v=0;v<n;v++)rat[v]=0;rat[u]=-inf;
			for(int i=nbs[u];i;i=next[i]){ int v=ev[i];rat[v]=-inf; }
			for(int v=0;v<n;v++){
				if(rat[v]<0)continue;
				for(int i=nbs[v];i;i=next[i]){ int w=ev[i];if(rat[w]<0)rat[v]++; }
			}
			/*for(int i=nbs[u];i;i=next[i]){int v=ev[i];rat[v]=-inf;
				for(int j=nbs[v];j;j=next[j]){int w=ev[j];
						rat[w]++;
				}
			}*/
			//sort(rat,rat+n,greater<int>());//for(int i=0;i<n;i++)cout<<rat[i]<<endl;
			//for(;ans[u]<n && rat[ans[u]]>0 && (!ans[u] || rat[ans[u]]==rat[ans[u]-1]);ans[u]++);
			//printf("ans[%d]=%d\n",u,ans[u]);
			int best=0;for(int v=0;v<n;v++){
				if(rat[v]>best){
					best=rat[v];ans[u]=1;
				}else if(rat[v]==best)ans[u]++;
			}
		}
		printf("%d\n",n);
		for(it=s.begin();it!=s.end();it++){
			//printf("%s %d\n",(*it).first.c_str(),ans[(*it).second]);
			cout<<(*it).first<<" "<<ans[(*it).second]<<endl;
		}
	}
	return 0;
}
