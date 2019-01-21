#include <bits/stdc++.h>
#include "message.h"
#include "asteroids.h"

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define M 110
#define N 30010
#define SH 350

int bk[M];
int bw[M];

int a[310][N];
int v[310][N]; 

int n, m;
int L, R; 

int cg(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	char c = GetPosition(x, y);
	if (c == '#') return -1; 
	return c-'0'; 
}

int p[310*N]; 

bool cmp(int a, int b) {
	int ax = a >> 20;
	int ay = a - (ax << 20);
	int bx = b >> 20;
	int by = b - (bx << 20);
	if (ax + ay != bx + by) return ax + ay < bx + by;
	return ax < bx; 
}


int main () {
	int nd = NumberOfNodes();
	int id = MyNodeId();
	n = GetHeight();
	m = GetWidth();
	for (int i = 0; i < nd; i ++) {
		bk[i+1] = bk[i] + n/nd+(i<(n%nd));
	}
	L = bk[id], R = bk[id+1];
	int Lw = 0, re = m;
	while (re > 0) {
		int r = min(300, re); 
		bw[Lw+1] = bw[Lw] + r;
		Lw ++;
		re -= r;
	}
	
	for (int i = 0; i <= R-L; i ++) 
		for (int j = 0; j < m; j ++) {
			v[i][j] = cg(L+i, j);
		}
	
	int pL = 0;
	for (int i = 1; i <= R-L; i ++)
		for (int j = 0; j < m; j ++) p[pL++] = (i << 20)+j;
	sort(p, p+pL, cmp); 
	
	for (int i = 0; i < m; i ++) 
		a[0][i] = v[0][i];
	
	int cur = 0; 
	int cb = 0; 
	// get block x+1 to calculate block x
	int ne = id+1;
	if (ne == nd) ne = 0; 
	if (id == 0) {
		//for (int i = 0; i < m; i ++) 
			//cout << L << " " << i << " " << v[0][i] << endl;
	}
	// if (id != 0) return 0; 
	for (int z = 0; z < Lw; z ++) {
		if (id != 0) {
			Receive(id-1); 
			for (int i = bw[z]; i < bw[z+1]; i ++) {
				a[0][i] = GetLL(id-1); 
				// cout << L << " " << i << " " << a[0][i] << endl;
			}
			
			if (R == L) {
				for (int i = bw[z]; i < bw[z+1]; i ++) {
					PutLL(ne, a[0][i]);
				}
				Send(ne);
				continue;
			}
		}

		while (cur < pL) {
			int x = p[cur] >> 20;
			int y = p[cur] - (x << 20); 
			
			if (y == bw[z+1]) break; 
			
			if (v[x][y] == -1 || v[x-1][y] == -1) {
				a[x][y] = -1;
			} else {
				int &T = a[x][y];
				T = -1;
				if (a[x-1][y] != -1) T = max(T, a[x-1][y] + v[x][y]);
				if (y < m-1 && a[x-1][y+1] != -1) T = max(T, a[x-1][y+1] + v[x][y] + v[x-1][y]); 
				if (y > 0 && a[x-1][y-1] != -1) T = max(T, a[x-1][y-1] + v[x][y] + v[x-1][y]); 
				//cout << L+x << " " << y << " " << a[x][y] << endl;
			}
			
			if (y+1 == bw[cb+1] && x == R-L) {
				for (int i = bw[cb]; i < bw[cb+1]; i ++) {
					//cout << a[R-L][i] << endl;
					PutLL(ne, a[R-L][i]); 
				}
				Send(ne); 
				cb ++;
			}
			
			cur ++;
		}
	}
	// return 0;
	
	if (id != 0) return 0; 
	
	int S = -1;
	for (int x = 0; x < Lw; x ++) {
		Receive(nd-1);
		for (int i = bw[x]; i < bw[x+1]; i ++) {
			int c = GetLL(nd-1); 
			S = max(S, c); 
		}
	}
	cout << S << endl;
	return 0;
}
