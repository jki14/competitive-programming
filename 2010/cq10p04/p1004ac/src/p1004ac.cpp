#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 1000005;

int prime[MAXN];
bool mark[MAXN];
int buf[50];
int sum[50];
int tot;
int size = 0;

void solve (int a, int b)
{
int i, j;
long long tmp, ans = 1;

memset (sum, 0, sizeof (sum));
for (i = 0; i < size; i++)
{
   if (a == 1) break;
   if (mark[a])
   {
    sum[tot] = b;
    buf[tot++] = a;
    break;
   }
   if (a % prime[i] == 0)
   {
    while (a % prime[i] == 0)
    {
     sum[tot]++;
     a /= prime[i];
    }
    sum[tot] *= b;
    buf[tot++] = prime[i];
   }
}
for (i = 0; i < tot; i++)
{
   tmp = (sum[i] + 1) % 10007;
   tmp = (tmp * (tmp + 1)) / 2;
   tmp %= 10007;
   ans = (ans * tmp * tmp) % 10007;
}
printf ("%lld\n", ans);
}
int main ()
{
int i, j, cas = 0;
int a, b;

memset (mark, true, sizeof (mark));
for (i = 2; i < MAXN; i++)
{
if (mark[i])
   prime[size++] = i;
    for (j = 0; j < size && i * prime[j] < MAXN; j++)
   {
    mark[i*prime[j]] = false;
    if (i % prime[j] == 0) break;
   }
}
while (scanf ("%d%d", &a, &b) != EOF)
{
   printf ("Case %d: ", ++cas);
   tot = 0;
   solve (a, b);
}
return 0;
}
