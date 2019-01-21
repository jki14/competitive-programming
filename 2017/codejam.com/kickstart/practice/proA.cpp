#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Candidate {
    private:
        string name;
        int score;
    public:
        Candidate (const string &name) {
            this->name = name;
            unordered_set<char> hashset;
            for (char c : name) {
                if (c == ' ') continue;
                hashset.insert(c);
            }
            this->score = hashset.size();
        }
        bool operator < (const Candidate &rhs) const {
            if (this->score != rhs.score) {
                return this->score < rhs.score;
            } else {
                return this->name > rhs.name;
            }
        }
        string getName() const{
            return this->name;
        }
};

string CountryLeader (vector<string> &candidate_names) {    
    //TODO: check if candidate_names is valid
    const int num_candidates = candidate_names.size();
    Candidate candidate(candidate_names[0]);
    for (int i = 1; i < num_candidates; ++i) {
        Candidate tmp(candidate_names[i]);
        if (candidate < tmp) {
            candidate = tmp;
        }
    }
    return candidate.getName();
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        vector<string> a(n, string());
        getline(std::cin, a[0]);
        for (int j = 0; j < n; ++j) {
            //cin >> a[j];
            getline(std::cin, a[j]);
            //cerr << a[j] << endl;
        }
        cout << "Case #" << i + 1 << ": " << CountryLeader(a) << endl;
    }
    return 0;
}
