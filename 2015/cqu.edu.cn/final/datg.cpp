#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>
#include <cstring>
using namespace std;

const int T=10;

const int N=1000;

const double eps=1e-9;

struct pnt{
        double x, y;
        pnt operator+(const pnt &p) const {
                pnt ret; ret.x=x+p.x;
                ret.y=y+p.y; return ret;
        }
        pnt operator-(const pnt &p) const {
                pnt ret; ret.x=x-p.x;
                ret.y=y-p.y; return ret;
        }
        pnt operator*(const double c) const {
                pnt ret; ret.x=x*c;
                ret.y=y*c; return ret;
        }
        pnt operator/(const double c) const {
                pnt ret; ret.x=x/c;
                ret.y=y/c; return ret;
        }
} p[1000086];

int vst[1000086];

inline double submul(const pnt &p1, const pnt &p2) { return p1.x*p2.y-p2.x*p1.y; }
inline double dist2(const pnt &p1, const pnt &p2){ return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y); }

int main(){
	FILE *log=fopen("datg.log", "w");
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int n, a, b, c;
		if(rand()&1){
			n=2500;
			for(int i=0; i<n; i++){
				p[i].x=(rand()%100001)*((rand()&1)?0.01:-0.01);
				p[i].y=(rand()%100001)*((rand()&1)?0.01:-0.01);
			}
			for(int i=a=0; i<n; i++){
                        	if (p[i].y-p[a].y<-eps || (p[i].y-p[a].y<eps && p[i].x-p[a].x<-eps))a=i;
	                }
			for(int i=c=0; i<n; i++){
                        	if (p[i].y-p[c].y>eps || (p[i].y-p[c].y>-eps && p[i].x-p[c].x<-eps))c=i;
			}
			for(int i=b=0; i<n; i++){
                        	if (p[i].x-p[b].x>eps || (p[i].x-p[b].x>-eps && (rand()&1)))b=i;
			}
			memset(vst, 0, sizeof(vst));
			int m=n;
			for(int i=0; i<n; i++){
				if (submul(p[c]-p[b], p[i]-p[b])<-eps
				|| submul(p[i]-p[a], p[b]-p[a])>eps
				|| submul(p[i]-p[a], p[c]-p[a])<-eps){
					vst[i]=1;
					m--;
				}
			}
			fprintf(log, "%d Y\n", m);
			printf("%d\n", m);
			for(int i=0; i<n; i++){
				if(!vst[i])printf("%.2f %.2f\n", p[i].x, p[i].y);
			}
		}else{
			n=rand()%998+3;
			fprintf(log, "%d N\n", n);
			printf("%d\n", n);
			for(int i=0; i<n; i++){
				double x=(rand()%100001)*((rand()&1)?0.01:-0.01);
				double y=(rand()%100001)*((rand()&1)?0.01:-0.01);
				printf("%.2f %.2f\n", x, y);
			}
		}
	}
	fclose(log);
	return 0;
}
