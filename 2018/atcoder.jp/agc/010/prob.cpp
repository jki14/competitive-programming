#include "bits/stdc++.h"
using namespace std;

bool possible(const vector<int> &a){
    if(a.size()<=1u)return true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(size_t i=0; i<a.size(); i++){
        pq.push(make_pair(a[(i+1)%a.size()]-a[i], i));
    }
    int dec=0;
    long long zero=0LL;
    while(true){
        pair<int, int> cur=pq.top();
        pq.pop();
        //fprintf(stderr, "pos = %d, delta = %d\n", cur.second, cur.first-dec);
        if(cur.first-dec>0)return false;
        if(cur.first-dec==0){
            while(!pq.empty()){
                if(pq.top().first-dec!=0){
                    return false;
                }
                pq.pop();
            }
            break;
        }
        int multi=(-cur.first+dec+((int)a.size())-1)/((int)a.size());
        cur.first+=((int)a.size())*multi;
        pq.push(cur);
        zero+=(a.size()*1LL-cur.second)*multi;
        dec+=multi;
        if(zero>a[0]*1LL)return false;
    }
    if(zero!=a[0]*1LL){
        return false;
    }
    return true;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> a(n, 0);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        if(possible(a)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
