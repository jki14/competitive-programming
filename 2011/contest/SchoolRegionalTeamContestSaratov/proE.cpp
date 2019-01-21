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

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		printf("%d\n",(n&1)^1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


