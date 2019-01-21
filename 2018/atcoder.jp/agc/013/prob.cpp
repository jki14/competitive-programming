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

vector<int> getPath(const vector<Vertice> &vertices){
    unordered_set<void*> inque;
    deque<Vertice*> dq;
    dq.push_back((Vertice*)&vertices[0]);
    inque.insert((void*)&vertices[0]);
    for(bool updated=true; updated; ){
        updated=false;
        Vertice *u = dq.front();
        for(Vertice *v : u->getNeighbors()){
            if(!inque.count((void*)v)){
                dq.push_front(v);
                inque.insert((void*)v);
                updated=true;
                break;
            }
        }
        if(updated)continue;
        u = dq.back();
        for(Vertice *v : u->getNeighbors()){
            if(!inque.count((void*)v)){
                dq.push_back(v);
                inque.insert((void*)v);
                updated=true;
                break;
            }
        }
    }
    vector<int> foo(dq.size(), 0);
    for(int i=0; i<(int)dq.size(); i++){
        foo[i]=dq[i]->getIndex()+1;
    }
    return foo;
}

int main(){
    int n, m;
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
        vector<int> foo=getPath(vertices);
        printf("%lu\n", foo.size());
        for(size_t i=0; i<foo.size(); i++){
            printf("%d%c", foo[i], " \n"[i==foo.size()-1]);
        }
    }
    return 0;
}
