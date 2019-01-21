#include <cstdio>

inline int cap(const int x){ return 300+(x-1)*100; }

int main(){
	int n, l, e;
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &l, &e);
		e-=n;
		while(e<0){
			l--;
			e+=cap(l);
		}
		printf("%d %d\n", l, e);
	}
	return 0;
}
