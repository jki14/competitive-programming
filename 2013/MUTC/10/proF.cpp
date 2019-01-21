#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define N 1100000

typedef long long lld;

int n;
lld x,y,sum;
lld a[N],s[N],f[N],g[N];

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>x>>y){
		s[n]=g[n]=0LL;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=n-1;i>=0;i--)s[i]=s[i+1]+a[i];sum=s[0];
		for(int i=n-1;i>=0;i--){
			f[i]=g[i+1]+s[i];
			g[i]=min(g[i+1],max(-s[i],x+y-sum+1-f[i]));
		}
		if(f[0]<=x)
			cout<<"ALICE"<<endl;
		else cout<<"BOB"<<endl;
	}
	return 0;
}
