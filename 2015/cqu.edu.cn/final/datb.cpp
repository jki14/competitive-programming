#include <cstdio>
#include <cstdlib>
#include <ctime>

const int T=100;

const int N=10000;

inline int exp_cap(const int x){ return 300+(x-1)*100; }

inline int exp_sum(const int x, const int y){
	int buf=y;
	for(int i=1; i<x; i++)buf+=exp_cap(i);
	return buf;
}

int main(){
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int n, x, y;
		n=rand()%(N+1);
		if(_T==14)n=0;
		do{
			x=rand()%99+1;
			y=rand()%exp_cap(x);
		}while(n>exp_sum(x, y));
		if(_T==21)n=y;
		if(_T==22)n=y+1;
		printf("%d %d %d\n", n, x, y);
	}
	return 0;
}
