#include <cstdio>
#include <cstdlib>
#include <ctime>

const int T=20;

const int N=16;

char buf[32];

int main(){
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int n;
		n=rand()%N+1;
		if(_T==14)n=1;
		printf("%d\n", n);
		int r=_T%7+1;
		buf[n]=0;
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				if(_T!=11 && (rand()%r)==0)
					buf[i]='x';
				else buf[i]='o';
			}
			printf("%s\n", buf);
		}
	}
	return 0;
}
