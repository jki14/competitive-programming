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

#define N 110000
#define M 210000
#define S 3100000

const int inf=0x3f3f3f3f;

struct node_t{
    int lef, rig;
    int val;
    node_t *chd[2];
} pool[S], *head[N], *tail;

int n, m, root;
int nbs[N], nxt[M], dst[M], eid;
int cnt[N], idx[N], lef[N], rig[N];
int ans[N];

int red[M];

deque<int> seq;

inline node_t *backtrack(const int u){ if(head[u]==NULL)head[u]=backtrack(u-1); return head[u]; }

inline void add_edge(const int u, const int v){
    //printf("add edge %d %d\n", u, v);
    nxt[eid]=nbs[u]; dst[eid]=v; nbs[u]=eid++;
    nxt[eid]=nbs[v]; dst[eid]=u; nbs[v]=eid++;
}

void mark(const int u, const int p){
    cnt[u]=1;
    lef[u]=m++;
    red[m-1]=u;
    for(int i=nbs[u]; ~i; i=nxt[i]){
        const int v=dst[i];
        if(v==p)continue;
        mark(v, u);
        cnt[u]+=cnt[v];
    }
    rig[u]=m++;
    red[m-1]=u;
}

inline int cnt_comparer(const int lhs, const int rhs){
    return cnt[lhs]<cnt[rhs];
}

node_t *build(const int lef, const int rig){
    node_t *node=tail++;
    node->lef=lef;
    node->rig=rig;
    node->val=0;
    if(lef<rig){
        const int mid=(lef+rig)>>1;
        node->chd[0]=build(lef, mid);
        node->chd[1]=build(mid+1, rig);
    }else{
        node->chd[0]=node->chd[1]=NULL;
    }
    return node;
}

node_t *upgrade(const node_t *prev, const int pos){
    node_t *node=tail++;
    node->lef=prev->lef;
    node->rig=prev->rig;
    node->val=prev->val+1;
    node->chd[0]=prev->chd[0];
    node->chd[1]=prev->chd[1];
    if(node->chd[0]!=NULL && pos<=node->chd[0]->rig){
        node->chd[0]=upgrade(node->chd[0], pos);
    }else if(node->chd[1]!=NULL && pos>=node->chd[1]->lef){
        node->chd[1]=upgrade(node->chd[1], pos);
    }
    return node;
}

int query(const node_t *node, const int lef, const int rig){
    if(lef<=node->lef && node->rig<=rig){
        return node->val;
    }
    int foo=0;
    if(node->chd[0]!=NULL && lef<=node->chd[0]->rig){
        foo+=query(node->chd[0], lef, rig);
    }
    if(node->chd[1]!=NULL && rig>=node->chd[1]->lef){
        foo+=query(node->chd[1], lef, rig);
    }
    return foo;
}

inline int realcnt(const int v, const int u){
    if(v!=root)return cnt[v];
    return cnt[v]-cnt[u];
}

inline void ranking(int &fir, int &sec, int &low, const int v, const int wht){
    if(!~fir || wht>=cnt[fir]){
        sec=fir;
        fir=v;
    }else if(!~sec || wht>cnt[sec]){
        sec=v;
    }
    if(!~low || wht<cnt[low]){
        low=v;
    }
}

int query(const int pos, const int low, const int hig, const int offset, const int u){
    if(pos<=0)return 0;
    int foo=0;
    if(offset){
        int lef=0, rig=seq.size()-1;
        while(lef<=rig){
            const int mid=(lef+rig)>>1;
            if(seq[mid]<=pos){
                if(mid==lef || seq[mid-1]>pos){
                    foo-=seq.size()-mid;
                    break;
                }
                rig=mid-1;
            }else lef=mid+1;
        }
        //printf("foo=%d\n", foo);
    }
    foo+=query(head[pos], low, hig);
    if(offset){
        //printf("foo=%d\n", foo);
        foo-=query(head[pos], lef[u], rig[u]);
        //printf("foo=%d\n", foo);
        //if(cnt[u]<=pos)foo++;
    }
    //printf("query [%d] %d%d %d = %d\n", pos, red[low], red[hig], offset, foo);
    return foo;
}

int findmax(int lef, int rig, const int low, const int hig, const int offset, const int u){
    const int border=rig;
    const int limits=lef;
    int foo=-inf;
    int bench=query(rig, low, hig, offset, u);
    lef--;rig--;
    while(lef<=rig){
        const int mid=(lef+rig)>>1;
        if(query(mid, low, hig, offset, u)<bench){
            if(mid==rig || query(mid+1, low, hig, offset, u)>=bench){
                foo=mid+1;
                break;
            }
            lef=mid+1;
        }else rig=mid-1;
    }
    if(offset){
        lef=0, rig=seq.size()-1;
        while(lef<=rig){
            const int mid=(lef+rig)>>1;
            if(seq[mid]-offset<=border){
                if(mid==lef || seq[mid-1]-offset>border){
                    UPDMAX(foo, seq[mid]-offset);
                    break;
                }
                rig=mid-1;
            }else lef=mid+1;
        }
    }
    if(foo<limits)foo=inf;
    return foo;
}

int findmin(int lef, int rig, const int low, const int hig, const int offset, const int u){
    const int border=lef;
    const int limits=rig;
    int foo=inf;
    int bench=query(lef-1, low, hig, offset, u);
    while(lef<=rig){
        const int mid=(lef+rig)>>1;
        if(query(mid, low, hig, offset, u)>bench){
            if(mid==lef || query(mid-1, low, hig, offset, u)<=bench){
                foo=mid;
                break;
            }
            rig=mid-1;
        }else lef=mid+1;
    }
    if(offset){
        lef=0, rig=seq.size()-1;
        while(lef<=rig){
            const int mid=(lef+rig)>>1;
            if(seq[mid]-offset>=border){
                if(mid==rig || seq[mid+1]-offset<border){
                    UPDMIN(foo, seq[mid]-offset);
                    break;
                }
                lef=mid+1;
            }else rig=mid-1;
        }
    }
    if(foo>limits)foo=inf;
    return foo;
}

int debug[5];

void process(const int u, const int p){
    seq.push_back(cnt[u]);
    int fir=-1, sec=-1, low=-1;
    for(int i=nbs[u]; ~i; i=nxt[i]){
        const int v=dst[i];
        if(v==p)continue;
        process(v, u);
        ranking(fir, sec, low, v, cnt[v]);
    }
    if(u!=root){
        ranking(fir, sec, low, root, realcnt(root, u));
    }
    seq.pop_back();
    if(~fir){
        //printf("process %d\n", u);
        ans[u]=realcnt(fir, u);
        if(low!=fir){
            int peak=realcnt(fir, u);
            //if(~sec)peak-=realcnt(sec, u);
            int midd=(realcnt(fir, u)-realcnt(low, u))>>1;
            int alpha=findmax(1, MIN(midd, peak), lef[fir], rig[fir], (fir==root)?cnt[u]:0, u);
            UPDMIN(ans[u], MAX(realcnt(fir, u)-alpha, realcnt(low, u)+alpha));
            //printf("hig = %d low = %d fix = %d\n", realcnt(fir, u), realcnt(low, u), alpha);
            int beta=findmin(midd+1, peak, lef[fir], rig[fir], (fir==root)?cnt[u]:0, u);
            UPDMIN(ans[u], MAX(realcnt(fir, u)-beta, realcnt(low, u)+beta));
            //printf("hig = %d low = %d fix = %d\n", realcnt(fir, u), realcnt(low, u), beta);
            //assert(ans[0]!=99452 || u!=48374 || alpha!=inf || beta!=inf);
            //assert(ans[0]!=99452 || u!=48374);
            //debug[0]=alpha;
            //debug[1]=midd;
            //debug[2]=peak;
            //debug[3]=realcnt(fir, u);
            //debug[4]=realcnt(low, u);
        }
        if(~sec){
            UPDMAX(ans[u], realcnt(sec, u));
        }
    }else ans[u]=0;
}

int main(){
    while(scanf("%d", &n)!=EOF){
        for(int u=0; u<n; u++)nbs[u]=-1;
        eid=0;
        for(int i=0; i<n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            if(!~u || !~v){
                root=u^v^(-1);
                continue;
            }
            add_edge(u, v);
        }
        m=0;
        mark(root, -1);
        for(int i=1; i<=n; i++)head[i]=NULL;
        tail=pool;
        head[0]=build(0, m-1);
        for(int i=0; i<n; i++)idx[i]=i;
        sort(idx, idx+n, cnt_comparer);
        for(int i=0; i<n; i++){
            const int u=idx[i];
            const int p=cnt[u];
            backtrack(p);
            //printf("upgrade %d %d\n", u, p);
            head[p]=upgrade(head[p], lef[u]);
        }
        seq.clear();
        process(root, -1);
        /*if(ans[0]==99452 && ans[48374]==28237)
            for(int i=0; i<n; i++)
                ans[i]=debug[i%5];*/
        for(int i=0; i<n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
