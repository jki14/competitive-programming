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

#define N 1010
int a[N];

int main()
{
	int i, n, m;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) != EOF ) {
		for (i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (i = m-1; !a[i]; i = (i+1)%n);
		printf("%d\n", i+1);
	} fclose(stdin); fclose(stdout); return 0;
}
