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

#define N 5010
char dig[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
char str[N], pstr[N];

void add(int i) {
	i /= 16;
	printf("%c", dig[i/256]); printf("%c", dig[i/16%16]); printf("%c", dig[i%16]); printf("0:");
}

void trans(int i) {
	printf("%c", dig[i/16]); printf("%c", dig[i%16]);
}

void conduct()
{
	int i, j, sur, n;
	n = strlen(str);
	for (i = 0; i < n; ++i) {
		pstr[i] = str[i];
		if (pstr[i] >= 'A' && pstr[i] <= 'Z') pstr[i] += 'a'-'A';
		else if (pstr[i] >= 'a' && pstr[i] <= 'z') pstr[i] -= 'a'-'A';
	}
	for (i = 0; i < n; ++i) {
		if (i % 16 == 0) {
			if (i) { printf(" "); for (j = i-16; j < i; ++j) printf("%c", pstr[j]); printf("\n"); }
			add(i);
		} if (i%2 == 0) printf(" "); trans((int)str[i]);
	} sur = 16 - n%16; if (sur == 16) sur = 0;
	if (sur%2) printf("  "); for (i = 0; i < sur/2*5; ++i) printf(" ");
	printf(" "); for (i = n-16+sur; i < n; ++i) printf("%c", pstr[i]); printf("\n");
}

int main() {
	while (gets(str)) conduct();
	return 0;
}
