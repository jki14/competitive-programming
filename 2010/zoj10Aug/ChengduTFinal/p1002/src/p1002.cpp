#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

#define maxn 21000
#define maxq 310000

multiset<int> s[maxn];
multiset<int>::iterator it,next;
int f[maxn],val[maxn],ave,q;
int reqU[maxq],reqV[maxq];
char reqT[maxq];

int TIMER;
int n,m,req;

char cstr[5];

int find(int x){ if(f[x]!=x)f[x]=find(f[x]);return f[x]; }

void swap(int &x,int &y){ int t=x;x=y;y=t; }

struct edge{
    int u,v;
    edge(){}
    edge(const int &v0,const int &v1){ u=v0;v=v1;if(u>v)swap(u,v); }
    bool operator < (const edge ee) const{
        return (ee.u==u)?ee.v<v:ee.u<u;
    }
};

multiset<edge>fl;
multiset<edge>::iterator lt;

void acc(int u,int v){
    u=find(u);v=find(v);if(u==v)return;
    if(s[u].size()>s[v].size())swap(u,v);
    //cout<<" Acc "<<u<<"->"<<v<<endl;
    s[v].insert(s[u].begin(),s[u].end());
    s[u].clear();f[u]=v;
}

int getRes(int x,int k){
    x=find(x);it=s[x].lower_bound(k);
    if(it!=s[x].end())return (*it);
    else return 0;
}

void update(int x,int k){
    int r=find(x);
    s[r].erase(s[r].find(val[x]));
    s[r].insert(k);
    val[x]=k;
}

void work(){
    //cout<<"-NewCase n="<<n<<" m="<<m<<" req="<<req<<endl;
    int i,u,v;ave=q=0;fl.clear();
    for(i=1;i<=n;i++){
        s[i].clear();f[i]=i;scanf("%d",&val[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        fl.insert(edge(u,v));
    }
    //cout<<" Begin To Save Req"<<endl;
    for(i=1;i<=req;i++){
        scanf("%s%d%d",cstr,&reqU[i],&reqV[i]);
        reqT[i]=cstr[0];
        if(reqT[i]=='E')
        	fl.erase(fl.find(edge(reqU[i],reqV[i])));
        else if(reqT[i]=='U')swap(val[reqU[i]],reqV[i]);
    }
    for(int i=1;i<=n;i++)s[i].insert(val[i]);
    for(lt=fl.begin();lt!=fl.end();lt++)
        acc((*lt).u,(*lt).v);
    //cout<<" Init Successful!"<<endl;
    for(i=req;i>0;i--){
        switch(reqT[i]){
            case 'F':
                ave+=getRes(reqU[i],reqV[i]);q++;
                break;
            case 'U':
                update(reqU[i],reqV[i]);
                break;
            case 'E':
                acc(reqU[i],reqV[i]);
                break;
        }
    }
    printf("Case %d: %.3f\n",TIMER,(double)ave/(double)q);
}

int main(){
    for(TIMER=0;scanf("%d%d%d",&n,&m,&req)!=EOF;work())TIMER++;
    return 0;
}
