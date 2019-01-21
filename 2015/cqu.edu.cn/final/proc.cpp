#include <cstdio>

#define N 32
#define K 8

const int dx[K] = {1,1,-1,-1,2,2,-2,-2};
const int dy[K] = {1,-1,1,-1,2,-2,2,-2};

int n;
char a[N][N], b[N][N];

int main(){
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=0; i<n; i++)scanf("%s", b[i]);
		for(int x=0; x<n; x++){
			for(int y=0; y<n; y++){
				if(b[x][y]=='x'){
					a[x][y]='x';
					continue;
				}
				a[x][y]='0';
				for(int i=0; i<K; i++){
					int r=x+dx[i], c=y+dy[i];
					if(r<0 || r>=n)continue;
					if(c<0 || c>=n)continue;
					if(b[r][c]=='x')a[x][y]++;
				}
			}
			a[x][n]=0;
			printf("%s\n",a[x]);
		}
	}
	return 0;
}
