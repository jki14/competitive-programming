#include <cstdio>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	printf("1\n%d %d\n", n, k);
	for(int i=1; i<n; i++)
		printf("%d %d\n", (i+1)>>1, i+1);
	return 0;
}
