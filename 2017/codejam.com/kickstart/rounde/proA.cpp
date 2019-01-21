#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int CopyAndPaste(string s) {
    const int kInf = 0x3f3f3f3f;
    const int len = s.length();
    //g = the longest common prefix length
    vector<vector<int>> g(len, vector<int>(len, 0));
    for (int i = len - 1; i >= 0; --i) {
        for (int j = len - 1; j >= i; --j){
            if (s[i] == s[j]) {
                if (i < len - 1 && j < len - 1) {
                    g[i][j] = g[j][i] = g[i+1][j+1] + 1;
                } else {
                    g[i][j] = g[j][i] = 1;
                }
            }
        }
    }
    vector<int> f(len + 1, kInf);
    f[0] = 0;
    vector<deque<int>> vq(len + 1,  deque<int>());
    vq[0].push_back(0);
    vector<vector<vector<bool>>> fast(len + 1, vector<vector<bool>>(len + 1, vector<bool>(len + 1, false)));
    fast[0][0][0] = true;
    for (int k = 0; k < len; ++k) {
        for (const int p : vq[k]){
            if (p == len) continue;
            //traversal fast
            for (int i = 0; i <= p; ++i) {
                for (int j = 0; i + j <= p; ++j) {
                    if (!fast[p][i][j]) continue;
                    //APPEND
                    if (f[p + 1] == kInf) {
                        f[p + 1] = k + 1;
                        vq[k + 1].push_back(p + 1);
                        //fprintf(stderr, "f[%d] = %d\n", p + 1, f[p + 1]);
                    }
                    if (f[p + 1] == k + 1) {
                        fast[p + 1][i][j] = true;
                        //fprintf(stderr, "k[%d][%d][%d] = true\n", p + 1, i , j);
                    }
                    //PASTE
                    if (j > 0 && j <= g[p][i]) {
                        if (f[p + j] == kInf) {
                            f[p + j] = k + 1;
                            vq[k + 1].push_back(p + j);
                            //fprintf(stderr, "f[%d] = %d\n", p + j, f[p + j]);
                        }
                        if (f[p + j] == k + 1) {
                            fast[p + j][i][j] = true;
                            //fprintf(stderr, "k[%d][%d][%d] = true\n", p + j, i , j);
                        }
                    }
                }
            }
        }
        if (k == 0) continue;
        for (const int p : vq[k - 1]) {
            if (p == len) continue;
            //traversal non-fast
            for (int i = 0; i <= p; ++i) {
                for (int j = 0; i + j <= p; ++j) {
                    if (fast[p][i][j]) continue;
                    //APPEND
                    if (f[p + 1] == kInf) {
                        f[p + 1] = k + 1;
                        vq[k + 1].push_back(p + 1);
                        //fprintf(stderr, "f[%d] = %d\n", p + 1, f[p + 1]);
                    }
                    if (f[p + 1] == k + 1) {
                        fast[p + 1][i][j] = true;
                        //fprintf(stderr, "k[%d][%d][%d] = true\n", p + 1, i , j);
                    }
                    //PASTE
                    if (j > 0 && j <= g[p][i]) {
                        if (f[p + j] == kInf) {
                            f[p + j] = k + 1;
                            vq[k + 1].push_back(p + j);
                            //fprintf(stderr, "f[%d] = %d\n", p + j, f[p + j]);
                        }
                        if (f[p + j] == k + 1) {
                            fast[p + j][i][j] = true;
                            //fprintf(stderr, "k[%d][%d][%d] = true\n", p + j, i , j);
                        }
                    }
                }
            }
        }
    }
    return f[len];
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        string s;
        cin >> s;
        cout << "Case #" << i + 1 << ": " << CopyAndPaste(s) <<endl;
    }
    return 0;
}
