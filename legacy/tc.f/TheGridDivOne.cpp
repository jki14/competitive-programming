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
	#define MIN(x, y) (((x)<(y))?(x):(y))
	#define MAX(x, y) (((x)<(y))?(x):(y))
	#define UPDMIN(x, y) { if(x>(y))x=(y); }
	#define UPDMAX(x, y) { if(x<(y))x=(y); }

	//STL
	#define SIZE(x) ((int)x.size())
	#define LENGTH(x) ((int)x.length())
	#define MP(x, y) make_pair(x, y)

	//BIT
	#define BINT(x) (1<<(x))
	#define BLLD(x) (1LL<<(x))
	#define BINT_CONTAIN_TEST(s, x) ((s&BINT(x))!=0)
	#define BLLD_CONTAIN_TEST(s, x) ((s&BLLD(x))!=0LL)
	
	template<class T> inline T LOWBIT(const T x){ return (x^(x-1))&x; }
	template<class T> inline int BITCOUNT(const T x){ return (!x)?x:(1+BITCOUNT(x&(x-1))); }

	//CONST VALUE
	const double PI=acos(-1.0);
	const double EPS=1e-5;

	//CALCULATE
	template<class T> inline T SQR(const T x){ return x*x; }
	template<class T, class T2> inline T POW(const T x, const T2 y){
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
	template<class T, class T2> inline T MOD_POW(const T x, const T2 y, const T m){
		if(y==0)return 1%m;else if((y&1)==0){
			T z=MOD_POW(x, y>>1, m); return MOD_MUL(z, z, m);
		}else return MOD_MUL(MOD_POW(x, y^1, m), x, m);
	}
	template<class T, class T2> inline T MOD_POW(const T x, const T2 y){
		if(y==0)return 1%MOD;else if((y&1)==0){
			T z=MOD_POW(x, y>>1); return MOD_MUL(z, z);
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

#define N 50
#define M 200
#define S 50000
#define E 5000000

#define R 4

const int dx[R] = { -1, 1, 0, 0 };
const int dy[R] = { 0, 0, -1, 1 };

const int NIL=0xffffffff;

class TheGridDivOne {
private:
	struct block_t{
		int x, y;
		block_t(){ x=y=NIL; }
		block_t(const int _x, const int _y){ x=_x; y=_y; }
		bool operator < (const block_t &opn) const{
			return (this->x!=opn.x)?(this->x<opn.x):(this->y<opn.y);
		}
	};

	int n, src, count, ans;
	int buff_x[M], buff_y[M];
	int nbs[S], *dst, *nxt, mrk[S], enm;
	lld dis[S], *wht;
	block_t a[S];
	set<block_t> b, s;

	int nobax(const int x, const int y1, const int y2){
		for(set<block_t>::iterator it=b.begin(); it!=b.end(); it++){
			if(it->x!=x)continue;
			if(it->y>=y1 && it->y<=y2)return 0;
		}
		return 1;
	}
	int nobay(const int y, const int x1, const int x2){
		for(set<block_t>::iterator it=b.begin(); it!=b.end(); it++){
			if(it->y!=y)continue;
			if(it->x>=x1 && it->x<=x2)return 0;
		}
		return 1;
	}
	
	void addedge(const int u, const int v, const lld w){
		nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;wht[enm]=w;
		nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;wht[enm]=w;
	}

public:
	int find(vector <int> block_x, vector <int> block_y, int step) {
		dst=(int*)malloc(sizeof(int)*E);
		nxt=(int*)malloc(sizeof(int)*E);
		wht=(lld*)malloc(sizeof(lld)*E);
		n=SIZE(block_x);
		b.clear();s.clear();count=0;
		for(int i=0; i<n; i++)b.insert(block_t(block_x[i], block_y[i]));
		buff_x[count]=0;buff_y[count]=0;count++;
		for(set<block_t>::iterator it=b.begin(); it!=b.end(); it++){
			for(int r=0; r<R; r++){
				block_t cur = block_t(it->x+dx[r], it->y+dy[r]);
				if(b.find(cur)!=b.end())continue;
				buff_x[count]=cur.x;
				buff_y[count]=cur.y;
				count++;
			}
		}
		printf("count=%d\n", count);
		for(int i=0; i<count; i++){
			for(int j=0; j<count; j++){
				block_t cur = block_t(buff_x[i], buff_y[j]);
				if(s.find(cur)!=s.end())continue;
				if(b.find(cur)!=b.end())continue;
				s.insert(cur);
			}
		}
		n=0;
		for(set<block_t>::iterator it=s.begin(); it!=s.end(); it++){
			if(!it->x && !it->y)src=n;
			a[n++]=*it;
		}
		printf("n=%d\n", n);
		memset(nbs, 0, sizeof(nbs));enm=0;
		for(int i=0; i<n ;i++){
			for(int j=i+1; j<n; j++){
				if(a[i].x==a[j].x){
					if(nobax(a[i].x, a[i].y, a[j].y)){
						addedge(i, j, a[j].y-a[i].y);
					}
				}else if(a[i].y==a[j].y){
					if(nobay(a[i].y, a[i].x, a[j].x)){
						addedge(i, j, a[j].x-a[i].x);
					}
				}
			}
		}
		printf("enm=%d\n", enm);
		memset(dis, 0x3f, sizeof(dis));
		memset(mrk, 0, sizeof(mrk));
		dis[src]=0;mrk[src]=1;
		queue<int> que;
		while(!que.empty())que.pop();
		que.push(src);
		for(;!que.empty();que.pop()){
			int u=que.front();
			for(int i=nbs[u]; i; i=nxt[i]){
				int v=dst[i];
				if(dis[v]>dis[u]+wht[i]){
					dis[v]=dis[u]+wht[i];
					if(!mrk[v]){
						mrk[v]=1;
						que.push(v);
					}
				}
			}
			mrk[u]=0;
		}
		ans=0;
		for(int i=0; i<n; i++){
			if(dis[i]-step>0LL)continue;
			if(nobay(a[i].y, a[i].x, a[i].x+step-(int)dis[i])){
				UPDMAX(ans, a[i].x+step-(int)dis[i]);
			}else UPDMAX(ans, a[i].x);
		}
		free(dst);
		free(nxt);
		free(wht);
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 0; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 1000; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-201, 309, 257, 423, -146, -663, -126, 531, -940, -195, -536, 690, 666, -954, 219, -393, 388, 265, 362, 938, -853, -692, 486, -475, 332, -715, 122, -592, 173, -393, 822, -14, 787, -623, -238, -405, -279, 236, -713, 810, 39, 945, 23};  vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-115, -435, 999, -540, 932, -126, -12, 790, 267, 64, 700, 648, -150, 322, -479, -711, 796, 164, -190, 201, -69, 371, -440, -761, -68, -284, -887, -826, 326, 160, 797, 893, 679, -804, -40, 183, 938, -909, 891, -23, 459, -542, -636}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 6; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheGridDivOne ___test;
	___test.run_test(3);
	return 0;
}
// END CUT HERE
