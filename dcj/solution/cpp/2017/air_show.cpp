#include "message.h"
#include "air_show.h"

#include "bits/stdc++.h"
using namespace std;

#define master 0

typedef long long lld;
typedef pair<int, int> pii;

const lld inf=0x3f3f3f3f3f3f3f3fLL;

int num_of_seg;

unordered_map<int, lld> timeCache[2];
unordered_map<int, lld> positionCache[2];

lld sum_of_time[2];
lld sum_of_prefix[2][100];
int ans[2], pos[2];
lld cur[2], til[2];
lld mem[2];

pair<int, lld> position_cache[2][2];

struct interval_t{
    pii end_points;
    int k;
    lld from_time;
    lld to_time;
    interval_t(){}
    interval_t(const pii &_end_points, const int _k, const lld _from_time, const lld _to_time){
        this->end_points=_end_points;
        this->k=_k;
        this->from_time=_from_time;
        this->to_time=_to_time;
    }
} interval_list[200];

inline pii get_end_points(const int tasks, const int nodes, const int index){
    int to=tasks/nodes+((index<(tasks%nodes))?1:0);
    int from=tasks/nodes*index+((index<(tasks%nodes))?index:(tasks%nodes));
    to+=from;
    //from+=1;
    //to+=1;
    return make_pair(from, to);
}

inline lld getTime(const int k, const int p){
    if((k!=0 && k!=1) || p<0 || p>=num_of_seg)while(1);
    unordered_map<int, lld>::iterator it=timeCache[k].find(p);
    if(it!=timeCache[k].end()){
        return it->second;
    }else{
        lld foo=GetTime(k, p);
        timeCache[k].insert(make_pair(p, foo));
        return foo;
    }
    return GetTime(k, p);
}

inline lld getPosition(const int k, const int p){
    if((k!=0 && k!=1) || p<0 || p>num_of_seg)while(1);
    unordered_map<int, lld>::iterator it=positionCache[k].find(p);
    if(it!=positionCache[k].end()){
        return it->second;
    }else{
        lld foo=GetPosition(k, p);
        positionCache[k].insert(make_pair(p, foo));
        return foo;
    }
    if(p==position_cache[k][0].first)return position_cache[k][0].second;
    if(p==position_cache[k][1].first)return position_cache[k][1].second;
    position_cache[k][0]=position_cache[k][1];
    position_cache[k][1]=make_pair(p, GetPosition(k, p));
    return position_cache[k][1].second;
}

inline lld position(const lld bin, const int i){
    return (bin>>(20*i)) & ((1LL<<20)-1LL);
}

int check(const lld pnt, const lld from, const lld to, const lld x, const lld y, lld dist){
    dist*=y;
    lld d0=(y-x)*position(from, 0)+x*position(to, 0)-y*position(pnt, 0);
    lld d1=(y-x)*position(from, 1)+x*position(to, 1)-y*position(pnt, 1);
    lld d2=(y-x)*position(from, 2)+x*position(to, 2)-y*position(pnt, 2);
    __int128 _dist=dist;
    __int128 _d0=d0;
    __int128 _d1=d1;
    __int128 _d2=d2;
    _dist*=_dist;
    if(_dist>0){
        _dist-=_d0*_d0;
    }
    if(_dist>0){
        _dist-=_d1*_d1;
    }
    if(_dist>0){
        _dist-=_d2*_d2;
    }
    return _dist>0;
}

int main(){
    int index=MyNodeId();
    lld dist=GetSafeDistance();
    num_of_seg=(int)GetNumSegments();
    int robots=(int)NumberOfNodes();
    if(robots>num_of_seg)robots=num_of_seg;
    if(index>=robots)return 0;
    if(robots>100)while(1);
    int from=get_end_points(num_of_seg, robots, index).first;
    int to=get_end_points(num_of_seg, robots, index).second;

    /*timeCache[0].clear();
    timeCache[1].clear();
    positionCache[0].clear();
    positionCache[1].clear();*/
    position_cache[0][0]=make_pair(-1, -1LL);
    position_cache[0][1]=make_pair(-1, -1LL);
    position_cache[1][0]=make_pair(-1, -1LL);
    position_cache[1][1]=make_pair(-1, -1LL);
    
    //SUM OF PREFIX
    sum_of_time[0]=sum_of_time[1]=0LL;
    for(int k=0; k<2; k++){
        for(int i=from; i<to; i++){
            sum_of_time[k]+=getTime(k, i);
        }
    }
    for(int r=0; r<robots; r++){
        for(int k=0; k<2; k++){
            PutLL(r, sum_of_time[k]);
        }
        Send(r);
    }
    
    for(int i=0; i<robots; i++){
        Receive(i);
        for(int k=0; k<2; k++){
            sum_of_prefix[k][i]=GetLL(i);
        }
    }
    for(int i=1; i<robots; i++){
        for(int k=0; k<2; k++){
            sum_of_prefix[k][i]+=sum_of_prefix[k][i-1];
        }
    }

    pos[0]=pos[1]=0;
    int temp=0;
    while(pos[0]<robots || pos[1]<robots){
        til[0]=til[1]=inf; 
        for(int k=0; k<2; k++){
            if(pos[k]<robots){
                til[k]=sum_of_prefix[k][pos[k]];
            }
        }
        int k=0;
        if(til[k]>til[k^1])k^=1;
        interval_list[temp++]=interval_t(get_end_points(num_of_seg, robots, pos[k]), k, (pos[k]>0)?(sum_of_prefix[k][pos[k]-1]+1LL):1LL, sum_of_prefix[k][pos[k]]);
        pos[k]++;
    }

    from=index<<1;
    to=from+2;
    ans[0]=ans[1]=0;
    cur[0]=cur[1]=-1LL;
    for(int offset=from; offset<to; offset++){
        interval_t &interval=interval_list[offset];
        lld timepoint=interval.from_time-1LL;
        for(int i=interval.end_points.first; i<interval.end_points.second; i++){
            if(i>=num_of_seg){
                while(1);
            }
            if(!~cur[interval.k^1]){
                for(int r=robots*2-1; ; r--){
                    if(interval_list[r].k==(interval.k^1)){
                        if(interval_list[r].from_time-1LL<=timepoint){
                            cur[interval.k^1]=interval_list[r].from_time-1LL;
                            pos[interval.k^1]=interval_list[r].end_points.first;
                            mem[interval.k^1]=getTime(interval.k^1, pos[interval.k^1]);
                            break;
                        }
                    }
                    if(r==0){
                        while(1);
                    }
                    assert(r!=0);
                }
            }
            
            while(cur[interval.k^1]+mem[interval.k^1]<timepoint){
                cur[interval.k^1]+=mem[interval.k^1];
                mem[interval.k^1]=getTime(interval.k^1, ++pos[interval.k^1]);
            }
            if(i!=0 && check(getPosition(interval.k, i), getPosition(interval.k^1, pos[interval.k^1]), getPosition(interval.k^1, pos[interval.k^1]+1), timepoint-cur[interval.k^1], mem[interval.k^1], dist)){
                ans[interval.k]++;
            }
            //TIMEPOINT MOVE
            timepoint+=getTime(interval.k, i);
        }
    }

    timeCache[0].clear();
    timeCache[1].clear();
    positionCache[0].clear();
    positionCache[1].clear();

    if(index!=master){
        PutInt(master, ans[0]);
        PutInt(master, ans[1]);
        Send(master);
    }else{
        for(int i=0; i<robots; i++){
            if(i==master)continue;
            Receive(i);
            ans[0]+=GetInt(i);
            ans[1]+=GetInt(i);
        }
        printf("%d %d\n", ans[0], ans[1]);
        //printf("-1 -1\n");
    }
    
    return 0;
}

