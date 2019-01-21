#include <cstdio>
#include <cstring>

const int maxn = 100100;

//这些数组下标为0处用来表示数组长度
//前面四个都是用来储存子串的起点or终点的
int start[25][maxn], end[25][maxn], s[25][maxn], e[25][maxn], temp1[maxn], temp2[maxn];

//front和back表示当前匹配的子串前or后紧接着的'?'个数,然后会加到start or end数组中
int front, back;
int fail[maxn];
void kmp(char* str, char* pat, int num)
{
    int i, j, k;
    memset(fail, -1, sizeof(fail));
    start[num][0] = 0;
    end[num][0] = 0;

    for( i = 1; pat[i]; ++i )
    {
        for( k = fail[i-1]; k >= 0 && pat[i] - pat[k+1]; k = fail[k] );
        if( pat[k+1] == pat[i] )
            fail[i] = k + 1;
    }

    i = j = 0;
    while( str[i] && pat[j] )
    {
        if( str[i] == pat[j] )
        {
            ++i, ++j;
            if( pat[j] == '\0' )
            {
                start[num][++start[num][0]] = i - j - front;
                end[num][++end[num][0]] = i - 1 + back;
                j = fail[j-1] + 1;
            }
        }
        else if( j == 0 )    ++i;
        else j = fail[j-1] + 1;
    }
    front = back = 0;
}

char str[maxn], p[maxn], t[maxn];
//st表示的是该间断点的状态,1代表'?',0是'*'
bool st[maxn];

int main()
{
    int i, j, k, ll, rr, mid;
    int len, cnt1, cnt2;
    bool ok;

    while( scanf("%s %s", str, p) != EOF )
    {
        ok = 1;
        front = back = 0;

        //先处理一下p的头尾,并相应的对str做出改变
        //使之变成统一的s1-s2-s3-s4形式,两头没有'?'or'*',方便下面的处理
        len = strlen(p);
        for( i = cnt1 = 0; i < len && (p[i] == '*' || p[i] == '?'); ++i )
            if( p[i] == '?' )
                ++cnt1;
        for( j = len-1, cnt2 = 0; j >= 0 && (p[j] == '*' || p[j] == '?'); --j )
            if( p[j] == '?' )
                ++cnt2;
        if( i > j )
        {
            if( cnt1 <= strlen(str) )    
                printf("YES\n");
            else    
                printf("NO\n");
            continue;
        }
        p[j+1] = '\0';    str[strlen(str)-cnt2] = '\0';
        strcpy(p, p+i);
        strcpy(str, str+cnt1);

        //对每个子串求它的匹配
        len = strlen(p);
        for( i = j = k = 0; i < len; ++i )
        {
            if( p[i] == '*' )
            {
                if( !j )
                    continue;
                t[j] = '\0';
                st[k] = 0;
                kmp(str, t, k++);
                j = 0;
            }
            else if( p[i] == '?' )
            {
                if( !j )
                {
                    //例子: aa*??b
                    //??应该算到b中,就是后一个子串
                    front = 1;
                    while( p[i+1] == '?' )
                    {
                        ++front;    
                        ++i;
                    }
                    continue;
                }
                back = 1;
                while( p[i+1] == '?' )
                {
                    //例子: aa???
                    ++back;
                    ++i;
                }
                //例子: aa???*b 与 aa???b
                st[k] = p[i+1] == '*' ? 0 : 1;
                t[j] = '\0';
                kmp(str, t, k++);
                j = 0;
            }
            else
                t[j++] = p[i];
        }
        t[j] = '\0';
        kmp(str, t, k);

        //检查每个子串是否都出现了
        for( i = 0; ok && i <= k; ++i )    if( !start[i][0] )
            ok = 0;

        //对状态为1,就是'?'两边的子串合并,使p串成为统一由'*'分隔的，以进行贪心
        if( ok )
        {
            len = 0;
            for( i = 0; ok && i < k; ++i )
            {
                //临时数组,储存合并后的始点和终点
                temp1[0] = temp2[0] = 0;
                if( st[i] )
                {
                    //枚举左边的子串的始点,然后对右边的终点进行二分查找
                    for( j = 1; j <= end[i][0]; ++j )
                    {
                        ll = 1, rr = start[i+1][0]+1;
                        while( rr - ll > 1 )
                        {
                            mid = (ll+rr)/2;
                            if( start[i+1][mid] <= end[i][j] + 1 )
                                ll = mid;
                            else
                                rr = mid;
                        }
                        if( start[i+1][ll] == end[i][j] + 1 )
                        {
                            temp1[++temp1[0]] = start[i][j];
                            temp2[++temp2[0]] = end[i+1][ll];
                        }
                    }

                    //找不到符合的,匹配失败
                    if( !temp1[0] )
                        ok = 0;
                    else
                    {
                        //把temp中的复制去i+1
                        memcpy(start[i+1], temp1, sizeof(temp1));
                        memcpy(end[i+1], temp2, sizeof(temp2));
                    }
                }
                else
                {
                    for( s[len][0] = e[len][0] = 0, j = 1; j <= end[i][0]; ++j )
                    {
                        //s, e储存合并后的子串
                        s[len][++s[len][0]] = start[i][j];
                        e[len][++e[len][0]] = end[i][j];
                    }
                    ++len;
                }
            }

            //不要忘了最后一个
            for( s[len][0] = e[len][0] = 0, j = 1; j <= end[k][0]; ++j )
            {
                s[len][++s[len][0]] = start[k][j];
                e[len][++e[len][0]] = end[k][j];
            }
            ++len;
        }

        //贪心验证
        if( ok )
        {
            k = -1;
            for( i = 0; ok && i < len; ++i )
            {
                for( j = 1; j <= s[i][0]; ++j )    if( s[i][j] > k )
                {
                    k = e[i][j];
                    break;
                }
                if( j > s[i][0] )
                    ok = 0;
            }
        }

        if( ok )
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
