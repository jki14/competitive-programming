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

static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;
static const double eps=1e-8;

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

	//TYPEDEF
	typedef long long lld;
	typedef unsigned long long u64;
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
	template<class T> inline T INVERSEE(const T a, const T b=MOD){
		T x, y;
		EEA(a, b, x, y);
		return x?x:1;
	}

	//REMINDER-LIZATION
	template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
	template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
	template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
	template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }
	template<class T> inline T MOD_MUL(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
	template<class T> inline void MOD_MUL(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }
	template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y, const T1 m=MOD){
		if(y==0)return 1%m;else if((y&1)==0){
			T1 z=MOD_POW(x, y>>1, m); return MOD_MUL(z, z, m);
		}else return MOD_MUL(MOD_POW(x, y^1, m), x, m);
	}
	inline lld MODL_MUL(lld x, lld y, const lld m=MOD){
		if(x<y)swap(x, y);
		lld z=0LL;
		while(y>0){
			if(y&1){
				MOD_ADD(&z, x, m);
			}
			MOD_ADD(&x, x, m);
			y>>=1;
		}
		return z;
	}
	inline lld MODL_POW(const lld x, const lld y, const lld m=MOD){
		if(y==0LL)return 1LL%m;else if((y&1)==0LL){
			lld z=MODL_POW(x, y>>1, m); return MODL_MUL(z, z, m);
		}else return MODL_MUL(MODL_POW(x, y^1, m), x, m);
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

	//COMPLEX
	template<class T> class Complex{
		public:
		T r, i;//real part & imaginary part; x+yi
		Complex(T x=0.0, T y=0.0){ this->r=x; this->i=y; }
		Complex operator + (const Complex &opn) const { return Complex(this->r+opn.r, this->i+opn.i); }
		Complex operator - (const Complex &opn) const { return Complex(this->r-opn.r, this->i-opn.i); }
		Complex operator * (const Complex &opn) const { return Complex(this->r*opn.r-this->i*opn.i, this->r*opn.i+this->i*opn.r); }
	};

	//MILLERRABIN
	class MILLERRABIN{
		private:
		static const int prime_table[12];
		int witness(lld a, lld d, lld s, lld n){
			lld r=MODL_POW(a, d, n);
			if(r==1 || r==n-1)return 0;
			for(int i=0; i<s-1; i++){
				r = MODL_MUL(r, r, n);
				if(r==1)return 1;
				if(r==n-1)return 0;
			}
			return 1;
		}
		public:
		int test(const lld n){
			if(n<=2LL) return 0;
			lld p=n-1LL, s=0LL;
			while(!(p&1)){ p>>=1;s++; }
			for(int i=0; i<12 && this->prime_table[i]<n; i++){
				if(witness(this->prime_table[i], p, s, n))return 0;
			}
			return 1;
		}
	};
	const int MILLERRABIN::prime_table[12] = { 2, 3, 5, 7, 11, 13 ,17, 19, 23, 29, 31, 37 };

	//Computational Geometry
	
	template<class T> inline int fsign(const T x){
		if(x>-eps && x<eps)return 0;
		return (x<0.0)?-1:1;
	}

	template<class T> class point_t{
		public:
		T x, y;
		point_t (){
			this->x=0.0;
			this->y=0.0;
		}
		point_t (const T _x, const T _y){
			this->x=_x;
			this->y=_y;
		}
		point_t operator - (const point_t &rhs) const{
			return point_t(this->x-rhs.x, this->y-rhs.y);
		}
		T operator ^ (const point_t &rhs) const{
			return this->x*rhs.y - this->y*rhs.x;
		}
		T operator * (const point_t &rhs) const{
			return this->x*rhs.x + this->y*rhs.y;
		}
		T cross(const point_t &p, const point_t &q) const{
			return (p-*this)^(q-*this);
		}
		void rotate(double radian){
			T x0=x, y0=y;
			T sinr=sin(radian);
			T cosr=cos(radian);
			x=x0*cosr-y0*sinr;
			y=x0*sinr+y0*cosr;
		}
		T dist2(const point_t &lhs, const point_t &rhs) const{
			return (lhs-rhs)*(lhs-rhs);
		}
		T dist2(const point_t &rhs) const{
			return (*this-rhs)*(*this-rhs);
		}
		T dist(const point_t &lhs, const point_t &rhs) const{
			return sqrt((lhs-rhs)*(lhs-rhs));
		}
		T dist(const point_t &rhs) const{
			return sqrt((*this-rhs)*(*this-rhs));
		}
	};

	template<class T> class segment_t{
		public:
		point_t<T> p, q;
		segment_t (){
			this->p.x=this->p.y=0.0;
			this->q.x=this->q.y=0.0;
		}
		template<class T2> segment_t (const point_t<T2> &_p, const point_t<T2> &_q){
			this->p.x=_p.x;
			this->p.y=_p.y;
			this->q.x=_q.x;
			this->q.y=_q.y;
		}
		segment_t (const T px, const T py, const T qx, const T qy){
			this->p.x=px;
			this->p.y=py;
			this->q.x=qx;
			this->q.y=qy;
		}
		T length() const{
			return this->p.dist(this->q);
		}
		T length2() const{
			return this->p.dist2(this->q);
		}
		int contain(const point_t<T> &pnt, const int ignore_endpoint=0) const{
			if(ignore_endpoint){
				return fsign((this->p-pnt)^(this->q-pnt))==0
					&& fsign((pnt.x-this->p.x)*(pnt.x-this->q.x)) <0
					&& fsign((pnt.y-this->p.y)*(pnt.y-this->q.y)) <0;
			}else{
				return fsign((this->p-pnt)^(this->q-pnt))==0
					&& fsign((pnt.x-this->p.x)*(pnt.x-this->q.x)) <=0
					&& fsign((pnt.y-this->p.y)*(pnt.y-this->q.y)) <=0;
			}
		}
		int intersection(const segment_t &sa, const segment_t &sb, const int ignore_endpoint=0) const{
			if(!ignore_endpoint){
				if(sa.contain(sb.p) || sa.contain(sb.q) || sb.contain(sa.p) || sb.contain(sa.q))
					return 1;
			}
			return fsign(sa.p.cross(sa.q, sb.p))*fsign(sa.p.cross(sa.q, sb.q))<0
				&& fsign(sb.p.cross(sb.q, sa.p))*fsign(sb.p.cross(sb.q, sa.q))<0;
		}
		int intersection(const segment_t &rhs, const int ignore_endpoint=0) const{
			return this->intersection(*this, rhs, ignore_endpoint);
		}
	};

//TAIL_OF_JKI'S_HEADER

#define N 210000

class lab_t{
	public:
	int pos, hig;
	lab_t(const int lhs=0, const int rhs=0){
		this->pos=lhs;
		this->hig=rhs;
	}
	bool operator < (const lab_t &rhs) const{
		if(this->pos!=rhs.pos)
			return this->pos<rhs.pos;
		return this->hig>rhs.hig;
	}
} a[N];

class buf_t{
	public:
	int val, det, suf, cnt, til;
	buf_t(const int v=0, const int d=0, const int s=0, const int c=0, const int t=0){
		this->val=v;
		this->det=d;
		this->suf=s;
		this->cnt=c;
		this->til=t;
	}
	int value() const{
		return this->val;
	}
	void add(const int pos){
		int sup=pos-this->til;
		MOD_ADD(&this->det, MOD_MUL(MOD_MUL(MOD_MUL(this->suf, this->cnt-1), sup), 2));
		MOD_ADD(&this->det, MOD_MUL(MOD_MUL(MOD_MUL(this->cnt, this->cnt-1), sup), sup));
		/*MOD_ADD(&this->det, MOD_MUL(MOD_MUL(this->suf, sup), 2));
		MOD_ADD(&this->cnt, 1);
		MOD_ADD(&this->suf, MOD_MUL(this->cnt, sup));*/
		MOD_ADD(&this->cnt, 1);
		MOD_ADD(&this->suf, MOD_MUL(this->cnt, sup));
		MOD_ADD(&this->det, MOD_MUL(MOD_MUL(MOD_ADD(this->suf, -sup), sup), 2));
		this->til=pos;
		MOD_ADD(&this->val, MOD_MUL(this->suf, this->suf));
		MOD_ADD(&this->val, -this->det);
	}
};

int n, ans;
int que[N], til;

map<int, buf_t> g;
map<int, buf_t>::iterator it;

int main() {
	int T;scanf("%d",&T);
	for(int _T=1; _T<=T; _T++){
		printf("Case #%d: ", _T);
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d%d", &a[i].pos, &a[i].hig);
		}
		sort(a, a+n);
		/*for(int i=1; i<n; i++){
			if(a[i].pos==a[i-1].pos){
				fprintf(stderr, "pos tie\n");
				break;
			}
		}*/
		til=ans=0;g.clear();
		for(int i=0; i<n; i++){
			while(til>0 && a[que[til-1]].hig<a[i].hig){
				it=g.find(a[que[til-1]].hig);
				if(it!=g.end()){
					MOD_ADD(&ans, it->second.value());
					g.erase(it);
				}/*else{
					fprintf(stderr, "fatal error\n");
				}*/
				til--;
			}
			while(til>0 && a[que[til-1]].hig==a[i].hig){
				til--;
			}
			que[til++]=i;
			it=g.find(a[i].hig);
			if(it!=g.end()){
				it->second.add(a[i].pos);
			}else g.insert(MP(a[i].hig, buf_t(0,0,0,0,a[i].pos)));
		}
		for(it=g.begin(); it!=g.end(); it++){
			MOD_ADD(&ans, it->second.value());
		}
		printf("%d\n", MOD_STD(ans));
	}
	return 0;
}
