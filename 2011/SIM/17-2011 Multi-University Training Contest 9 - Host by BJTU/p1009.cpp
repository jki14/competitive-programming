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

#define N 10010
int a[N];
int n;

void conduct() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < 2*n; ++i) scanf("%d", &a[i]);
	for (i = 0, j = 1; j < n; ++i) j *= 2;
	printf("%d\n", i);
}

int main() {
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	} return 0;
}
