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
char str1[N], str2[N];
int a[N], b[N], c[N], d[N], e[N];

void getnum(char *str, int *seq) {
	int i, n;
	seq[0] = n = strlen(str); seq[n+1] = 0;
	for (i = 0; i < n; ++i) seq[n-i] = str[i]-'0';
	while (seq[0]>1 && !seq[seq[0]]) seq[0]--;
}

int cmp(int pos) {
	for (int i = 0; i < b[0]; ++i) {
		if (a[pos-i]>b[b[0]-i]) return 1;
		if (a[pos-i]<b[b[0]-i]) return -1;
	} return 0;
}
int cmp2(int *a, int *b) {
	if (a[0] < b[0]) return -1; if (a[0] > b[0]) return 1;
	for (int i = 0; i < a[0]; ++i) {
		if (a[a[0]-i]<b[b[0]-i]) return -1;
		if (a[a[0]-i]>b[b[0]-i]) return 1;
	} return 0;
}
void assgn(int *a, int *b) {
	for (int i = 0; i <= b[0]; ++i) a[i] = b[i];
}

void construct(int pos, int add, int *seq) {
	for (int i = 0; i <= a[0]; ++i) seq[i] = a[i]; seq[a[0]+1] = 0;
	for (int i = pos+1; add>0 && i <= seq[0]+1; ++i) {
		seq[i] += add; add = seq[i]/10; seq[i] %= 10;
	} for (int i = 0; i < b[0]; ++i) seq[pos-i] = b[b[0]-i];
	for (int i = 1; i <= pos-b[0]; ++i) seq[i] = 0;
	if (seq[seq[0]+1]) seq[0]++;
}

void sub(int *a, int *b, int *c) {
	int n, m, i;
	n = min(a[0], b[0]); m = 0;
	for (i = 0; i <= a[0]; ++i) c[i] = a[i];
	for (i = 1; i <= n; ++i) {
		c[i] = a[i]+m-b[i];
		if (c[i]<0) { c[i]+=10; m=-1; }
		else m = 0;
	} for (; m < 0; ++i) {
		c[i]--;
		if (c[i]<0) { c[i]+=10; m=-1; }
		else m = 0;
	} while (c[0]>1 && !c[c[0]]) c[0]--;
}

void print(int *a) {
	for (int i = a[0]; i > 0; --i) printf("%d", a[i]);
	printf("\n");
}

void conduct() {
	int i, val, n;
	scanf("%s", str1); scanf("%s", str2);
	getnum(str1, a); getnum(str2, b);
	if (a[0]<b[0] || (a[0] == b[0] && cmp2(a, b)<=0)) {
		sub(b, a, c); print(c); return;
	} c[0] = N; if (b[0]==1 && b[1] == 0) n = a[0]; else n = a[0]+1;
	for (i = b[0]; i <= n; ++i) {
		val = cmp(i);
		if (val > 0) construct(i, 1, e);
		else if (val < 0) construct(i, 0, e);
		else assgn(e, a);
		//printf("e: "); print(e); printf("a: "); print(a);
		sub(e, a, d); if (cmp2(d, c)<0) assgn(c, d);
	} print(c);
}


int main() {
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	} return 0;
}
