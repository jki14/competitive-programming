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

#define maxn 11
#define maxm 510000
#define L 9
#define K 4

const int dx[K]={ 3,-1,1,-3 };
const char cd[K]={ 'd','l','r','u' };

int X;
int f[L][maxm],x[maxm],p[L][maxm],k;
char d[L][maxm],que[maxm];

map< int,int >m[L];
map< int,int >::iterator it;

char src[maxn],tar[maxn],s[maxm][maxn],sta[maxn];

int tra[maxn];

int T;

int allow(const int &x,const int &d){
	switch(d){
		case 0:
			return x<6;
		case 1:
			return x%3!=0;
		case 2:
			return x%3!=2;
		case 3:
			return x>2;
	}
	return 0;
}

void getstr(const int &x){
	for(int i=0;i<L;i++)
		sta[i]=s[x][i];
	sta[L]=0;
}

void putstr(const int &x){
	for(int i=0;i<L;i++)
		s[x][i]=sta[i];
	s[x][L]=0;
}

int s2i(){
	int i,k,ret;
	for(i=0;i<L;i++)if(sta[i]=='X'){
		sta[i]='0';k=i;break;
	}
	sscanf(sta,"%d",&ret);
	sta[k]='X';
	return ret;
}

void init(){
	int i,j;m[X].clear();
	k=0;f[X][k]=p[X][k]=0;d[X][k]=0;
	for(i=0;i<L;i++){
		if(i>X)sta[i]='0'+i-1;
		else if(i==X){
			sta[i]='X';
			x[k]=i;
		}else	sta[i]='0'+i;
	}sta[L]=0;
	//printf("sta=%s\n",sta);
	putstr(k);
	m[X].insert(pair<int,int>(s2i(),k));
	for(i=0;i<=k;i++){getstr(i);
		for(j=0;j<K;j++){
			if(!allow(x[i],j))continue;
			swap(sta[x[i]],sta[x[i]+dx[j]]);
			it=m[X].find(s2i());if(it!=m[X].end()){
				swap(sta[x[i]],sta[x[i]+dx[j]]);
				continue;
			}
			m[X].insert(pair<int,int>(s2i(),++k));
			f[X][k]=f[X][i]+1;x[k]=x[i]+dx[j];p[X][k]=i;d[X][k]=cd[j];putstr(k);
			
			//printf("STA=%s f=%d x=%d p=%d d=%c  by %s\n",sta,f[k],x[k],p[k],d[k],s[i]);
			swap(sta[x[i]],sta[x[i]+dx[j]]);
		}
	}
	/*printf("Case %d: %d\n",T,f[ans]);
	for(i=ans,j=0;i;i=p[i]){
		que[++j]=d[i];
	}
	for(;j;j--)printf("%c",que[j]);
	printf("\n");*/
}

void work(){
	int i,j;
	for(i=0;i<L;i++){
		if(tar[i]=='X'){X=i;tar[i]='0';break;}
	}
	sscanf(tar,"%d",&k);it=m[X].find(k);k=(*it).second;
	printf("Case %d: %d\n",T,f[X][k]);
	for(i=k,j=0;i;i=p[X][i])que[++j]=d[X][i];
	for(;j;j--)printf("%c",que[j]);printf("\n");
}

int main(){
	int i,t,k;scanf("%d",&t);
	for(X=0;X<L;X++)init();
	for(T=1;T<=t;T++){
		scanf("%s",src);
		for(i=k=0;i<L;i++){
			if(src[i]=='X')continue;
			tra[src[i]-'0']=++k;
			src[i]='0'+k;
		}
		scanf("%s",tar);
		for(i=0;i<L;i++){
			if(tar[i]=='X')continue;
			tar[i]='0'+tra[tar[i]-'0'];
		}
		work();
	}
	return 0;
}

