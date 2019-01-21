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

int n,m,x,y,k;
int a[N],b[N],u[N],v[N],ans;

int max(const int &x,const int &y){ return (x>y)?x:y; }
int min(const int &x,const int &y){ return (x<y)?x:y; }

void work(){ans=0;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)scanf("%d",&b[i]);
	for(int i=k=0;i<m;i++){if(k>=n)break;
		if(a[k]-x<=b[i] && b[i]<=a[k]+y){
			u[ans]=k++;v[ans]=i;ans++;
		}else if(b[i]>a[k]+y){ k++;i--; }
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)printf("%d %d\n",u[i]+1,v[i]+1);
}

int main(){
	while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
		work();
	return 0;
}
