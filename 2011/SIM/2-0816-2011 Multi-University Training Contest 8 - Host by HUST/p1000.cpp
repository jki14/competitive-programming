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
	double a, b, c;
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) printf("%.6f\n", (a*b-c*c) / (a+b+2*c));
	return 0;
}
