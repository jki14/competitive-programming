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

#define square(x) (x)*(x)
struct pnt { double x, y; };
struct node { double x; int idx; 
	bool operator<(const node &nd)
	{
		if (fabs(x-nd.x) > eps) return x < nd.x;
		return !(idx%2);
	}
};
#define N 500010
const double eps = 1e-6;
pnt p[N], cen;
node q[N*2];
double wid, r;
int seq[2*N], rt[N], stk[N];
bool col[N];
int n;

struct comp {
	bool operator()(const double &a, const double &b) { return a - b < -eps; }
};

map<double, int, comp> st;
map<node, int> ed;

void input()
{
	int i;
	for (i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	scanf("%lf%lf", &cen.x, &cen.y); wid /= 2;
}

int root(int x) { 
	int i;
	if (rt[x] == x) return x;
	stk[stk[0] = 1] = x;
	while (rt[x] != x) { x = rt[x]; stk[++stk[0]] = x;if(stk[0]>50000)while(1);printf("rt[%d]=%d\n",x,rt[x]); }
	for (i = 1; i <= stk[0]; ++i) rt[stk[i]] = x; return x;
}

int cmp(const int &x, const int &y) { 
	/*if (q[x].x - q[y].x < -eps) return 1;
	if (q[x].x - q[y].x > eps) return 0;
	if (x%2) return 0; return 1;*/
	printf("x=%d,y=%d~\n",x,y);
	if(fabs(q[x].x-q[y].x)>eps)return q[x].x<q[y].x;
	return (x&1)==1;
}

double getdis(const pnt &p1, const pnt &p2) { return sqrt(fabs(square(p2.x-p1.x) + square(p2.y-p1.y))); }

void conduct()
{
	int i, ans;
	map<double, int, comp>::iterator pos, lft, rit;
	map<node, int>::iterator link;
	st.clear();
	ed.clear();
	for (i = 0; i < n; ++i) { q[i*2].x = p[i].x; q[i*2+1].x = p[i].x + wid;}
	for (i = 0; i < 2*n; ++i) q[i].idx = i;	
	for (i = 0; i < 2*n; ++i) ed.insert(pair<node, int>(q[i], i));
	for (link = ed.begin(), i = 0; link != ed.end(); ++link, ++i) seq[i] = link->second;
	//for (i = 0; i < 2*n; ++i) printf("q[%d]:%.3f %.3f\n", i, q[i].x, q[i].y);
	
	/*printf("!n=%d\n",n);
	for (i = 0; i < 2*n; ++i) {
		//printf("seq[%d]=%d\n",i,seq[i]);
		seq[i] = i; 
		//printf("seq[%d]=%d\n",i,seq[i]);
	}
	printf("SORT FAIL?");	
	sort(seq, seq+n, cmp); */
	printf("NO\n");
	for (i = 0; i < n; ++i) rt[i] = i;
	cout<<"succ 1"<<endl;
	for (i = 0; i < 2*n; ++i) 
		if (seq[i]%2) {
			//printf("%.3f %.3f\n", p[seq[i]/2].x, p[seq[i]/2].y);
			pos = st.find(p[seq[i]/2].y); 
			if (pos != st.end() && pos->second == seq[i]/2) st.erase(pos);
			cout<<"succ "<<i<<endl;
		} else {
			//printf("%.3f %.3f\n", p[seq[i]/2].x, p[seq[i]/2].y);
			if ((pos = st.find(p[seq[i]/2].y)) != st.end()) {
				if (root(seq[i]/2) != root(pos->second)) rt[rt[pos->second]] = rt[seq[i]/2]; else;
				pos->second = seq[i]/2;
			}
			else { st.insert(pair<double, int>(p[seq[i]/2].y, seq[i]/2)).second; pos = st.find(p[seq[i]/2].y); }
			if(pos==st.end())while(1);
			lft = pos; rit = pos; if (lft != st.begin()) lft--; rit++;
			if (pos != st.begin() && fabs(pos->first - lft->first) - wid < eps) 
				if (root(pos->second) != root(lft->second)) rt[rt[lft->second]] = rt[pos->second]; 
			if (rit != st.end() && fabs(pos->first - rit->first) - wid < eps) 
				if (root(pos->second) != root(rit->second)) rt[rt[rit->second]] = rt[pos->second];
			//for (pos = st.begin(); pos != st.end(); ++pos) printf("[%d][%.3f] ", pos->second, pos->first); 
			//printf("\n");
		}
	//for (i = 0; i < n; ++i) printf("rt[%d]=%d\n", i, root(i));
	memset(col, false, sizeof(col));
	for (i = 0; i < n; ++i) if (getdis(cen, p[i]) - r < eps) col[root(i)] = true;
	for (i = ans = 0; i < n; ++i) if (col[root(i)]) ans++;
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d%lf%lf", &n, &r, &wid) != EOF) {
		input();
		cout<<"init succ"<<endl;
		conduct();
	} return 0;
}
