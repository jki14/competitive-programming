#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int n, m, l, dp[2000][2000], x[2000], sum[2000], jeo[2000];
int main()
{
    while(scanf("%d%d%d", &n, &m, &l) != EOF)
    {
        for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
        sum[0] = 0;
        memset(jeo, 0, sizeof(jeo));
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + x[i];
        memset(dp, 0, sizeof(dp));
        int ans = -1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= m && j <= i; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
                if (i - l >= 0 && i - l >= j)
                    jeo[j] = max(jeo[j] + x[i], dp[i - l][j] + sum[i] - sum[i - l]);
                if (i - l >= 0) dp[i][j] = max(dp[i][j], jeo[j]);
                if (j == m && dp[i][j] > ans) ans = dp[i][j];
            }
        printf("%d\n", ans);
    }
return 0;
}
