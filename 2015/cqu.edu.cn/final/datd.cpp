#include <cstdio>
#include <cstdlib>
#include <ctime>

const int T=20;

const int N=10000;

int main(){
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int n, m;
		n=rand()%N+1;
		if(_T==1)n=1;
		m=rand()%N+1;
		if(_T==2)m=1;
		printf("%d %d\n", n, m);
		for(int k=0; k<m; k++){
			int p=rand()%10000+1;
			int t=rand()%2;
			if(_T==3)t=0;
			if(_T==4)t=1;
			printf("%d %d\n", p, t);
		}
	}
	return 0;
}
