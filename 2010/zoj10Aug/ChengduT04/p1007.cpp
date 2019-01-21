#include"iostream"
#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<climits>
#include<memory.h>
using namespace std;
#define SIZE 3000//顶点数
#define ESIZE 4200000//边数的二倍
#define MAX 200000000
struct Edge{
    int from,to,v,next;
} edge[ESIZE];
//注意初始化head
int head[SIZE],d[SIZE],num[SIZE],pre[SIZE],pos[SIZE],di[SIZE],b[SIZE];//pos用来标记顶点所在的边数组位置
int in[SIZE],out[SIZE],ob,now;
int m,n,s,t;//n个顶点，m个边,s为起点，t为终点
void add_Edge(int from,int to,int v)//加边，起点from 终点to 容量V
{
    edge[now].from=from;
    edge[now].to=to;
    edge[now].v=v;
    edge[now].next=head[from];
    pos[edge[now].to]=now;
    di[from]=now;
    b[from]=now;
    head[from]=now++;


    edge[now].from=to;
    edge[now].to=from;
    edge[now].v=0;
    edge[now].next=head[to];
    di[to]=now;
    b[to]=now;
    head[to]=now++;
}
void init()
{
      int i,j,k;
    for(i=0;i<=n;i++)
           d[i]=3*n;

    queue<int>Q;
    memset(num,0,sizeof(num));
    Q.push(t);
    d[t]=0;
// cout<<d[s]<<n<<endl;
    num[0]++;

    while(!Q.empty())
    {
        k=Q.front();
        Q.pop();
    //    cout<<k<<endl;
        k=head[k];
        while(k!=-1)
        {
   //         cout<<edge[k].from<<" "<<edge[k].to<<endl;
            if(d[edge[k].to]>=3*n)
            {
                d[edge[k].to]=d[edge[k].from]+1;
                Q.push(edge[k].to);
                num[d[edge[k].to]]++;
            }
            k=edge[k].next;
        }
    }
}
int FindLable(int k)
{
    int i;
    //k=head[k];
    k=di[k];
    while(k!=-1)
    {
        if(d[edge[k].from]==d[edge[k].to]+1&&edge[k].v>0)
            {
                pos[edge[k].to]=k;
                di[edge[k].from]=k;
                return edge[k].to;
            }
            k=edge[k].next;
    }
/*for(i=1;i<=n;i++)
        if(r[k][i]>0&&d[k]==d[i]+1)
            return i;
            */
    return 0;
}
int ReLable(int k)
{
    int min=INT_MAX,i;

   // k=head[k];
    k=b[k];
    while(k!=-1)
    {
        if(d[edge[k].to]+1<min&&edge[k].v>0)
            {
                min=d[edge[k].to]+1;
                di[edge[k].from]=k;
            }
            k=edge[k].next;
    }
    return min==INT_MAX?n:min;

}
int max_flow()
{
    int flow=0,b,i=s,j,x;
    memset(pre,-1,sizeof(pre));
    while(d[s]<n)
    {
        j=FindLable(i);
        if(j>0)
        {
            pre[j]=i;
            i=j;
            if(i==t)
            {
                b=INT_MAX;
                for(i=t;i!=s;i=pre[i])
                    if(edge[pos[i]].v<b)
                        b=edge[pos[i]].v;
                for(i=t;i!=s;i=pre[i])
                {
                    edge[pos[i]].v-=b;
                    edge[pos[i]^1].v+=b;
                    //r[pre[i]][i]-=b;
                    //r[i][pre[i]]+=b;
                }
                flow+=b;
            }
        }
        else
        {
            x=ReLable(i);
            num[d[i]]--;
            num[x]++;
            if(num[d[i]]==0)
                break;
            d[i]=x;
            if(i!=s)
                i=pre[i];

        }
    }
    return flow;
}
int must[55][55],map[55][55];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main()
{
    int cas,i,j,a,c,r,k,b,sum;
    while(scanf("%d%d%d",&r,&c,&k)!=EOF){
        s=r*c+1;
        t=r*c+2;
        now=0;
        sum=0;
        memset(head,-1,sizeof(head));
        memset(must,0,sizeof(must));
        n=r*c+2;
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++){
                scanf("%d",&map[i][j]);
                sum+=map[i][j];
            }
        for(i=1;i<=k;i++)
        {
            scanf("%d%d",&a,&b);
            must[a][b]=1;
        }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
            {
                if((i+j)%2)
                    add_Edge((i-1)*c+j,t,map[i][j]);
                else
                    add_Edge(s,(i-1)*c+j,map[i][j]);
            }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if((i+j)%2==0)
                {
                    for(k=0;k<4;k++)
                    {
                        int x=i+dir[k][0];
                        int y=j+dir[k][1];
                        if(x>0&&x<=r&&y>0&&y<=c)
                        {
                            add_Edge((i-1)*c+j,(x-1)*c+y,2*(map[i][j]&map[x][y]));
                        }
                    }
                }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(must[i][j])
                {
                    if((i+j)%2)
                        add_Edge((i-1)*c+j,t,MAX);
                    else
                        add_Edge(s,(i-1)*c+j,MAX);
                }
        init();

        int re=max_flow();
   printf("%d\n",sum-re);
    }
    return 0;
}

 


