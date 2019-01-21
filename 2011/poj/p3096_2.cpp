#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define chars 26
#define maxlen 100

const int intA=(int)'A';

struct trie{
	int val;
	struct trie *next[chars];
}*head;

typedef struct trie typeT;

char str[maxlen],pchar[2],num;

void Tins(typeT * &x){
	x=new typeT;
	x->val=-1;
	memset(x->next,NULL,sizeof(x->next));
}

int Tgetnum(char str[2]){
	typeT *p;p=head;int i=0;
	while(i<2){
		int k=str[i]-'A';
		if(p->next[k]==NULL)
			Tins(p->next[k]);
		p=p->next[k];
		i++;
	}
	if(p->val<num)
		p->val=num;
	else
		return 1;
	return 0;
}

int work(){
	int k,i,len=strlen(str);
	for(k=1;k<len;k++){
		for(i=0;i+k<len;i++){
			pchar[0]=str[i];
			pchar[1]=str[i+k];
			if(Tgetnum(pchar))return 1;
		}
		num++;
	}
	return 0;
}

int main(){
	head=new typeT;num=0;
	while(scanf("%s",str)!=EOF && str[0]!='*'){
		if(work())
			printf("%s is NOT surprising.\n",str);
		else
			printf("%s is surprising.\n",str);
	}
	return 0;
}

