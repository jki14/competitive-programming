#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 13
#define S 4100
#define T 930

const double eps = 1e-6;

int n,a[N],b[N];
double f[S][T];
int id[S],bit[N];

vector<int> vec[N];

int bitnum(int x){
    int ret=0;
    for(;x;x>>=1)
        if(x&1)ret++;
    return ret;
}

void build(){
    //build bit & clear vec
    for(int i=0;i<=n;i++){
        bit[i]=1<<i;
        vec[i].clear();
    }
    //build s & num & id;
    int e=1<<n;
    for(int i=0;i<e;i++)vec[bitnum(i)].push_back(i);
    for(int k=0;k<=n;k++){
        int size=vec[k].size();
        for(int i=0;i<size;i++)id[vec[k][i]]=i;
    }
}

void work(){
    /* Init */
    scanf("%d",&n);build();
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    /* Core */
    for(int k=1;k<=n;k++){
        int size=vec[k].size();
        for(int i=0;i<size;i++){
            int asta=vec[k][i];
            for(int j=0;j<size;j++){
                int bsta=vec[k][j];
                for(int ah=0;ah<n;ah++){
                    if(!(asta&bit[ah]))continue;
                    int anex=asta^bit[ah];
                    double ret,d;ret=d=0.0;
                    for(int bh=0;bh<n;bh++){
                        if(!(bsta&bit[bh]))continue;
                        ret+=f[anex][id[bsta^bit[bh]]];
                        if(a[ah]>b[bh])
                            ret+=3.0;
                        else if(a[ah]==b[bh])ret+=1.0;
                        d+=1.0;
                    }ret/=d;
                    f[asta][id[bsta]]=max(f[asta][id[bsta]],ret);
                }
            }
        }
    }
    int full=(1<<n)-1;
    printf("%.6f\n",f[full][0]);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)work();
    return 0;
}

