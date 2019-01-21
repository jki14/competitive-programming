#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

//HEAD_OF_CONFIG_

static const int MOD=10007;

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

	//TYPEDEF
	typedef long long lld;
	typedef unsigned long long u64;
	typedef double dou;
	typedef pair<int, int> pii;

	//COMPARE
	template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
	template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

	template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
	template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

	//STL
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
	template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
	template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

	//BIT
	inline int BINT(const int x){ return 1<<x; }
	inline lld BLLD(const int x){ return 1LL<<x; }
	inline int BINT_TEST(const int s, const int x){ return (s&BINT(x))!=0; }
	inline int BLLD_TEST(const lld s, const int x){ return (s&BLLD(x))!=0LL; }
	
	template<class T> inline T LOWBIT(const T x){ return (x^(x-1))&x; }
	template<class T> inline int BITCOUNT(const T x){ return (!x)?x:(1+BITCOUNT(x&(x-1))); }

	//CONST VALUE
	const double PI=acos(-1.0);
	const double EPS=1e-5;

	//CALCULATE
	template<class T> inline T SQR(const T x){ return x*x; }
	template<class T1, class T2> inline T1 POW(const T1 x, const T2 y){
		if(!y)return 1;else if((y&1)==0){
			return SQR(POW(x, y>>1));
		}else return POW(x, y^1)*x;
	}

	//NUMBERIC
	template<class T> inline T GCD(const T x, const T y){
		if(x<0)return GCD(-x, y);
		if(y<0)return GCD(x, -y);
		return (!y)?x:GCD(y, x%y);
	}
	template<class T> inline T LCM(const T x, const T y){
		if(x<0)return LCM(-x, y);
		if(y<0)return LCM(x, -y);
		return x*(y/GCD(x, y));
	}
	template<class T> inline T EEA(const T a, const T b, T &x, T &y){
		/* a*x+b*y == GCD(a, b) == EEA(a, b, x, y) */
		if(a<0){ T d=EEA(-a, b, x, y); x=-x; return d; }
		if(b<0){ T d=EEA(a, -b, x, y); y=-y; return d; }
		if(!b){
			x=1; y=0; return a;
		}else{
			T d=EEA(b, a%b, x, y);
			T t=x; x=y; y=t-(a/b)*y;
			return d;
		}
	}
	template<class T> inline vector<pair<T, int> > FACTORIZE(T x){
		vector<pair<T, int> > ret;
		if(x<0)x=-x;
		for (T i=2;x>1;){
			if(x%i==0){
				int count=0;
				for(;x%i==0;x/=i)count++;
				ret.push_back(MP(i, count));
			}
			i++;if(i>x/i)i=x;
		}
		return ret;
	}
	template<class T> inline int ISPRIME(const T x){
		if(x<=1)return 0;
		for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T EULARFUNCTION(T x){
		vector<pair<T, int> > f=FACTORIZE(x);
		for(typename vector<pair<T, int> >::iterator it=f.begin(); it!=f.end(); it++){
			x=x/it->first*(it->first-1);
		}
		return x;
	}
	template<class T> inline T INVERSEE(const T a, const T b){
		T x, y;
		EEA(a, b, x, y);
		return x?x:1;
	}

	//REMINDER-LIZATION
	template<class T> inline T MOD_STD(const T x, const T m){ return (x%m+m)%m; }
	template<class T> inline T MOD_STD(const T x){ return (x%MOD+MOD)%MOD; }
	template<class T> inline T MOD_ADD(const T x, const T y, const T m){ return (x+y)%m; }
	template<class T> inline T MOD_ADD(const T x, const T y){ return (x+y)%MOD; }
	template<class T> inline void MOD_ADD(T *x, const T y, const T m){ *x=(*x+y)%m; }
	template<class T> inline void MOD_ADD(T *x, const T y){ *x=(*x+y)%MOD; }
	template<class T> inline T MOD_MUL(const T x, const T y, const T m){ return (T)((1LL*x*y)%m); }
	template<class T> inline T MOD_MUL(const T x, const T y){ return (T)((1LL*x*y)%MOD); }
	template<class T> inline void MOD_MUL(T *x, const T y, const T m){ *x=(T)((1LL*(*x)*y)%m); }
	template<class T> inline void MOD_MUL(T *x, const T y){ *x=(T)((1LL*(*x)*y)%MOD); }
	template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y, const T1 m){
		if(y==0)return 1%m;else if((y&1)==0){
			T1 z=MOD_POW(x, y>>1, m); return MOD_MUL(z, z, m);
		}else return MOD_MUL(MOD_POW(x, y^1, m), x, m);
	}
	template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y){
		if(y==0)return 1%MOD;else if((y&1)==0){
			T1 z=MOD_POW(x, y>>1); return MOD_MUL(z, z);
		}else return MOD_MUL(MOD_POW(x, y^1), x);
	}

	//MATRIX
	template<class T> class MATX{
		private:
			unsigned long hig, wid;
			T *data;
			
			void __init(){
				this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				memset(this->data, 0, sizeof(T)*this->hig*this->wid);
			}

		public:
			MATX(){ 
				this->hig=this->wid=1;
				__init();
			}
			MATX(const unsigned long _len){
				this->hig=this->wid=_len;
				__init();
			}
			MATX(const unsigned long _hig, const unsigned long _wid){
				this->hig=_hig;
				this->wid=_wid;
				__init();
			}
			MATX(const MATX &rhs){
				this->hig=rhs.hig;
				this->wid=rhs.wid;
				this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=rhs.at(x, y);
			}
			~MATX(){
				free(this->data);
			}

			T & operator()(const unsigned long x, const unsigned long y){
				if(x>=this->hig || y>=this->wid)return (*(T*)NULL);
				return this->data[x*wid+y];
			}

			MATX & operator=(const MATX &rhs){
				if(this->hig!=rhs.hig || this->wid!=rhs.wid){
					free(this->data);
					this->hig=rhs.hig;
					this->wid=rhs.wid;
					this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				}
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=rhs.at(x, y);
				return *this;
			}

			const MATX operator+(const MATX &opn) const{
				MATX ret(*this);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						ret.data[x*ret.wid+y]+=opn.at(x, y);
				return ret;
			}
			const MATX operator-(const MATX &opn) const{
				MATX ret(*this);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						ret.data[x*ret.wid+y]-=opn.at(x, y);
				return ret;
			}
			const MATX operator*(const MATX &opn) const{
				MATX ret(this->hig, opn.wid);
				const unsigned long len=MIN(this->wid, opn.hig);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						for(unsigned long z=0; z<len; z++)
							ret.data[x*ret.wid+y]+=this->at(x, z)*opn.at(z, y);
				return ret;
			}

			const MATX mul(const MATX &opn) const{ return *this*opn; }
			template<class T2> const MATX mul(const MATX &opn, const T2 m) const{
				MATX ret(this->hig, opn.wid);
				const unsigned long len=MIN(this->wid, opn.wid);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						for(unsigned long z=0; z<len; z++)
							MOD_ADD(&ret.data[x*ret.wid+y], MOD_MUL(this->at(x, z), opn.at(z, y), m), m);
				return ret;
			}
			
			MATX & operator +=(const MATX &rhs){
				*this=*this+rhs;
				return *this;
			}	
			MATX & operator -=(const MATX &rhs){
				*this=*this-rhs;
				return *this;
			}	
			MATX & operator *=(const MATX &rhs){
				*this=*this*rhs;
				return *this;
			}

			const MATX pow(const unsigned long p) const{
				MATX buff(*this), ret(this->hig, this->wid);
				ret.set_one();
				if(p>0)for(unsigned long i=1;;i<<=1){
					if(p&i)ret*=buff;
					buff*=buff;
					if(i>(p>>1))break;
				}
				return ret;
			}
			template<class T2> const MATX pow(const unsigned long p, const T2 m) const{
				MATX buff(*this), ret(this->hig, this->wid);
				ret.set_one();
				if(p>0)for(unsigned long i=1;;i<<=1){
					if(p&i)ret=ret.mul(buff, m);
					buff=buff.mul(buff, m);
					if(i>(p>>1))break;
				}
				return ret;
			}


			const T at(const unsigned long x, const unsigned long y) const{
				if(x>=this->hig || y>=this->wid)return 0;
				return this->data[x*wid+y];
			}

			void show() const{
				for(unsigned long x=0; x<this->hig; x++){
					for(unsigned long y=0; y<this->wid; y++)
						cout<<this->at(x, y)<<" ";
					cout<<endl;
				}
			}

			void set_one(){
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=(x==y)?1:0;
			}

	};

//TAIL_OF_JKI'S_HEADER_

#define N 10086

const double eps = 1e-9;

struct pnt {
	double x, y;
} cp[N], ch[N], bp;

inline int dcmp(const double x){
	if(x<-eps)return -1;
	if(x>eps)return 1;
	return 0;
}

inline double cross(const pnt &p0, const pnt &p1, const pnt &p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

inline double dot(const pnt &p0, const pnt &p1, const pnt &p2) {
	return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}

inline double sqr(const double x) {return x * x;}

inline double dist2(const pnt &a, const pnt &b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

inline int samepnt(const pnt &a, const pnt &b) {
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

int cmp(const pnt &p1, const pnt &p2) {
	int u = dcmp(cross(bp, p1, p2));
	return u > 0 || (u == 0 && dcmp(dist2(bp, p1) - dist2(bp, p2)) < 0);
}

void graham(pnt pin[], int n, pnt ch[], int &m) {
	int i, j, k, u, v;
	memcpy(ch, pin, n * sizeof(pnt));
	for (i = k = 0; i < n; ++i) {
		u = dcmp(ch[i].x - ch[k].x);
		v = dcmp(ch[i].y - ch[k].y);
		if (v < 0 || (v == 0 && u < 0)) k = i;
	}
	bp = ch[k];
	sort(ch, ch + n, cmp);
	n = unique(ch, ch + n, samepnt) - ch;
	if (n <= 1) {m = n; return ;}
	if (dcmp(cross(ch[0], ch[1], ch[n - 1])) == 0) {
		m = 2; ch[1] = ch[n - 1]; return;
	}
	ch[n++] = ch[0];
	for (i = 1, j = 2; j < n; ++j) {
		while (i > 0 && dcmp(cross(ch[i - 1], ch[i], ch[j])) <= 0) i--;
		ch[++i] = ch[j];
	}
	m = i;
}

int main(){
	int T;scanf("%d",&T);
	for(int _T=1; _T<=T; _T++){
		int n, m, p, q, r;
		printf("Case #%d:\n", _T);
		scanf("%d", &n);n<<=2;
		for(int i=0; i<n; i++){
			scanf("%lf%lf", &cp[i].x, &cp[i].y);
		}
		graham(cp, n, ch, m);
		if(m<3){
			printf("0\n");
			continue;
		}
		double ans=1e99;
		ch[m]=ch[0];p=q=1;
		for(int i=0; i<m; i++){
			while(dcmp(cross(ch[i], ch[i+1], ch[p+1])-cross(ch[i], ch[i+1], ch[p]))>0)p=(p+1)%m;
			while(dcmp(dot(ch[i], ch[i+1], ch[q+1])-dot(ch[i], ch[i+1], ch[q]))>0)q=(q+1)%m;
			if(!i)r=q;
			while(dcmp(dot(ch[i], ch[i+1], ch[r+1])-dot(ch[i], ch[i+1], ch[r]))<=0)r=(r+1)%m;
			double d=dist2(ch[i], ch[i+1]);
			UPDMIN(ans, cross(ch[i], ch[i+1], ch[p])*(dot(ch[i],ch[i+1],ch[q])-dot(ch[i],ch[i+1],ch[r]))/d);
		}
		printf("%.0f\n", ans);
	}
	return 0;
}
