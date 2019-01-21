#include "bits/stdc++.h"
using namespace std;

//COMPARE
template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

#define N 11000

const int def=0xc0c0c0c0;

const long double inf=1e9;
const long double ema=1e-9;

int n;
long double xx[N], yy[N];
long double x, y, xl, xr, yl, yr;

inline long double gvalue(const long double x, const long double y){
    long double foo=0.;
    for(int i=0; i<n; i++){
        foo+=sqrt((xx[i]-x)*(xx[i]-x)+(yy[i]-y)*(yy[i]-y));
    }
    return foo;
}

long double process(const long double x){
    long double l=yl, r=yr;
    for(int k=0; k<64 && l-r<-ema; k++){
        long double pre=(l*2.+r)/3.;
        long double nxt=(l+r*2.)/3.;
        if(gvalue(x, pre)<gvalue(x, nxt)){
            r=nxt;
        }else{
            l=pre;
        }
    }
    y=l;
    return gvalue(x, y);
}

void calc(){
    long double l=xl, r=xr;
    for(int k=0; k<64 && l-r<-ema; k++){
        long double pre=(l*2.+r)/3.;
        long double nxt=(l+r*2.)/3.;
        if(process(pre)<process(nxt)){
            r=nxt;
        }else{
            l=pre;
        }
    }
    x=l;
    process(x);
}

int px[11000], py[11000];
int lx, hx, ly, hy;
int idx[11000];

inline int gcd(const int x, const int y){
    if(!y)return x;
    return gcd(y, x%y);
}

int dcoline(){
    if(lx==hx || ly==hy)return 0;
    int sx=0xc0c0c0c0, sy=-1;
    for(int i=1; i<n; i++){
        int p=idx[i], q=idx[0];
        if(px[p]==px[q] && py[p]==py[q])continue;
        int dx=px[p]-px[q];
        int dy=py[p]-py[q];
        int d=gcd(dx, dy);
        dx/=d;
        dy/=d;
        if(sx==def){
            sx=dx;
            sy=dy;
        }
        if(sx!=dx || sy!=dy){
            return 1;
        }
    }
    return 0;
}

inline int cmp(const int lhs, const int rhs){
    if(px[lhs]!=px[rhs])return px[lhs]<px[rhs];
    return py[lhs]<py[rhs];
}

int main(){
    while(scanf("%d", &n)!=EOF){
        xl=yl=inf;
        xr=yr=-inf;
        lx=ly=0x3f3f3f3f;
        hx=hy=0xc0c0c0c0;
        for(int i=0; i<n; i++){
            scanf("%d%d", &px[i], &py[i]);
            UPDMIN(lx, px[i]);UPDMAX(hx, px[i]);
            UPDMIN(ly, py[i]);UPDMAX(hy, py[i]);
            xx[i]=px[i]*1.0L;yy[i]=py[i]*1.0L;
            UPDMIN(xl, xx[i]);UPDMAX(xr, xx[i]);
            UPDMIN(yl, yy[i]);UPDMAX(yr, yy[i]);
        }
        for(int i=0; i<n; i++)idx[i]=i;
        sort(idx, idx+n, cmp);
        if(!dcoline()){
            printf("%.9Lf %.9Lf\n", px[idx[((n+1)>>1)-1]]*1.L, py[idx[((n+1)>>1)-1]]*1.L);
        }else{
            calc();
            printf("%.9Lf %.9Lf\n", x, y);
        }
    }
    return 0;
}
