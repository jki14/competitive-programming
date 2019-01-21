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

#define N 200010
long long a[N], b[N];
int n;

void input()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%lld%lld", &a[i], &b[i]);
}

void conduct()
{
	int i;
	long long sa, sb, sum;
	sa = 0; sb = 0; sum = 0;
	for (i = 1; i <= n; ++i) { sum += a[i] * sb + b[i] * sa; sa += a[i]; sb += b[i]; }
	printf("%lld\n", sum);
}

int main()
{
	int time;
	scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case %d: ", i);
		input();
		conduct();
	}
	return 0;
}
