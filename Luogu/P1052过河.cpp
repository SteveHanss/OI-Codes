#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 110, M = 9510;

int n, m;
int S, T;
int pos[N];
bool st[M];
int f[M];

int main()
{
    scanf("%d%d%d%d", &n, &S, &T, &m);

    for (int i = 1; i <= m; i ++ )
        scanf("%d", &pos[i]);

    if (S == T)
    {
        int ans = 0;
        for (int i = 1; i <= m; i ++ ) 
            if (pos[i] % S == 0) ans ++ ;
        printf("%d\n", ans);
        return 0;
    }
    sort(pos + 1, pos + 1 + m);

    //路径压缩
    int dx = 0;
    for (int i = 1; i <= m; i ++ )
    {
        if (pos[i] - pos[i - 1] > 90)
            dx += pos[i] - pos[i - 1] - 90;    
        st[pos[i] - dx] = true;
    }

    if (n - pos[m] > 90)
        dx += n - pos[m] - 90;

    n -= dx;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n + 9; i ++ )
    {
        if (i - S < 0) continue;
        for (int j = S; j <= min(i, T); j ++ )
            f[i] = min(f[i], f[i - j] + st[i]);
    }   
    int ans = 0x3f3f3f3f;
    for (int i = n; i <= n + 9; i ++ )
        ans = min(ans, f[i]);

    printf("%d\n", ans);

    cerr << clock() << endl;

    return 0;
}