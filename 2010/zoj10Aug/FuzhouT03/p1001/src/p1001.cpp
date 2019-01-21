#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 1100
#define maxm 1100

vector<int> que;

int slv[maxm],scr[maxm],id[maxm],_id[maxm];
int n,m,k;

int cmp(const int &i,const int &j){
	if(scr[i]!=scr[j])return scr[i]>scr[j];
	if(slv[i]!=slv[j])return slv[i]>slv[j];
	return i<j;
}

void work(){
	memset(slv,0,sizeof(slv));memset(scr,0,sizeof(scr));
	int i,j,val,sco;for(i=0;i<n;i++){
		que.clear();sco=m;for(j=1;j<=m;j++){
			scanf("%d",&val);if(val){
				sco--;que.push_back(j);
			}
		}
		for(j=0;j<(int)que.size();j++){
			slv[que[j]]++;scr[que[j]]+=sco;
		}
	}
	for(i=1;i<=m;i++)id[i]=i;sort(id+1,id+1+m,cmp);for(i=1;i<=m;i++)_id[id[i]]=i;
	printf("%d %d\n",scr[k],_id[k]);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)work();
	return 0;
}
