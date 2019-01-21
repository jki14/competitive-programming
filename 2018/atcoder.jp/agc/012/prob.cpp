#include "bits/stdc++.h"
using namespace std;

class Vertice{
    private:
    int idx;
    vector<Vertice*> neighbors;
    public:
    void clear(){
        this->neighbors.clear();
    }
    void addNeighbor(Vertice* neighbor){
        this->neighbors.push_back(neighbor);
    }
    vector<Vertice*> &getNeighbors(){
        return this->neighbors;
    }
    void setIndex(const int index){
        this->idx=index;
    }
    int getIndex(){
        return this->idx;
    }
};

class Operation{
    private:
    int v, d, c;
    public:
    Operation(const int lhs, const int mhs, const int rhs){
        this->v=lhs;
        this->d=mhs;
        this->c=rhs;
    }
    int getV() const{
        return this->v;
    }
    int getD() const{
        return this->d;
    }
    int getC() const{
        return this->c;
    }
};

vector<int> painting(const int n, const vector<Operation> &operations, const vector<Vertice> &vertices){
    vector<int> foo(n, -1);
    vector<int> dst(n, 0);
    vector<int> vst(n, -1);
    for(int i=operations.size()-1; i>=0; i--){
        const Operation &operation=operations[i];
        queue<Vertice*> que;
        dst[operation.getV()]=operation.getD();
        if(dst[operation.getV()]>vst[operation.getV()]){
            vst[operation.getV()]=dst[operation.getV()];
            que.push((Vertice*)(&vertices[operation.getV()]));
        }
        for(; !que.empty(); que.pop()){
            Vertice *u=que.front();
            if(!~foo[u->getIndex()])
                foo[u->getIndex()]=operation.getC();
            if(dst[u->getIndex()]>0){
                for(Vertice *v : u->getNeighbors()){
                    if(dst[u->getIndex()]-1>vst[v->getIndex()]){
                        dst[v->getIndex()]=dst[u->getIndex()]-1;
                        que.push(v);
                        vst[v->getIndex()]=dst[v->getIndex()];
                    }
                }
            }
        }
    }
    for(int &x : foo){
        x=max(x, 0);
    }
    return foo;
}

int main(){
    int n, m, q;
    while(scanf("%d%d", &n, &m)!=EOF){
        vector<Vertice> vertices;
        vertices.resize(n);
        for(int i=0; i<n; i++){
            vertices[i].setIndex(i);
        }
        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            vertices[u].addNeighbor(&vertices[v]);
            vertices[v].addNeighbor(&vertices[u]);
        }
        scanf("%d", &q);
        vector<Operation> operations;
        for(int i=0; i<q; i++){
            int v, d, c;
            scanf("%d%d%d", &v, &d, &c);
            operations.push_back(Operation(v-1, d, c));
        }
        vector<int> foo=painting(n, operations, vertices);
        for(const int r : foo){
            printf("%d\n", r);
        }
    }
    return 0;
}
