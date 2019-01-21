#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct SegmentTreeNode {
    int lef, rig;
    int cnt;
    SegmentTreeNode *chd[2];
};

SegmentTreeNode* build(const int lef, const int rig, const vector<int> &values) {
    SegmentTreeNode *node = new SegmentTreeNode();
    node->lef = lef;
    node->rig = rig;
    if (lef == rig) {
        node->cnt = values[lef];
        node->chd[0] = nullptr;
        node->chd[1] = nullptr;
    } else {
        const int mid = (lef + rig) >> 1;
        node->chd[0] = build(lef, mid, values);
        node->chd[1] = build(mid+1, rig, values);
        node->cnt = node->chd[0]->cnt + node->chd[1]->cnt;
    }
    return node;
}

void destroy(SegmentTreeNode *node) {
    if (node->chd[0] != nullptr) {
        destroy(node->chd[0]);
        destroy(node->chd[1]);
}
delete node;
}

int getPosition(SegmentTreeNode *node, const int score) {
    if (node->lef != node->rig) {
        if (score <= node->chd[0]->cnt) {
            return getPosition(node->chd[0], score);
        } else {
            return getPosition(node->chd[1], score - node->chd[0]->cnt);
        }
    } else {
        return node->lef;
    }
}

void update(SegmentTreeNode *node, const int pos, const int delta) {
    node->cnt += delta;
    if (node->lef != node->rig) {
        if (pos <= node->chd[0]->rig) {
            update(node->chd[0], pos, delta);
        } else {
            update(node->chd[1], pos, delta);
        }
    }
}

bool Kicksort(const vector<int> &original) {
    //TODO: check original is valid
    const int n = original.size();
    SegmentTreeNode *root = build(0, n - 1, vector<int>(n, 1));
    multiset<int> ms(original.begin(), original.end());
    for (int k = 0; k < n; ++k) {
        const int score = ((n - k) - 1) / 2 + 1;
        const int position = getPosition(root, score);
        if ((ms.count(original[position]) == 1 && original[position] == *ms.begin()) || original[position] == *ms.rbegin()){
            update(root, position, -1);
            //TODO: can be optimized to avoid find operation
            ms.erase(ms.find(original[position]));
        } else {
            destroy(root);
            return false;
        }
           
    }
    destroy(root);
    return true;
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        if (Kicksort(a)) {
            cout << "Case #" << i + 1 << ": YES" <<endl;
        } else {
            cout << "Case #" << i + 1 << ": NO" <<endl;
        }
    }
    return 0;
}
