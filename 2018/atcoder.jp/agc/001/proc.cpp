#include "bits/stdc++.h"
using namespace std;

class TreeNode{
    private:
    vector<TreeNode*> neighbors;
    public:
    void clear(){
        this->neighbors.clear();
    }
    void addNeighbor(TreeNode *neighbor){
        this->neighbors.push_back(neighbor);
    }
    int numOfNeighbors(){
        return (int)this->neighbors.size();
    }
    TreeNode *getNeighbor(const int offset){
        return this->neighbors[offset];
    }
} tree[2048];

int nodetest(TreeNode *node, TreeNode *prev, const int curdist, const int maxdist){
    int cnt=0;
    if(curdist>maxdist){
        cnt++;
    }
    for(int i=0; i<node->numOfNeighbors(); i++){
        TreeNode *neighbor=node->getNeighbor(i);
        if(neighbor==prev){
            continue;
        }
        cnt+=nodetest(neighbor, node, curdist+1, maxdist);
    }
    return cnt;
}

int edgetest(TreeNode *u, TreeNode *v, const int maxdist){
    return nodetest(u, v, 0, maxdist)+nodetest(v, u, 0, maxdist);
}

int minRemove(TreeNode *node, TreeNode *prev, const int maxlen){
    int foo=0x3f3f3f3f;
    if(!(maxlen&1)){
        foo=min(foo, nodetest(node, NULL, 0, maxlen>>1));
    }
    for(int i=0; i<node->numOfNeighbors(); i++){
        TreeNode *neighbor=node->getNeighbor(i);
        if(neighbor==prev)continue;
        if(maxlen&1){
            foo=min(foo, edgetest(node, neighbor, (maxlen-1)>>1));
        }
        foo=min(foo, minRemove(neighbor, node, maxlen));
    }
    return foo;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        for(int i=0; i<n; i++)tree[i].clear();
        for(int i=1; i<n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            tree[u].addNeighbor(&tree[v]);
            tree[v].addNeighbor(&tree[u]);
        }
        printf("%d\n", minRemove(&tree[0], NULL, m));
    }
    return 0;
}
