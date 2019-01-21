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
	template<class T> inline T _cmod(T x,T m){ return (x%m+m)%m; }
	template<class T> inline T _amod(T x,T y,T m){ return x=((x+y)%m+m)%m; }
	template<class T> inline T _mmod(T x,T y,T m){ return (T)((((lld)x)*((lld)y)%((lld)m)+((lld)m))%((lld)m)); }
	template<class T> inline T _pmod(T x,T y,T m){
		if(y==0)return 1%m;else if((y&1)==0){ 
			T z=_pmod(x,y>>1,m);return _mmod(z,z,m); 
		}else return _mmod(_pmod(x,y^1,m),x,m);
	}
	#define _cmd(x) _cmod(x,mod)
	#define _amd(x,y) _amod(x,y,mod)
	#define _mmd(x,y) _mmod(x,y,mod)
	#define _pmd(x,y) _pmod(x,y,mod)

	//MATRIX OPERATIONS
	
	const int _MTRXSIZE = 40;
	template<class T> inline void _shwMTRX(int n,T A[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++){ for(int j=0;j<n;j++)cout<<A[i][j]<<" ";cout<<endl; }
	}
	template<class T> inline void _stdMTRX(int n,T A[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) A[i][j]=(i==j)?1:0;
	}
	template<class T> inline void _addMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];
	}
	template<class T> inline void _subMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];
	}
	template<class T> inline void _mulMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T _A[_MTRXSIZE][_MTRXSIZE],T _B[_MTRXSIZE][_MTRXSIZE]){
		T A[_MTRXSIZE][_MTRXSIZE],B[_MTRXSIZE][_MTRXSIZE];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0; }
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]+=A[i][k]*B[k][j];
	}
	template<class T> inline void _addModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=_cmod(A[i][j]+B[i][j],m);
	}
	template<class T> inline void _subModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=_cmod(A[i][j]-B[i][j],m);
	}
	template<class T> inline void _mulModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T _A[_MTRXSIZE][_MTRXSIZE],T _B[_MTRXSIZE][_MTRXSIZE]){
		T A[_MTRXSIZE][_MTRXSIZE],B[_MTRXSIZE][_MTRXSIZE];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0; }
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]=(C[i][j]+_mmod(A[i][k],B[k][j],m))%m;
	}
	template<class T> inline void _powModMTRX(int n,T y,T m,T C[_MTRXSIZE][_MTRXSIZE],T X[_MTRXSIZE][_MTRXSIZE]){
		T R[_MTRXSIZE][_MTRXSIZE];for(int i=0;i<n;i++)for(int j=0;j<n;j++)R[i][j]=X[i][j];_stdMTRX(n,C);
		if(y>0)for(T i=1;;i<<=1){
			if(y&i)_mulModMTRX(n,m,C,C,R);
			_mulModMTRX(n,m,R,R,R);
			if(i>(y>>1))break;
		}
	}

	//FRACTION
	template<class T> struct _frct{T a,b;_frct(T a=0,T b=1);string toString();};  
	template<class T> _frct<T>::_frct(T a,T b){T d=_gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
	template<class T> string _frct<T>::toString(){ostringstream tout;tout<<a<<"/"<<b;return tout.str();}
	template<class T> _frct<T> operator+(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b+q.a*p.b,p.b*q.b);}  
	template<class T> _frct<T> operator-(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b-q.a*p.b,p.b*q.b);}  
	template<class T> _frct<T> operator*(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.a,p.b*q.b);}  
	template<class T> _frct<T> operator/(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b,p.b*q.a);}  

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 1100
#define S 21000

const int inf=0x3f3f3f3f;
const int neg=0xc0c0c0c0;
const dou eps=1e-4;

int n,m,p,v,num;
double g[N][N],ans[S];
int match1[N],match2[N];
int s[N],t[N];
int rank[N];

set<double> _s;
set<double>::iterator it;

struct Point {
	int x,y;
}c[N];

struct Line{
	Point a,b;
	Line(){ }
	Line(const Point &_a,const Point &_b){ a=_a;b=_b; }
}b[N];

inline int xmult(const Point &p1,const Point &p2,const Point &p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int intersectIn(const Line &u,const Line &v){
	if (max(u.a.x,u.b.x)>min(v.a.x,v.b.x)&&max(v.a.x,v.b.x)>min(u.a.x,u.b.x)&&
	    max(u.a.y,u.b.y)>min(v.a.y,v.b.y)&&max(v.a.y,v.b.y)>min(u.a.y,u.b.y)&&
	    ((lld)xmult(u.b,v.a,u.a))*((lld)xmult(u.b,v.b,u.a))<0LL&&
	    ((lld)xmult(v.b,u.a,v.a))*((lld)xmult(v.b,u.b,v.a))<0LL){
		//printf("(%d,%d)->(%d,%d) X (%d,%d)->(%d,%d)\n",u.a.x,u.a.y,u.b.x,u.b.y,v.a.x,v.a.y,v.b.x,v.b.y);
		return 1;
	}else{
		//printf("(%d,%d)->(%d,%d) O (%d,%d)->(%d,%d)\n",u.a.x,u.a.y,u.b.x,u.b.y,v.a.x,v.a.y,v.b.x,v.b.y);
		return 0;
	}
	/*if(u.a==v.a && u.b!=v.)
	if(!dotsInline(u.a,u.b,v.a) || !dotsInline(u.a,u.b,v.b)){
		return !sameSide(u.a,u.b,v) && !sameSide(v.a,v.b,u);
	}else{
		return dotOnlineIn(u.a,v) || dotOnlineIn(u.b,v) || dotOnlineIn(v.a,u) ||dotOnlineIn(v.b,u);
	}*/
}

int able(const Line &x){
	for(int i=0;i<m;i++)if(intersectIn(x,b[i]))return 0;
	return 1;
}

double dis(const Point &u,const Point &v){
	return sqrt(_sqr((dou)u.x-(dou)v.x)+_sqr((dou)u.y-(dou)v.y));
}

int hungary(const double &cap){int ret=0;
	memset(match1,0xff,sizeof(match1));
	memset(match2,0xff,sizeof(match2));
	for(int i=0;i<n;ret+=(match1[i++]>=0)){
		memset(t,0xff,sizeof(t));int p,q;
		for(s[p=q=0]=i;p<=q && match1[i]<0;p++){
			for(int k=s[p],j=0;j<n && match1[i]<0;j++){
				if(g[k][j]<cap+eps && rank[k]<rank[j] && t[j]<0){
					s[++q]=match2[j];
					t[j]=k;
					if(s[q]<0){
						for(p=j;p>=0;j=p){
							match2[j]=k=t[j];
							p=match1[k];
							match1[k]=j;
						}
					}
				}
			}
		}
	}
	return ret;
}

int pathCover(const double &cap){
	//printf("pathCover(%.2f)=%d\n",cap,n-hungary(cap));
	return n-hungary(cap);
}

double core(){
	int l=1,r=num;
	while(l<=r){int mid=(l+r)>>1;
		if(pathCover(ans[mid])<=p){
			if(mid==1 || pathCover(ans[mid-1])>p)return ans[mid];
			r=mid-1;
		}else l=mid+1;
	}
	return -1.0;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&p);_s.clear();_s.insert(0.0);v=n+m+m;
		for(int i=0;i<n;i++)scanf("%d%d",&c[i].x,&c[i].y);
		for(int i=0;i<m;i++)scanf("%d%d%d%d",&b[i].a.x,&b[i].a.y,&b[i].b.x,&b[i].b.y);
		for(int i=0;i<n;i++){ int u;scanf("%d",&u);rank[--u]=i; }
		for(int i=n;i<v;i++)c[i]=i<n+m?b[i-n].a:b[i-n-m].b;
		for(int i=0;i<v;i++)for(int j=0;j<v;j++)g[i][j]=inf;
		for(int i=0;i<v;i++)
			for(int j=i+1;j<v;j++)
				if(able(Line(c[i],c[j]))){
					g[i][j]=g[j][i]=dis(c[i],c[j]);
					//printf("g[%d][%d]=%.2f\n",i,j,g[i][j]);
				}

		for(int k=0;k<v;k++)
			for(int i=0;i<v;i++)
				for(int j=0;j<v;j++)
					_updmin(g[i][j],g[i][k]+g[k][j]);

		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){ _s.insert(g[i][j]);/*printf("%d->%d :%.2f\n",i,j,g[i][j]);*/ }

		for(it=_s.begin(),num=0;it!=_s.end();it++)ans[++num]=(*it);ans[0]=0.0;
		printf("%.2f\n",core());
	}
	return 0;
}

