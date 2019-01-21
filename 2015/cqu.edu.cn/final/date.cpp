#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int T=20;

const int N=1000;

int src[10086], dst[10086], enm;
int que[10086], wht[10086], idx[10086];

inline int cmp(const int x, const int y){ return wht[x]<wht[y]; }

inline void add_edge(const int u, const int v){
	src[enm]=u; dst[enm]=v; enm++;
}

int main(){
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int n=N, m, k=rand()%4+2;
		printf("%d %d\n", n, k);
		if(_T<=5)
			m=rand()%20+20;
		else if(_T<=10)
			m=rand()%100+100;
		else if(_T<=13)
			m=rand()%5+5;
		else if(_T<=18)
			m=rand()%1000+1;
		else if(_T<=19)
			m=2;
		else m=1;
		for(int i=0; i<n; i++){ wht[i]=rand();idx[i]=i; }
		sort(idx, idx+n, cmp);
		int tail=0, rem=n-1;
		que[tail++]=idx[0];
		enm=0;
		for(int i=0; i<tail; i++){
			if(!rem)continue;
			int nxt=rand()%min(rem+1, m+1);
			if(!nxt && i+1==tail)nxt=1;
			while(nxt--){
				add_edge(que[i], que[tail]=idx[tail]);
				tail++;
				rem--;
			}
		}
		for(int i=0; i<n; i++){ wht[i]=rand();idx[i]=i; }
		sort(idx, idx+n-1, cmp);
		for(int i=0; i<n-1; i++){
			if(rand()&1){
				printf("%d %d\n", src[idx[i]]+1, dst[idx[i]]+1);
			}else printf("%d %d\n", dst[idx[i]]+1, src[idx[i]]+1);
		}
	}
	return 0;
}
