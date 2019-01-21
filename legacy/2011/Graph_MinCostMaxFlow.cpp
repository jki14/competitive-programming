//============================================================================
// Name        : MinCostMaxFlow
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 最小费用最大流
//============================================================================

/*
    此版本为完整记录版

 申明:
    本算法由ZKW大牛提出,最初算法以及原始代码参考如下URL
    http://www.cppblog.com/zxytim/archive/2010/01/08/105182.html;

    第二版代码为zx23Michael大牛个人提升写作效率修改的邻接阵版;

    在此，特别感谢两位大牛。

    在第二版代码基础上,由鄙人进行代码写作及运行效率的完善，并由抛弃邻接表结构从而大幅度提升执行效率以及支持复杂图的运算。

                                                       by J.Ki
*/

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
#include<set>
#include<map>
using namespace std;

const int maxv=1100;
const int maxe=1100000;


//变量常量申明
const int inf=0x3fffffff;
int ec[maxe],ef[maxe],ew[maxe],eu[maxe],ev[maxe],next[maxe],be[maxe];
int dis[maxv],nbs[maxv],vis[maxv],num,flow,cost;
vector<int> path;

//功能函数
int min(const int &x,const int &y){ return(x<y)?x:y; }

void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

void AddEdge(int u,int v,int cc,int ww){
	//cout<<" AddEdge "<<u<<"->"<<v<<" c="<<cc<<" w="<<ww<<endl;
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;ew[num]=ww;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;ew[num]=-ww;
}

int getflow(int u,int s,int t,int k)
{
	if(u==t){cost+=k*dis[s];flow+=k;return k;}vis[u]=1;path.push_back(u);
	int minflow,v;for(int i=nbs[u];i;i=next[i]){v=ev[i];
		if(ec[i]-ef[i] && !vis[v] && ew[i]+dis[v]==dis[u]){
			minflow=min(k,ec[i]-ef[i]);
			if(int d=getflow(v,s,t,minflow)){
				ef[i]+=d;ef[be[i]]-=d;
				return d;
			}
		}
	}
	return 0;
}

bool renumber()
{
	int adds=inf,i,u,v;
	for(i=1;i<num;i++)if(vis[u=eu[i]] && ec[i]-ef[i] && !vis[v=ev[i]])
		adds=min(adds,dis[v]-dis[u]+ew[i]);
	if(adds==inf)return 0;
	for(i=0;i<(int)path.size();i++)dis[path[i]]+=adds;
	return 1;
}

void mcflow(int s,int t){
	cost=flow=0;memset(dis,0,sizeof(dis));
	for(clr();getflow(s,s,t,inf)||renumber();clr());
}

/*
//初始化
memset(nbs,0,sizeof(nbs));num=0;

//调用法则
调用mcflow()后 最大流存储于flow中 最小费用存储于cost中 流量网络存储于ef[]中

//Hint
注意重复调用时请讲ef[]清零
*/

int main(){
	return 0;
}
