#ifdef _WIN32
#  define LL "%I64d"
#else
#  define LL "%Ld"
#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <complex>
#include <utility>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
#define MOD 1000000007
ll N,M,K;
ll _C[110][110];
void init(){
  for(int i=0;i<110;++i){
   _C[i][0] = _C[i][i] = 1;
   for(int j=1;j<i;++j){
    _C[i][j] = _C[i-1][j] + _C[i-1][j-1];
    if(_C[i][j] >= MOD)_C[i][j] -= MOD;
                       }
                        }
}
ll POW(ll w , ll step){
  ll ret = 1;
  for(;step>0;step>>=1 , w = (w*w)%MOD)
   if(step&1)ret = (ret*w)%MOD;
  return ret;
}
ll dp[110][10010];
ll take[110];
int main(){
  init();
  cin>>N>>M>>K;
  dp[0][0] = 1;
  for(int i=1;i<=N;++i){
   ll cnt = M/N;
   if(M%N >= i)++cnt;
   for(int I=0;I<=N;++I)
    take[I] = POW(_C[N][I] , cnt);
   for(int ALL=0;ALL<=K;++ALL){
    int MAX = min((ll)ALL , N);
    ll& T = dp[i][ALL];
    for(int cur=0;cur<=MAX;++cur)
     T = (T + dp[i-1][ALL-cur]*take[cur])%MOD;
                              }
                       }
  cout<<dp[N][K]<<'\n';
  return 0;
}
