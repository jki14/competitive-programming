#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Monster {
    int x, y;
    Monster(const int _x, const int _y) : x(_x), y(_y) {
        //pass
    }
};

class FenwickTree {
    private:
    long long *pool;
    size_t size;
    inline size_t lowbit(const size_t x) const{
        return x & (-x);
    }
    public:
    FenwickTree(const size_t size) {
        this->pool = new long long [size];
        this->size = size;
        this->clear();
    }
    ~FenwickTree() {
        delete this->pool;
    }
    void clear() {
        for (size_t i = 0; i < this->size; ++i) {
            this->pool[i] = 0;
        }
    }
    void update(const size_t p, const long long d) {
        //fprintf(stderr, "at %llu, +%lld\n", p, d);
        for (size_t i = p; i <= this->size; i += this->lowbit(i)) {
            this->pool[i - 1] += d;
        }
    }
    long long presum(const size_t p) const {
        long long foo = 0;
        for (size_t i = p; i > 0; i -= lowbit(i)) {
            foo += this->pool[i - 1];
        }
        return foo;
    }
};

long long SafeSquares(const vector<Monster> &monsters, const int r, const int c) {
    //TODO: check if monsters, r, and c are valid
    vector<vector<int>> occupied(r, vector<int>());
    for (const auto &monster : monsters) {
        occupied[monster.x].push_back(monster.y);
    }
    FenwickTree ftNum(c);
    FenwickTree ftSum(c);
    long long foo = 0LL;
    for (int k = 0; k < r; ++k) {
        set<int> bst;
        bst.insert(-1);
        bst.insert(c);
        ftNum.clear();
        ftNum.update(c, 1);
        ftSum.clear();
        ftSum.update(c, c);
        for (int i = k; i < r && i - k + 1 <= c; ++i) {
            for (const int y : occupied[i]) {
                auto insRet = bst.insert(y);
                if (!insRet.second) {
                    //fprintf(stderr, "continue\n");
                    continue;
                }
                auto it = insRet.first;
                auto tmp = it;
                tmp--;
                int l = *(tmp);
                tmp++;
                tmp++;
                int r = *(tmp);
                //fprintf(stderr, "%d , %d , %d\n", l, y, r);
                ftNum.update(r - l - 1, -1);
                ftSum.update(r - l - 1, l - r + 1);
                if (y - l > 1) {
                    ftNum.update(y - l - 1, 1);
                    ftSum.update(y - l - 1, y - l - 1);
                }
                if (r - y > 1) {
                    ftNum.update(r - y - 1, 1);
                    ftSum.update(r - y - 1, r - y - 1);
                }
            }
            int w = i - k + 1;
            foo += (ftSum.presum(c) - ftSum.presum(w - 1)) - (ftNum.presum(c) - ftNum.presum(w - 1)) * (w - 1);
        }
    }
    return foo;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int r, c, k;
        cin >> r >> c >> k;
        vector<Monster> monsters(k, Monster(0, 0));
        for (int j = 0; j < k; ++j) {
            cin >> monsters[j].x >> monsters[j].y;
        }
        cout << "Case #" << i + 1 << ": " << SafeSquares(monsters, r, c) << endl;
    }
    return 0;
}
