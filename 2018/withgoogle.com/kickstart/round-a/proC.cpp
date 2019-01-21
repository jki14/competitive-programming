#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const long long gcToken = 1000000007LL;

//recursively hash keys: length -> heading char -> tailing char -> chrs-count
class Pattern {
    private:
        int len;
        char front, back;
        vector<int> count;
    public:
        Pattern(const string &str) {
            this->len = str.length();
            this->front = str.front();
            this->back = str.back();
            this->count.resize(26);
            for (int i = 0; i < 26; ++i) {
                this->count[i] = 0;
            }
            for (const char c : str) {
                this->count[c - 'a']++;
            }
        }
        void goRight(const char front, const char back) {
            this->count[this->front - 'a']--;
            this->front = front;
            this->back = back;
            this->count[this->back - 'a']++;
        }
        int getHash() const {
            long long foo = this->front - 'a';
            foo = foo * 26 + (this->back - 'a');
            for (int i = 0; i < 26; ++i) {
                foo = (foo * (this->len + 1LL) + this->count[i]) % gcToken;
            }
            return (int)foo;
        }
        bool operator == (const Pattern &rhs) const{
            if(this->len!= rhs.len) return false;
            if(this->front != rhs.front) return false;
            if(this->back != rhs.back) return false;
            for (int i = 0; i < 26; ++i) {
                if(this->count[i] != rhs.count[i])
                    return false;
            }
            return true;
        }
};

class MagicBox {
    private:
        unordered_multimap<int, Pattern> foo;
    public:
        void insert(const Pattern &pattern) {
            this->foo.insert(make_pair(pattern.getHash(), pattern));
        }
        int getSize() {
            return this->foo.size();
        }
        void erase(const Pattern &pattern) {
            const int key = pattern.getHash();
            auto it = this->foo.find(key);
            while (it != this->foo.end() && it->first == key && it->second == pattern) {
                it = this->foo.erase(it);
            }
        }
};

int ScrambledWords(const string &text, const vector<string> &patterns) {
    //TODO: check if text and patterns are valid
    int n = text.length();
    unordered_map<int, MagicBox> chest;
    for (const string &pattern : patterns) {
        int length = pattern.length();
        auto it = chest.find(length);
        if (it == chest.end()) {
            it = chest.insert(make_pair(length, MagicBox())).first;
        }
        it->second.insert(Pattern(pattern));
    }
    int foo = 0;
    for (auto &entry : chest) {
        if (entry.first > n) continue;
        foo += entry.second.getSize();
        Pattern pattern(text.substr(0, entry.first));
        for (int i = entry.first - 1; i < n; ++i) {
            if (i != entry.first - 1){
                pattern.goRight(text[i - entry.first + 1], text[i]);
            }
            entry.second.erase(pattern);
        }
        foo -= entry.second.getSize();
    }
    return foo;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n, m;
        cin >> m;
        vector<string> patterns(m, string());
        for (int j = 0; j < m; ++j) {
            cin >> patterns[j];
        }
        char tmp0, tmp1;
        long long A, B, C, D;
        cin >> tmp0 >> tmp1 >> n >> A >> B >> C >> D;
        vector<long long> x(n, 0);
        x[0] = tmp0;
        x[1] = tmp1;
        for (int i = 2; i < n; ++i) {
            x[i] = (A * x[i - 1] + B * x[i - 2] + C) % D;
        }
        string text(n, '?');
        text[0] = tmp0;
        text[1] = tmp1;
        for (int i = 2; i < n; ++i) {
            text[i] = 'a' + x[i] % 26;
        }
        //cerr << text << endl;
        cout << "Case #" << i + 1 << ": " << ScrambledWords(text, patterns) << endl;
        fflush(stdout);
    }
    return 0;
}
