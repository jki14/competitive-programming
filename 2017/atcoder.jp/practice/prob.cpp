#include "bits/stdc++.h"
using namespace std;

static int gcc_random_seed=1923123970;
inline int gcc_random(int &prev=gcc_random_seed) {
    int next=((prev*1103515245)+12345)&0x7fffffff;
    prev=next;
    return next;
}
inline int32_t unix_rand32() {
    FILE *urand=fopen("/dev/urandom", "rb");
    int32_t foo;
    fread(&foo, 1, sizeof(int32_t), urand);
    fclose(urand);
    return foo;
}

struct bhnode_t {
    int idx;
    bhnode_t *chd[2], *anc;
} pool[32], *tail;

int n, m;

int seq[32];
int f[32][32];

char buf[32];

inline int compare(const int x, const int y) {
    if(f[x][y])return f[x][y];
    printf("? %c %c\n", 'A'+x, 'A'+y);
    fflush(stdout);
    scanf("%s", buf);
    if(buf[0]=='<') {
        f[x][y]=-1;
        f[y][x]=1;
    } else {
        f[x][y]=1;
        f[y][x]=-1;
    }
    return f[x][y];
}

void insert(const int pos) {
    bhnode_t *node=tail++;
    if(node!=pool) {
        int offset=distance(pool, node);
        node->anc=&pool[(offset-1)>>1];
        if(node->anc->chd[0]!=NULL) {
            node->anc->chd[1]=node;
        } else {
            node->anc->chd[0]=node;
        }
    } else {
        node->anc=NULL;
    }
    node->chd[0]=node->chd[1]=NULL;
    while(node->anc!=NULL && compare(pos, node->anc->idx)<0) {
        node->idx=node->anc->idx;
        node=node->anc;
    }
    node->idx=pos;
}

void remove() {
    bhnode_t *node=pool;
    node->idx=(--tail)->idx;
    if(tail->anc!=NULL) {
        if(tail==tail->anc->chd[0]) {
            tail->anc->chd[0]=NULL;
        } else {
            tail->anc->chd[1]=NULL;
        }
    }
    while(true) {
        bhnode_t *desc=NULL;
        if(node->chd[0]!=NULL && (desc==NULL || compare(node->chd[0]->idx, desc->idx)<0))
            desc=node->chd[0];
        if(node->chd[1]!=NULL && (desc==NULL || compare(node->chd[1]->idx, desc->idx)<0))
            desc=node->chd[1];
        if(desc!=NULL && compare(desc->idx, node->idx)<0) {
            int cur=node->idx;
            node->idx=desc->idx;
            desc->idx=cur;
            node=desc;
        } else {
            break;
        }
    }
}

char ans[32];

inline int cmp(const int x, const int y) {
    return compare(x, y)<0;
}

pair<int, int> leastbias(const list<vector<int>> &cand){
    pair<int, int> rep;
    int least=0x3f3f3f3f;
    for(int x=0; x<n; x++){
        for(int y=x+1; y<n; y++){
            int cur=0;
            for(const vector<int> &row : cand){
                if(row[x]<row[y]){
                    cur++;
                }else{
                    cur--;
                }
            }
            cur=abs(cur);
            if(least>cur){
                least=cur;
                rep.first=x;
                rep.second=y;
            }
        }
    }
    fprintf(stderr, "bias=%d\n", least);
    return rep;
}

void erase(list<vector<int>> &cand, const int low, const int hig){
    for(list<vector<int>>::iterator it=cand.begin(); it!=cand.end(); ){
        if(it->at(low)<it->at(hig)){
            it++;
        }else{
            it=cand.erase(it);
        }
    }
}

int main() {
    gcc_random_seed=unix_rand32()&0x7fffffff;
    scanf("%d%d", &n, &m);

    //binary-heap
    /*tail=pool;
    for(int i=0; i<n; i++) {
        insert(seq[i]);
    }
    char *last=ans;
    for(int i=0; i<n; i++) {
        *last++='A'+pool->idx;
        remove();
    }
    *last++=0;*/
    //std::sort
    /*sort(seq, seq+n, cmp);
    for(int i=0; i<n; i++){
        ans[i]='A'+seq[i];
    }
    ans[n]=0;*/
    ans[n]=0;
    memset(f, 0, sizeof(f));
    if(n<=5) {
        list<vector<int>> cand;
        vector<int> row;
        for(int i=0; i<n; i++)row.push_back(i);
        do {
            cand.push_back(row);
        } while(next_permutation(row.begin(), row.end()));
        while(cand.size()>1u) {
            pair<int, int> req=leastbias(cand);
            if(compare(req.first, req.second)<0){
                erase(cand, req.first, req.second);
            }else{
                erase(cand, req.second, req.first);
            }
        }
        for(int i=0; i<n; i++){
            ans[cand.begin()->at(i)]='A'+i;
        }
    } else {
        //std::lower_bound
        for(int i=0; i<n; i++) {
            seq[i]=i;
        }
        for(int i=0; i<n; i++) {
            int p=i+gcc_random()%(n-i);
            if(i!=p)
                swap(seq[i], seq[p]);
        }
        vector<int> vec;
        vec.push_back(seq[0]);
        for(int i=1; i<n; i++) {
            vector<int>::iterator it=upper_bound(vec.begin(), vec.end(), seq[i], cmp);
            if(it!=vec.end()) {
                vec.insert(it, seq[i]);
            } else {
                vec.push_back(seq[i]);
            }
        }
        for(int i=0; i<n; i++) {
            ans[i]='A'+vec[i];
        }
    }
    printf("! %s\n", ans);
    fflush(stdout);
    return 0;
}
