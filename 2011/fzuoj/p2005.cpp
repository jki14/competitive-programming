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

#define maxn 300
#define maxnum 300000
#define chr 30
#define maxlen 5200000

const int K='Z'-'A';

int n,res;
int route[maxnum][chr],fail[maxnum],flag[maxnum],num;
int que[maxnum],vis[maxnum],mk[maxnum];

char s[maxlen],ss[maxlen];

void strrev(char *s){
	int i,len=strlen(s);
	for(i=0;(i<<1)+2<=len;i++){
		swap(s[i],s[len-1-i]);
	}
}

void init(char *key,const int &d){
	int p,k;
	for(p=0;*key;key++){
		k=(*key)-'A';
		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p]=d;
}

void build(){
	int k,p,q,l,r;l=r=0;que[r++]=0;
	memset(fail,0,sizeof(fail));
	for(;l<r;l++){
		p=que[l];
		for(k=0;k<=K;k++){
			if(route[p][k]){
				que[r++]=route[p][k];
				if(p){
					for(q=fail[p];q && !route[q][k];)q=fail[q];
					fail[route[p][k]]=route[q][k];

					//printf("fail[%d]=%d\n",route[p][k],route[q][k]);
				}
			}
		}
	}
}

void search(char *pat){
	int k,p,q;
	for(p=0;*pat;pat++){
		k=(*pat)-'A';
		while(p && !route[p][k])p=fail[p];
		p=route[p][k];
		for(q=p;q && !vis[q];q=fail[q]){
			vis[q]=1;
			if(flag[q])mk[flag[q]]=1;
			
			//printf("q=%d fail[q]=%d\n",q,fail[q]);

		}
	}
}

void work(){
	int i,j,k,len;
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));res=0;
	memset(vis,0,sizeof(vis));
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++){
		scanf("%s",s);
		init(s,i);
	}
	build();
	scanf("%s",ss);len=strlen(ss);
	for(i=j=0;j<len;){
		if(ss[j]=='['){j++;
			for(k=0;ss[j]>='0' && ss[j]<='9';j++){
				k*=10;k+=ss[j]-'0';
			}
			while(k--)s[i++]=ss[j];
			j+=2;
		}else{
			s[i++]=ss[j++];
		}
	}s[i]=0;
	search(s);
	//puts(s);
	strrev(s);
	search(s);
	//puts(s);
	for(i=1;i<=n;i++)if(mk[i])res++;
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){scanf("%d",&n);
		work();
	}
	return 0;
}
