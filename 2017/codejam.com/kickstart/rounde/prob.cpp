#include "bits/stdc++.h"
using namespace std;

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

//TAIL_OF_JKI'S_HEADER

int n, m;
int a[5100];
int len[5100], num[5100];
lld stk[5100];

lld ans;

inline int find(const int req){
    int lef=0, rig=m-1;
    while(lef<=rig){
        int mid=(lef+rig)>>1;
        if(len[mid]>req){
            if(mid==lef || len[mid-1]<=req)return mid;
            rig=mid-1;
        }else lef=mid+1;
    }
    return -1;
}

map<int, int> s;
map<int, int>::iterator it;

int main(){
    int T;scanf("%d", &T);
    for(int _T=1; _T<=T; _T++){
        printf("Case #%d: ", _T);
        scanf("%d", &n);
        s.clear();
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            it=s.find(a[i]);
            if(it!=s.end()){
                it->second++;
            }else s.insert(MP(a[i], 1));
        }
        m=0;
        for(it=s.begin(); it!=s.end(); it++){
            len[m]=it->first;
            num[m]=it->second;
            m++;
        }
        stk[m]=0LL;
        for(int i=m-1; ~i; i--){
            stk[i]=stk[i+1]+((num[i]*1LL*(num[i]-1))>>1);
        }
        ans=0LL;
        for(int top=0; top<m; top++){
            for(int lav=top+1; lav<m; lav++){
                lld cur=num[top]*1LL*num[lav];
                lld pad=0LL;
                int req=(len[lav]-len[top])>>1;
                int low=find(req);
                if(!~low)continue;
                lld sid=stk[low];
                if(top>=low){
                    sid-=(num[top]*1LL*(num[top]-1))>>1;
                    pad+=num[lav]*1LL*(num[top]*1LL*(num[top]-1)*(num[top]-2)/2LL/3LL);
                }
                if(lav>=low){
                    sid-=(num[lav]*1LL*(num[lav]-1))>>1;
                    pad+=num[top]*1LL*(num[lav]*1LL*(num[lav]-1)*(num[lav]-2)/2LL/3LL);
                }
                ans+=cur*sid+pad;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
