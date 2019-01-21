#include <iostream>
#include <fstream>
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
#include <stack>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

//COMPARE
template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

#define N 1100

const double inf=1e9;
const double eps=1e-9;

int n;
double xx[N], yy[N];
double x, y, xl, xr, yl, yr;

inline double gvalue(const double x, const double y){
    double foo=0.;
    for(int i=0; i<n; i++){
        foo+=sqrt((xx[i]-x)*(xx[i]-x)+(yy[i]-y)*(yy[i]-y));
    }
    return foo;
}

double process(const double x){
    double l=yl, r=yr;
    while(l-r<-eps){
        double pre=(l*2.+r)/3.;
        double nxt=(l+r*2.)/3.;
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
    double l=xl, r=xr;
    while(l-r<-eps){
        double pre=(l*2.+r)/3.;
        double nxt=(l+r*2.)/3.;
        if(process(pre)<process(nxt)){
            r=nxt;
        }else{
            l=pre;
        }
    }
    x=l;
    process(x);
}

int main(){
    int T;scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        xl=yl=inf;
        xr=yr=-inf;
        for(int i=0; i<n; i++){
            scanf("%lf%lf", &xx[i], &yy[i]);
            UPDMIN(xl, xx[i]);UPDMAX(xr, xx[i]);
            UPDMIN(yl, yy[i]);UPDMAX(yr, yy[i]);
        }
        calc();
        printf("%.20f %.20f\n", x, y);
    }
    return 0;
}
