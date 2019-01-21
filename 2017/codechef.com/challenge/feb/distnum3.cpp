#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map> 
using namespace std;
 
inline void Read(int &Num)
{
    char c = getchar();
    bool Neg = false;
    while (c < '0' || c > '9')
    {
        if (c == '-') Neg = true;
        c = getchar();
    }
    Num = c - '0'; c = getchar();
    while (c >= '0' && c <= '9')
    {
        Num = Num * 10 + c - '0';
        c = getchar();
    }
    if (Neg) Num = -Num;
}
 
const int MaxN = 210000, MaxQ = 110000;
 
int n, m, q, BlkSize, Top, Index, ID_Index, Chg_Index, Qt;
int V[MaxN], W[MaxN], Col[MaxN], Father[MaxN], ID[MaxN], Depth[MaxN], S[MaxN], Cnt[MaxN], Jump[MaxN][20], Ti[MaxN];
int req[MaxQ][3]; 

int Ans;
int AnsA[MaxQ];
 
bool InPath[MaxN];
 
struct Edge
{
    int v;
    Edge *Next;
} E[MaxN * 2], *P = E, *Point[MaxN];
 
inline void AddEdge(int x, int y)
{
    ++P; P -> v = y;
    P -> Next = Point[x]; Point[x] = P;
}
 
void DFS(int x, int Fa, int Dep)
{
    Father[x] = Fa; Depth[x] = Dep;
    int Bottom = Top;
    for (Edge *j = Point[x]; j; j = j -> Next)
    {
        if (j -> v == Fa) continue;
        DFS(j -> v, x, Dep + 1);
        if (Top - Bottom >= BlkSize)
        {
            ++ID_Index;
            while (Top > Bottom)
                ID[S[Top--]] = ID_Index;
        }
    }
    S[++Top] = x;
}
 
struct Query
{
    int x, y, vx, vy, tl, Idx;
} Q[MaxQ];
 
inline bool Cmp(Query q1, Query q2)
{
    if (q1.vx != q2.vx) return q1.vx < q2.vx;
    if (q1.vy != q2.vy) return q1.vy < q2.vy;
    return q1.tl < q2.tl;
}
 
struct Chg
{
    int Pos, Num, Prev;
} C[MaxQ];
 
inline void ChangeCol(int Num, int f)
{
    if (f == -1)
    {  
        //Ans -= (LL)V[Num] * (LL)W[Cnt[Num]];
        //--Cnt[Num];
        if(!(--Cnt[Num])){
            Ans--;
        }
    }
    else
    {
        //++Cnt[Num];
        //Ans += (LL)V[Num] * (LL)W[Cnt[Num]];
        if(!(Cnt[Num]++)){
            Ans++;
        }
    }
}
 
void ChangeTL(int x, int y)
{
    if (x == y) return;
    if (x < y)
    {
        for (int i = x + 1; i <= y; ++i)
        {
            if (InPath[C[i].Pos])
            {
                ChangeCol(Col[C[i].Pos], -1);
                ChangeCol(C[i].Num, 1);
            }
            Col[C[i].Pos] = C[i].Num;
        }
    }
    else
    {
        for (int i = x; i > y; --i)
        {
            if (InPath[C[i].Pos])
            {
                ChangeCol(Col[C[i].Pos], -1);
                ChangeCol(C[i].Prev, 1);
            }
            Col[C[i].Pos] = C[i].Prev;
        }
    }
}
 
inline void Reverse(int x)
{
    if (InPath[x])
    {
        InPath[x] = false;
        ChangeCol(Col[x], -1);
    }
    else
    {
        InPath[x] = true;
        ChangeCol(Col[x], 1);
    }
}
 
void Change(int x, int y)
{
    while (x != y)
    {
        if (Depth[x] < Depth[y]) swap(x, y);
        Reverse(x);
        x = Father[x];     
    }
}
 
int LCA(int x, int y)
{
    if (Depth[x] < Depth[y]) swap(x, y);
    int Dif = Depth[x] - Depth[y];
    for (int i = 0; i <= 18; ++i)
        if (Dif & (1 << i)) x = Jump[x][i];
    if (x == y) return x;
    for (int i = 18; i >= 0; --i)
        if (Jump[x][i] != Jump[y][i])
        {
            x = Jump[x][i];
            y = Jump[y][i];
        }
    return Father[x];
}
 
void Prepare()
{
    for (int i = 1; i <= n; ++i) Jump[i][0] = Father[i];
    for (int j = 1; j <= 18; ++j)
        for (int i = 1; i <= n; ++i)
            Jump[i][j] = Jump[Jump[i][j - 1]][j - 1];
}
 
int main()
{
    Read(n); Read(q);
    map<int, int> dic;
    for (int i = 1; i <= n; ++i){
        Read(Col[i]);
        dic[Col[i]]=0;
    }
    int a, b;
    for (int i = 1; i <= n - 1; ++i)
    {
        Read(a); Read(b);
        AddEdge(a, b);
        AddEdge(b, a);
    }
    for (int i = 1; i <= q; ++i){
        Read(req[i][0]); Read(req[i][1]); Read(req[i][2]);
        if(req[i][0]==2){
            dic[req[i][2]]=0;
        }
    }
    m=0;
    for(map<int, int>::iterator it=dic.begin(); it!=dic.end(); it++){
        it->second=++m;
    }
    for(int i=1; i<=n; i++)Col[i]=dic[Col[i]];
    BlkSize = (int)pow(n, 0.667);
    DFS(1, 0, 0);
    while (Top > 0) ID[S[Top--]] = ID_Index;
    Prepare();
    for (int i = 1; i <= n; ++i) Ti[i] = Col[i];
    for (int i = 1; i <= q; ++i)
    {
        //Read(f); Read(a); Read(b);
        //printf("%d %d %d\n", req[i][0], req[i][1], req[i][2]);
        if (req[i][0] == 2)
        {
            req[i][2]=dic[req[i][2]];
            ++Chg_Index;
            C[Chg_Index].Prev = Ti[req[i][1]];
            Ti[req[i][1]] = req[i][2];
            C[Chg_Index].Pos = req[i][1];
            C[Chg_Index].Num = req[i][2];
        }
        else
        {
            ++Qt;
            Q[Qt].x = req[i][1]; Q[Qt].y = req[i][2];
            Q[Qt].vx = ID[req[i][1]]; Q[Qt].vy = ID[req[i][2]];
            Q[Qt].tl = Chg_Index;
            Q[Qt].Idx = Qt;
        }
    }
    sort(Q + 1, Q + Qt + 1, Cmp);
    Ans = 0ll;
    ChangeTL(0, Q[1].tl);
    Change(Q[1].x, Q[1].y);
    int t = LCA(Q[1].x, Q[1].y);
    Reverse(t);
    AnsA[Q[1].Idx] = Ans;  
    Reverse(t);
    for (int i = 2; i <= Qt; ++i)
    {
        ChangeTL(Q[i - 1].tl, Q[i].tl);
        Change(Q[i - 1].x, Q[i].x);
        Change(Q[i - 1].y, Q[i].y);
        t = LCA(Q[i].x, Q[i].y);
        Reverse(t);
        AnsA[Q[i].Idx] = Ans;  
        Reverse(t);
    }
    for (int i = 1; i <= Qt; ++i) printf("%d\n", AnsA[i]);
    return 0;
}
