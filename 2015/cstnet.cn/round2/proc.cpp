#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long lld;

template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }
template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

#define N 110000
#define M 24

const int inf=0x3f3f3f3f;

int n,m;
int arr[N],a[N],r[M];
lld cnt[M],sum[M],lef[M];
int id[M];
lld ans,buf;

void merge(int A[],int p, int q, int r);
void mergeSort(int A[],int p, int r);

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    for(int i = 0; i < n1; i++)L[i] = A[p + i];
    for(int i = 0; i < n2; i++)R[i] = A[q + 1 + i];
    L[n1] = inf;
    R[n2] = inf;

    int i = 0, j = 0;
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            buf += n1 - i;
        }
    }
}

void mergeSort(int A[], int p, int r) {
    if(p >= r)return; 
    int q = (p + r) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r); 
    merge(A, p, q, r);
}

inline int cmp(const int x, const int y){
	if(!cnt[x])return 0;
	if(!cnt[y])return 1;
	return sum[x]<sum[y];
}

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		printf("Case #%d: ",_T);
		scanf("%d%d",&n,&m);ans=inf;
		memset(cnt,0,sizeof(cnt));
		memset(lef,0,sizeof(lef));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);a[i]--;
			cnt[a[i]]++;//sum[a[i]]+=i;
		}
		memset(sum,0x3f,sizeof(sum));
		for(int i=0;i<n;i++){
			if(sum[a[i]]<inf)continue;
			lef[a[i]]++;
			if((lef[a[i]]<<1)>=cnt[a[i]])sum[a[i]]=i;
		}
		for(int i=0;i<m;i++){ id[i]=i; }
		sort(id,id+m,cmp);
		for(int i=0;i<m;i++)r[id[i]]=i;
		//do{
		for(int i=0;i<n;i++)arr[i]=r[a[i]];
		buf=0LL;
        	mergeSort(arr, 0, n - 1);
		UPDMIN(ans,buf);
		//}while(next_permutation(r,r+m));
		printf("%lld\n",ans);
	}
	return 0;
}

