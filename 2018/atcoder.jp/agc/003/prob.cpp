#include "bits/stdc++.h"
using namespace std;

long long numOfPairs(const vector<int> &cards){
    long long num=0LL;
    int remain=0;
    for(int cnt : cards){
        num+=min(remain, cnt)*1LL;
        cnt-=min(remain, cnt);
        num+=cnt/2;
        remain=cnt%2;
    }
    return num;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> cards;
        for(int i=0; i<n; i++){
            int cnt;
            scanf("%d", &cnt);
            cards.push_back(cnt);
        }
        printf("%lld\n", numOfPairs(cards));
    }
    return 0;
}
