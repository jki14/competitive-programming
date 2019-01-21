#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxlen 30
#define maxn 210
#define maxm 5100

#define lmt 100000

int n,m,l;
int s[maxn][maxlen];
int mk[maxn][maxlen],ct;
int len[maxn];
int lock[maxn][maxlen];
vector<int> cp[maxn][maxlen];
vector<int> cc[maxn][maxlen];
int d[maxn],p[maxn][maxlen],u[maxn][maxlen],v[maxn][maxlen];
int x[maxm],y[maxm];

int cover(const int &i,const int &j,const int &d){
	if(lock[i][j]) return s[i][j]==d;
	s[i][j]=d;
	lock[i][j]=1;
	for(int k=0;k<(int)cp[i][j].size();k++)
		if(!cover(cp[i][j][k],cc[i][j][k],d))return 0;
	return 1;
}

void clean(const int &i,const int &j){
	if(!lock[i][j])return;
	s[i][j]=0;
	lock[i][j]=0;
	for(int k=0;k<(int)cp[i][j].size();k++)
		clean(cp[i][j][k],cc[i][j][k]);
}

int check(const int &i,const int &j,const int &d){
	if(mk[i][j]==ct)return 1;
	mk[i][j]=ct;
	if(s[i][j]!=d)return 0;
	for(int k=0;k<(int)cp[i][j].size();k++)
		if(!check(cp[i][j][k],cc[i][j][k],d))return 0;
	return 1;
}

int scmp(const int &i,const int &j){
	int k,t=min(len[i],len[j]);
	for(k=0;k<t;k++)
		if(s[i][k]!=s[j][k])return s[i][k]<s[j][k];
	return len[i]<len[j];
}

int suit(){
	for(int i=0;i<m;i++)
		if(!scmp(x[i],y[i]))return 0;
	return 1;
}	

int dfs(const int &i,const int &j){
	if(i>=n){int xx,yy;
		ct++;
		for(xx=0;xx<n;xx++)
			for(yy=0;yy<len[xx];yy++)
				if(!check(xx,yy,s[xx][yy]))return 0;
		/*printf("~~~~~\n");
		for(xx=0;xx<n;xx++){
			for(yy=0;yy<len[xx];yy++)printf("%d",s[xx][yy]);
			printf("\n");
		}
		printf("~~~~~\n");*/
		return suit();
	}
	int ii=i,jj=j+1,k;
	if(jj>=len[ii]){ jj=0;ii++; }
	if(lock[i][j]){
		return dfs(ii,jj);
	}else{
		for(k=1;k<=l;k++){
			if(cover(i,j,k)){
				if(dfs(ii,jj))return 1;
			}
			clean(i,j);
		}
	}
	return 0;
}

void work(){
	int i,j,k,t;
	memset(mk,0,sizeof(mk));ct=0;
	memset(s,0,sizeof(s));
	memset(len,0,sizeof(len));
	for(i=l=0;i<n;i++){
		scanf("%d",&d[i]);
		for(j=0;j<d[i];j++){
			scanf("%d%d%d",&p[i][j],&u[i][j],&v[i][j]);
			p[i][j]--;u[i][j]--;v[i][j]--;
			len[i]+=v[i][j]-u[i][j]+1;
		}
		l=max(l,len[i]);
	}
	for(i=0;i<n;i++)
		for(j=0;j<l;j++){
			cp[i][j].clear();
			cc[i][j].clear();
		}	
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]--;y[i]--;
	}
	//build [c]
	for(i=0;i<n;i++){t=0;
		for(j=0;j<d[i];j++){
			for(k=u[i][j];k<=v[i][j];k++){
				cp[i][t].push_back(j);
				cc[i][t].push_back(k);
				cp[j][k].push_back(i);
				cc[j][k].push_back(t);t++;
			}
		}
	}
	//DFS
	memset(lock,0,sizeof(lock));
	if(dfs(0,0))
		printf("Yes\n");
	else
		printf("No\n");
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

