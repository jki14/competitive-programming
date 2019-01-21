#include <iostream>
#include <vector>
using namespace std;

//int called;

int calculate(const int used_nodes, const int num_edges, const int sum_length, const int maxlength, const int maxl, const vector<vector<int>> &edge_matrix) {
    //called ++;
    int foo = 0;
    const int n = edge_matrix.size();
    const int max_length = edge_matrix[maxlength / n][maxlength % n];
    if (num_edges == 3 && sum_length > max_length) {
        foo += 1;
    }
    int trick_pos = n;
    while(trick_pos > 0 && !(used_nodes & (1 << (trick_pos - 1))))
        trick_pos--;
    for (int i = 0; i < n; ++i) {
        if (used_nodes & (1 << i)) continue;
        for (int j = max(i+1, trick_pos); j < n; ++j) {
            if(used_nodes & (1 << j)) continue;
            if(edge_matrix[i][j] == 0) continue;
            const int tmp = used_nodes | (1 << i) | (1 << j);
            if (edge_matrix[i][j] < max_length) {
                foo += calculate(tmp, min(num_edges + 1, 3), min(sum_length + edge_matrix[i][j], maxl + 1), maxlength, maxl, edge_matrix);
            } else {
                foo += calculate(tmp, min(num_edges + 1, 3), min(sum_length + max_length, maxl + 1), i * n + j, maxl, edge_matrix);
            }
        }
    }
    return foo;
}

int FairiesAndWitches(const vector<vector<int>> &edge_matrix) {
    //TODO: check if edge_matrix is valid
    //n represents #nodes
    //const int n = edge_matrix.size();
    //maxl represents the max length of edges
    int maxl = 0;
    for (const vector<int> &row : edge_matrix) {
        for(const int length : row) {
            maxl = max(length, maxl);
        }
    }
    /*vector<vector<vector<vector<int>>>> cache(1 << n,
        vector<vector<vector<int>>>(4,
            vector<vector<int>>(maxl + 2,
                vector<int>(n * n, -1)
            )
        )
    );*/
    //called = 0;
    return calculate(0, 0, 0, 0, maxl, edge_matrix);
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i){
        int n;
        cin >> n;
        vector<vector<int>> em(n, vector<int>(n, 0));
        for (vector<int> &row : em) {
            for (int &el : row) {
                cin >> el;
            }
        }
        cout << "Case #" << i + 1 << ": " << FairiesAndWitches(em) << endl;
        //cerr << "  called " << called << endl;
    }
    return 0;
}
