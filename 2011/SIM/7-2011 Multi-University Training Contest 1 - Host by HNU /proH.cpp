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

int main()
{
	int i, j, k, n;
	long long ans;
	while (scanf("%d", &n) != EOF) {
		j = sqrt((double)n); ans = 0;
		if (j*j == n) ans += 4; else j += 1;
		for (i = 1; i < j; ++i) {
			k = sqrt((double)n - i*i); 
			if (i*i + k*k == n) {
				j = k;
				if (i == k) ans += 4; else ans += 8;
			}
		}
		printf("%lld\n", ans);
	}
}
