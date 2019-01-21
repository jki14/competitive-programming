#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int a[5010];
int n,k;
int cmp(const int &a,const int &b){
	return a>b;
}
int  main()
{
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		printf("%d\n",a[k-1]);
	}
	return 0;
}
