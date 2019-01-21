#include "bits/stdc++.h"
using namespace std;

const int inf=0x3f3f3f3f;

int r, c;

inline int calc(const int p){
    return p*(p-1)*(p-2)/6;
}

inline int pots(const int x, const int y, const int dx, const int dy){
    int h=(r-x-1)/dx;
    int w=(c-y-1)/dy;
    //if(min(h+1, w+1)>=3)
    //    fprintf(stderr, "pots %d %d %d %d = %d\n", x, y, dx, dy, min(h+1, w+1));
    return min(h+1, w+1);
}

inline int gcd(const int x, const int y){
    if(x<0)return gcd(-x, y);
    if(y<0)return gcd(x, -y);
    return (!y)?x:gcd(y, x%y);
}

int main(){
    int T;scanf("%d", &T);
    while(T--){
        scanf("%d%d", &r, &c);
        int ans=calc(r*c);
        ans-=calc(r)*c;
        ans-=calc(c)*r;
        for(int x=0; x<r; x++){
            for(int y=0; y<c; y++){
                for(int dx=1; x+dx<r; dx++){
                    for(int dy=1; y+dy<c; dy++){
                        if(x-dx>=0 && y-dy>=0)continue;
                        if(gcd(dx, dy)!=1)continue;
                        ans-=calc(pots(x, y, dx, dy))*2;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
