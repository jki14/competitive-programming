#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define maxn 1100

#define ii i+dx[k]
#define jj j+dy[k]

#define xx (x+k-1)
#define yy (y+k-1)

const int dx[4]={ -1,0,1,0 };
const int dy[4]={ 0,1,0,-1 };

int a[maxn][maxn],n,res;
int v[maxn][maxn][4],c[maxn][maxn][2];
int f[maxn],f0[maxn];
//int st[11000];
//vector<int> tail[maxn];
int tail[maxn][maxn];
char stmp[maxn];

/*map<int,int> f;
map<int,int>::iterator it;*/

/*int stQue(int i,int s,int t,int ss,int tt){
	if(s>t || ss>tt ||tt<s || ss>t)return 0;
	if(ss<=s && t<=tt)return st[i];
	if(s==t)return 0;
	int mid=(s+t)/2,x,y;
	x=stQue(i*2,s,mid,ss,tt);y=stQue(i*2+1,mid+1,t,ss,tt);
	if(x==0 || (y!=0 && x>y))x=y;
	return x;
}

void stIns(int i,int s,int t,int k){
	if(s>t || k<s || k>t)return;
	if(st[i]==0 || st[i]>k)st[i]=k;
	if(s==t)return;
	int mid=(s+t)/2;
	stIns(i*2,s,mid,k);stIns(i*2+1,mid+1,t,k);
}

void stDel(int i,int s,int t,int k){
	if(s>t || k<s || k>t)return;
	if(st[i]==k)st[i]=stQue(1,1,n,s+1,t);
	if(s==t)return;
	int mid=(s+t)/2;
	stDel(i*2,s,mid,k);stDel(i*2+1,mid+1,t,k);
}*/

int getf(const int &x){
	if(f[x]!=x)f[x]=getf(f[x]);
	return f[x];
}

void work(){
	scanf("%d",&n);res=0;
	int i,j,k,x,y;
	memset(v,0,sizeof(v));
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++){
		scanf("%s",stmp);
		//printf("%s\n",stmp);
		for(j=0;j<n;j++)
			a[i+1][j+1]=(stmp[j]=='1')?1:0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]){
				for(k=3;k!=1;k++,k%=4){
					if(a[ii][jj])
						v[i][j][k]=v[ii][jj][k]+1;
					else
						v[i][j][k]=1;
				}
			}
	for(i=n;i>=1;i--)
		for(j=n;j>=1;j--)
			if(a[i][j]){
				for(k=1;k<3;k++){
					if(a[ii][jj])
						v[i][j][k]=v[ii][jj][k]+1;
					else
						v[i][j][k]=1;
				}
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			c[i][j][0]=min(v[i][j][1],v[i][j][2]);
			c[i][j][1]=min(v[i][j][0],v[i][j][3]);
			//cout<<"c["<<i<<"]["<<j<<"][0]="<<c[i][j][0]<<endl;
			//cout<<"c["<<i<<"]["<<j<<"][1]="<<c[i][j][1]<<endl;
		}
	for(i=0;i<=n+1;i++)f0[i]=i;
	for(x=y=1;x<=n;x++){
		//memset(st,0,sizeof(st));
		//f.clear();
		memcpy(f,f0,sizeof(f));
		//for(i=0;i<=n;i++)tail[i].clear();
		//memset(tail,0,sizeof(tail));
		for(i=0;i<=n;i++)tail[i][0]=0;
		for(k=1;xx<=n && yy<=n;k++){
			tail[k+c[xx][yy][0]][0]++;
			tail[k+c[xx][yy][0]][tail[k+c[xx][yy][0]][0]]=k;
		}
		for(k=1;xx<=n && yy<=n;k++){
			for(i=1;i<=tail[k][0];i++){
				//stDel(1,1,n,tail[k][i]);
				//it=f.find(tail[k][i]);
				//f.erase(it);
				f[tail[k][i]]=f[tail[k][i]+1];
			}
			//j=stQue(1,1,n,k+2-c[xx][yy][1],k+1);
			//it=f.upper_bound(k+1-c[xx][yy][1]);
			//if(it!=f.end() && (*it).first<=k+1 ){
				//res=max(res,k+2-(*it).first);
			//}
			//if(j)res=max(res,k+2-j);
			j=getf(k-c[xx][yy][1]+1);
			res=max(res,k-j+1);
		}
	}
	for(x=1,y=2;y<=n;y++){
		//memset(st,0,sizeof(st));
		//f.clear();
		memcpy(f,f0,sizeof(f));
		//for(i=0;i<=n;i++)tail[i].clear();
		//memset(tail,0,sizeof(tail));
		for(i=0;i<=n;i++)tail[i][0]=0;
		for(k=1;xx<=n && yy<=n;k++){
			tail[k+c[xx][yy][0]][0]++;
			tail[k+c[xx][yy][0]][tail[k+c[xx][yy][0]][0]]=k;
		}
		for(k=1;xx<=n && yy<=n;k++){
			for(i=1;i<=tail[k][0];i++){
				//stDel(1,1,n,tail[k][i]);
				//it=f.find(tail[k][i]);
				//f.erase(it);
				f[tail[k][i]]=f[tail[k][i]+1];
			}
			//j=stQue(1,1,n,k+2-c[xx][yy][1],k+1);
			//it=f.upper_bound(k+1-c[xx][yy][1]);
			//if(it!=f.end() && (*it).first<=k+1 ){
				//res=max(res,k+2-(*it).first);
			//}
			//if(j)res=max(res,k+2-j);
			j=getf(k-c[xx][yy][1]+1);
			res=max(res,k-j+1);
		}
	}
	/*for(x=1,y=2;y<=n;y++){
		memset(st,0,sizeof(st));
		for(i=0;i<=n;i++)tail[i].clear();
		for(k=0;xx<=n && yy<=n;k++){
			if(a[xx][yy]){
				stIns(1,1,n,k+1);
				tail[k+c[xx][yy][0]].push_back(k+1);
			}
		}
		for(k=0;xx<=n && yy<=n;k++){
			for(i=0;i<(int)tail[k].size();i++)stDel(1,1,n,tail[k][i]);
			j=stQue(1,1,n,k+2-c[xx][yy][1],k+1);
			if(j)res=max(res,k+2-j);
		}
	}*/
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

