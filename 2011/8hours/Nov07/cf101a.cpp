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
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 110000
#define C 26

int n,k,a[C],id[C],num;
char s[N];

int cmp(const int &x,const int &y){
	 return a[x]<a[y];
}

void work(){
	n=strlen(s);memset(a,0,sizeof(a));
	for(int i=0;s[i];i++)a[s[i]-'a']++;
	scanf("%d",&k);for(int i=0;i<C;i++)id[i]=i;
	sort(id,id+C,cmp);num=C;
	for(int i=0;i<C;i++){
		int d=min(k,a[id[i]]);
		a[id[i]]-=d;
		k-=d;if(!a[id[i]])num--;
	}
	printf("%d\n",num);
	for(int i=0;i<n;i++)if(a[s[i]-'a'])printf("%c",s[i]);
	printf("\n");
}

int main(){
	while(scanf("%s",s)!=EOF)
		work();
	return 0;
}

