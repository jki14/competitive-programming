#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

int T;
int n,res;
char a[10];

void work(){
	T++;
	scanf("%d",&n);
	int x,y,o,b,k;
	x=y=0;
	o=b=1;
	while(n--){
		scanf("%s%d",a,&k);
		switch(a[0]){
			case 'O':
				x+=abs(k-o);
				o=k;
				x=max(x,y)+1;
				break;
			case 'B':
				y+=abs(k-b);
				b=k;
				y=max(x,y)+1;
				break;
		}
	}
	res=max(x,y);
	printf("Case #%d: %d\n",T,res);
}

int main(){
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int t;scanf("%d",&t);T=0;
	while(t--)work();
	fclose(stdin);fclose(stdout);
	return 0;
}

