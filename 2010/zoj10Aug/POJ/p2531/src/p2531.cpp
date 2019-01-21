#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 30

int n,ans,sum,a[maxn][maxn];

void work(){
	memset(a,0,sizeof(a));
	int i,j,k,lmt,cut,sum=0;
	ans=LONG_MIN;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(i<j)sum+=a[i][j];
		}
	lmt=1<<n;
	for(k=0;k<lmt;k++){
		cut=0;
		for(i=0;i<n && sum-cut>ans;i++)
			for(j=i+1;j<n && sum-cut>ans;j++)
				if(((k&(1<<i))==0)==((k&(1<<j))==0))
					cut+=a[i][j];
		if(sum-cut>ans){
			//cout<<"update at k="<<k<<endl;
			//cout<<"sum="<<sum<<" cut="<<cut<<endl;
			ans=sum-cut;
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
