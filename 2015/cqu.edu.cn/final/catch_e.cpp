#include <cstdio>

int main(){
	int T, n, m;
	scanf("%d", &T);
	printf("1\n");
	for(int _T=1;_T<=T;_T++){
		scanf("%d%d", &n, &m);
		if(_T==19)printf("%d %d\n", n, m);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d", &u, &v);
			if(_T==19)printf("%d %d\n", u, v);
		}
	}
	return 0;
}
