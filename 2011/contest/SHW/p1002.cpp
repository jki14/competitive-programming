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

char cmd[1010];
int n;

void conduct()
{
	int cur, pst, i, cnt;
	cur = pst = 0;
	for (i = 0; i < n; ++i) {
		scanf("%s%d", cmd, &cnt);
		if (!strcmp(cmd, "DROP")) {
			printf("DROP 2 %d\n", cnt);
			pst += cnt;
		} else {
			if (cur >= cnt) {
				printf("TAKE 1 %d\n", cnt);
				cur -= cnt;
			} else {
				if (cur) printf("TAKE 1 %d\n", cur);
				printf("MOVE 2->1 %d\nTAKE 1 %d\n", pst, cnt-cur);
				cur = pst + cur - cnt; pst = 0;
			}
		}
	}
}

int main()
{
	int time = 0;
	while (scanf("%d", &n) != EOF && n) {
		if (time) printf("\n"); else time = 1;
		conduct();
	} return 0;
}
