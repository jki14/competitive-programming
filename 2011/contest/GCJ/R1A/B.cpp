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
#define maxlen 30
#define Q 26

int T;

int n,m,k,kk,p,len;
int resval,res,c1,c2,mark;
int sc[maxn],d[maxn],h;
int cp[maxn][maxlen];
char c;
char s[maxn][maxlen];
char a[maxm][maxlen];

void work(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<m;i++)scanf("%s",a[i]);
	memset(sc,0,sizeof(sc));
	memset(cp,0,sizeof(cp));
	for(i=0;i<n;i++)
		for(j=0,len=strlen(s[i]);j<len;j++){
			c=s[i][j];c1=c-'a';c2=(1<<c1);
			sc[i]|=c2;
			cp[i][c1]|=(1<<j);
		}
	printf("Case #%d:",T);
	for(k=0;k<m;k++){
		resval=-1;
		for(p=0;p<n;p++){len=strlen(s[p]);memset(d,0,sizeof(d));mark=0;
			for(i=0;i<n;i++)if(len==(int)strlen(s[i]))d[i]=1;
			for(kk=0;kk<Q;kk++){c=a[k][kk];c1=c-'a';h=0;c2=(1<<c1);
				for(i=0;i<n;i++){
					if(d[i])h|=sc[i];
				}
				if((h&c2)==0){
					continue;
				}
				if((sc[p]&c2)==0){
					mark++;
					for(i=0;i<n;i++)
						if(d[i] && (sc[i]&c2)!=0)d[i]=0;
					continue;
				}
				for(i=0;i<n;i++)if(d[i] && cp[i][c1]!=cp[p][c1])d[i]=0;
			}
			if(resval<mark){
				resval=mark;res=p;
			}
		}
		printf(" %s",s[res]);
	}
	printf("\n");
}

int main(){
	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

