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

#define LEN 1100
#define N 2100

const string src="Kevin,Bacon";
const int inf=111000000;

map<string , int > s;
map<string , int >::iterator it;

int T;

int p,n,m;
int a[N][N],d[N],mk[N];
int que[N],tail;

char str[LEN];

void sssp(const int &src){
	for(int i=0;i<=n;i++)d[i]=inf;
	d[src]=0;
	
	memset(mk,0,sizeof(mk));

	for(int k=0;k<=n;k++){
		int val=inf,pos=-1;
		for(int i=0;i<=n;i++)if(!mk[i] && d[i]<val){
			val=d[i];pos=i;
		}
		if(pos==-1)break;
		mk[pos]=1;
		for(int i=0;i<=n;i++)
			d[i]=min(d[i],d[pos]+a[pos][i]);
	}
}

void work(){T++;n=0;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			if(i==j)a[i][j]=0;else a[i][j]=inf;
		}
	s.clear();

	for(int i=0;i<p;i++){
		int val,j,k;scanf("%d",&val);
		string nam;gets(str);
		k=2;tail=j=0;nam.clear();
		while(str[j]==' ')j++;
		while(str[j]){
			if(str[j]==',' || str[j]==':'){k--;
				if(k)nam=nam+str[j];
			}else nam=nam+str[j];
			if(!k){k=2;
				it = s.find(nam);
				if(it==s.end()){
					s.insert(pair<string , int >(nam,++n));
					que[tail++]=n;
				}else{ que[tail++]=(*it).second; }
				nam.clear();
			}
			if(str[j]==':')break;
			j++;while(str[j]==' ')j++;
		}
		for(int u=0;u<tail;u++)
			for(int v=0;v<tail;v++)
				a[que[u]][que[v]]=min(a[que[u]][que[v]],val);
	}

	int isrc=0;it=s.find(src);
	if(it!=s.end())isrc=(*it).second;
	sssp(isrc);
	
	printf("Database %d\n",T);
	
	/*for(it=s.begin();it!=s.end();it++){
		printf("%s %d\n",(*it).first.c_str(),(*it).second);
	}
	for(int i=0;i<=n;i++)printf("d[%d]=%d\n",i,d[i]);*/

	while(m--){
		string nam;int j=0;
		gets(str);nam.clear();
		while(str[j]==' ')j++;
		while(str[j]){
			nam=nam+str[j];
			j++;while(str[j]==' ' || str[j]=='\n')j++;
		}

		int ret;
		it=s.find(nam);
		if(it==s.end())ret=inf;
		else ret=d[(*it).second];

		//str[strlen(str)-1]=0;
		if(ret>=inf)
			printf("%s: infinity\n",str);
		else
			printf("%s: %d\n",str,ret);
	}
	printf("\n");
}

int main(){T=0;
	while(scanf("%d%d",&p,&m)!=EOF && (p || m))
		work();
	return 0;
}


