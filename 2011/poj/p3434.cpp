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
#include<queue>
#include<deque>
using namespace std;

#define maxC 30
#define maxn 1100
#define S 11000
#define B 4
#define K 3

const int dx[B]={ -1,0,1,0 };
const int dy[B]={ 0,1,0,-1 };

const int db[K]={ 1,2,1 };

int n,m,c[maxC];
char a[maxn][maxn];
int hx[maxn],hy[maxn],b[maxn];
int que[maxC],qx[S],qy[S],r;

int bx[maxC][S],bu[maxC],bv[maxC];
int by[maxC][S];

int getb(const int &x,const int &y,const char &key){
	for(int i=0;i<B;i++)
		if(a[x+dx[i]][y+dy[i]]==key)return (i+2)%B;
	return 0;
}

void search(const int &x,const int &y,const int &k,const int &f){
	int i;char key='a'+k;
	qx[r]=x;qy[r++]=y;
	for(i=0;i<B;i++){
		if(i==f)continue;
		if(a[x+dx[i]][y+dy[i]]==key){
			search(x+dx[i],y+dy[i],k,(i+2)%B);
			return;
		}
	}

}

void outa(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
	//printf("\n");
}

void work(){
	int i,j,k,bk;
	int x,y;
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++){
		scanf("%s",a[i]);
		for(j=n;j>=1;j--)a[i][j]=a[i][j-1];
		a[i][0]='#';a[i][n+1]='#';
	}
	for(i=0;i<=n;i++)a[0][i]=a[n+1][i]='#';
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(a[i][j]<='Z' && a[i][j]>='A'){
				k=a[i][j]-'A';
				c[k]=1;
				hx[k]=i;hy[k]=j;b[k]=getb(i,j,'a'+k);
				
				//printf("The %c B=%d\n",'A'+k,b[k]);

				bu[k]=bv[k]=0;
				r=0;search(i,j,k,b[k]);
				for(r--;r>=0;r--){
					//printf("bx[%d].size()=%d\n by[%d].size()=%d\n",k,bx[k].size(),k,by[k].size());
					//bx[k].push(qx[r]);
					bx[k][bv[k]]=qx[r];
					by[k][bv[k]]=qy[r];
					bv[k]++;
				}
				//reverse(bx[k].begin(),bx[k].end());
				//reverse(by[k].begin(),by[k].end());
				
				/*printf("Check Vector %c\n",'A'+k);
				for(x=0;x<(int)bx[k].size();x++){
					printf("  %d %d\n",bx[k][x],by[k][x]);
				}*/

			}
		}
	for(r=i=0;i<maxC;i++)if(c[i])que[r++]=i;
	while(m--){bk=1;
		for(j=0;j<r;j++){k=que[j];
			for(i=0;i<K;i++){
				x=hx[k]+dx[b[k]];y=hy[k]+dy[b[k]];
				if(a[x][y]=='.'){bk=0;
					a[x][y]='A'+k;
					a[hx[k]][hy[k]]='a'+k;
					a[bx[k][bu[k]]][by[k][bu[k]]]='.';
					bx[k][bv[k]]=x;by[k][bv[k]]=y;
					bv[k]++;bv[k]%=S;
					bu[k]++;bu[k]%=S;
					hx[k]=x;hy[k]=y;
					//outa();
					break;
				}
				b[k]=(b[k]+db[i])%B;
			}
		}
		if(bk)break;
	}
	outa();
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

