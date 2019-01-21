#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define sqr(x) ((x)*(x))
using namespace std;

struct point3{double x,y,z;};
struct line3{point3 a,b;};
struct plane3{point3 a,b,c;};

//计算cross product U x V
point3 xmult(point3 u,point3 v){
	point3 ret;
	ret.x=u.y*v.z-v.y*u.z;
	ret.y=u.z*v.x-u.x*v.z;
	ret.z=u.x*v.y-u.y*v.x;
	return ret;
}

//计算dot product U . V
double dmult(point3 u,point3 v){
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

//矢量差 U - V
point3 subt(point3 u,point3 v){
	point3 ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
}

//向量大小
double vlen(point3 p){
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}


//直线到直线距离
double linetoline(line3 u,line3 v){
	point3 n=xmult(subt(u.a,u.b),subt(v.a,v.b));
	return fabs(dmult(subt(u.a,v.a),n))/vlen(n);
}
double linetoline(point3 u1,point3 u2,point3 v1,point3 v2){
	point3 n=xmult(subt(u1,u2),subt(v1,v2));
	return fabs(dmult(subt(u1,v1),n))/vlen(n);
}
//==============================================
//向量大小的平方
inline double sqrlen(const point3& p)
{
	return (p.x*p.x +p.y*p.y +p.z*p.z);
}

//点到直线最近点
point3 ptoline(const point3& p, const line3& l)
{
	point3 ab=subt(l.b, l.a);
	double t=-dmult(subt(p,l.a),ab) / sqrlen(ab);
	ab.x *=t;
	ab.y *=t;
	ab.z *=t;
	return subt(l.a,ab);
}

void nearest_point_pair(const line3 & u,const line3 & v, point3& p1, point3& p2)
{
	point3 ab=subt(u.b,u.a), cd=subt(v.b,v.a), ac=subt(v.a,u.a);
	double r= (dmult(ab,cd)*dmult(ac,ab) - sqrlen(ab)*dmult(ac,cd))  /
	           (sqrlen(ab)*sqrlen(cd) - sqr(dmult(ab,cd)));
	p2.x=v.a.x +r* cd.x;
	p2.y=v.a.y +r* cd.y;
	p2.z=v.a.z +r* cd.z;
	p1=ptoline(p2,u);
}


int main()
{
	std::ios::sync_with_stdio(false);
	int t=0;cin>>t;
	double p1x,p1y,p1z,p2x,p2y,p2z,p3x,p3y,p3z,p4x,p4y,p4z;
	point3 dot1,dot2,dot3,dot4;
	while (t--)
	{
		cin>>p1x>>p1y>>p1z>>p2x>>p2y>>p2z
		   >>p3x>>p3y>>p3z>>p4x>>p4y>>p4z;
		dot1.x=p1x; dot1.y=p1y; dot1.z=p1z;
		dot2.x=p2x; dot2.y=p2y; dot2.z=p2z;
		dot3.x=p3x; dot3.y=p3y; dot3.z=p3z;
		dot4.x=p4x; dot4.y=p4y; dot4.z=p4z;
		cout<<fixed<<setprecision(6)<<linetoline(dot1,dot2,dot3,dot4)<<endl;

		line3 firstline,secondline;
		point3 nearest1,nearest2;
		firstline.a=dot1;  firstline.b=dot2;
		secondline.a=dot3;  secondline.b=dot4;
		nearest_point_pair(firstline,secondline,nearest1,nearest2);
		cout<<fixed<<setprecision(6)<<nearest1.x<<' '<<nearest1.y<<' '<<nearest1.z<<' '
									<<nearest2.x<<' '<<nearest2.y<<' '<<nearest2.z<<endl;
	}
	return 0;
}

