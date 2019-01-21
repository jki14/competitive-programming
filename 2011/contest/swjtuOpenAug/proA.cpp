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

#define maxn 2100

int T;

int n,opt;
char a[maxn];

void work(){T++;
	int i,ope;
	n=strlen(a);
	for(ope=opt=i=0;i<n;i++){
		if(a[i]=='{'){
			ope++;
		}else{
			if(ope)
				ope--;
			else{
				opt++;
				ope++;
			}
		}
	}
	opt+=ope/2;
	printf("%d. %d\n",T,opt);
}

int main(){T=0;
	while(scanf("%s",a)!=EOF && a[0]!='-')work();
	return 0;
}

