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

const int T=1000;

int n;
char a[N],b[N];

void work(){
	n=random()%(100000-10)+10;
	for(int i=0;i<n;i++)a[i]='a'+random()%26;a[n]=0;

	int j=0;
	for(int i=0;i<n;i++){
		int k=random()%30+1;
		if(k<=20)
			b[j++]=a[i];
		else if(k<=25)
			b[j++]='?';
		else{
			k-=random()%100;
			b[j++]='*';
			for(;i<n && k;k--)i++;
		}
	}b[j++]=0;
	printf("%s\n%s\n",a,b);
}

int main(){
	srand(time(0));
	for(int t=0;t<T;t++)
		work();
	return 0;
}

