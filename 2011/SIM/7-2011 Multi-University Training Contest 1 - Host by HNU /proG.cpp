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

void input()
{
	scanf("%lf%lf%lf", &c.x, &c.y, &cr);
	scanf("%lf%lf%lf", &p.x, &p.y, &pr);
	scanf("%lf%lf%lf", &d.x, &d.y, &t);
	cr -= pr; q.x = p.x + t * d.x; q.y = p.y + t * d.y;
}

double getdis(pnt p1, pnt p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }

vec getvec(pnt p1, pnt p2)
{
	vec ret; ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y; return ret;
}

line getline(pnt p1, pnt p2)
{
	vec v = getvec(p1, p2);
	line ret;
	ret.a = -v.y; ret.b = v.x;
	ret.c = ret.a * p1.x + ret.b * p1.y;
	return ret;
}

double nummul(vec v1, vec v2) { return v1.x*v2.x + v1.y*v2.y; }

void getcrs(line l, pnt c, double r, pnt &p1, pnt &p2)
{
	double a = square(l.a/l.b) + 1;
	double b = 2 * (l.a * c.y / l.b - l.a * l.c / l.b - c.x);
	double c = square(c.x) + square(c.y) - square(cr) + square(l.c/l.b) - 2 * l.c * c.y / l.b;
	p1.x = -1.0 * b / a / 2 + sqrt((square(b) - 4*a*c)/(4*square(a)));
	p2.x = -1.0 * b / a / 2 - sqrt((square(b) - 4*a*c)/(4*square(a)));
	p1.y = (l.c - l.a * p1.x) / l.b;
	p2.y = (l.c - l.a * p2.x) / l.b;
}

line getref(line l0, line l1, pnt p)
{
	vec v; v.x = l0.b; v.y = -l0.a; double dis = sqrt(square(v.x)+square(v.y));
	double ca = v.x / dis, sa = v.y / dis;
	

void conduct()
{
	line l0, l1, l2;
	pnt p1, p2, q1, q2;
	double dis, tot;
	l1 = getline(p, q); tot = getdis(p, q);
	getcrs(l1, c, r, p1, p2);
	if (nummul(d, getvec(p, p1)) > nummul(d, getvec(p, p2))) p2 = p1; p1 = p;
	while (true) {
		if ((dis = getdis(p1, p2)) - tot > -eps) {
			d = getvec(p1, p2); p.x = p1.x + tot / dis * d.x; p.y = p1.y + tot / dis * d.y;
			printf("%.1f %.1f\n", p.x, p.y); return;
		} else {
			tot -= dis; l0 = getline(c, p2);
			l2 = getref(l0, l1, p2); getcrs(l2, c, r, q1, q2);
			p1 = p2; if (!cmp(q1, p2)) p2 = q2; else p2 = q1; l1 = l2;
		}
	}
}

int main()
{
	int time; scanf("%d", &time);
	while (time--) { input(); conduct(); }
	return 0;
}
