#include "bits/stdc++.h"
using namespace std;

long long calculate(const vector<int> &seq){
    vector<int> pos(seq.size(), 0);
    for(int i=0; i<(int)seq.size(); i++){
        pos[seq[i]-1]=i;
    }
    long long foo=0LL;
    set<int> border;
    border.insert(-1);
    border.insert(seq.size());
    for(int e=0; e<(int)seq.size(); e++){
        set<int>::iterator it=border.upper_bound(pos[e]);
        int rigLen=*it-pos[e];
        it--;
        int lefLen=pos[e]-*it;
        foo+=(e+1)*1LL*lefLen*rigLen;
        border.insert(pos[e]);
    }
    return foo;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> a(n, 0);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        printf("%lld\n", calculate(a));
    }
    return 0;
}
