#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define head que[l]
#define tail que[r-1]

#define length (i-head)
#define val (sum[i]-sum[head])

#define maxn 210000

int TIMER,T;
int n,n2,m,res,len,src,tai;
int a[maxn],sum[maxn],que[maxn];

void work(){
	int i,l,r;for(i=0;i<n;i++){ scanf("%d",&a[i]);a[i+n]=a[i]; }
	n2=n*2;for(sum[0]=i=0;i<n2;i++){ sum[i+1]=sum[i]+a[i]; }
	l=r=0;res=sum[1];src=1;len=1;
	que[r++]=0;for(i=1;i<n+m;i++){
		while(head+m<i)l++;
		//cout<<" sum["<<i<<"]="<<sum[i]<<"      head="<<head<<endl;
		if(val>res){ res=val;src=head+1;len=length; }else
		if(val==res && head+1<src){ res=val;src=head+1;len=length; }else
		if(val==res && head+1==src && length<len){ res=val;src=head+1;len=length; }
		while(l<r && sum[tail]>=sum[i])r--;que[r++]=i;
	}
	tai=src+len-1;if(tai>n)tai-=n;
	printf("%d %d %d\n",res,src,tai);
}

int main(){
	int t;scanf("%d",&t);while(t--){
		scanf("%d%d",&n,&m);work();
	}
	return 0;
}
