#include "bits/stdc++.h"
using namespace std;

typedef long long lld;
const lld MOD=1000000007LL;

inline lld MOD_STD(const lld x){ return (x%MOD+MOD)%MOD; }
inline lld MOD_ADD(const lld x, const lld y){ return (x+y)%MOD; }
inline lld MOD_MUL(const lld x, const lld y){ return (x*y)%MOD; }
inline lld MOD_POW(const lld x, const lld y){
    if(y==0LL){
        return 1LL%MOD;
    }else if((y&1LL)==0LL){
        lld z=MOD_POW(x, y>>1); 
        return MOD_MUL(z, z);
    }else{
        return MOD_MUL(MOD_POW(x, y^1LL), x);
    }
}

#include "weird_editor.h"
#include "message.h"

inline int calc_from(const int tasks, const int nodes, const int nodeId){
    const int rem=tasks%nodes;
    return tasks/nodes*nodeId+((nodeId<rem)?nodeId:rem);
}

inline int calc_length(const int tasks, const int nodes, const int nodeId){
    const int rem=tasks%nodes;
    return tasks/nodes+((nodeId<rem)?1:0);
}

lld f[10], g[10], h[10];

int main(){
    int nodes=NumberOfNodes();
    int nodeId=MyNodeId();
    int tasks=(int)GetNumberLength();
    if(nodes>tasks)nodes=tasks;
    if(nodeId>=nodes)return 0;
    int from=calc_from(tasks, nodes, nodeId);
    int to=from+calc_length(tasks, nodes, nodeId);

    int bar=-1;
    for(int i=0; i<10; i++){
        f[i]=0LL;
        g[i]=0LL;
        h[i]=1LL;
    }
    for(int i=to-1; i>=from; i--){
        int c=GetDigit(i);
        if(c==0)continue;
        if(c>=bar){
            f[c]++;
            g[c]=MOD_ADD(MOD_MUL(c, h[c]), g[c]);
            h[c]=MOD_MUL(h[c], 10LL);
            bar=c;
        }
    }

    /*fprintf(stderr, "f=[");
    for(int i=0; i<10; i++){
        if(i)fprintf(stderr, ",");
        fprintf(stderr, "%d", f[i]);
    }
    fprintf(stderr, "]\n");
    
    fprintf(stderr, "g=[");
    for(int i=0; i<10; i++){
        if(i)fprintf(stderr, ",");
        fprintf(stderr, "%d", g[i]);
    }
    fprintf(stderr, "]\n");*/

    
    if(nodeId!=nodes-1){
        for(int i=1; i<10; i++){
            PutLL(nodes-1, f[i]);
            PutLL(nodes-1, g[i]);
        }
        Send(nodes-1);
    }else{
        lld ans=0;
        lld len=0;
        int bar=-1;
        for(int c=1; c<10; c++){
            if(f[c]==0LL)continue;
            if(c>=bar){
                ans=MOD_ADD(MOD_MUL(g[c], MOD_POW(10LL, len)), ans);
                len+=f[c];
                bar=c;
            }
        }
        //fprintf(stderr, "ans=%d len=%d bar=%d\n", ans, len, bar);
        for(int i=nodes-2; i>=0; i--){
            Receive(i);
            for(int c=1; c<10; c++){
                lld cnt=GetLL(i);
                lld foo=GetLL(i);
                if(cnt==0LL)continue;
                if(c>=bar){
                    ans=MOD_ADD(MOD_MUL(foo, MOD_POW(10LL, len)), ans);
                    len+=cnt;
                    bar=c;
                }
            }
            //fprintf(stderr, "ans=%d len=%d bar=%d\n", ans, len, bar);
        }
        ans=MOD_MUL(ans, MOD_POW(10LL, tasks-len));
        printf("%lld\n", MOD_STD(ans));
    }

    return 0;
}

