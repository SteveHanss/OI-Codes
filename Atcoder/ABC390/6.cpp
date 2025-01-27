#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h> 
#include <cstring>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n;
int a[N];
int pos[N];
int pre[N], ne[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    for (int i = 1; i <= n + 1; i ++ ) pos[i] = 0; // i - 0 = i
    for (int i = 1; i <= n; i ++ )
    {
        pre[i] = max(pos[a[i]], pos[a[i] + 1]); //求前驱
        pos[a[i]] = i; //更新
    }

    for (int i = 1; i <= n + 1; i ++ ) pos[i] = n + 1; // n + 1 - i = n - i + 1
    for (int i = n; i >= 1; i -- )
    {
        ne[i] = pos[a[i] + 1];
        pos[a[i]] = i;
    }

    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
        ans += (LL)(i - pre[i]) * (ne[i] - i);
    printf("%lld\n", ans);

    cerr << clock() << endl;

    return 0;
}