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

const double eps = 1e-6;

void conduct() {
	int t, k, num1, num2; double ans1, ans2;
	scanf("%d%d", &k, &t);
	ans1 = t / 5.0 * 2.0; ans2 = t / 4.0 * 2.5;
	if (k > 3 && k <= 10) { ans1 += (k-3) * 2.0; ans2 += (k-3) * 2.5; }
	else if (k > 10) { ans1 += 14.0 + (k-10) * 3.0; ans2 += 17.5 + (k-10) * 3.75; }
	num1 = (int)(ans1+0.5+eps); num2 = (int)(ans2+0.5+eps);
	printf("%d\n", num2-num1);
}

int main() {
	int time; scanf("%d", &time);
	while (time--) conduct();
	return 0;
}
