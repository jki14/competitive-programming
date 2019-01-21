#include "query_of_death.h"

#include "message.h"

#include "bits/stdc++.h"
using namespace std;

typedef long long lld;
template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }

inline int calc_from(const int tasks, const int nodes, const int nodeId){
    const int rem=tasks%nodes;
    return tasks/nodes*nodeId+((nodeId<rem)?nodeId:rem);
}

inline int calc_length(const int tasks, const int nodes, const int nodeId){
    const int rem=tasks%nodes;
    return tasks/nodes+((nodeId<rem)?1:0);
}

int main(){
    int nodes=NumberOfNodes();
    int nodeId=MyNodeId();
    int tasks=GetLength();
    int dooms=nodes/2;

    int last=MIN(nodes-dooms, tasks)+dooms-1;
    if(nodeId<dooms){
        if(tasks==1){
            if(nodeId==0){
                for(int j=dooms; j<=last; j++){
                    PutInt(j, 0);
                    Send(j);
                }
            }
            return 0;
        }
        nodes=dooms;
        nodeId=nodeId;
        if(nodes>tasks)nodes=tasks;
        if(nodeId>=nodes)return 0;
        int from=calc_from(tasks, nodes, nodeId);
        int to=from+calc_length(tasks, nodes, nodeId);
        for(int i=from; i<to; i++){
            int prev=GetValue(i);
            if(prev!=GetValue(i)){
                for(int j=0; j<nodes; j++){
                    if(j==nodeId)continue;
                    PutInt(j, from);
                    PutInt(j, to);
                    Send(j);
                }
                return 0;
            }
        }
        int prev=GetValue(to-1);
        for(int i=1; i<8; i++){
            if(prev!=GetValue(to-1)){
                for(int j=0; j<nodes; j++){
                    if(j==nodeId)continue;
                    PutInt(j, from);
                    PutInt(j, to);
                    Send(j);
                }
                return 0;
            }
        }
        int index=Receive(-1);
        from=GetInt(index);
        to=GetInt(index);
        nodes--;
        if(nodeId>index)nodeId--;
        int length=to-from;
        if(nodes>length)nodes=length;
        if(nodeId>=nodes)return 0;
        from=from+calc_from(length, nodes, nodeId);
        to=from+calc_length(length, nodes, nodeId);
        for(int i=from; i<to; i++){
            int value=GetValue(i);
            for(int k=1; k<8; k++){
                if(value!=GetValue(i)){
                    for(int j=dooms; j<=last; j++){
                        PutInt(j, i);
                        Send(j);
                    }
                    return 0;
                }
            }
        }
    }else{
        nodes=nodes-dooms;
        nodeId=nodeId-dooms;
        if(nodes>tasks)nodes=tasks;
        if(nodeId>=nodes)return 0;
        int from=calc_from(tasks, nodes, nodeId);
        int to=from+calc_length(tasks, nodes, nodeId);

        unordered_map<int, int> cached;
        int qod=-1;
        while(true){
            int index=Receive(-1);
            if(index<dooms){
                qod=GetInt(index);
                break;
            }else{
                cached[index]=GetInt(index);
            }
        }
    
        int ans=0;
        for(int i=from; i<to; i++){
            if(i==qod)continue;
            ans+=GetValue(i);
        }

        if(nodeId+dooms!=last){
            PutInt(last, ans);
            Send(last);
        }else{
            for(int i=dooms; i<nodes+dooms; i++){
                if(i==last)continue;
                if(!cached.count(i)){
                    Receive(i);
                    ans+=GetInt(i);
                }else{
                    ans+=cached[i];
                }
            }
            ans+=GetValue(qod);
            printf("%d\n", ans);
        }

    }

    return 0;
}

