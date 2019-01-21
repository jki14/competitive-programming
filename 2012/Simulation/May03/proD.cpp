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

#define LEN 12
char str[LEN+10];
int a[LEN], b[LEN], tag[LEN];
int n;

void conduct() {
	int i, j, k;
	scanf("%d", &n);
	scanf("%s", str); for (i = 0; i < LEN; ++i) a[i] = str[i];
	sort(a, a+12); memset(tag, 1, sizeof(tag));
	for (i = 1; i < n; ++i) {
		scanf("%s", str);
		for (j = 0; j < LEN; ++j) b[j] = str[j]; sort(b, b+12);
		j = 0; k = 0;
		while (j < 12 && k < 12) {
			while (j < 12 && a[j] < b[k]) { tag[j] = 0; ++j; }
			while (k < 12 && b[k] < a[j]) ++k;
			while (j < 12 && k < 12 && a[j] == b[k]) { ++j; ++k; }
		} for (; j < 12; ++j) tag[j] = 0;
	} for (i = j = 0; i < 12; ++i) if (tag[i]) str[j++] = a[i]; str[j] = '\0';
	printf("%s\n", str);
}

int main() {
	int time; scanf("%d", &time);
	while (time--) conduct();
	return 0;
}
