#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 1100000
#define P 10

int n,sum,d,a[N];
char _a[N];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",_a);n=strlen(_a);a[n]=0;
		for(int i=sum=0;i<n;i++){
			sum+=a[i]=_a[n-i-1]-'0';
		}
		sum%=10;d=10-sum;if(a[0]+d<P){
			a[0]+=d;
		}else{
			d=(d+a[0])%10;
			int i=1;while(a[i]==9){
				d=(d+a[i])%10;
				a[i++]=0;
			}
			a[i]++;a[0]=((d-1)%10+10)%10;
		}
		for(int i=(a[n]?n:n-1);i>=0;i--){
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
