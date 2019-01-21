#include <fcntl.h>
#include <unistd.h>
#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_CONFIG_

static const int MOD=1000000007; //1000000000000000003LL
static const double eps=1e-8;

//TAIL_OF_CONFIG_

//[HEAD_OF_JKI'S_HEADER_

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
        MOD_STD(&x, m);
        MOD_STD(&y, m);
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

    //General
    template<class T> class cycleq_t{
        private:
        size_t cnt, cap;
        size_t lef, rig;
        T *que;
        public:
        cycleq_t(const size_t size){
            this->cap=size;
            this->que=(T*)malloc(sizeof(T)*size);
            this->clear();
        }
        ~cycleq_t(){
            free(this->que);
        }
        inline void clear(){
            this->lef=this->rig=0;
            this->cnt=0;
        }
        inline void put(const T &obj){
            assert(this->cnt<this->cap);
            this->que[this->rig++]=obj;
            if(this->rig==this->cap)
                this->rig=0;
            this->cnt++;
        }
        inline void put_back(const T &obj){
            this->put(obj);
        }
        inline void put_front(const T &obj){
            assert(this->cnt<this->cap);
            this->lef--;
            if(!~this->lef)
                this->lef=this->cap-1;
            this->que[this->lef]=obj;
            this->cnt++;
        }
        inline T pop(){
            assert(this->cnt>0);
            T res=this->que[this->lef++];
            if(this->lef==this->cap)
                this->lef=0;
            this->cnt--;
            return res;
        }
        inline T pop_front(){
            return this->pop();
        }
        inline T pop_back(){
            assert(this->cnt>0);
            this->rig--;
            if(!~this->rig)
                this->rig=this->cap-1;
            this->cnt--;
            return this->que[this->rig];
        }
        inline T get(int64_t offset=0){
            if(offset>=0){
                assert(offset<this->cnt);
                offset+=this->lef;
                if(offset>this->cap)
                    offset-=this->cap;
                return this->que[offset];
            }else{
                assert(offset>=-this->cnt);
                offset+=this->rig;
                if(offset<0)
                    offset+=this->cap;
                return this->que[offset];
            }
        }
    };

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
        int idx;
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

    #ifndef __APPLE__
    template<class T> static int compare_pas(const void *x, const void *y, void *z){
    #else
    template<class T> static int compare_pas(void *z, const void *x, const void *y){
    #endif
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
        #ifndef __APPLE__
        qsort_r(pnts+1, n-1, sizeof(point_t<T>), compare_pas<T>, pnts);
        #else
        qsort_r(pnts+1, n-1, sizeof(point_t<T>), pnts, compare_pas<T>);
        #endif
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

    //Graph
    template<class T> class maxflow_c{
        private:
        size_t capv, cape;
        size_t cntv, cnte;
        struct mf_edge_t;
        struct mf_vertex_t{
            mf_edge_t *head, *hold;
            size_t idx, hig;
        } *vertex, **vhead, **vtail, **vque;
        struct mf_edge_t{
            mf_vertex_t *src, *dst;
            mf_edge_t *nxt, *rsv;
            T cap, cur;
        } *edge_pool, *edge_tail, **esup;
        struct dncnode_t{
            mf_vertex_t *vtx;
            T precap, reflux;
        } *dinic_stack_pool;
        size_t *dcnt;
        size_t higlev(size_t src, size_t trm, const int reverse=0){
            if(reverse)
                swap(src, trm);
            if(this->vque==NULL)
                this->vque=(mf_vertex_t**)malloc(sizeof(mf_vertex_t*)*this->capv);
            size_t lef=0, rig=0;
            for(mf_vertex_t **vtxp=this->vhead; vtxp!=this->vtail; vtxp++)
                (*vtxp)->hig=numeric_limits<size_t>::max();
            this->vertex[src].hig=0;
            this->vque[rig++]=&this->vertex[src];
            this->vertex[trm].hig=numeric_limits<size_t>::max();
            for(; lef<rig; lef++){
                mf_vertex_t *vtx=this->vque[lef];
                for(mf_edge_t *edge=vtx->head; edge!=NULL; edge=edge->nxt){
                    if(!reverse){
                        if(edge->cur<edge->cap && edge->dst->hig>vtx->hig+1){
                            edge->dst->hig=vtx->hig+1;
                            this->vque[rig++]=edge->dst;
                        }
                    }else{
                        if(edge->rsv->cur<edge->rsv->cap && edge->dst->hig>vtx->hig+1){
                            edge->dst->hig=vtx->hig+1;
                            this->vque[rig++]=edge->dst;
                        }
                    }
                }
            }
            this->vque[rig++]=NULL;
            return this->vertex[trm].hig;
        }
        T isap_augment(const size_t src, const size_t trm){
            T inc=numeric_limits<T>::max();
            for(size_t i=trm; i!=src; i=this->esup[i]->src->idx){
                UPDMIN(inc, this->esup[i]->cap-this->esup[i]->cur);
            }
            for(size_t i=trm; i!=src; i=this->esup[i]->src->idx){
                this->esup[i]->cur+=inc;
                this->esup[i]->rsv->cur-=inc;
            }
            return inc;
        }
        size_t isap_retreat(size_t &i, const size_t src){
            size_t best=numeric_limits<size_t>::max();
            for(mf_edge_t *edge=this->vertex[i].head; edge!=NULL; edge=edge->nxt){
                if(edge->cur<edge->cap){
                    UPDMIN(best, edge->dst->hig+1);
                }
            }
            size_t rep=--this->dcnt[this->vertex[i].hig];
            this->vertex[i].hig=best;
            if(best<this->cntv){
                this->dcnt[best]++;
            }
            if(i!=src)
                i=this->esup[i]->src->idx;
            return rep;
        }
        public:
        maxflow_c(const size_t numv, const size_t nume){
            this->capv=numv;
            this->cape=nume;
            this->vertex=(mf_vertex_t*)malloc(sizeof(mf_vertex_t)*numv);
            for(size_t i=0; i<numv; i++){
                this->vertex[i].idx=i;
            }
            this->vhead=(mf_vertex_t**)malloc(sizeof(mf_vertex_t*)*numv);
            this->vtail=this->vhead;
            this->vque=NULL;
            this->edge_pool=(mf_edge_t*)malloc(sizeof(mf_edge_t)*(nume<<1));
            this->dinic_stack_pool=NULL;
            this->esup=NULL;
            this->dcnt=NULL;
            this->reset();
        };
        ~maxflow_c(){
            if(this->dcnt!=NULL)
                free(this->dcnt);
            if(this->esup!=NULL)
                free(this->esup);
            if(this->dinic_stack_pool!=NULL)
                free(this->dinic_stack_pool);
            free(this->edge_pool);
            if(this->vque!=NULL)
                free(this->vque);
            free(this->vhead);
            free(this->vertex);
        }
        void reset(){
            for(size_t i=0; i<this->capv; i++)
                this->vertex[i].head=NULL;
            this->vtail=this->vhead;
            this->edge_tail=this->edge_pool;
            this->cntv=0;
            this->cnte=0;
        }
        void add_edge(const size_t u, const size_t v, const T c, const T r=0){
            assert(u<this->capv && v<this->capv);
            assert(this->cnte<this->cape);
            this->edge_tail->nxt=this->vertex[u].head;
            this->edge_tail->rsv=this->edge_tail+1;
            this->edge_tail->src=&this->vertex[u];
            this->edge_tail->dst=&this->vertex[v];
            this->edge_tail->cap=c;
            this->edge_tail->cur=0;
            if(this->vertex[u].head==NULL){
                *this->vtail++=&this->vertex[u];
                this->cntv++;
            }
            this->vertex[u].head=this->edge_tail++;
            this->edge_tail->nxt=this->vertex[v].head;
            this->edge_tail->rsv=this->edge_tail-1;
            this->edge_tail->src=&this->vertex[v];
            this->edge_tail->dst=&this->vertex[u];
            this->edge_tail->cap=r;
            this->edge_tail->cur=0;
            if(this->vertex[v].head==NULL){
                *this->vtail++=&this->vertex[v];
                this->cntv++;
            }
            this->vertex[v].head=this->edge_tail++;
            this->cnte++;
        }
        T dinic(const size_t src, const size_t trm){
            assert(src<this->capv && trm<this->capv && src!=trm);
            T foo=0;
            if(this->dinic_stack_pool==NULL)
                this->dinic_stack_pool=(dncnode_t*)malloc(sizeof(dncnode_t)*this->capv);
            while(higlev(src, trm)<numeric_limits<size_t>::max()){
                for(size_t i=0; this->vque[i]!=NULL; i++){
                    this->vque[i]->hold=this->vque[i]->head;
                }
                dncnode_t *top=this->dinic_stack_pool;
                top->vtx=&this->vertex[src];
                top->precap=numeric_limits<T>::max();
                top->reflux=0;
                while(this->vertex[src].hold!=NULL){
                    if(top->vtx->idx!=trm && top->vtx->hold!=NULL && top->vtx->hold->cur<top->vtx->hold->cap && top->vtx->hold->src->hig+1==top->vtx->hold->dst->hig){
                        dncnode_t *prv=top++;
                        top->vtx=prv->vtx->hold->dst;
                        top->precap=MIN(prv->precap-prv->reflux, prv->vtx->hold->cap-prv->vtx->hold->cur);
                        top->reflux=0;
                    }else if(top->vtx->idx==trm){
                        T inc=top->precap;
                        foo+=inc;
                        while(top->precap==top->reflux+inc){
                            inc+=top->reflux;
                            top--;
                            top->vtx->hold->cur+=inc;
                            top->vtx->hold->rsv->cur-=inc;
                        }
                        top->reflux+=inc;
                    }else{
                        if(top->vtx->hold==NULL){
                            T ref=top->reflux;
                            top--;
                            top->vtx->hold->cur+=ref;
                            top->vtx->hold->rsv->cur-=ref;
                            top->reflux+=ref;
                        }
                        top->vtx->hold=top->vtx->hold->nxt;
                    }
                }
            }
            return foo;
        }
        T isap(const size_t src, const size_t trm){
            assert(src<this->capv && trm<this->capv && src!=trm);
            T foo=0;
            if(higlev(src, trm, 1)<numeric_limits<size_t>::max()){
                if(this->dcnt==NULL)this->dcnt=(size_t*)malloc(sizeof(size_t)*this->capv);
                if(this->esup==NULL)this->esup=(mf_edge_t**)malloc(sizeof(mf_edge_t*)*this->capv);
                for(size_t i=0; i<this->cntv; i++)this->dcnt[i]=0;
                for(size_t i=0; this->vque[i]!=NULL; i++){
                    this->vque[i]->hold=this->vque[i]->head;
                    this->dcnt[this->vque[i]->hig]++;
                }
                size_t i=src;
                while(this->vertex[src].hig<this->cntv){
                    mf_edge_t *edge=this->vertex[i].hold;
                    while(edge!=NULL && !(edge->cur<edge->cap && edge->src->hig==edge->dst->hig+1)){
                        edge=edge->nxt;
                    }
                    if(edge!=NULL){
                        this->vertex[i].hold=edge;
                        this->esup[edge->dst->idx]=edge;
                        i=edge->dst->idx;
                        if(i==trm){
                            foo+=isap_augment(src, trm);
                            i=src;
                        }
                    }else{
                        this->vertex[i].hold=this->vertex[i].head;
                        if(isap_retreat(i, src)==0)
                            break;
                    }
                }
            }
            return foo;
        }
    };

//]TAIL_OF_JKI'S_HEADER

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};

typedef point_t<int> pti_t;

int hTable[1024][1024];

class RoadsAndJunctions {
private:
    int n, m, x;
    pti_t *a, *b;
    //timespec start;
    int timeResource;
    /*int urandom(void *dest, const uint32_t size){
        int hook = open("/dev/urandom", O_RDONLY);
        if(hook<0)return 1;
        if(read(hook, dest, size)!=size){
            close(hook);
            return 1;   
        }
        close(hook);
        return 0;
    }*/
    double getExpect(const double junctionCost, double failureProbability){
        /*timespec current;
        clock_gettime(CLOCK_REALTIME, &current);
        double timeCost=(current.tv_sec-this->start.tv_sec)*1000.0+(current.tv_nsec-this->start.tv_nsec)/1000000.0;
        if(timeCost>6000)return 1e9;*/
        this->timeResource-=(this->n+this->x)*(this->n+this->x);
        if(this->timeResource<0)return 1e9;
        vector<int> junctionStatus(this->x, 0);
        vector<double> costs;
        for(int k=0; k<10; k++){
            //generate junctionStatus
            for(int &suc : junctionStatus){
                double tmp = rand()*1.0/(RAND_MAX*1.0 + 1.0);
                if(tmp+1e-7>failureProbability){
                    suc = 1;
                }else{
                    suc = 0;
                }
            }
            double foo = junctionCost * this->x;
            buildRoads(junctionStatus, &foo);
            costs.push_back(foo);
        }
        return accumulate(costs.begin(), costs.end(), 0.0)/costs.size();
    }
    inline pti_t *getPti(const int offset){
        if(offset<this->n){
            return &this->a[offset];
        }else{
            return &this->b[offset-this->n];
        }
    }
    inline int dist2(const pti_t *lhs, const pti_t *rhs){
        int dx=lhs->x-rhs->x;
        int dy=lhs->y-rhs->y;
        return dx*dx+dy*dy;
    }
public:
    RoadsAndJunctions(){
        //init-start
        //clock_gettime(CLOCK_REALTIME, &this->start);
        this->timeResource=200000000;
        //srand
        //int seed;
        //while(urandom(&seed, sizeof(seed))!=0);
        srand(time(NULL));
        //alloc *a
        this->a=(pti_t*)malloc(sizeof(pti_t)*128);
        //alloc *b
        this->b=(pti_t*)malloc(sizeof(pti_t)*1048576);
    }
    ~RoadsAndJunctions(){
        free(this->a);
        free(this->b);
    }
    vector<int> buildJunctions(int S, vector<int> cities, double junctionCost, double failureProbability) {
        this->n=cities.size()>>1;
        //init
        for(int i=0; i<this->n; i++){
            this->a[i].x=cities[i<<1];
            this->a[i].y=cities[(i<<1)|1];
            this->a[i].idx=i;
        }
        //graham
        int *keyPoint=(int*)malloc(sizeof(int)*128);
        int len;
        graham(this->a, this->n, keyPoint, len);
        //build *b
        for(int x=0; x<=S; x++){
            for(int y=0; y<=S; y++){
                hTable[x][y]=0;
            }
        }
        for(int i=0; i<this->n; i++){
            hTable[this->a[i].x][this->a[i].y]=1;
        }
        int *lef=(int*)malloc(sizeof(int)*1024);
        int *rig=(int*)malloc(sizeof(int)*1024);
        for(int i=0; i<=S; i++)lef[i]=1001;
        for(int i=0; i<=S; i++)rig[i]=-1;
        for(int i=0; i<len; i++){
            const int lhs=keyPoint[i];
            const int rhs=keyPoint[(i+1)%len];
            if(this->a[lhs].y!=this->a[rhs].y){
                int dx=this->a[rhs].x-this->a[lhs].x;
                int dy=this->a[rhs].y-this->a[lhs].y;
                int dd=dy/abs(dy);
                for(int y=this->a[lhs].y; ; y+=dd){
                    double x=this->a[lhs].x*1.0+dx*(y-this->a[lhs].y)*1.0/dy;
                    UPDMIN(lef[y], (int)ceil(x));
                    UPDMAX(rig[y], (int)floor(x));
                    if(y==this->a[rhs].y)break;
                }
            }else{
                UPDMIN(lef[this->a[lhs].y], this->a[lhs].x);
                UPDMAX(rig[this->a[lhs].y], this->a[lhs].x);
                UPDMIN(lef[this->a[rhs].y], this->a[rhs].x);
                UPDMAX(rig[this->a[rhs].y], this->a[rhs].x);
            }
        }
        this->m=0;
        for(int y=0; y<=S; y++){
            for(int x=lef[y]; x<=rig[y]; x++){
                if(hTable[x][y])continue;
                this->b[this->m].x=x;
                this->b[this->m].y=y;
                this->m++;
            }
        }
        free(lef);
        free(rig);
        free(keyPoint);
        //DEBUG
        /*fprintf(stderr, "%d\n", this->n);
        for(int i=0; i<this->n; i++){
            fprintf(stderr, "%d %d\n", this->a[i].x, this->a[i].y);
        }
        fflush(stderr);
        fprintf(stderr, "%d\n", this->m);
        for(int i=0; i<this->m; i++){
            fprintf(stderr, "%d %d\n", this->b[i].x, this->b[i].y);
        }
        fflush(stderr);*/
        //CORE
        for(int x=0; x<=S; x++){
            for(int y=0; y<=S; y++){
                hTable[x][y]=-1;
            }
        }
        for(int i=0; i<this->m; i++){
            hTable[this->b[i].x][this->b[i].y]=i;
        }
        this->x=0;
        vector<int> tmp;
        double bestScore=this->getExpect(junctionCost, failureProbability);
        int unupdated=0;
        for(int k=1; k<=this->n && k<=this->m; k++){
            this->x=k;
            for(int r=0; r<3; r++){
                for(int i=0; i<k; i++){
                    int j=rand()%(this->m-i);
                    swap(this->b[i], this->b[j]);
                    hTable[this->b[i].x][this->b[i].y]=i;
                    hTable[this->b[j].x][this->b[j].y]=j;
                }
                double newScore=this->getExpect(junctionCost, failureProbability);
                int upperBound=8;
                for(int d=floor(S*0.25); d; d=floor(d*0.5)){
                    //for(int t=0; t<upperBound; t++){
                    for(int t=0; ; t++){
                        int updated=0;
                        for(int i=0; i<k; i++){
                            int j=rand()%(k-i);
                            swap(this->b[i], this->b[j]);
                            hTable[this->b[i].x][this->b[i].y]=i;
                            hTable[this->b[j].x][this->b[j].y]=j;
                        }
                        for(int i=0; i<k; i++){
                            for(int p=0; p<4; p++){
                                const int _x=this->b[i].x+dx[p]*d;
                                const int _y=this->b[i].y+dy[p]*d;
                                if(_x<0 || _x>S)continue;
                                if(_y<0 || _y>S)continue;
                                const int j=hTable[_x][_y];
                                if(j<k)continue;
                                swap(this->b[i], this->b[j]);
                                hTable[this->b[i].x][this->b[i].y]=i;
                                hTable[this->b[j].x][this->b[j].y]=j;
                                double lastScore=this->getExpect(junctionCost, failureProbability);
                                if(lastScore<newScore){
                                    newScore=lastScore;
                                    updated=1;
                                }else{
                                    swap(this->b[i], this->b[j]);
                                    hTable[this->b[i].x][this->b[i].y]=i;
                                    hTable[this->b[j].x][this->b[j].y]=j;
                                }
                            }
                        }
                        if(!updated)break;
                    }
                    upperBound*=2;
                }
                if(bestScore>newScore){
                    bestScore=newScore;
                    unupdated=-1;
                    tmp.clear();
                    for(int i=0; i<k; i++){
                        tmp.push_back(this->b[i].x);
                        tmp.push_back(this->b[i].y);
                    }
                }
            }
            unupdated++;
            if(unupdated==3)break;
        }
        this->x=tmp.size()>>1;
        for(int i=0; i<this->x; i++){
            const int _x=tmp[i<<1];
            const int _y=tmp[(i<<1)|1];
            const int j=hTable[_x][_y];
            if(i!=j){
                swap(this->b[i], this->b[j]);
                hTable[this->b[i].x][this->b[i].y]=i;
                hTable[this->b[j].x][this->b[j].y]=j;
            }
            this->b[i].idx=this->n+i;
        }
        //fprintf(stderr, "expectScore=%.2f\n", bestScore);
        return tmp;
    }
    vector<int> buildRoads(vector <int> junctionStatus, double *cost=NULL){
        const int nn=this->n+this->x;
        vector<int> d2(nn, 2147483647);
        vector<int> p2(nn, -1);
        vector<int> roads;
        for(int i=this->n; i<nn; i++){
            if(junctionStatus[i-this->n]==0){
                d2[i]=0;
            }
        }
        //+0
        int node=0;
        while(true){
            d2[node]=0;
            int next=0;
            for(int i=0; i<nn; i++){
                if(d2[i]==0)continue;
                int wht=this->dist2(getPti(node), getPti(i));
                if(wht<d2[i]){
                    d2[i]=wht;
                    p2[i]=node;
                }
                if(d2[i]!=0 && (d2[next]==0 || d2[next]>d2[i])){
                    next=i;
                }
            }
            if(d2[next]==0)break;
            if(cost!=NULL){
                *cost+=sqrt(d2[next]*1.0);
            }else{
                roads.push_back(this->getPti(p2[next])->idx);
                roads.push_back(this->getPti(next)->idx);
            }
            node=next;
        }
        return roads;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < SIZE(v); ++i)
        cin >> v[i];
}

int main() {
    RoadsAndJunctions rj;
    int S, C;
    cin >> S >> C;
    vector<int> cities(C);
    getVector(cities);
    double junctionCost, failureProbability;
    cin >> junctionCost >> failureProbability;

    vector<int> ret = rj.buildJunctions(S, cities, junctionCost, failureProbability);
    const int nj=ret.size()>>1;
    vector<int> junctionStatus(nj, 0);
    //generate junctionStatus
    for(int &suc : junctionStatus){
        double tmp = rand()*1.0/(RAND_MAX*1.0 + 1.0);
        if(tmp+1e-7>failureProbability){
            suc = 1;
        }else{
            suc = 0;
        }
    }
    vector<int> res = rj.buildRoads(junctionStatus);
    const int nc=cities.size()>>1;
    fprintf(stdout, "%d\n", nc);
    for(int i=0; i<nc; i++){
        fprintf(stdout, "%d %d\n", cities[i<<1], cities[(i<<1)|1]);
    }
    fprintf(stdout, "%d\n", nj);
    for(int i=0; i<nj; i++){
        fprintf(stdout, "%d %d\n", ret[i<<1], ret[(i<<1)|1]);
    }
    const int nr=res.size()>>1;
    fprintf(stdout, "%d\n", nr);
    for(int i=0; i<nr; i++){
        fprintf(stdout, "%d %d\n", res[i<<1], res[(i<<1)|1]);
    }
    fflush(stdout);
    /*cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
    
    int J;
    cin >> J;
    vector<int> junctionStatus(J);
    getVector(junctionStatus);

    ret = rj.buildRoads(junctionStatus);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();*/
}
