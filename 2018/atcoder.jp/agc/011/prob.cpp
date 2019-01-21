#include "bits/stdc++.h"
using namespace std;

int cnt(const vector<int> &A){
    int foo=A.size();
    vector<int> a=A;
    sort(a.begin(), a.end());
    long long presum=a[0]*1LL;
    for(size_t i=1; i<a.size(); i++){
        if(presum*2LL<a[i]*1LL){
            foo=a.size()-i;
        }
        presum+=a[i]*1LL;
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
        printf("%d\n", cnt(a));
    }
    return 0;
}
