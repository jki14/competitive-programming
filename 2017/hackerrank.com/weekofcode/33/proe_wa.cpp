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
#define M 410000

class bdgraph_t{
    //private:
    public:
    struct edge_t{
        int src, dst, wht;
        int cut;
        edge_t *next;
        edge_t *dual;
    } edge_pool[M], *edge_tail, *edge_head[N];
    int dfn[N], low[N];
    int ins[N], stk[N], top;
    int col[N];
    //public:
    int offset;
    unordered_map<int, unordered_map<int, pii> > lca;
    int hig[N];
    inline int find(const int u){ if(this->col[u]!=u)this->col[u]=this->find(this->col[u]);return this->col[u]; }
    void clear(const int n=N){
        this->edge_tail=this->edge_pool;
        for(int i=0; i<n; i++){
            this->edge_head[i]=NULL;
            this->dfn[i]=-1;
            this->ins[i]=-1;
            this->col[i]=i;
        }
        this->offset=0;
        this->top=0;
        this->lca.clear();
    }
    void add_edge(const int u, const int v, const int x=-1, const int y=-1){
        this->edge_tail->next=this->edge_head[u];
        this->edge_tail->src=u;
        this->edge_tail->dst=v;
        this->edge_tail->wht=x;
        this->edge_tail->cut=0;
        this->edge_tail->dual=this->edge_tail+1;
        this->edge_head[u]=this->edge_tail++;
        this->edge_tail->next=this->edge_head[v];
        this->edge_tail->src=v;
        this->edge_tail->dst=u;
        this->edge_tail->wht=y;
        this->edge_tail->cut=0;
        this->edge_tail->dual=this->edge_tail-1;
        this->edge_head[v]=this->edge_tail++;
    }
    void add_request(const int u, const int v, const int k=1){
        unordered_map<int, unordered_map<int, pii> >::iterator it=this->lca.find(u);
        if(it==this->lca.end()){
            it=this->lca.insert(MP(u, unordered_map<int, pii>())).first;
        }
        it->second.insert(MP(v, MP(-1, -1)));
        if(k)this->add_request(v, u, 0);
    }
    void tarjan(const int u, const int p){
        this->low[u]=this->dfn[u]=this->offset++;
        this->stk[this->top++]=u;
        this->ins[u]=1;
        int sub_branch=0;
        for(edge_t *edge=this->edge_head[u]; edge!=NULL; edge=edge->next){
            int v=edge->dst;
            if(v==p)continue;
            if(!~this->dfn[v]){
                sub_branch++;
                tarjan(v, u);
                if(this->low[u]>this->low[v])this->low[u]=this->low[v];
                //cut edge
                if(this->low[v]>this->dfn[u]){
                    edge->cut=1;
                    edge->dual->cut=1;
                }
                //cut vertex non-root
                if(~p && this->low[v]>=this->dfn[u]){
                    
                }
            }else{
                if(this->low[u]>this->dfn[v]){
                    this->low[u]=this->dfn[v];
                }
            }
        }
        //cut vertex root
        if(!~p && sub_branch>1){
            
        }
        /*this->ins[u]=0;
        this->top--;*/
        //block found
        if(this->low[u]==this->dfn[u]){
            while(true){
                int v=this->stk[--this->top];
                this->ins[v]=0;
                this->col[v]=u;
                if(v==u)break;
            }
        }
    }
    void process(const int u, const int p, const int w){
        if(~p){
            this->hig[u]=this->hig[p]+1;
        }else{
            this->hig[u]=0;
        }
        this->dfn[u]=this->offset++;
        for(edge_t *edge=this->edge_head[u]; edge!=NULL; edge=edge->next){
            int v=edge->dst;
            if(v==p)continue;
            this->low[u]=edge->wht;
            process(v, u, edge->wht);
            this->col[v]=u;
        }
        this->low[u]=w;
        unordered_map<int, unordered_map<int, pii> >::iterator it=this->lca.find(u);
        if(it!=this->lca.end()){
            for(unordered_map<int, pii>::iterator it2=it->second.begin(); it2!=it->second.end(); it2++){
                if(~it2->second.first)continue;
                int v=it2->first;
                if(~this->dfn[v]){
                    it2->second=MP(find(v), this->low[u]);
                    this->lca[v][u]=MP(find(v), this->low[v]);
                }
            }
        }
    }
} a, b;

int n, m, q;
int x[N], y[N], z[N];

int main(){
    while(scanf("%d%d%d", &n, &m, &q)!=EOF){
        a.clear(n);
        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            a.add_edge(u, v);
        }
        for(int u=0; u<n; u++){
            if(!~a.dfn[u]){
                a.tarjan(u, -1);
            }
        }
        b.clear(n);
        for(bdgraph_t::edge_t *edge=a.edge_pool; edge!=a.edge_tail; edge+=2){
            if(!edge->cut)continue;
            b.add_edge(a.col[edge->src], a.col[edge->dst], edge->src, edge->dst);
            //fprintf(stderr, "b add_edge %d, %d\n", a.col[edge->src], b.col[edge->dst]);
        }
        for(int i=0; i<q; i++){
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            x[i]--;
            y[i]--;
            z[i]--;
            //x[i]=a.col[x[i]];
            //y[i]=a.col[y[i]];
            //z[i]=a.col[z[i]];
            b.add_request(a.col[x[i]], a.col[z[i]]);
            b.add_request(a.col[y[i]], a.col[z[i]]);
            b.add_request(a.col[x[i]], a.col[y[i]]);
        }
        for(int u=0; u<n; u++){
            if(a.col[u]!=u)continue;
            if(!~b.dfn[u]){
                b.process(u, -1, -1);
            }
        }
        for(int i=0; i<q; i++){
            //fprintf(stderr, "request %d, %d, %d\n", x[i], y[i], z[i]);
            if(~b.lca[a.col[x[i]]][a.col[z[i]]].first && ~b.lca[a.col[y[i]]][a.col[z[i]]].first){
                if(a.col[x[i]]==a.col[z[i]]){
                    if(a.col[y[i]]==a.col[z[i]]){
                        printf("YES\n");
                        continue;
                    }
                    if(b.lca[a.col[x[i]]][a.col[y[i]]].second!=x[i]){
                        printf("YES\n");
                        continue;
                    }
                }else if(a.col[y[i]]==a.col[z[i]]){
                    if(a.col[x[i]]==a.col[z[i]]){
                        printf("YES\n");
                        continue;
                    }
                    if(b.lca[a.col[y[i]]][a.col[x[i]]].second!=y[i]){
                        printf("YES\n");
                        continue;
                    }
                }else if(b.lca[a.col[x[i]]][a.col[z[i]]].first==a.col[z[i]] || b.lca[a.col[y[i]]][a.col[z[i]]].first==a.col[z[i]]){
                    if(b.hig[b.lca[a.col[x[i]]][a.col[y[i]]].first]<=b.hig[a.col[z[i]]]){
                        printf("YES\n");
                        continue;
                    }
                }
            }
            printf("NO\n");
        }
    }
    return 0;
}
