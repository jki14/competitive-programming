#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define MAXKIND 129
#define MAXN 505
#define MAXLEN 10005
#define MAXQSIZE 500005

struct TNode{
    int id;
    TNode *fail,*next[MAXKIND];
    TNode(){
        id=-1;fail=NULL;
        memset(next,0,sizeof(next));
    }
};

typedef struct TNode *Trie;

TNode *que[MAXQSIZE];

void insert(Trie p,char *key,int idx){
    for(;*key;key++){
        int i=*key;
        if(!p->next[i]) p->next[i]=new TNode;
        p=p->next[i];
    }
    p->id=idx;
}

void build_ac(Trie root){
    root->fail=NULL;
    int l,r;l=r=0;que[r++]=root;
    TNode *p,*q;
    for(;l<r;l++){
        p=que[l];
        for(int i=0;i<MAXKIND;i++){
            if(p->next[i]){
                que[r++]=p->next[i];
                if(p==root)
                    p->next[i]->fail=root;
                else{
                    for(q=p->fail;q;q=q->fail)
                        if(q->next[i]){
                            p->next[i]->fail=q->next[i];
                            break;
                        }
                    if(!q) p->next[i]->fail=root;
                }
            }
        }
    }
}

int search(Trie root,char *pat,int *arr)
{
    int i,flag=0;TNode *p=root,*q;
    for(;*pat;pat++){
        i=*pat;while(!p->next[i] && p!=root) p=p->fail;
        p=p->next[i];if(!p) p=root;
        for(q=p;q->id != -1 && !arr[q->id] && q != root;q=q->fail){
            arr[p->id]=1;flag++;
        }
    }
    return flag;
}

char str[MAXLEN];
int tag[MAXN],n,m;

void work(){
    memset(tag,0,sizeof(tag));
    Trie tree=new TNode;
    int i;for(i=1;i<=n;i++){
        scanf("%s",str);
        insert(tree,str,i);
    }
    build_ac(tree);scanf("%d",&m);
    int cnt=0;for(i=1;i<=m;i++){
        scanf("%s",str);if(search(tree,str,tag)){
            printf("web %d:",i);
            cnt++; for(int j=1;j<MAXN;j++)
                if(tag[j]) printf(" %d",j);
            printf("\n");
            memset(tag,false,sizeof(tag));
        }
    }
    printf("total: %d\n",cnt);
}

int main(){
    while(scanf("%d",&n)!=EOF)work();
    return 0;
}
