#include "bits/stdc++.h"
using namespace std;

typedef long long lld;

const int inf=0x3f3f3f3f;

int miu[110000];

int miu_func(int s){
    int res=1;
    for(int i=2; i*i<=s; i++){        
        if(s%i==0){
            s/=i;
            if(s%i==0)return 0;
            res*=-1;
        }
    }
    if(s>1)res*=-1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    miu[0]=0;miu[1]=1;
    for(int i=2; i<=100000; i++)miu[i]=miu_func(i);
    int T;cin>>T;
    for(int _T=1; _T<=T; _T++){
        cout<<"Case "<<_T<<": ";
        int a, x, b, y, k;
        cin>>a>>x>>b>>y>>k;
        if(k==0)k=inf;
        if(x>y)swap(x, y);
        x/=k;
        y/=k;
        lld ans=0LL, foo=0LL;
        for(int i=1; i<=x; i++){
            ans+=miu[i]*1LL*(x/i)*(y/i);
        }
        for(int i=1; i<=x; i++){
            foo+=miu[i]*1LL*(x/i)*(x/i);
        }
        ans-=foo>>1;
        cout<<ans<<endl;
    }
    return 0;
}
