#include<stdio.h>
#include<string.h>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
struct hello
{
	int x,y;
}p1,p2,t1,t2;
int paichi()//快速排斥实验
{
	if(
		min(p1.x,p2.x)<max(t1.x,t2.x)&&
		min(t1.x,t2.x)<max(p1.x,p2.x)&&
		min(p1.y,p2.y)<max(t1.y,t2.y)&&
		min(t1.y,t2.y)<max(p1.y,p2.y)
		)
		return 1;
	return 0;
}
int  cross(int a,int b,int c,int d)  //叉积
{
	return a*b-c*d;
}
int kuali()
{
	int p1t1x=t1.x-p1.x, p1t1y=t1.y-p1.y;
	int p1p2x=p2.x-p1.x, p1p2y=p2.y-p1.y;
	int p1t2x=t2.x-p1.x, p1t2y=t2.y-p1.y;

	int t1p1x=p1.x-t1.x, t1p1y=p1.y-t1.y;
	int t1t2x=t2.x-t1.x, t1t2y=t2.y-t1.y;
	int t1p2x=p2.x-t1.x, t1p2y=p2.y-t1.y;

	if((cross(p1t1x,p1p2y,p1t1y,p1p2x)*cross(p1p2x,p1t2y,p1p2y,p1t2x))>=0)
	{
		if((cross(t1p1x,t1t2y,t1p1y,t1t2x)*cross(t1t2x,t1p2y,t1t2y,t1p2x))>=0)
			return 1;
	}
	return 0;
}
int main()
{	
	while(1)
	{
		scanf("%d%d",&p1.x,&p1.y);
		scanf("%d%d",&p2.x,&p2.y);
		scanf("%d%d",&t1.x,&t1.y);
		scanf("%d%d",&t2.x,&t2.y);
		if(paichi())
		{
			if(kuali())
				puts("Yes");
			else
				puts("No");
		}
		else
			puts("No");
	}
}
