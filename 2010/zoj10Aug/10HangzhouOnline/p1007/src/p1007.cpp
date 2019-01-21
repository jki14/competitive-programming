#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define lmt 100
#define lmt2 10

int i,j,k,n,m;
int f[lmt][lmt][lmt],_d[lmt2][lmt2][lmt2][lmt2];
char str[lmt2],t[lmt2];
int g[lmt][lmt];

void out()
{
	int j,i;
	system("cls");
	for (j=m;j>=1;j--)
	{
		for (i=0;i<n;i++)
		{
			printf("%d",g[i][j]);
		}
		printf("\n");
	}
}

bool dfs(int p)			//已经找到了p个
{
	int i,j;
//	out();
	if (p==10)return true;
	for (i=0;i<n;i++)
	{
		switch (t[p])
		{
		case 'I':
			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (j+4<=m)
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i][j+3]=1;
				g[i][j+4]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i][j+3]=0;
				g[i][j+4]=0;
			}

			if (i+3<n &&j+1<=m && (g[i+1][j]==1 && g[i+1][j+1]==0) &&(g[i+2][j]==1 && g[i+2][j+1]==0) &&(g[i+3][j]==1 && g[i+3][j+1]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+2][j+1]=1;
				g[i+3][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+2][j+1]=0;
				g[i+3][j+1]=0;
			}
			break;
		case 'J':

			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (i+2<n && j+2<=m && (g[i+1][j]==1 && g[i+1][j+1]==0) &&(g[i+2][j]==1 && g[i+2][j+1]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i+1][j+1]=1;
				g[i+2][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i+1][j+1]=0;
				g[i+2][j+1]=0;
			}

			if (i+1<n && j+3<=m && (g[i+1][j]==1 && g[i+1][j+1]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+2]=1;
				g[i+1][j+1]=1;
				g[i+1][j+3]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+2]=0;
				g[i+1][j+1]=0;
				g[i+1][j+3]=0;
			}

			if (i+2<n && j>=1 && j+1<=m && (g[i+1][j]==1 && g[i+1][j+1]==0) && (g[i+2][j-1]==1 && g[i+2][j]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+2][j+1]=1;
				g[i+2][j]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+2][j+1]=0;
				g[i+2][j]=0;
			}

			if (i+1<n && j+3<=m && (g[i+1][j+2]==1 && g[i+1][j+3]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i][j+3]=1;
				g[i+1][j+3]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i][j+3]=0;
				g[i+1][j+3]=0;
			}

			break;
		case 'L':

			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (i+2<n && j+2<=m && (g[i+1][j]==1 && g[i+1][j+1]==0) &&(g[i+2][j]==1 && g[i+2][j+1]==0))
			{
				g[i+2][j+1]=1;
				g[i+2][j+2]=1;
				g[i+1][j+1]=1;
				g[i][j+1]=1;
				if (dfs(p+1))return true;
				g[i+2][j+1]=0;
				g[i+2][j+2]=0;
				g[i+1][j+1]=0;
				g[i][j+1]=0;
			}

			if (i+1<n && j+3<=m && (g[i+1][j]==1 && g[i+1][j+1]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i][j+3]=1;
				g[i+1][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i][j+3]=0;
				g[i+1][j+1]=0;
			}

			if (i+2<n && j+2<=m && (g[i+1][j+1]==1 && g[i+1][j+2]==0) && (g[i+2][j+1]==1 && g[i+2][j+2]==0))
			{
				g[i][j+2]=1;
				g[i+1][j+2]=1;
				g[i+2][j+2]=1;
				g[i][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+2]=0;
				g[i+1][j+2]=0;
				g[i+2][j+2]=0;
				g[i][j+1]=0;
			}

			if (i+1<n && j>=2 && j+1<=m && (g[i+1][j-2]==1 && g[i+1][j-1]==0))
			{
				g[i][j+1]=1;
				g[i+1][j]=1;
				g[i+1][j-1]=1;
				g[i+1][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j]=0;
				g[i+1][j-1]=0;
				g[i+1][j+1]=0;
			}
			break;
		case 'O':
			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (i+1<n && j+2<=m && (g[i+1][j]==1 && g[i+1][j+1]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i+1][j+1]=1;
				g[i+1][j+2]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i+1][j+1]=0;
				g[i+1][j+2]=0;
			}
			break;
		case 'S':

			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (i+2<n && j+2<=m && (g[i+1][j]==1 && g[i+1][j+1]==0) && (g[i+2][j+1]==1 && g[i+2][j+2]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+1][j+2]=1;
				g[i+2][j+2]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+1][j+2]=0;
				g[i+2][j+2]=0;
			}

			if (i+1<n && j>=1 && j+2<=m && (g[i+1][j-1]==1 && g[i+1][j]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i+1][j+1]=1;
				g[i+1][j]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i+1][j+1]=0;
				g[i+1][j]=0;
			}

			break;
		case 'T':
			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (i+1<n && j>=1 && j+2<=m && (g[i+1][j-1]==1 && g[i+1][j]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+1][j]=1;
				g[i+1][j+2]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+1][j]=0;
				g[i+1][j+2]=0;
			}

			if (i+1<n && j+3<=m && (g[i+1][j+1]==1 && g[i+1][j+2]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i][j+3]=1;
				g[i+1][j+2]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i][j+3]=0;
				g[i+1][j+2]=0;
			}
			if (i+2<n && j>=1 && j+1<=m && (g[i+1][j-1]==1 && g[i+1][j]==0) && (g[i+2][j]==1 && g[i+2][j+1]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+1][j]=1;
				g[i+2][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+1][j]=0;
				g[i+2][j+1]=0;
			}
			if (i+2<n && j+2<=m && (g[i+1][j]==1 && g[i+1][j+1]==0) && (g[i+2][j]==1 && g[i+2][j+1]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+1][j+2]=1;
				g[i+2][j+1]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+1][j+2]=0;
				g[i+2][j+1]=0;
			}
			break;
		case 'Z':
			for (j=40;j>=1;j--)if (g[i][j]==1)break;
			if (i+2<n && j>=1 && j+1<=m && (g[i+1][j-1]==1 && g[i+1][j]==0) && (g[i+2][j-1]==1 && g[i+2][j]==0))
			{
				g[i][j+1]=1;
				g[i+1][j+1]=1;
				g[i+1][j]=1;
				g[i+2][j]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i+1][j+1]=0;
				g[i+1][j]=0;
				g[i+2][j]=0;
			}

			if (i+1<n && j+3<=m && (g[i+1][j+1]==1 && g[i+1][j+2]==0))
			{
				g[i][j+1]=1;
				g[i][j+2]=1;
				g[i+1][j+2]=1;
				g[i+1][j+3]=1;
				if (dfs(p+1))return true;
				g[i][j+1]=0;
				g[i][j+2]=0;
				g[i+1][j+2]=0;
				g[i+1][j+3]=0;
			}

			break;
		default:;
		}
	}st[
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	while(n!=0)
	{
		memset(map,0,sizeof(map));
		for (i=0;i<n;i++)g[i][0]=1;
		for (i=0;i<10;i++)
		{
			scanf("%s",st);
			t[i]=str[0];
		}
		if (dfs(0))	printf("Yes\n");
		else printf("No\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}
