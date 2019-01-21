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
#include <stack>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <typeinfo>
using namespace std;

//HEAD_OF_JKI'S_HEADER_

    //COMPARE
    template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
    template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

    template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
    template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

    //STL
    template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
    template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
    template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

//TAIL_OF_JKI'S_HEADER

class HardProof {
    private:
    int n;
    int *que, *vst, til, msk;
    int around(const int low, const int hig, const vector<int> &dis){
        msk++;til=0;
        que[til++]=0;
        vst[0]=msk;
        for(int i=0; i<til; i++){
            int u=que[i];
            for(int v=0; v<n; v++){
                if(vst[v]==msk)continue;
                if(dis[u*n+v]>=low && dis[u*n+v]<=hig){
                    vst[v]=msk;
                    que[til++]=v;
                }
            }
        }
        if(til!=n)return 0;
        msk++;til=0;
        que[til++]=0;
        vst[0]=msk;
        for(int i=0; i<til; i++){
            int u=que[i];
            for(int v=0; v<n; v++){
                if(vst[v]==msk)continue;
                if(dis[v*n+u]>=low && dis[v*n+u]<=hig){
                    vst[v]=msk;
                    que[til++]=v;
                }
            }
        }
        if(til!=n)return 0;
        return 1;
    }
    int check(const int len, const vector<int> &dis){
        for(vector<int>::const_iterator it=dis.begin(); it!=dis.end(); it++){
            if(around(*it, *it+len, dis))
                return 1;
        }
        return 0;
    }
    int core_entry(const vector<int> &dis){
        n=0;while(n*n<SIZE(dis))n++;
        int lef=0, rig=0;
        for(vector<int>::const_iterator it=dis.begin(); it!=dis.end(); it++){
            UPDMAX(rig, *it);
        }
        while(lef<=rig){
            int mid=(lef+rig)>>1;
            if(check(mid, dis)){
                if(mid==lef || !check(mid-1, dis))return mid;
                rig=mid-1;
            }else lef=mid+1;
        }
        return -1;
    }
    public:
    HardProof(){
        que=(int*)malloc(sizeof(int)*64);
        vst=(int*)malloc(sizeof(int)*64);
        memset(vst, 0, sizeof(int)*64);msk=0;
    }
    ~HardProof(){
        free(que);
        free(vst);
    }
    int minimumCost(vector<int> D) {
        return core_entry(D);
    }
};
