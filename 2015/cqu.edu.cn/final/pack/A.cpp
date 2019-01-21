#include <cstdio>

int main(){
	int n, a;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d", &n);
		a=0;
		for(int i=0; i<n; i++){
			int x;scanf("%d", &x);
			if(x&1)a++;else a--;
		}
		printf("%c\n", a?'U':'B');
	}
	return 0;
}
