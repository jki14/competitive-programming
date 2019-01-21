#include<stdio.h>
#include<string.h>
bool f[152][11];
short dp[152][59050];
int n,m,b[11],res,A[11],B[11];
int max(int x,int y)
{
	return x>y?x:y;
}
int hash(int a[])
{
	int i,res=0;
	for(i=0;i<m;i++)
		res+=a[i]*b[i];
	return res;
}
void _hash(int a[],int zt)
{
	int i;
	for(i=0;i<m;i++,zt/=3)
		a[i]=zt%3;
}
void lzs(int l,int x,int zt,int c)
{
	if(x==m)
	{
		if(dp[l][zt]<c)
			dp[l][zt]=c;
		return ;
	}
	if(x<m-1&&!B[x]&&!B[x+1]&&!A[x]&&!A[x+1])
		lzs(l,x+2,zt+2*b[x]+2*b[x+1],c+1);
	if(x<m-2&&!B[x]&&!B[x+1]&&!B[x+2])
		lzs(l,x+3,zt+2*b[x]+2*b[x+1]+2*b[x+2],c+1);
	lzs(l,x+1,zt,c);
}
int main()
{
	int t,k,x,y,i,j,l,st,ed;
	b[0]=1;
	for(i=1;i<11;i++)
		b[i]=b[i-1]*3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(f,true,sizeof(f));
		while(k--)
		{
			scanf("%d%d",&x,&y);
			f[x][y-1]=false;
		}
		memset(dp,-1,sizeof(dp));
		for(i=0;i<m;i++)
		{
			if(!f[1][i])
				A[i]=2;
			else
				A[i]=1;
		}
		st=hash(A);
		dp[1][st]=0;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<b[m];j++)
			{
				if(dp[i-1][j]==-1)
					continue;
				_hash(A,j);
				for(l=0;l<m;l++)
				{
					if(!f[i][l])
						B[l]=2;
					else if(A[l]<2)
						B[l]=0;
					else
						B[l]=1;
				}
				ed=hash(B);
				lzs(i,0,ed,dp[i-1][j]);
			}
		}
		int res=0;
		for(i=0;i<b[m];i++)
			if(res<dp[n][i])
				res=dp[n][i];
		printf("%d\n",res);
	}
}
