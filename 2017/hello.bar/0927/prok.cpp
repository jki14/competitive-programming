#include "bits/stdc++.h"
using namespace std;

char a[8], b[8];
unordered_set<int> s;
int pos[110000];

int run_once(int x){
    for(int i=4; ~i; i--){
        a[i]=b[i]='0'+(x%10);
        x/=10;
    }
    sort(a, a+5, greater<char>());
    sort(b, b+5);
    int lhs, rhs;
    sscanf(a, "%d", &lhs);
    sscanf(b, "%d", &rhs);
    return lhs-rhs;
}

int main(){
    a[5]=b[5]=0;
    int T;scanf("%d", &T);
    while(T--){
        int x, p=0;
        scanf("%d", &x);
        s.clear();
        while(!s.count(x)){
            s.insert(x);
            pos[x]=p++;
            x=run_once(x);
        }
        int r=(999999-pos[x])%(p-pos[x]);
        for(const int z : s){
            if(pos[z]==pos[x]+r){
                printf("%05d\n", z);
            }
        }
    }
    return 0;
}
