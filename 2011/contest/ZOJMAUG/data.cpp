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
	int x, y;
	printf("49999 1 1\n");
	for (int i = 0; i < 50000; ++i) {
		x = (rand() % 30000) * (rand() % 30000) - 900000000;
		y = (rand() % 30000) * (rand() % 30000) - 900000000;
		x = 100000; y = 100000;
		printf("%d %d\n", x, y);
	}
}

