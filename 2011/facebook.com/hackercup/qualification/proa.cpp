#include <iostream>
#include <unordered_set>

class Solver{
    private:
    std::unordered_set<int> squares;
    public:
    Solver() {
        for (long long i = 0LL; i * i <= 2147483647LL; ++i) {
            this->squares.insert((int)(i * i));
        }
    }
    int count(const int x) const{
        int foo = 0;
        for (const int a : this->squares) {
            if (x < a) continue;
            const int b = x - a;
            if (this->squares.count(b)) {
                foo += (a != b) ? 1: 2;
            }
        }
        return foo / 2;
    }
};

int main() {
    int case_num;
    std::cin >> case_num;
    Solver solver = Solver();
    for (int case_id = 1; case_id <= case_num; ++case_id) {
        int x;
        std::cin >> x;
        std::cout << "Case #" << case_id << ": " << solver.count(x) << std::endl;
    }
    return 0;
}
