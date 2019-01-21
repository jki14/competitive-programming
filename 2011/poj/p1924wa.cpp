#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

#define maxn 110
#define xx r.first+routex[t]
#define yy r.second+routey[t]
#define xxr r.first+routex[t]*2
#define yyr r.second+routey[t]*2
#define pre k^1

typedef pair<int,int> PII;

const int routex[9]={ -1,-1,-1,0,0,0,1,1,1 };
const int routey[9]={ -1,0,1,-1,0,1,-1,0,1 };

vector<PII> list[2];

int rk[maxn][maxn],a[maxn][maxn],v[maxn][maxn];
char map[maxn][maxn];
int n,m,p,res,ag[maxn];
PII s,T,r,tmp;
vector<PII> f[maxn];

int allow(int x,int y){
	if(x<0 || x>=n)return 0;
	if(y<0 || y>=m)return 0;
	return 1;
}

void rebuild(int k){
	memcpy(a,rk,sizeof(rk));
	for(int i=0;i<p;i++){
		r=f[i][k%(int)f[i].size()];
		if(ag[i]){
			for(int t=0;t<9;t++)
				if(allow(xx,yy))a[xx][yy]=1;
		}else{
			a[r.first][r.second]=1;
		}

		r=f[i][(k+1)%(int)f[i].size()];
		if(ag[i]){
			for(int t=0;t<9;t++)
				if(allow(xx,yy) && !a[xx][yy])a[xx][yy]=2;
		}else{
			if(!a[r.first][r.second])a[r.first][r.second]=2;
		}
	}
}

void work(){
	int i,j,k=res=0;
	for(i=0;i<n;i++)scanf("%s",map[i]);
	memset(rk,0,sizeof(rk));
	memset(ag,0,sizeof(ag));
	scanf("%d",&p);for(i=0;i<p;i++){
		f[i].clear();
		for(scanf("%d",&j);j;j--){
			scanf("%d%d",&r.first,&r.second);
			r.first--;r.second--;
			f[i].push_back(r);
		}
		if(map[f[i][0].first][f[i][0].second]=='a')ag[i]=1;
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(map[i][j]=='p'){
				//s=pair<int,int>(i,j);
				s.first=i;s.second=j;
			}else if(map[i][j]=='t'){
				//t=(PII)(i,j);
				T.first=i;T.second=j;
			}else if(map[i][j]=='#')rk[i][j]=1;
	rebuild(0);if(a[s.first][s.second]==1){  printf("impossible\n");return; }
	for(list[pre].clear(),list[pre].push_back(s);!list[pre].empty();k=pre){
		res++;rebuild(res);list[k].clear();
		if(res>100)break;
		memset(v,0,sizeof(v));
		
		/*//debug
		if(res==1){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++)
					cout<<a[i][j];
				cout<<endl;
			}
			for(j=0;j<m;j++)cout<<'@';cout<<endl;
		}*/
		
		//walk&run
		for(i=0;i<(int)list[pre].size();i++){
			r=list[pre][i];
			for(int t=0;t<9;t++)
				if(allow(xx,yy)){
					if(a[xx][yy]==0){
						if(/*(PII)(xx,yy)==t*/T.first==xx && T.second==yy){ printf("%d\n",res);return; }
						if(!v[xx][yy]){
							tmp.first=xx;tmp.second=yy;
							list[k].push_back(tmp);
							v[xx][yy]=1;
						}
					}
					if(a[xx][yy]==0 || a[xx][yy]==2){
						if(/*(PII)(xx,yy)==t*/T.first==xx && T.second==yy){ printf("%d\n",res);return; }
						if(allow(xxr,yyr) && !a[xxr][yyr]){
							if(/*(PII)(xxr,yyr)==t*/T.first==xx && T.second==yy){ printf("%d\n",res);return; }
							if(!v[xxr][yyr]){
								tmp.first=xxr;tmp.second=yyr;
								list[k].push_back(tmp);
								v[xxr][yyr]=1;
							}
						}
					}
				}
		}
	}
	printf("impossible\n");
}

int main(){
	int fir=1;
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0)){
		if(!fir)printf("\n");fir=0;
		work();
	}
	return 0;
}

