#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 110
#define maxm 11
#define maxl 30
#define q 26

int T;
int n,m,len;
int resval,res;
int mk[30],v[maxn];
char s[maxn][maxl];
char a[maxm][maxl];
char c;

int getp(const int &x){
	for(int i=0;i<len;i++)
		if(s[x][i]==c)return 0;
	return 1;
}

void work(){
	int i,j,k,mark;
	int x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<m;i++)scanf("%s",a[i]);
	printf("Case #%d:",T);
	for(i=0;i<m;i++){
		resval=-1;
		for(j=0;j<n;j++){len=strlen(s[j]);
			memset(v,0,sizeof(v));mark=0;
			//length clear
			for(x=0;x<n;x++)if(((int)strlen(s[x]))==len)v[x]=1;
			for(k=0;k<q;k++){c=a[i][k];
				memset(mk,0,sizeof(mk));
				for(x=0;x<n;x++)if(v[x])
					for(y=0;y<len;y++)mk[s[x][y]-'a']=1;
				if(!mk[c-'a'])continue;
				if(getp(j)){
					mark++;
					//cout<<"get mark at c="<<c<<endl;
					continue;
				}
				for(y=0;y<len;y++)
					if(s[j][y]==c)
						for(x=0;x<n;x++)if(v[x] && s[x][y]!=c)v[x]=0;
				for(x=0;x<n;x++)
					if(v[x])
						for(y=0;y<len;y++)
							if(s[x][y]==c && s[j][y]!=c)v[x]=0;
			}
			if(resval<mark){
				resval=mark;
				res=j;
			}
			//cout<<"mark["<<s[j]<<"]="<<mark<<endl;
		}
		printf(" %s",s[res]);
	}
	printf("\n");
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}
