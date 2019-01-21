//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
using namespace std;

char s[9][10]={"a", "ab", "aab", "aabb", "aaaba", "aaabab", "aaababb", "aaaababb", "aaaababba"};
char s1[]="babbaa";
void Solve()
{
	int m, n;
	scanf("%d%d", &m, &n);
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			printf("a");
		}
		printf("\n");
		return;
	} else if (m == 2) {
		if(n <= 9){
			printf("%s\n", s[n-1]);
		}else{
			printf("aaaa");
			for(int i = 0; i<n-6; ++i){
				printf("%c", s1[i%6]);
			}
			printf("\n");
		}
	} else {
		for(int i = 0; i<n; ++i){
			printf("%c", i%3+'a');
		}
		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		Solve();
	}
	printf("\n");
}
