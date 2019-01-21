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

int n,k,root;
int lef[N],rig[N];

void insert(int &pos){
	
	//printf("pos=%d\n",pos);

	if(!pos){
		pos=k;
		return;
	}
	if(k<pos)
		insert(lef[pos]);
	else
		insert(rig[pos]);
}

void putout(const int &pos){
	if(!pos)return;
	if(pos==root)
		printf("%d",pos);
	else
		printf(" %d",pos);
	putout(lef[pos]);
	putout(rig[pos]);
}

void work(){
	memset(lef,0,sizeof(lef));
	memset(rig,0,sizeof(rig));
	scanf("%d",&k);root=k;
	/* Core */
	for(int i=1;i<n;i++){
		scanf("%d",&k);
		insert(root);
	}
	putout(root);
	printf("\n");
}


int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

