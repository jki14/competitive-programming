#include "bits/stdc++.h"
using namespace std;

class TreeNode{
    private:
    int idx;
    vector<TreeNode*> losers;
    public:
    int getIndex(){
        return this->idx;
    }
    vector<TreeNode*> &getLosers(){
        return this->losers;
    }
    void setIndex(const int index){
        this->idx=index;
    }
    void clearLosers(){
        this->losers.clear();
    }
    void addLoser(TreeNode *loser){
        this->losers.push_back(loser);
    }
} treeNode[110000];

int minimumHeight(TreeNode *node, unordered_map<int, int> &cache){
    unordered_map<int, int>::iterator it = cache.find(node->getIndex());
    if(it!=cache.end()){
        return it->second;
    }
    vector<int> sub;
    for(TreeNode *loser : node->getLosers()){
        sub.push_back(minimumHeight(loser, cache));
    }
    sort(sub.begin(), sub.end());
    int foo=-1;
    for(const int h : sub){
        if(foo<h){
            foo=h;
        }else{
            foo++;
        }
    }
    foo++;
    cache.insert(make_pair(node->getIndex(), foo));
    return foo;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; i++){
            treeNode[i].setIndex(i);
        }
        for(int i=1; i<n; i++){
            int p;
            scanf("%d", &p);
            p--;
            treeNode[p].addLoser(&treeNode[i]);
        }
        unordered_map<int, int> cache;
        printf("%d\n", minimumHeight(&treeNode[0], cache));
    }
    return 0;
}
