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

#define K 2
#define N 110000

typedef long long lld;

int n,best;
int c[N],s[N],key[N],id[N];
int pos[N][K];
int x,y,a,b;
lld val[N][K],ans;

int cmp(const int &i,const int &j){ return (c[i]!=c[j])?c[i]<c[j]:s[i]>s[j]; }

void work(){
	ans=0LL;
	memset(val,0xff,sizeof(val));
	for(int i=0;i<n;i++){ scanf("%d%d",&c[i],&s[i]);key[i]=i+1;id[i]=i; }
	sort(id,id+n,cmp);lld sum=0LL;int amount=0;
	for(int i=0;i<n;i++){
		if(i && c[id[i]]!=c[id[i-1]]){ sum=0LL;amount=0; }
		sum+=(lld)s[id[i]];amount++;
		if(sum>val[amount][0]){
			val[amount][1]=val[amount][0];
			pos[amount][1]=pos[amount][0];
			val[amount][0]=sum;
			pos[amount][0]=i-amount+1;
		}else if(sum>val[amount][1]){
			val[amount][1]=sum;
			pos[amount][1]=i-amount+1;
		}
	}
	for(int k=2;k<=n;k++){
		if(k&1){
			x=(k>>1)+1;y=k>>1;a=0;b=0;
			if(c[id[pos[x][0]]]==c[id[pos[y][0]]]){
				if(val[x][0]+val[y][1]>val[x][1]+val[y][0]){
					b=1;
				}else{
					a=1;
				}
			}
		}else{
			x=y=(k>>1);a=0;b=1;
		}
		if(val[x][a]<0 || val[y][b]<0)continue;
		if(ans<val[x][a]+val[y][b]){ ans=val[x][a]+val[y][b];best=k; }
	}
	cout<<ans<<endl;
	printf("%d\n",best);int k=best;
	
	if(k&1){
		x=(k>>1)+1;y=k>>1;a=0;b=0;
		if(c[id[pos[x][0]]]==c[id[pos[y][0]]]){
			if(val[x][0]+val[y][1]>val[x][1]+val[y][0]){
				b=1;
			}else{
				a=1;
			}
		}
	}else{
		x=y=(k>>1);a=0;b=1;
	}
	for(int i=0;i<best;i++){
		if(i)printf(" ");
		if((i&1)==0){
			printf("%d",key[id[pos[x][a]+(i>>1)]]);
		}else{
			printf("%d",key[id[pos[y][b]+(i>>1)]]);
		}
	}printf("\n");
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

