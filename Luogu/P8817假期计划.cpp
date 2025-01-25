#include <iostream>
#include <time.h>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 2510, M = 2e4 + 10;

int n, m, k;
int h[N], ne[M], e[M], idx;
LL w[N];
int f[N][4]; //f(i, j) 表示 i 可达的在家附近且第 j 大的点
int dist[N][N];

void add(int a, int b)
{
    ne[++ idx] = h[a], e[idx] = b, h[a] = idx;
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    dist[u][u] = 0;
    while (q.size())
    {
        int t = q.front(); q.pop();
        if (dist[u][t] >= k + 1) continue;
        for (int i = h[t]; i; i = ne[i])
        {
            int j = e[i];
            if (dist[u][j] == -1)
            {
                dist[u][j] = dist[u][t] + 1;
                if (u != 1 && dist[1][j] <= k + 1 && dist[1][j] != -1)
                {
                    for (int i = 1; i <= 3; i ++ )
                        if (w[j] > w[f[u][i]])
                        {
                            for (int k = 3; k >= i + 1; k -- ) 
                                f[u][k] = f[u][k - 1];
                            f[u][i] = j;
                            break;
                        }
                }
                q.push(j);
            }
        }
    }
}

bool check(int a, int b, int c, int d)
{
    if (a == b || b == c || c == d || a == c || b == d || a == d) return false;
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 2; i <= n; i ++ )
        scanf("%lld", &w[i]);

    for (int i = 1; i <= m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= n; i ++ )
        bfs(i);

    LL ans = -1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 2; j <= n; j ++ )
            if (i != j && ~dist[i][j])
            {
                vector<int> tmp1, tmp2;
                for (int k = 1; k <= 3; k ++ )
                {
                    if (f[i][k]) tmp1.push_back(f[i][k]);
                    if (f[j][k]) tmp2.push_back(f[j][k]);
                }
                for (int ii = 0; ii < tmp1.size(); ii ++ )
                    for (int jj = 0; jj < tmp2.size(); jj ++ )
                    {
                        int a = tmp1[ii], b = tmp2[jj];
                        if (check(a, b, i, j))
                            ans = max(ans, w[a] + w[b] + w[i] + w[j]);
                    }
            }

    printf("%lld\n", ans);

    cerr << clock() << endl;

    return 0;
}
