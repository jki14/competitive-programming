#include <cstdio>
#include <vector>
using namespace std;

const double eps = 1e-11;

struct Result_t{
    int entry;
    double score;
};

struct Position_t{
    int x, y;
};

Result_t solution(const int r, const int c, const int k, const vector<Position_t> &missed){
    vector<vector<bool>> missTable(r, vector<bool>(c, false));
    for (const Position_t &el : missed) {
        missTable[el.x][el.y] = true;
    }
    vector<vector<double>> f(r, vector<double>(c - 1, 0.0));
    f[r - 1][k] = 1.0;
    for (int i = r - 1; i > 0; --i) {
        for (int j = 0; j < c - 1; ++j) {
            if (f[i][j] < eps) continue;
            if ((i & 1) == 1) {
                if (j == 0) {
                    if (!missTable[i][j])
                        f[i - 1][j] += f[i][j];
                } else if (j == c - 3) {
                    if (!missTable[i][j + 1])
                        f[i - 1][j + 1] += f[i][j];
                }
                if (j > 0 && !missTable[i][j]) {
                    f[i - 1][j] += f[i][j] * 0.5;
                }
                if (j < c - 3 && !missTable[i][j + 1]) {
                    f[i - 1][j + 1] += f[i][j] * 0.5;
                }
                if (missTable[i - 1][j + 1]) {
                    f[i - 2][j] += f[i][j];
                }
            } else {
                if (j > 0 && !missTable[i][j]) {
                    f[i - 1][j - 1] += f[i][j] * 0.5;
                }
                if (j < c - 2 && !missTable[i][j + 1]) {
                    f[i - 1][j] += f[i][j] * 0.5;
                }
                if (missTable[i - 1][j]) {
                    f[i - 2][j] += f[i][j];
                }
            }
        }
    }
    Result_t foo;
    foo.entry = 0;
    foo.score = f[0][0];
    for (int i = 1; i < c - 1; ++i) {
        if (f[0][i] > foo.score) {
            foo.entry = i;
            foo.score = f[0][i];
        }
    }
    return foo;
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    for (int case_id = 1; case_id <= case_num; ++case_id) {
        int r, c, k, n;
        scanf("%d%d%d%d", &r, &c, &k, &n);
        vector<Position_t> missed(n, Position_t());
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &missed[i].x, &missed[i].y);
        }
        Result_t foo = solution(r, c, k ,missed);
        printf("Case #%d: %d %.6f\n", case_id, foo.entry, foo.score);
    }
    return 0;
}
