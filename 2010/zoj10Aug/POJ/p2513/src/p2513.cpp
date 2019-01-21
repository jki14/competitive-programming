#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 610000
#define maxl 20
#define chars 30

const int inta=(int)'a';

struct trie{
	int val;
	struct trie *next[chars];
}*head;

int f[maxn],d[maxn],num;
char u[maxl],v[maxl];

void Tinti(struct trie * &x){
	x=new trie;
	x->val=-1;
	memset(x->next,NULL,sizeof(x->next));
}

int Tgetnum(char *str){
	struct trie *p;
	p=head;
	int i=0;
	while(str[i]){
		int a=(int)str[i]-inta;
		if(p->next[a]==NULL)
			Tinti(p->next[a]);
		p=p->next[a];
		i++;
	}
	if(p->val==-1){
		p->val=num++;
		f[p->val]=p->val;
	}
	return p->val;
}

int getf(int x){
	if(f[x]!=x)
		f[x]=getf(f[x]);
	return f[x];
}

void work(){
	int single=0,i,k,s,t;num=0;
	memset(d,0,sizeof(d));Tinti(head);
	while(scanf("%s%s",u,v)!=EOF){
		s=Tgetnum(u);t=Tgetnum(v);
		f[getf(t)]=getf(s);
		d[s]++;d[t]++;
	}
	for(i=0,k=getf(i);i<num;i++){
		if((d[i]&1)==1){ single++;if(single>2)break; }
		if(getf(i)!=k){ single=-1;break; }
	}
	if(single==0 || single==2)
		printf("Possible\n");
	else
		printf("Impossible\n");
}

int main(){
	work();
	return 0;
}
