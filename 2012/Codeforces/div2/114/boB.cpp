#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

const int N = 1100000;
char str[N], ln[N], n;

int judge() {
	int n = strlen(str); int i;
	for (i = 0; i < n; ++i) if (str[i] != ' ') break;
	if (str[i] == '#') return 1; else return 0;
}

void cat() {
	int m = strlen(str);
	for (int i = 0; i < m; ++i) if (str[i] != ' ') {
		ln[n++] = str[i];
		if (n>1060000){ while(true); }
	}
//	printf("str:%s\n", str); printf("n:%d ln:%s\n", n, ln);
	ln[n] = 0;
}

void print() {
	for (int i = 0; i < n; ++i) putchar(ln[i]);
	putchar('\n');
}

int main() {
	int cnt, m;
	cnt = 0; n = 0;
	while (gets(str)) {
		if (judge()) {
			if (cnt) print(); cnt = 0; n = 0;
			m = strlen(str);
			for (int i = 0; i < m; ++i) putchar(str[i]);
			putchar('\n');
		} else { cnt++; cat(); }
	}  if (cnt) { print(); }
	return 0;
}
