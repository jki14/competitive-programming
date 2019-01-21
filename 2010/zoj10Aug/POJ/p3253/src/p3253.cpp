#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define lld long long

#define maxn 21000

struct myComp{
	bool operator () (const int &a,const int &b){
		return a>b;
	}
};

priority_queue<int,vector<int>,myComp> heap;
int n,tot;
lld res;

void work(){
	int u;
	res=(lld)0;tot=0;while(!heap.empty())heap.pop();
	for(int i=0;i<n;i++){ scanf("%d",&u);tot+=u;heap.push(u); }
	while(heap.size()>1){
		u=heap.top();heap.pop();u+=heap.top();heap.pop();heap.push(u);
		res+=(lld)u;
	}
	printf("%lld\n",res);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
