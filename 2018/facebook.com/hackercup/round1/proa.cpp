#include <iostream>
#include <string>
#include <vector>

const int kModNum = 1000000007;

int recursive(const std::vector<std::string> &a, std::vector<std::vector<std::vector<int>>> &f, const int i, const int j, const int k) {
    if (~f[i][j][k]) return f[i][j][k];
    int &foo = f[i][j][k];
    foo = 0;
    if (a[j][i] != '#') {
        if (k == 1) {
            if (j != 0) {
                foo = (foo + recursive(a, f, i, j - 1, 0)) % kModNum;
            }
            if (j != 2) {
                foo = (foo + recursive(a, f, i, j + 1, 2)) % kModNum;
            }
        } else {
            if (i != 0) {
                foo = recursive(a, f, i - 1, j, 1);
            }
        }
    }
    //std::cerr << "f[" << i << "][" << j << "][" << k << "] = " << foo << std::endl;
    return foo;
}

int solution(const std::vector<std::string> &a) {
    //TODO: check if a is valid
    const int n = a[0].size();
    std::vector<std::vector<std::vector<int>>> f(n, std::vector<std::vector<int>>(3, std::vector<int>(3, -1)));
    if (a[0][0] != '#') {
        f[0][0][0] = 1;
    } else {
        f[0][0][0] = 0;
    }
    return recursive(a, f, n - 1, 2, 1);
}

int main() {
    int case_num;
    std::cin >> case_num;
    for (int case_id = 1; case_id <= case_num; ++case_id) {
        int n;
        std::cin >> n;
        std::vector<std::string> a(3, std::string());
        for (int i = 0; i < 3; ++i) {
            std::cin >> a[i];
        }
        std::cout << "Case #" << case_id << ": " << solution(a) << std::endl;
    }
    return 0;
}
