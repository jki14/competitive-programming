#include <iostream>
using namespace std;

const int maxn=12;

const int mod=1000000007;
int res,n,a[maxn],i;

void doit(int x)
{
	if(x==n)
	{
		for(i=0;i<n;i++)
			if(a[i]==i)
			{
				res++;
				while(res>=mod)res%=mod;
				return;
			}
		return;
	}
	for(a[x]=0;a[x]<n;a[x]++)
		doit(x+1);
}

int main()
{
	for(n=1;n<=maxn;n++)
	{
		res=0;
		doit(0);
		cout<<"f["<<n<<"]="<<res<<";"<<endl;
	}
	return 0;
}
