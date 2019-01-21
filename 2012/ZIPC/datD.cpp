#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

const int T = 10;
const int n = 200000;
const int m = 100;
const int K = 100000;
const int v = 100;

int main(){
	srand(time(NULL));
	printf("%d\n",T);
	for(int i=0;i<T;i++){
		int k=(rand()%K)+1;
		printf("%d %d %d\n",n,m,k);
		for(int j=0;j<n;j++)printf("%d ",(rand()%v)+1);printf("\n");
		for(int j=0;j<m;j++){
			int opt=rand()%3,x,y;
			if(opt==0){
				x=(rand()%n)+1;
				y=(rand()%v)+1;
			}else if(opt==1){
				x=(rand()%n)+1;
				y=(rand()%n)+1;
			}else{
				x=(rand()%(n-k+1))+1;
				y=rand()%(n-x+1);
				y=min(n,x+y);
			}
			printf("%d %d %d\n",opt,x,y);

		}
	}
	return 0;
}
