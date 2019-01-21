#include "bits/stdc++.h"
using namespace std;

int main() {
    char a[8];
    while(scanf("%s", a)!=EOF) {
        int foo=0;
        for(int i=0; a[i]; i++) {
            foo+=(a[i]=='1');
        }
        printf("%d\n", foo);
    }
}
