#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct {
    double x, y, z;
} POINT;

POINT plist[10], circle;
double R, dis;
double xmax, ymax, zmax, xmin, ymin, zmin, x, y, z;

bool cmp(const POINT &a, const POINT &b) {
    if (a.z != b.z)
        return a.z < b.z;
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

inline double sqr(double x) {
    return x * x;
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}

int main(int argc, char** argv) {
    int i, T;
    scanf("%d", &T);
    while (T--) {
        for (i = 1; i <= 8; i++)
            scanf("%lf%lf%lf", &plist[i].x, &plist[i].y, &plist[i].z);
        scanf("%lf%lf%lf%lf", &circle.x, &circle.y, &circle.z, &R);
        sort(plist + 1, plist + 9, cmp);
        xmin = plist[1].x, xmax = plist[2].x;
        ymin = plist[1].y, ymax = plist[3].y;
        zmin = plist[1].z, zmax = plist[5].z;

        if (circle.x < xmin)
            x = xmin;
        else if (circle.x > xmax)
            x = xmax;
        else
            x = circle.x;
        if (circle.y < ymin)
            y = ymin;
        else if (circle.y > ymax)
            y = ymax;
        else
            y = circle.y;
        if (circle.z < zmin)
            z = zmin;
        else if (circle.z > zmax)
            z = zmax;
        else
            z = circle.z;
        dis = distance(x, y, z, circle.x, circle.y, circle.z);
        if (dis > R)
            puts("No");
        else
            puts("Yes");
    }
   return 0;
}
