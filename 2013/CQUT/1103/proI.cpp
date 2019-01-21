#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int n;while(scanf("%d",&n)!=EOF && n){
		int ans=0;
		for(int i=0;i<n;i++){
			int x;scanf("%d",&x);
			ans+=x*x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
