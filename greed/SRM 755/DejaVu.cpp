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
  class bipartite_matching_c{
    private:
    size_t capl, capr, cape;
    size_t cnte;
    struct bm_edge_t;
    struct bm_left_node_t{
      bm_edge_t *head;
      int flag;
    } *leftnodes;
    struct bm_right_node_t{
      bm_left_node_t *partner;
    } *rightnodes;
    struct bm_edge_t{
      bm_right_node_t *right;
      bm_edge_t *next;
    } *edgepool, *edgetail;
    int augmented(bm_left_node_t *node, const int flag){
      node->flag=flag;
      for(bm_edge_t *edge=node->head; edge!=NULL; edge=edge->next){
        if(edge->right->partner==NULL || (edge->right->partner->flag<flag && augmented(edge->right->partner, flag))){
          edge->right->partner=node;
          return 1;
        }
      }
      return 0;
    }
    public:
    bipartite_matching_c(const size_t numl, const size_t numr, const size_t nume){
      this->capl=numl;
      this->leftnodes=(bm_left_node_t*)malloc(sizeof(bm_left_node_t)*this->capl);
      this->capr=numr;
      this->rightnodes=(bm_right_node_t*)malloc(sizeof(bm_right_node_t)*this->capr);
      this->cape=nume;
      this->edgepool=(bm_edge_t*)malloc(sizeof(bm_edge_t)*this->cape);
      this->reset();
    }
    ~bipartite_matching_c(){
      free(this->leftnodes);
      free(this->rightnodes);
      free(this->edgepool);
    }
    void reset(){
      for(size_t i=0; i<this->capl; i++){
        this->leftnodes[i].head=NULL;
      }
      this->edgetail=this->edgepool;
      this->cnte=0;
    }
    void add_edge(const size_t u, const size_t v){
      assert(u<this->capl || v<this->capr);
      assert(this->cnte<this->cape);
      this->edgetail->next=this->leftnodes[u].head;
      this->edgetail->right=&this->rightnodes[v];
      this->leftnodes[u].head=this->edgetail++;
      this->cnte++;
    }
    int maximum_matching(){
      for(size_t i=0; i<this->capl; i++){
        this->leftnodes[i].flag=-1;
      }
      for(size_t i=0; i<this->capr; i++){
        this->rightnodes[i].partner=NULL;
      }
      int foo=0;
      for(size_t u=0; u<this->capl; u++){
        if(this->leftnodes[u].head==NULL)continue;
        if(augmented(&this->leftnodes[u], u))foo++;
      }
      return foo;
    }
  };

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

int n, m;
lld b[210000];
int a[210000];
vector<vector<int>> c;

struct node_t {
  int lef, rig;
  int foo, bar;
  node_t* chd[2];
} pool[410000], *last, *root;

node_t* build(int const lef, int const rig) {
  node_t *node = last++;
  node->lef = lef;
  node->rig = rig;
  node->foo = 0;
  node->bar = 0;
  if (lef == rig) {
    node->chd[0] = nullptr;
    node->chd[1] = nullptr;
  } else {
    int const mid = (lef + rig) >> 1;
    node->chd[0] = build(lef, mid);
    node->chd[1] = build(mid + 1, rig);
  }
  return node;
}

inline int get(node_t const* node) {
  return node->foo + node->bar;
}

inline void upgrade(node_t* node) {
  node->bar = MAX(get(node->chd[0]), get(node->chd[1]));
}

void update(node_t* node, int const lef, int const rig, int const det) {
  if (lef <= node->lef && node->rig <= rig) {
    node->foo += det;
  } else {
    if (lef <= node->chd[0]->rig) {
      update(node->chd[0], lef, rig, det);
    }
    if (node->chd[1]->lef <= rig) {
      update(node->chd[1], lef, rig, det);
    }
    upgrade(node);
  }
}

class DejaVu {
  public:
  int mostDejaVus(int N, int seed, int R) {
    n = N;
    b[0] = seed;
    for (int i = 1 ; i < n; ++i) {
      b[i] = (b[i-1] * 1664525 + 1013904223) % 4294967296;
    }
    map<int, int> dict;
    for (int i = 0; i < n; ++i) {
      a[i] = b[i] % R;
      dict[a[i]] = 0;
    }
    m = 0;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
      it->second = m++;
    }
    for (auto& val : a) {
      val = dict[val];
    }
    c.resize(m);
    for (auto& r : c) {
      r.clear();
      r.push_back(-1);
    }
    last = pool;
    root = build(0, n - 1);
    int foo = 0;
    for (int i = 0; i < n; ++i) {
      int const k = a[i];
      int const p = c[k].size() - 1;
      if (p >= 2) {
        update(root, c[k][p - 2] + 1, c[k][p - 1], -1);
      }
      if (p >= 1) {
        update(root, c[k][p - 1] + 1, c[k][p], 1);
      }
      c[k].push_back(i);
      UPDMAX(foo, get(root));
    }
    return foo;
  }
};

// CUT begin
ifstream data("DejaVu.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, int seed, int R, int __expected) {
    time_t startClock = clock();
    DejaVu *instance = new DejaVu();
    int __result = instance->mostDejaVus(N, seed, R);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        int seed;
        from_stream(seed);
        int R;
        from_stream(R);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, seed, R, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1555343168;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "DejaVu (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end