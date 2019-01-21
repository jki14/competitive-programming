#include "bits/stdc++.h"
using namespace std;

int progress(vector<int> &lens){
    sort(lens.begin(), lens.end());
    int foo=0;
    for(int i=0; i<(int)lens.size(); i+=2){
        foo+=lens[i];
    }
    return foo;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> a;
        for(int i=0; i<n; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            a.push_back(x);
            a.push_back(y);
        }
        printf("%d\n", progress(a));
    }
    return 0;
}
