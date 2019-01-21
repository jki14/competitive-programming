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
#define maxn 400
#define maxm maxn*maxn
#define clr(x) memset(x,0,sizeof(x));
struct newtype{
	int u,d,l,r,head,bl,br;
};
newtype p[4000];
int root=0,ans[82],num[maxn];
int m,n,sum=0;

void init(){
	newtype a;
	root=0;sum=0;
	a.r=0;a.l=0;
	p[sum]=a;
	root=0;clr(ans);clr(num);
}
void add(const int i,const int j){
	newtype a;sum++;
	if(i!=-1)
	{
		a.u=p[i].u;a.d=i;
		p[p[i].u].d=sum;p[i].u=sum;
		a.head=p[i].head;
	}
	else
	{
		a.u=sum;a.d=sum;
		a.head=sum;
	}
	if(j!=-1)
	{
		a.l=p[j].l;a.r=j;
		p[p[j].l].r=sum;p[j].l=sum;
	}
	else
	{
		a.l=sum;a.r=sum;
	}
	p[sum]=a;
	num[a.head]++;
}
void remove(int i){
	p[p[i].r].l=p[i].l;p[p[i].l].r=p[i].r;
	int j,k;
	for(j=p[i].d;j!=i;j=p[j].d){
		for(k=p[j].r;k!=j;k=p[k].r){
			p[p[k].d].u=p[k].u;
			p[p[k].u].d=p[k].d;
			num[p[k].head]--;
		}
	}
}
void resume(int i){
	int j,k;
	for(j=p[i].d;j!=i;j=p[j].d){
		for(k=p[j].r;k!=j;k=p[k].r){
			p[p[k].d].u=k;p[p[k].u].d=k;
			num[p[k].head]++;
		}
	}
	p[p[i].r].l=i;p[p[i].l].r=i;
}
bool dfs(int i){
	if(p[root].r==root){
		return true;
	}
	int j,k,l;k=p[root].r;
	for(j=p[root].r;j!=root;j=p[j].r)
		if(num[j]<num[k])
			k=j;
	remove(k);
	for(j=p[k].d;j!=k;j=p[j].d){
		ans[p[j].bl]=p[j].br;
		for(l=p[j].r;l!=j;l=p[l].r)
			remove(p[l].head);
		if(dfs(i+1)==true)
			return true;
		else 
		{
			for(l=p[j].l;l!=j;l=p[l].l)
				resume(p[l].head);
		}
	}
	resume(k);
	return false;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	string a;
	char ch;
	int i,j,k;
	do{
		char ch;
		do{
			scanf("%c",&ch);
		}while((ch!='e')&&((ch>'9')||(ch<'1'))&&(ch!='.'));
		if(ch=='e')break;
		init();
		for(j=1;j<=9;j++)
			for(k=1;k<=9;k++)
				add(-1,root);
		for(j=1;j<=9;j++)
			for(k=1;k<=9;k++)
				add(-1,root);
		for(j=1;j<=9;j++)
			for(k=1;k<=9;k++)
				add(-1,root);
		for(i=1;i<=81;i++)
			add(-1,root);
		for(i=1;i<=81;i++){
			if(ch=='.'){
				for(j=1;j<=9;j++)
				{
					int x=(i-1)/9+1,y=(i-1)%9+1;
					add(x*9-9+j,-1);p[sum].bl=i;p[sum].br=j;
					add(y*9-9+j+81,p[sum].r);p[sum].bl=i;p[sum].br=j;
					add((((x-1)/3)*3+((y-1)/3+1))*9-9+j+162,p[sum].r);p[sum].bl=i;p[sum].br=j;
					add(i+243,p[sum].r);p[sum].bl=i;p[sum].br=j;
				}
			}
			else{
				j=int(ch)-int('0');
				int x=(i-1)/9+1,y=(i-1)%9+1;
					add(x*9-9+j,-1);p[sum].bl=i;p[sum].br=j;
					add(y*9-9+j+81,p[sum].r);p[sum].bl=i;p[sum].br=j;
					add((((x-1)/3)*3+((y-1)/3+1))*9-9+j+162,p[sum].r);p[sum].bl=i;p[sum].br=j;
					add(i+243,p[sum].r);p[sum].bl=i;p[sum].br=j;
			}
			scanf("%c",&ch);
		}
		dfs(0);
		for(i=1;i<=81;i++)
			printf("%d",ans[i]);
		printf("\n");
	}while(true);
	return 0;
}
