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
#include<set>
#include<map>
using namespace std;

//typedef long long lld;

#define S 2100000

int bas[9]= { 0,10,100,1000,10000,100000,1000000,10000000,100000000 };

int lef,rig,len;
int err[S];
int ans;

void core(){ans=0;
	scanf("%d%d",&lef,&rig);memset(err,0,sizeof(err));
	for(int val=lef;val<=rig;val++){
		len=(int)(log((double)val)/log(10.0));if(len<1)continue;
		int next=val;
		//printf("About %d\n",val);
		for(int i=0;i<len;i++){
			int dig=next / bas[len];
			next = (next - dig*bas[len]) * 10 + dig;
			if(next<=rig && next>val){
				if(err[next]!=val){ 
					//printf("\n Error %d %d\n",val,next); }
					err[next]=val;ans++;
				}
			}
		}
	}
	printf("%d",ans);
}

int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		core();
		printf("\n");
	}
	return 0;
}
