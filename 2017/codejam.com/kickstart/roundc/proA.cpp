#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetDecrypted(const int current, const vector<int> &sum, const int k) {
    if (k == (int)sum.size()) {
        return string(1, 'A' + current);
    }
    if (current <= sum[k]) {
        return (char)('A' + current) + GetDecrypted(sum[k] - current, sum, k + 1);
    } else {
        return (char)('A' + current) + GetDecrypted(sum[k] - current + 26, sum, k+1);
    }
}

string AmbiguousCipher(string encrypted) {
    //check input parameter is valid
    int len = encrypted.length();
    if (len & 1) return "AMBIGUOUS";
    vector<int> neighbor_sum(len / 2 - 1, 0);
    // -X-X...X ->
    for (int i = 0; i < len / 2 - 1; ++i) {
        neighbor_sum[i] = encrypted[i * 2 + 2] - 'A';
    }
    string partl = GetDecrypted(encrypted[0] - 'A', neighbor_sum, 0);
    // <- X-...X-X-
    for (int i = 0; i < len / 2 - 1; ++i) {
        neighbor_sum[i] = encrypted[len - 3 - i * 2] - 'A';
    }
    string partr = GetDecrypted(encrypted[len - 1] - 'A', neighbor_sum, 0);
    reverse(partr.begin(), partr.end());
    string foo(len, '?');
    for (int i = 0; i < len; ++i) {
        if (i & 1) {
            foo[i] = partl[i / 2];
        } else {
            foo[i] = partr[i / 2];
        }
    }
    return foo;
}

int main(){
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        string encrypted;
        cin >> encrypted;
        cout << "Case #"<< i + 1 << ": " << AmbiguousCipher(encrypted) << endl;
    }
    return 0;
}
