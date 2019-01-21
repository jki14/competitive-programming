#include <cstdio>
#include <cstdlib>
#include <ctime>

const int T=20;

const int N_LOW=896;
const int N_HIG=1024;

const int V_LOW=1;
const int V_HIG=1024;

int main(){
	int B=0;
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int r=rand()%3;
		int n=N_LOW+rand()%(N_HIG-N_LOW+1);
		if(r<2){
			printf("%d\n", n);
			for(int i=0; i<n; i++){
				int v=V_LOW+rand()%(V_HIG-V_LOW+1);
				if(i)printf(" ");
				printf("%d", v);
			}
			printf("\n");
		}else{
			B++;
			n&=0xffffffff-1;
			printf("%d\n", n);
			int count=0;
			for(int i=0; i<n; i++){
				int v=V_LOW+rand()%(V_HIG-V_LOW+1);
				if(rand()%(n-i)<n/2-count){
					//odd
					count++;
					v|=1;
				}else{
					//even
					v&=0xffffffff-1;
				}
				if(i)printf(" ");
				printf("%d", v);
			}
			printf("\n");
		}
	}
	return B;
}
