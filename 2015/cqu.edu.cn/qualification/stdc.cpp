#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int a[100001];
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		int k=-1;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
			if(i>0 && a[i]<a[i-1]) k=a[i-1];
		}
		n=n+a[0]-1;
		if(k==-1){
			int tmp=n-m;
			if(m>tmp && q>tmp){
				printf("1\n");
			}else{
				printf("-1\n");
			}
		}else{
			if(q>k) {printf("0\n");continue;}
			int tmp=n%k;
			int ans=n/k;
			if(tmp>=q) ans++;
			if(a[0]>q) ans--;
			printf("%d\n",ans);
		}
	}
	return 0;
}
