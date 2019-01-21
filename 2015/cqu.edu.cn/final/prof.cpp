#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

#define N 2048

int n, m, idx, ans;
int x[N], y[N], t[N];
int mrk[N][N], rig[N][N];
string sx[N], sy[N];

map<string, int> s;

char buf[32];

template<class T> inline void SWAP(T &x, T &y){ T z=x;x=y;y=z; }

int main(){
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		s.clear(); idx=0;
		for(int i=0; i<n; i++){
			scanf("%s", buf);sx[i]=buf;s.insert(make_pair(sx[i], 0));
			scanf("%s", buf);sy[i]=buf;s.insert(make_pair(sy[i], 0));
			scanf("%d", &t[i]);
		}
		for(map<string, int>::iterator it=s.begin(); it!=s.end(); it++){
			it->second=idx++;
		}
		memset(mrk, 0, sizeof(mrk));
		memset(rig, 0xc0, sizeof(rig));
		ans=0;
		for(int i=0; i<n; i++){
			x[i]=s[sx[i]];y[i]=s[sy[i]];
			if(i && t[i]>t[i-1]){
				for(int j=i-1; j>=0 && t[j]==t[i-1]; j--){
					rig[x[j]][y[j]]=t[j];
				}
			}
			if(t[i]-rig[y[i]][x[i]]<=m){
				int u=x[i], v=y[i];
				if(u>v)SWAP(u, v);
				if(!mrk[u][v]){
					mrk[u][v]=1;
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
