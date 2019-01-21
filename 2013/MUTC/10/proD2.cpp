#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 1100000
#define L 14

const int neg=0xc0c0c0c0;

int n;
int sum[N],ret[N],tail;
int sta[N],top;

char opt[L];

void insert(const int &wht){
	tail++;sum[tail]=sum[tail-1]+wht;
	ret[tail]=max(ret[tail-1],sum[tail]);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(sum,0,sizeof(sum));tail=top=0;
		memset(ret,0,sizeof(ret));ret[0]=neg;
		for(int i=0;i<n;i++){
			scanf("%s",opt);
			switch(opt[0]){
				case 'I':
					int wht;scanf("%d",&wht);
					insert(wht);
					break;
				case 'D':
					if(tail)tail--;
					break;
				case 'L':
					if(tail){
						sta[++top]=sum[tail]-sum[tail-1];
						tail--;
					}
					break;
				case 'R':
					if(top)insert(sta[top--]);
					break;
				case 'Q':
					int pos;scanf("%d",&pos);
					printf("%d\n",ret[pos]);
			}
		}
	}
	return 0;
}
