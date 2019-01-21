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

#define N 1000010
char str[N], ans[N];
char ss[10][10];
int pos[N];
int n, m;

int judge(int x) {
	if (x%2 || n-x < 3) return 0; int i;
	for ( i = 0; i < 3; ++i) if (str[x+i] != ss[0][i]) break; if (i == 3) return 1;
	for ( i = 0; i < 3; ++i) if (str[x+i] != ss[1][i]) break; if (i == 3) return 2;
	return 0;
}

void insert(char *ans, int x) {
	if (x%2) { ans[x] = '7'; ans[x+1] = '7'; }
	else { ans[x] = '4'; ans[x+1] = '4'; }
}

void trans(char *ans, int x, int use, int tot, bool tag) {
	for (int i = 0; i < 3; ++i) {
		ans[x+i] = ss[(int)(((bool)(max(tot-use, 0)%2))^tag)][i];
		//printf("%d:%c\n", x+i, ans[x+i]);
	}
}

void conduct()
{
	int cnt, i, j, k, ret;
	scanf("%s", str);
	for (cnt = i = 0; i < n; ++i) {
		if ((ret = judge(i))) {
			for (k = j = 0; j < cnt; ++j) {
				for (; k < pos[j]; ++k) ans[k] = str[k];
				if (j < m) insert(ans, pos[j]);
				else { ans[k] = str[k]; ans[k+1] = str[k+1]; } k += 2;
			} for (; k < i; ++k) ans[k] = str[k]; trans(ans, k, cnt, m, (bool)(ret-1)); k += 3;
			//printf("k:%d n:%d\n", k, n);
			for (; k < n; ++k) ans[k] = str[k]; break;
		} else if (i && str[i] == '7' && str[i-1] == '4') pos[cnt++] = i-1;
	} 
	if (i == n) {
		for (k = j = 0; j < cnt; ++j) {
			for (; k < pos[j]; ++k) ans[k] = str[k];
			if (j < m) insert(ans, pos[j]);
			else { ans[k] = str[k]; ans[k+1] = str[k+1]; } k += 2;
		} for (; k < n; ++k) ans[k] = str[k];
	} ans[n] = '\0'; printf("%s\n", ans);
}

int main()
{
	strcpy(ss[0], "447"); strcpy(ss[1], "477");
	while (scanf("%d%d", &n, &m) != EOF) conduct();
	return 0;
}
