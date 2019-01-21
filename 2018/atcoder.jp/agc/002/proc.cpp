#include "bits/stdc++.h"
using namespace std;

vector<int> progress(vector<int> &lens, const int threshold){
    vector<int> foo;
    for(int i=0; i<(int)lens.size()-1; i++){
        if(lens[i]+lens[i+1]>=threshold){
            for(int j=0; j<i; j++){
                foo.push_back(j);
            }
            for(int j=lens.size()-2; j>=i; j--){
                foo.push_back(j);
            }
            break;
        }
    }
    return foo;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        vector<int> a;
        for(int i=0; i<n; i++){
            int len;
            scanf("%d", &len);
            a.push_back(len);
        }
        vector<int> foo=progress(a, m);
        if(foo.empty()){
            printf("Impossible\n");
        }else{
            printf("Possible\n");
            for(int x : foo){
                printf("%d\n", x+1);
            }
        }
    }
    return 0;
}
