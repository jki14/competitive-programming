#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_CONFIG_

static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;
static const double eps=1e-14;

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
    int *PRIMELIST(const int til, int *length=NULL){
        int *foo=(int*)malloc(sizeof(int)*(til+1));
        int len=0;
        memset(foo, 0, sizeof(int)*(til+1));
        for(int i=2; i<=til; i++){
            if(!foo[i])foo[len++]=i;
            for(int j=0; j<len && foo[j]<=til/i; j++){
                foo[foo[j]*i]=1;
                if(i%foo[j]==0)break;
            }
        }
        if(length!=NULL){
            *length=len;
        }
        foo[len++]=0;
        foo=(int*)realloc(foo, sizeof(int)*len);
        return foo;
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
                return this->data[x*this->wid+y];
            }

            T * operator[](const unsigned long x){
                if(x>=this->hig)return (T*)NULL;
                return this->data+(x*this->wid);
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

    //Complex
    template<class T> class complex_t{
        public:
        T r, i;//real part & imaginary part; x+yi
        complex_t(T x=0.0, T y=0.0){ this->r=x; this->i=y; }
        complex_t operator + (const complex_t &opn) const { return complex_t(this->r+opn.r, this->i+opn.i); }
        complex_t operator - (const complex_t &opn) const { return complex_t(this->r-opn.r, this->i-opn.i); }
        complex_t operator * (const complex_t &opn) const { return complex_t(this->r*opn.r-this->i*opn.i, this->r*opn.i+this->i*opn.r); }
    };

    template<class T> void fast_fourier_trans(complex_t<T> f[], const int len, const int is_dft){
        for(int i=1, j=len>>1; i<len-1; i++){
            if(i<j)swap(f[i], f[j]);
            int k=len>>1;
            while(j>=k){
                j-=k;
                k>>=1;
            }
            if(j<k)j+=k;
        }
        for(int h=2; h<=len; h<<=1){
            complex_t<T> wn(cos(is_dft?(-2*PI/h):(2*PI/h)), sin(is_dft?(-2*PI/h):(2*PI/h)));
            for(int i=0; i<len; i+=h){
                complex_t<T> wm(1.0, 0.0);
                for(int j=i; j<i+(h>>1); j++){
                    complex_t<T> u = f[j];
                    complex_t<T> t = wm*f[j+(h>>1)];
                    f[j] = u+t;
                    f[j+(h>>1)] = u-t;
                    wm = wm*wn;
                }
            }
        }
        if(!is_dft){
            for(int i=0; i<len; i++)
                f[i].r/=len*1.0;
        }
    }

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
        bool operator < (const point_t &rhs) const{
            if(fsign(this->y-rhs.y)!=0)
                return fsign(this->y-rhs.y)<0;
            return fsign(this->x-rhs.x)<0;
        }
        T cross(const point_t &p, const point_t &q) const{
            return (p-*this)^(q-*this);
        }
        void rotate(const double radian){
            T x0=x, y0=y;
            T sinr=sin(radian);
            T cosr=cos(radian);
            x=x0*cosr-y0*sinr;
            y=x0*sinr+y0*cosr;
        }
        void rotate(const point_t &p, const double radian){
            T x0=x-p.x, y0=y-p.y;
            T sinr=sin(radian);
            T cosr=cos(radian);
            x=x0*cosr-y0*sinr+p.x;
            y=x0*sinr+y0*cosr+p.y;
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

    template<class T> static int compare_pas(const void *x, const void *y, void *z){
        const point_t<T> *p1 = (point_t<T>*)x;
        const point_t<T> *p2 = (point_t<T>*)y;
        const point_t<T> *p0 = (point_t<T>*)z;
        int sgn = fsign(((*p1)-(*p0))^((*p2)-(*p0)));
        if(sgn!=0)return -sgn;
        return fsign(p0->dist2(*p1)-p0->dist2(*p2));
    }
    template<class T> void polar_angle_sort(point_t<T> *pnts, const int n){
        int p=0;
        for(int i=1; i<n; i++){
            if(pnts[p]<pnts[i])p=i;
        }
        swap(pnts[0], pnts[p]);
        qsort_r(pnts+1, n-1, sizeof(point_t<T>), compare_pas<T>, pnts);
    }

    template<class T> void graham(point_t<T> *pnts, const int n, int *idx, int &m){
        polar_angle_sort(pnts, n);
        m=0;
        if(n<3)return;
        idx[m++]=0;
        idx[m++]=1;
        for(int i=2; i<n; i++){
            while(m>1 && fsign(pnts[idx[m-2]].cross(pnts[idx[m-1]], pnts[i]))<=0)m--;
            idx[m++]=i;
        }
    }


//TAIL_OF_JKI'S_HEADER

#define S 170000000

struct position_t{
    int x, y;
    position_t(const int lhs, const int rhs){
        this->x = lhs;
        this->y = rhs;
    }
    int zoneid(){
        return (this->x<0 || (this->x==0 && this->y>0))?0:1;
    }
    int dist2(){
        return this->x*this->x+this->y*this->y;
    }
    int squared(){
        int goal=this->dist2();
        int root=floor(sqrt(goal));
        return root*root==goal;
    }
    bool operator == (const position_t &rhs){
        return this->x==rhs.x && this->y==rhs.y;
    }
};

const int solution[68][12] = {
{0,3,7,20,26,34,8,10,25,39,43,62},//0
{0,1,3,20,34,41,8,10,25,39,43,62},//1
{2,6,8,17,34,62,3,4,20,25,43,56},//2
{3,6,7,8,25,62,2,20,26,34,39,43},//3
{4,6,30,41,43,47,10,19,33,59,59,59},//4
{5,16,45,52,52,54,3,22,31,31,31,46},//5
{4,6,30,41,43,47,10,19,33,59,59,59},//6
{3,6,7,8,25,62,2,20,26,34,39,43},//7
{8,13,28,49,51,65,4,25,27,37,43,45},//8
{9,15,31,33,60,63,15,31,34,34,37,56},//9
{10,21,25,30,38,62,9,21,24,41,44,48},//10
{11,12,29,31,44,60,35,37,43,44,57,64},//11
{12,45,48,54,65,65,15,23,47,52,57,65},//12
{8,13,28,49,51,65,4,25,27,37,43,45},//13
{14,34,39,49,52,53,26,54,55,55,59,66},//14
{9,15,31,33,60,63,15,31,34,34,37,56},//15
{16,31,33,34,56,56,9,16,31,34,37,63},//16
{3,4,17,34,43,62,0,8,10,20,25,56},//17
{18,30,40,42,44,61,18,28,31,48,49,66},//18
{4,19,26,33,59,59,1,30,32,43,47,59},//19
{0,3,7,20,26,34,8,10,25,39,43,62},//20
{10,21,25,30,38,62,9,21,24,41,44,48},//21
{4,11,22,34,42,54,3,21,34,34,35,47},//22
{1,23,28,46,54,61,27,30,31,33,66,66},//23
{24,56,56,58,58,62,21,26,36,44,47,54},//24
{3,6,7,8,25,62,2,20,26,34,39,43},//25
{4,19,26,33,59,59,1,30,32,43,47,59},//26
{4,8,27,28,43,65,13,25,37,45,49,51},//27
{8,13,28,49,51,65,4,25,27,37,43,45},//28
{11,12,29,31,44,60,35,37,43,44,57,64},//29
{4,6,30,41,43,47,10,19,33,59,59,59},//30
{9,15,31,33,60,63,15,31,34,34,37,56},//31
{4,7,32,33,47,59,15,19,30,43,59,59},//32
{9,15,31,33,60,63,15,31,34,34,37,56},//33
{16,31,33,34,56,56,9,16,31,34,37,63},//34
{11,12,35,43,44,53,29,31,37,44,57,67},//35
{3,11,27,36,59,65,0,26,38,40,43,62},//36
{9,26,31,33,37,60,7,31,34,34,56,63},//37
{10,21,25,30,38,62,9,21,24,41,44,48},//38
{3,17,17,34,39,43,0,8,10,20,25,56},//39
{18,30,40,42,44,61,18,28,31,48,49,66},//40
{4,6,30,41,43,47,10,19,33,59,59,59},//41
{18,30,40,42,44,61,18,28,31,48,49,66},//42
{4,6,30,41,43,47,10,19,33,59,59,59},//43
{18,30,40,42,44,61,18,28,31,48,49,66},//44
{12,45,48,54,65,65,15,23,47,52,57,65},//45
{6,31,31,46,50,52,2,3,31,45,52,54},//46
{4,6,30,41,43,47,10,19,33,59,59,59},//47
{12,45,48,54,65,65,15,23,47,52,57,65},//48
{8,13,28,49,51,65,4,25,27,37,43,45},//49
{6,31,31,46,50,52,2,3,31,45,52,54},//50
{8,13,28,49,51,65,4,25,27,37,43,45},//51
{6,31,31,46,50,52,2,3,31,45,52,54},//52
{11,12,35,43,44,53,29,31,37,44,57,67},//53
{12,45,48,54,65,65,15,23,47,52,57,65},//54
{26,34,52,55,59,66,14,39,49,53,54,55},//55
{16,31,33,34,56,56,9,16,31,34,37,63},//56
{41,44,54,57,65,66,8,19,23,27,45,55},//57
{21,47,56,56,58,62,24,26,36,44,54,58},//58
{4,19,26,33,59,59,1,30,32,43,47,59},//59
{9,15,31,33,60,63,15,31,34,34,37,56},//60
{18,30,40,42,44,61,18,28,31,48,49,66},//61
{3,6,7,8,25,62,2,20,26,34,39,43},//62
{9,15,31,33,60,63,15,31,34,34,37,56},//63
{12,31,43,44,57,64,11,29,35,37,44,60},//64
{8,13,28,49,51,65,4,25,27,37,43,45},//65
{4,28,40,40,54,66,28,33,41,45,54,55},//66
{12,29,43,44,57,67,11,31,35,37,44,53}//67
};

vector<position_t> post[2][68];
double dist[68];

int main(){
    map<int, int> dist2_map;
    for(int x=-12; x<=12; x++){
        for(int y=-12; y<=12; y++){
            position_t position(x, y);
            if(position.squared())continue;
            dist2_map.insert(MP(position.dist2(), 0));
        }
    }
    int len=0;
    for(auto &entry:dist2_map){
        entry.second=len;
        dist[len]=entry.first;
        dist[len]=sqrt(entry.first*1.0);
        dist[len]-=floor(dist[len]);
        post[0][len].clear();
        post[1][len].clear();
        len++;
    }
    for(int x=-12; x<=12; x++){
        for(int y=-12; y<=12; y++){
            position_t position(x, y);
            if(position.squared())continue;
            post[position.zoneid()][dist2_map[position.dist2()]].push_back(position);
        }
    }
    int x, y;
    while(scanf("%d%d", &x, &y)!=EOF){
        position_t position(x, y);
        assert(dist2_map.count(position.dist2()));
        int offset=dist2_map[position.dist2()];
        int zoneid=position.zoneid();
        for(int i=0; i<6; i++){
            int kind=solution[offset][i];
            int count=1;
            while(i+1<6 && solution[offset][i+1]==kind){
                count++;
                i++;
            }
            if(offset==kind){
                count--;
            }
            for(int j=0; j<count; j++){
                if(post[zoneid][kind][j]==position){
                    count++;
                    continue;
                }
                printf("%d %d\n", post[zoneid][kind][j].x, post[zoneid][kind][j].y);
            }
        }
        for(int i=6; i<12; i++){
            int kind=solution[offset][i];
            int count=1;
            while(i+1<12 && solution[offset][i+1]==kind){
                count++;
                i++;
            }
            for(int j=0; j<count; j++){
                printf("%d %d\n", post[zoneid^1][kind][j].x, post[zoneid^1][kind][j].y);
            }
        }
    }
    return 0;
}
