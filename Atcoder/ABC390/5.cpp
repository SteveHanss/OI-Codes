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

const int N = 5010;

int n, m;
vector<PII> food[4];
int f[4][N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ )
    {
        int v, a, c;
        scanf("%d%d%d", &v, &a, &c);
        food[v].push_back(make_pair(a, c));
    }

    for (int v = 1; v <= 3; v ++ )
        for (int i = 0; i < food[v].size(); i ++ )
        {
            int w = food[v][i].x, ve = food[v][i].y;
            for (int j = m; j >= ve; j -- )
            {
                if (i == 0) f[v][j] = w;
                else f[v][j] = max(f[v][j], f[v][j - ve] + w);
            }
        }

    int ans = 0;
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= m - i - 1; j ++ )
            ans = max(ans, min(f[1][i], min(f[2][j], f[3][m - i - j])));

    printf("%d\n", ans);

    cerr << clock() << endl;

    return 0;
}