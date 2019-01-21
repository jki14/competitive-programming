#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1100000

int n,fail[maxn];
char s[maxn];

void makefail(char *s,int slen){
    for(int i=0,j=-1;i<=slen;i++,j++){
    	fail[i]=j;
        while(j!=-1 && s[i]!=s[j])j=fail[j];
    }
}

void work(){
	int i;
	scanf("%s",s);
	makefail(s,n);
	//puts(s);
	for(i=1;i<=n;i++){
		//cout<<" fail["<<i<<"] = "<<fail[i]<<endl;
		if(fail[i] && i%(i-fail[i])==0)
			printf("%d %d\n",i,(int)i/(i-fail[i]));
	}
}


int main(){
	int t=1;
	while(scanf("%d",&n) && n){
		printf("Test case #%d\n",t++);
		work();
		printf("\n");
	}
	return 0;
}
