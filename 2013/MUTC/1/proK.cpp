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

#define I 1100000
#define A 1000000
#define N 1100
#define S 20
#define B 16
#define R 4

const int neg=0xc0c0c0c0;

int bit[S],cnt[S],id[S];

int n,m,ans;
int a[N],b[N],c[N],d[N],e[N];

int is[I],prm[I],num;

void getprm(const int &n){num=0;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x3f,sizeof(is));
	prm[num++]=2;is[0]=is[1]=0;
	for(int i=4;i<=n;i+=2)is[i]=0;
	for(int i=3;i<e;i+=2)if(is[i]){
		prm[num++]=i;int d=i<<1;
		for(int j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(int i=e|1;i<=n;i+=2)if(is[i])prm[num++]=i;
}

int prime(const lld &x){if(x==1)return 0;
	for(int i=0;i<num && x/prm[i]>=prm[i];i++){
		if(!(x%prm[i]))return 0;
		if(i==num-1)while(1);
	}
	return 1;
}

int sqr2num(const int &x){
	int y=sqrt(x);if(y*y!=x)return 0;
	int z=sqrt(y);if(z*z!=y)return 0;
	return 1;
}

int judge3(const int &x, const vector<pii> &fac){
	int s=1;for(int i=0;i<_size(fac);i++)s*=(fac[i].second+1);
	if(s&1 && !sqr2num(x))return 0;
	if((s>>1)&1)return 0;
	return 1;
	//if(!(x&1) && !((x>>1)&1))return 1;
	//return 0;
	/*for(int i=0;i<_size(fac);i++){
		if(fac[i].second%4==1 || fac[i].second%4==2){
			int flag=0;
			for(int j=0;j<_size(fac);j++)if(j!=i && fac[j].second%2==1)flag=1;
			if(!flag)return 0;
		}
	}*/
	//return 1;
}

int score(const int &x){int ret=0;
	vector<pii> fac=_fac(x);
	/* judge 0 */
	if(is[x])ret|=bit[0];
	/* judge 1 */
	if(_size(fac)==1 && is[fac[0].second+1])ret|=bit[1];
	/* judge 2 */
	if(_size(fac)==1 && prime(((lld)x*(lld)fac[0].first-1LL)/((lld)fac[0].first-1LL)))ret|=bit[2];
	/* judge 3 */
	if(/*_sqr((int)(sqrt(x)))==x || x==1 || */judge3(x,fac))ret|=bit[3];
	//printf("score(%d)=%d\n",x,ret);
	return ret;
}

void run(const int &state){
	int ret=0,fnl=0,k=m;
	for(int i=0;i<B;i++)if(state&bit[i]){ if(!d[i])return;fnl|=i;k--;ret+=cnt[i]; }
	if(k<0)return;
	for(int i=0;i<R;i++)if(!(fnl&bit[i]))ret+=e[i];
	for(int _i=0;_i<B && k;_i++){int i=id[_i];
		if(state&bit[i] && d[i]>1){
			int num=min(k,d[i]-1);
			k-=num;ret+=num*cnt[i];
		}
	}
	if(!k)_updmax(ans,ret);
}

int sub(const int &x){ int ret=0;for(int i=0;i<B;i++)if(x&bit[i])ret++;return ret; }

int cmp(const int &i,const int &j){ return cnt[i]>cnt[j]; }

int main(){

	getprm(A);

	for(int i=0;i<=B;i++)bit[i]=_ni(i);
	for(int i=0;i<B;i++)cnt[id[i]=i]=sub(i);
	sort(id,id+B,cmp);

	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);ans=neg;
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			c[i]=score(a[i]);
			d[c[i]]+=b[i];
		}
		for(int i=0;i<R;i++)scanf("%d",&e[i]);
		for(int state=0;state<bit[B];state++)run(state);
		for(int i=0;i<n;i++){
			if(i)printf(" ");
			printf("%d",cnt[c[i]]);
		}printf("\n");
		printf("%d\n",ans);
	}
	return 0;
}

