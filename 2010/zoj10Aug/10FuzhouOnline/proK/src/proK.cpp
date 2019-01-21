#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;

struct node
{
	int index, ori;
};

struct point
{
	double x, y, z, dis, angle;
	int area;
};

struct vector
{
	double x, y, z;
};

const double EPS = 1e-20;
const int LEN = 100010;
vector v, s;
point p[LEN][3];
node queue[LEN*3];
int n, m, Case, _Case;

bool zero(vector v)
{
	if (fabs(v.x) < EPS && fabs(v.y) < EPS && fabs(v.z) < EPS) return true;
	return false;
}

int compare(point p1, point p2)
{
	if (p1.dis - p2.dis > EPS) return 1;
	if (p1.dis - p2.dis < -EPS) return -1;
	if (p1.area > p2.area) return 1;
	if (p1.area < p2.area) return -1;
	if (p1.angle - p2.angle > EPS) return 1;
	if (p1.angle - p2.angle < -EPS) return -1;
	return 0;
}

int compare(node n1, node n2)
{
	return compare(p[n1.index][n1.ori], p[n2.index][n2.ori]);
}

vector getVector(node n1, node n2)
{
	vector request;
	request.x = p[n2.index][n2.ori].x - p[n1.index][n1.ori].x;
	request.y = p[n2.index][n2.ori].y - p[n1.index][n1.ori].y;
	request.z = p[n2.index][n2.ori].z - p[n1.index][n1.ori].z;
	return request;
}

double getDis(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int getArea(vector v1, vector v2, vector v3)
{
	double temp = (v1.y * v2.z - v2.y * v1.z) * v3.x + (v1.z * v2.x - v2.z * v1.x) * v3.y + (v1.x * v2.y - v2.x * v1.y) * v3.z;
	if (temp > EPS) return 1;
	if (temp < -EPS) return -1;
	return 0;
}

double getAngle(vector v1, vector v2)
{
	if (zero(v1)) return 0;
	if (zero(v2)) return 0;
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) / (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z) * sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z));
}

int getOri(vector v1, vector v2)
{
	double temp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	if (temp > EPS) return 1;
	if (temp < -EPS) return -1;
	return 0;
}

void getVerVec(vector &s)
{
	if (fabs(v.x) > EPS) {s.x = 0; s.y = 1; s.z = 1;}
	if (fabs(v.y) > EPS) {s.x = 1; s.y = 0; s.z = 0;}
	if (fabs(v.z) > EPS) {s.x = 1; s.y = 1; s.z = 0;}
}

void makeUpPoint(point &p)
{
	double t = (v.x * p.x + v.y * p.y + v.z * p.z) / (v.x * v.x + v.y * v.y + v.z * v.z);
	point temp;
	temp.x = v.x * t; temp.y = v.y * t; temp.z = v.z * t;
	p.dis = getDis(p, temp);
	vector _temp;
	_temp.x = p.x - temp.x; _temp.y = p.y - temp.y; _temp.z = p.z - temp.z;
	p.area = getArea(s, _temp, v);
	p.angle = getAngle(s, _temp);
}

void qsort(int x, int y)
{
	if (x >= y) return;
	int i, j;
	node k;
	i = rand() % (y-x) + x;
	k = queue[i];
	queue[i] = queue[x];
	i = x;
	j = y;
	while (i < j)
	{
		while (i < j && compare(queue[j], k) >= 0) --j;
		queue[i] = queue[j];
		while (i < j && compare(queue[i], k) <= 0) ++i;
		queue[j] = queue[i];
	}
	queue[i] = k;
	qsort(x, i-1);
	qsort(i+1, y);
}

int checkNum(int x, int y)
{
	int i, request;
	vector temp;
	node st;
	for (i = x; i <= y; ++i)
		if (queue[i].ori == 1) break;
	if (i == y+1) return 0;
	st = queue[i];
	for (i = i+1; i <= y; ++i)
	{
		if (queue[i].ori == 0) continue;
		temp = getVector(queue[i], st);
		if (getOri(temp, v) > 0) st = queue[i];
	}
	request = 0;
	for (i = x; i <= y; ++i)
	{
		if (queue[i].ori == 1) continue;
		temp = getVector(queue[i], st);
		if (getOri(temp, v) <= 0) request++;
	}
	return request;
}

void init()
{
	int i;
	cin >> n >> m;
	for (i = 0; i < n; ++i) { cin >> p[i][0].x >> p[i][0].y >> p[i][0].z;}
	for (i = 0; i < m; ++i) { cin >> p[i][1].x >> p[i][1].y >> p[i][1].z;}
	cin >> v.x >> v.y >> v.z;
	if (fabs(v.x * v.y) < EPS && fabs(v.x * v.z) < EPS && fabs(v.y * v.z) < EPS) getVerVec(s);
	else
	{
		s.x = 2 * v.y * v.z;
		s.y = -v.x * v.z;
		s.z = -v.x * v.y;
	}
	for (i = 0; i < n; ++i) makeUpPoint(p[i][0]);
	for (i = 0; i < m; ++i) makeUpPoint(p[i][1]);
	for (i = 0; i < n; ++i) {queue[i].index = i; queue[i].ori = 0;}
	for (i = 0; i < m; ++i) {queue[n+i].index = i; queue[i].ori = 1;}
	qsort(0, n+m-1);
}

void conduct()
{
	int ans;
	int i, j;
	ans = 0;
	for (i = 0; i < n+m; ++i)
	{
		j = i;
		while (j+1 < n+m && compare(queue[i], queue[j+1]) == 0) ++j;
		ans += checkNum(i, j);
		i = j;
	}
	//cout << "Case " << _Case - Case << ": " << ans << endl;
	cout << "Case " << Case << ": " << ans << endl;
}

int main()
{
	srand(time(0));
	cin >> _Case;
		init();
		conduct();
	return 0;
}
