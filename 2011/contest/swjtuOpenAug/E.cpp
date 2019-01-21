
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAXN 105000
#define MAXL 105

int n, len;
//char s[MAXL], t[MAXL];
string s, t;
int dir[4] = {1, -1, 2, -2};
map<string, int> mp;

struct node
{
int stp, id;
//char c[MAXL];
string c;
}qu[MAXN];

int isOk(string str)
{
int i, j, k;
for (i = 0; i < len; i++)
   if (str[i] == 'B') break;
for (j = len - 1; j >= 0; j--)
   if (str[j] == 'B') break;
for (k = i; k <= j; k++)
   if (str[k] == 'W') return 0;
return 1;
}

int in(int x)
{
return x >= 0 && x < len;
}

void print(node p)
{
cout << p.c << endl;
printf ("stp %d id %d\n\n", p.stp, p.id);
}

int bfs(int id)
{
if (isOk(s)) return 0;
int i, j, qs = 0, qe = 1, cnt = 0;
node p, q;
mp.clear();
p.stp = 0;
p.id = id;
//strcpy(p.c, s);
p.c = s;
qu[0] = p;
mp[s] = cnt++;
while (qs < qe)
{
   p = qu[qs++];

   if (p.stp == 9) continue;
   //print(p);
   for (i = 0; i < 4; i++)
   {
    q.id = p.id + dir[i];
    if (!in(q.id)) continue;

    q.stp = p.stp + 1;
    t = p.c;
    if (i < 2)
    {
     t[p.id] = t[q.id];
     t[q.id] = 'F';

     //strcpy(q.c, p.c);
     q.c = t;
    }
    else
    {
     if (t[q.id] == 'W')
      t[p.id] = 'B';
     else
      t[p.id] = 'W';
     t[q.id] = 'F';

     //strcpy(q.c, p.c);
     q.c = t;
    }
    //printf ("i %d\n", i);
    //print(q);
    //strcpy(t, q.c);
    if (isOk(q.c)) return q.stp;

    if (mp[q.c] == 0)
    {
     qu[qe++] = q;
     mp[q.c] = cnt++;
    }
   }
}
return -1;
}

int main()
{
int i, j, tt = 0, id;

while (cin >> s)
{
   if (s[0] == '-') break;

   len = s.length();
   for (i = 0; i < len; i++)
    if (s[i] == 'F')
     break;
   id = i;

   printf ("%d. %d\n", ++tt, bfs(id));
}
}

/*
WBWF
WBBBBFB
WBWBBWBFB
WWWWWF
WBWWFWB
*/

/* dfs

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MAXN 1050000
#define MAXL 105

int n, len;
//char s[MAXL], t[MAXL];
string s, t;
int dir[4] = {1, -1, 2, -2};

int mn, id;


int isOk(string str)
{
    int i, j, k;
    for (i = 0; i < len; i++)
        if (str[i] == 'B') break;
    for (j = len - 1; j >= 0; j--)
        if (str[j] == 'B') break;
    for (k = i; k <= j; k++)
        if (str[k] == 'W') return 0;
    return 1;
}

int in(int x)
{
    return x >= 0 && x < len;
}

void dfs(int dep)
{
    if (isOk(s))
    {
        if (mn > dep)
            mn = dep;
        //cout << "Hahah " << mn << endl;
        return;
    }

    if (dep == 9 || dep >= mn) return;

    //cout << "s   " << s << endl;
    int i, tid;
    char ch;
    string t = s;
    for (i = 0; i < 4; i++)
    {
        tid = id + dir[i];
        if (!in(tid)) continue;

        ch = s[tid];


        if (i > 1)
        {
            if (ch == 'W')
                ch = 'B';
            else
               ch = 'W';
        }
        s[tid] = 'F';
        s[id] = ch;
        id = tid;
        //cout << "i " << i << " " << s << endl;
        dfs(dep+1);

        id = tid - dir[i];
        s = t;
    }
    //cout << endl;
}

int main()
{
    int i, j, tt = 0;

    while (cin >> s)
    {
        if (s[0] == '-') break;

        //len = strlen(s);
        len = s.length();
        for (i = 0; i < len; i++)
            if (s[i] == 'F')
                break;
        id = i;
        mn = 10;
        dfs(0);
   if (mn > 9) mn = -1;
        printf ("%d. %d\n", ++tt, mn);
    }
}
*/

