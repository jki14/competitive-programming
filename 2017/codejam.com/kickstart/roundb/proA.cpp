#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int kMod = 1000000007;

int MathEncoder(const vector<int> &arr) {
    //TODO: check if arr is valid
    int foo = 0;
    int tailing = 0;
    int pow2m = 1;
    int length = arr.size();
    for (int i = 1; i < length;  ++i) {
        pow2m = pow2m * 2 % kMod;
        const int gap = arr[i] - arr[i-1];
        tailing = tailing * 2 % kMod;
        tailing = (tailing + (pow2m - 1LL) * gap % kMod) % kMod;
        foo = (foo + tailing) % kMod;
    }
    return (foo % kMod + kMod) % kMod;
}

int main(){
    int c;
    cin >> c;
    for (int i=0; i<c; i++) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        cout<<"Case #"<<i+1<<": "<<MathEncoder(a)<<endl;
    }
    return 0;
}
