#include <iostream>
#include <time.h>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 110, M = 10;

int n, m;
int a[N], s[N];
LL f[N][M];

int mod(int x)
{
    return (x % 10 + 10) % 10;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }

    for (int i = 1; i <= n * 2; i ++ )
        s[i] = s[i - 1] + a[i];

    LL ans_max = 0, ans_min = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) //枚举起点
    { 
        //求最大值
        memset(f, 0, sizeof f);
        for (int j = 1; j <= n; j ++ )
        {
            f[j][1] = mod(s[i + j - 1] - s[i - 1]);
            for (int k = 2; k <= m; k ++ )
                for (int u = 1; u < j; u ++ )
                    f[j][k] = max(f[j][k], mod(s[i + j - 1] - s[i + u - 1]) * f[u][k - 1]);
        }
        ans_max = max(ans_max, f[n][m]);
        // 求最小值
        memset(f, 10, sizeof f); //注意这里不能设置成 0x3f，因为有些值不能划分成 m 份时是极大值，而乘个 10 很大
        for (int j = 1; j <= n; j ++ )
        {
            f[j][1] = mod(s[i + j - 1] - s[i - 1]);
            for (int k = 2; k <= m; k ++ )
                for (int u = 1; u < j; u ++ )
                    f[j][k] = min(f[j][k], mod(s[i + j - 1] - s[i + u - 1]) * f[u][k - 1]);
        }
        ans_min = min(ans_min, f[n][m]);
    }

    printf("%lld\n%lld\n", ans_min, ans_max);

    cerr << clock() << endl;

    return 0;
}