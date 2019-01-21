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

#define L 1100

char a[L];
		//  a   b   c   d   e
const char s[26]={ 'y','h','e','s','o'
		//  f   g   h   i   j
 		  ,'c','v','x','d','u'
	        //  k   l   m   n   o
		  ,'i','g','l','b','k'
		//  p   q   r   s   t
		  ,'r','z','t','n','w'
		//  u   v   w   x   y   z
		  ,'j','p','f','m','a','q' };


void core(){
	gets(a);for(int i=0;a[i];i++){
		if(a[i]==' ')continue;
		a[i]=s[a[i]-'a'];
	}
	printf("%s",a);
}

int main(){gets(a);
	int t;sscanf(a,"%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		core();
		printf("\n");
	}
	return 0;
}
