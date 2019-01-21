#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 510000
#define d s[h]
#define fth a[a[d].pnt]

struct vtr{
	int val;
	struct vtr *next;
}*c[maxn],*p;

struct node{
	int pnt,k,l,f;
}a[maxn];

int n,L,R;
int s[maxn],h,t;

void work(){
	int i,u,v,l;
	a[0].k=0;a[0].l=0;a[0].pnt=0;
	for(i=0;i<n;i++)c[i]=NULL;
	for(i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&l);
		a[v].l=l;a[v].pnt=u;
		p=new vtr();p->val=v;p->next=c[u];c[u]=p;
	}
	h=0;t=1;s[h]=0;
	while(h<t){
		a[d].k=fth.k^1;
		a[d].f=-1;
		a[d].l+=fth.l;
		if(c[d]){
			p=c[d];
			while(p){
				//cout<<"C<-f "<<p->val<<"<-"<<a[p->val].pnt<<endl;
				s[t++]=p->val;
				p=p->next;
			}
		}
		else{
			if(a[d].l<L || a[d].l>R)
				a[d].f=-1;
			else
				a[d].f=a[d].l;
			//cout<<"End Point is "<<a[p].f<<endl;
		}
		h++;
	}
	h=t-1;
	while(h>0){
		if(a[d].f>=0){
			if(fth.f==-1)
				fth.f=a[d].f;
			else{
				if(fth.k){
					if(fth.f<a[d].f)fth.f=a[d].f;
				}
				else{
					if(fth.f>a[d].f)fth.f=a[d].f;
				}
			}
		}
		h--;
	}
	if(a[0].f>0)
		printf("%d\n",a[0].f);
	else
		printf("Oh, my god!\n");
}

int main(){
	while(scanf("%d%d%d",&n,&L,&R)!=EOF)
		work();
	return 0;
}
