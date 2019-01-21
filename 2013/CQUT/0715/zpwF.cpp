#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
 
using namespace std;

const int maxn=220002;

int n,m,ans;

class Cp
{
public:
	int x,y;
}	a[maxn],aans[1000];

int cmp(const void *a,const void *b)
{
	if ( (*(Cp *)a).x==(*(Cp *)b).x )
		return (*(Cp *)a).y-(*(Cp *)b).y;
	return (*(Cp *)a).x-(*(Cp *)b).x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int i,j,k;
	
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].x*=2,a[i].y*=2;
	}
	if (n<=m) 
	{
		cout << -1 << endl;
		return 0;
	}
	qsort(a+1,n,sizeof a[0],cmp);
	
	for (int kl=0;kl<=k;kl++)
		for (int kr=0;kr<=k-kl;kr++)
		{
			int lp=1+kl,rp=n-kr;
			Cp Z;
			Z.x=(a[lp].x+a[rp].x)/2,Z.y=(a[lp].y+a[rp].y)/2;
			
			int km=0;
			i=lp+1;
			j=rp-1;
			while (i<j)
			{
				if (a[i].x+a[j].x==Z.x*2 && a[i].y+a[j].y==Z.y*2)
					i++,j--;
				else
				{
					km++;
					if (a[i].x+a[j].x==Z.x*2)
					{
						if (Z.y-a[i].y<a[j].y-Z.y)
							j--;
						else
							i++;
					}
					else
					{
						if (Z.x-a[i].x<a[j].x-Z.x)
							j--;
						else 
							i++;
					}
				}
			}
			if (km+kr+kl<=m)
				aans[++ans]=Z;
		}
		
	qsort(aans+1,ans,sizeof aans[0],cmp);
	for (i=2;i<=ans;i++)
	{
		while ( aans[i].x == aans[i-1].x && aans[i].y==aans[i-1].y )
		{
			ans--;
			for (j=i;j<=ans;j++)
				aans[j]=aans[j+1];
		}
	}
		
	cout << ans << endl;
	for (i=1;i<=ans;i++)
		cout << aans[i].x/2.0 << " " << aans[i].y/2.0 << endl;
	
	return 0;
}
