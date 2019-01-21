#include "bits/stdc++.h"
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

#define N 51000
#define D 225

/*struct cube_t{
    unordered_map<int, pair<int, unordered_map<int, pair<int, unordered_map<int, pair<int, unordered_set<int>>>>>>> foo;
    unordered_map<int, pair<int, unordered_map<int, pair<int, unordered_map<int, pair<int, unordered_set<int>>>>>>>::iterator p0;
    unordered_map<int, pair<int, unordered_map<int, pair<int, unordered_set<int>>>>>::iterator p1;
    unordered_map<int, pair<int, unordered_set<int>>>::iterator p2;
    int mask, ceil;
    int value[N];
    void clear(const int n){
        this->foo.clear();
        this->ceil=n;
        this->mask=1;
        while(this->mask*this->mask<n)this->mask++;
        for(int i=0; i<n; i++)this->value[i]=0;
    }
    int get(int r){
        for(int i=0; i<this->mask; i++){
            p0=foo.find(i);
            if(p0==foo.end())continue;
            if(r>p0->second.first){
                r-=p0->second.first;
                continue;
            }
            for(int j=0; j<this->mask; j++){
                int cnt=this->ceil-this->mask*i-j;
                if(cnt<=0)break;
                p1=p0->second.second.find(cnt);
                if(p1==p0->second.second.end())continue;
                if(r>p1->second.first){
                    r-=p1->second.first;
                    continue;
                }
                for(int k=0; k<this->mask; k++){
                    p2=p1->second.second.find(k);
                    if(p2==p1->second.second.end())continue;
                    if(r>p2->second.first){
                        r-=p2->second.first;
                        continue;
                    }
                    for(int x=0; x<this->mask; x++){
                        int pos=this->ceil-this->mask*k-x-1;
                        if(pos<0)break;
                        if(!p2->second.second.count(pos))continue;
                        if(r!=1){
                            r--;
                        }else{
                            return pos;
                        }
                    }
                    break;
                }
                break;
            }
            break;
        }
        assert(0);
        return -1;
    }
    void set(const int pos, const int d){
        int &cnt=this->value[pos];
        if(cnt){
            p0=this->foo.find((this->ceil-cnt)/this->mask);
            assert(p0!=this->foo.end());
            p1=p0->second.second.find(cnt);
            assert(p1!=p0->second.second.end());
            p2=p1->second.second.find((this->ceil-pos-1)/this->mask);
            assert(p2!=p1->second.second.end());
            assert(p2->second.second.count(pos));
            p2->second.second.erase(pos);
            p2->second.first--;
            //if(!p2->second.first)p1->second.second.erase(p2);
            p1->second.first--;
            //if(!p1->second.first)p0->second.second.erase(p1);
            p0->second.first--;
            //if(!p0->second.first)this->foo.erase(p0);
        }
        cnt+=d;
        if(cnt){
            int k0=(this->ceil-cnt)/this->mask;
            p0=this->foo.find(k0);
            if(p0==this->foo.end()){
                this->foo.insert(MP(k0, MP(0, unordered_map<int, pair<int, unordered_map<int, pair<int, unordered_set<int>>>>>())));
                p0=this->foo.find(k0);
            }
            p1=p0->second.second.find(cnt);
            if(p1==p0->second.second.end()){
                p0->second.second.insert(MP(cnt, MP(0, unordered_map<int, pair<int, unordered_set<int>>>())));
                p1=p0->second.second.find(cnt);
            }
            int k2=(this->ceil-pos-1)/this->mask;
            p2=p1->second.second.find(k2);
            if(p2==p1->second.second.end()){
                p1->second.second.insert(MP(k2, MP(0, unordered_set<int>())));
                p2=p1->second.second.find(k2);
            }
            assert(!p2->second.second.count(pos));
            p2->second.second.insert(pos);
            p2->second.first++;
            p1->second.first++;
            p0->second.first++;
        }
    }
    void show(){
        fprintf(stderr, "{\n");
        for(p0=this->foo.begin(); p0!=this->foo.end(); p0++){
            fprintf(stderr, "  %d => (%d\n", p0->first, p0->second.first);
            fprintf(stderr, "    ,{\n");
            for(p1=p0->second.second.begin(); p1!=p0->second.second.end(); p1++){
                fprintf(stderr, "      %d => (%d\n", p1->first, p1->second.first);
                fprintf(stderr, "        ,{\n");
                for(p2=p1->second.second.begin(); p2!=p1->second.second.end(); p2++){
                    fprintf(stderr, "          %d => { ", p2->first);
                    for(int pos : p2->second.second){
                        fprintf(stderr, "%d ", pos);
                    }
                    fprintf(stderr, "}\n");
                }
                fprintf(stderr, "        }\n");
                fprintf(stderr, "      )\n");
            }
            fprintf(stderr, "    }\n");
            fprintf(stderr, "  )\n");
        }
    }
} cube;*/

struct cube_t{
    struct pblock_t{
        int lef, cnt;
    };
    struct emount_t{
        int lef, cnt;
        pblock_t pblock[233];
    };
    struct cblock_t{
        int lef, cnt;
        emount_t emount[233];
    } cblock[233];
    int mask, ceil;
    int value[N];
    void clear(const int n){
        this->ceil=n;
        this->mask=1;
        while(this->mask*this->mask<n)this->mask++;
        for(int x=0; x<this->mask; x++){
            cblock[x].lef=this->ceil-this->mask*x;
            cblock[x].cnt=0;
            for(int y=0; y<this->mask; y++){
                cblock[x].emount[y].lef=cblock[x].lef-y;
                cblock[x].emount[y].cnt=0;
                for(int z=0; z<this->mask; z++){
                    cblock[x].emount[y].pblock[z].lef=this->ceil-this->mask*z-1;
                    cblock[x].emount[y].pblock[z].cnt=0;
                }
            }
        }
        for(int i=0; i<n; i++)this->value[i]=0;
    }
    int get(int r){
        for(int x=0; x<this->mask; x++){
            if(r>cblock[x].cnt){
                r-=cblock[x].cnt;
                continue;
            }
            for(int y=0; y<this->mask; y++){
                if(r>cblock[x].emount[y].cnt){
                    r-=cblock[x].emount[y].cnt;
                    continue;
                }
                for(int z=0; z<this->mask; z++){
                    if(r>cblock[x].emount[y].pblock[z].cnt){
                        r-=cblock[x].emount[y].pblock[z].cnt;
                        continue;
                    }
                    for(int p=cblock[x].emount[y].pblock[z].lef; p>=0; p--){
                        if(p<=cblock[x].emount[y].pblock[z].lef-this->mask)break;
                        if(this->value[p]!=cblock[x].emount[y].lef)continue;
                        if(r!=1){
                            r--;
                        }else{
                            return p;
                        }
                    }
                    break;
                }
                break;
            }
            break;
        }
        assert(0);
        return -1;
    }
    void set(const int pos, const int d){
        int &cnt=this->value[pos];
        if(cnt){
            int x=(this->ceil-cnt)/this->mask;
            int y=cblock[x].lef-cnt;
            int z=(this->ceil-pos-1)/this->mask;
            cblock[x].emount[y].pblock[z].cnt--;
            cblock[x].emount[y].cnt--;
            cblock[x].cnt--;
        }
        cnt+=d;
        if(cnt){
            int x=(this->ceil-cnt)/this->mask;
            int y=cblock[x].lef-cnt;
            int z=(this->ceil-pos-1)/this->mask;
            cblock[x].emount[y].pblock[z].cnt++;
            cblock[x].emount[y].cnt++;
            cblock[x].cnt++;
        }
    }
} cube;

int block;

struct query_t{
    int u, v, k;
    int e;
    int idx;
    bool operator < (const query_t &rhs) const{
        int x=this->u/block;
        int y=rhs.u/block;
        if(x!=y)return x<y;
        return this->v<rhs.v;
    }
} query[51000];

map<int, int> c2p;
int p2c[51000];

unordered_map<int, unordered_map<int, int>> lca;
unordered_map<int, unordered_map<int, int>>::iterator i0;
unordered_map<int, int>::iterator i1;

int dfi[51000], dfo[51000], til;
int seq[110000];

int n, q, c[51000];
int ans[51000];

int nbs[51000], nxt[110000], dst[110000], eid;
int f[51000];

void makedfn(const int u, const int p){
    dfi[u]=til;
    seq[til++]=u;
    for(int i=nbs[u]; ~i; i=nxt[i]){
        int v=dst[i];
        if(v==p)continue;
        makedfn(v, u);
    }
    dfo[u]=til;
    seq[til++]=u;
}

inline int find(const int u){ if(f[u]!=u)f[u]=find(f[u]);return f[u]; }

void makelca(const int u, const int p){
    f[u]=u;
    for(int i=nbs[u]; ~i; i=nxt[i]){
        int v=dst[i];
        if(v==p)continue;
        makelca(v, u);
        f[v]=u;
    }
    i0=lca.find(u);
    if(i0!=lca.end()){
        for(i1=i0->second.begin(); i1!=i0->second.end(); i1++){
            i1->second=find(i1->first);
        }
    }
}

int mrk[51000];

void flip(const int p){
    if(!~p)return;
    if(mrk[seq[p]]){
        cube.set(c[seq[p]], -1);
        mrk[seq[p]]=0;
    }else{
        cube.set(c[seq[p]], 1);
        mrk[seq[p]]=1;
    }
}

void add_edge(const int u, const int v){
    nxt[eid]=nbs[u]; dst[eid]=v; nbs[u]=eid++;
    nxt[eid]=nbs[v]; dst[eid]=u; nbs[v]=eid++;
}

int main(){

    /*cube.clear(4);

    cube.set(0, 1);
    cube.set(1, 1);
    cube.set(0, 1);
    //cube.show();
    fprintf(stderr, "%d\n", cube.get(1)+1);
    fprintf(stderr, "%d\n", cube.get(2)+1);

    cube.set(1, -1);
    cube.set(1, 1);
    cube.set(1, 1);
    cube.set(2, 1);
    //cube.show();
    fprintf(stderr, "%d\n", cube.get(1)+1);
    fprintf(stderr, "%d\n", cube.get(3)+1);

    return 0;*/
    
    while(scanf("%d%d", &n, &q)!=EOF){
        cube.clear(n);
        c2p.clear();
        for(int i=0; i<n; i++){
            scanf("%d", &c[i]);
            c2p.insert(MP(c[i], -1));
        }
        int kind=0;
        for(map<int, int>::iterator it=c2p.begin(); it!=c2p.end(); it++){
            it->second=kind;
            p2c[kind++]=it->first;
        }
        for(int i=0; i<n; i++){
            c[i]=c2p[c[i]];
        }
        for(int i=0; i<n; i++)nbs[i]=-1;eid=0;
        for(int i=1; i<n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u-1, v-1);
        }
        til=0;
        makedfn(0, -1);
        lca.clear();
        for(int i=0; i<q; i++){
            query[i].idx=i;
            scanf("%d%d%d", &query[i].u, &query[i].v, &query[i].k);
            query[i].u--;
            query[i].v--;
            if(dfi[query[i].u]>dfi[query[i].v]){
                swap(query[i].u, query[i].v);
            }
            i0=lca.find(query[i].v);
            if(i0==lca.end()){
                lca.insert(MP(query[i].v, unordered_map<int, int>()));
                i0=lca.find(query[i].v);
            }
            i0->second.insert(MP(query[i].u, -1));
        }
        makelca(0, -1);
        for(int i=0; i<q; i++){
            if(lca[query[i].v][query[i].u]!=query[i].u){
                query[i].e=dfi[lca[query[i].v][query[i].u]];
                query[i].u=dfo[query[i].u];
                query[i].v=dfi[query[i].v];
            }else{
                query[i].e=-1;
                query[i].u=dfi[query[i].u];
                query[i].v=dfi[query[i].v];
            }
        }
        block=round(sqrt(n*2.0));
        sort(query, query+q);
        for(int i=0; i<n; i++)mrk[i]=0;
        int u=-1, v=-1;
        for(int i=0; i<q; i++){
            while(u<query[i].u)flip(u++);
            while(u>query[i].u)flip(--u);
            while(v<query[i].v)flip(++v);
            while(v>query[i].v)flip(v--);
            if(~query[i].e)flip(query[i].e);
            ans[query[i].idx]=p2c[cube.get(query[i].k)];
            if(~query[i].e)flip(query[i].e);
        }
        for(int i=0; i<q; i++){
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
