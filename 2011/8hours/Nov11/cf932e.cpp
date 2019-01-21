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

#define N 2100

char a[N][N];
int n,ans,r0[N],c0[N],r1[N],c1[N];

void nex(int &i,int &j){
	i++;j++;
	if(j==n){ j=n-i-1;i=0; }
	if(i==n){ i=n-j-1;j=0; }
}

void work(){ans=0;
	for(int i=0;i<n;i++)
		scanf("%s",a[i]);
	memset(r0,0,sizeof(r0));
	memset(c0,0,sizeof(c0));
	memset(r1,0,sizeof(r1));
	memset(c1,0,sizeof(c1));
	/* First */
	for(int i=0,j=n-1;i!=j;nex(i,j)){
		int opt=r0[i]^c0[j],tar=(a[i][j]=='1');
		if(opt!=tar){
			//printf("OPT %d %d\n",i+1,j+1);
			ans++;r0[i]^=1;c0[j]^=1;
		}
	}
	/* Second */
	for(int i=n-1,j=0;i!=j;nex(i,j)){
		int opt=r1[i]^c1[j],tar=(a[i][j]=='1');
		if(opt!=tar){
			//printf("OPT %d %d\n",i+1,j+1);
			ans++;r1[i]^=1;c1[j]^=1;
		}
	}
	/* Final */
	for(int i=0;i<n;i++){
		int opt=r0[i]^c0[i]^r1[i]^c1[i],tar=(a[i][i]=='1');
		//printf("opt=%d tar=%d a[][]=%c\n",opt,tar,a[i][i]);
		if(opt!=tar){
			//printf("OPT %d %d\n",i+1,i+1);
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
