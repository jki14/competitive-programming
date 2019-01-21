#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> f;

inline int func(const int x){
    if(!f.count(x)){
        if(x<=0){
            f[x]=0;
        }else{
            unordered_set<int> mex;
            for(int i=2; i*i<=x; i++){
                if(x%i)continue;
                int b[2]={ i, x/i };
                for(int k=0; k<2; k++){
                    if(b[k]&1){
                        mex.insert(func(b[k^1]));
                    }else{
                        mex.insert(0);
                    }
                }
            }
            mex.insert(0);
            int cur=0;
            while(mex.count(cur))cur++;
            f[x]=cur;
        }
    }
    return f[x];
}

int main(){
    f.clear();
    int n;
    while(scanf("%d", &n)!=EOF){
        int foo=0;
        for(int i=0; i<n; i++){
            int x;
            scanf("%d", &x);
            foo^=func(x);
        }
        if(foo){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
    }
    return 0;
}
