#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#define f (p>>1)
#define l (p<<1)
#define r ((p<<1)+1)
int i,n,a[500010]={0},b[500010]={0},c[500010]={1},sum,num,d[500010][5]={0},e[4]={0},q,x,t,p,tail=0;
int getmax(const int &p)
{
	int ret;
	ret=p;
	if (l<=tail &&c[ret]<c[l])
		ret=l;
	if (r<=tail &&c[ret]<c[r])
		ret=r;
	return ret;
}
void getin(int x,int y)
{
	c[p=++tail]=x;
	b[tail]=y;
	if (f && c[p]>c[f])
	{
		swap(b[p],b[f]);
		swap(c[p],c[f]);
		p=f;
	}	
}
void pop()
{
	p=1;
	swap(c[p],c[tail]);
	swap(b[p],b[tail]);
	tail--;
	q=getmax(p);
	while (p!=q && p<=tail)
	{
		swap(b[p],b[q]);
		swap(c[p],c[q]);
		p=q;
		q=getmax(p);
	}
}

int main()
{
	cin>>n;
	/*for(i=1;i<=100010;i++)
		c[i]=1;*/
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	i=0;
	while (i<n)
	{
		num=1;
		while (i+1<n && a[i]==a[i+1])
		{
			num++;
			i++;
		}
		getin(num,a[i]);
		i++;
	}
	x=0;
	while (tail>=3)
	{
		x++;
		for (int i=1;i<=3;i++)
		{
			c[1]--;
			d[x][i]=b[1];
			e[i]=c[1];
			pop();
		}
		for (int i=1;i<=3;i++)
		{
			if (e[i]>0)
			{
				getin(e[i],d[x][i]);
			}
		}
	}
	cout<<x<<endl;
	for(i=1;i<=x;i++)
				{	if (d[i][1]<d[i][2])
						swap(d[i][1],d[i][2]);
					if (d[i][1]<d[i][3])
						swap(d[i][1],d[i][3]);
					if (d[i][2]<d[i][3])	
						swap(d[i][2],d[i][3]);	
					
				}
	for(i=1;i<=x;i++)
		cout<<d[i][1]<<" "<<d[i][2]<<" "<<d[i][3]<<endl;
	return 0;
}
