#include "todd_and_steven.h"

#include "message.h"

#include "bits/stdc++.h"
using namespace std;

typedef long long lld;

const lld infl=0x3f3f3f3f3f3f3f3fLL;
const lld mod=1000000007LL;

struct interval_t{
    int k, lef, rig;
    lld hig;
} interval[1100];

inline int calc_from(const int tasks, const int nodes, const int nodeId){
    const int rem=tasks%nodes;
    return tasks/nodes*nodeId+((nodeId<rem)?nodeId:rem);
}

inline int calc_length(const int tasks, const int nodes, const int nodeId){
    const int rem=tasks%nodes;
    return tasks/nodes+((nodeId<rem)?1:0);
}

int len[2];
int pos[2], lef[2], rig[2];
lld foo[2];

int tasks;

inline lld getValue(const int k, const int p){
    if(k==0){
        return GetToddValue(p);
    }
    if(k==1){
        return GetStevenValue(p);
    }
    assert(0);
}

int main(){
    int nodes=NumberOfNodes();
    int nodeId=MyNodeId();
    len[0]=(int)GetToddLength();
    len[1]=(int)GetStevenLength();
    
    tasks=0;
    pos[0]=pos[1]=0;
    while(1){
        foo[0]=foo[1]=infl;

        if(pos[0]<len[0] && pos[0]<nodes){
            lef[0]=calc_from(len[0], nodes, pos[0]);
            rig[0]=lef[0]+calc_length(len[0], nodes, pos[0]);
            if(lef[0]<rig[0])foo[0]=getValue(0, rig[0]-1);
        }

        if(pos[1]<len[1] && pos[1]<nodes){
            lef[1]=calc_from(len[1], nodes, pos[1]);
            rig[1]=lef[1]+calc_length(len[1], nodes, pos[1]);
            if(lef[1]<rig[1])foo[1]=getValue(1, rig[1]-1);
        }

        int k=0;
        if(foo[k]>foo[k^1]){
            k^=1;
        }
        if(foo[k]==infl)break;
        interval[tasks].k=k;
        interval[tasks].lef=lef[k];
        interval[tasks].rig=rig[k];
        interval[tasks].hig=foo[k];
        pos[k]++;
        tasks++;
    }

    if(nodes>tasks)nodes=tasks;
    if(nodeId>=nodes)return 0;
    int from=calc_from(tasks, nodes, nodeId);
    int to=from+calc_length(tasks, nodes, nodeId);
    //fprintf(stderr, "tasks %d->%d\n", from, to);

    lld low=(from>0)?interval[from-1].hig+1LL:0LL;
    lld hig=interval[to-1].hig;

    pos[0]=pos[1]=-1;
    for(int i=tasks-1; (!~pos[0]) || (!~pos[1]); i--){
        if(~pos[interval[i].k])continue;
        if(interval[i].lef==0 || getValue(interval[i].k, interval[i].lef)<=low){
            pos[interval[i].k]=interval[i].lef;
        }
    }

    while(pos[0]<len[0] && getValue(0, pos[0])<low)pos[0]++;
    while(pos[1]<len[1] && getValue(1, pos[1])<low)pos[1]++;

    lld ans=0LL;
    lld prev=pos[0]+pos[1];
    while(1){
        foo[0]=foo[1]=infl;
        if(pos[0]<len[0])foo[0]=getValue(0, pos[0]);
        if(pos[1]<len[1])foo[1]=getValue(1, pos[1]);
        int k=0;
        if(foo[k]>foo[k^1]){
            k^=1;
        }
        if(foo[k]>hig)break;
        ans=(ans+(foo[k]^prev))%mod;
        pos[k]++;
        prev++;
    }

    if(nodeId!=nodes-1){
        PutLL(nodes-1, ans);
        Send(nodes-1);
    }else{
        for(int i=0; i<nodes; i++){
            if(i==nodes-1)continue;
            Receive(i);
            ans=(ans+GetLL(i))%mod;
        }
        ans=(ans%mod+mod)%mod;
        printf("%lld\n", ans);
    }

    return 0;
}

