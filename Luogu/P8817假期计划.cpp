#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 2510, M = 1e4 + 10;

int n, m, k;
int h[N], ne[M], e[M], idx;
LL w[N];
LL f[N][6]; //f(i, j) 表示的是从 1 开始，到 i，且已经经过了 j 个景点的最大值
bool st[N];
int dist[N][N];
vector<int> act[N];

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
                act[u].push_back(j);
                q.push(j);
            }
        }
    }
}

LL dfs(int u, int cnt)
{
    if (cnt == 1) return f[u][1] = w[u];
    if (f[u][cnt] != -1) return f[u][cnt];
    for (int i = 0; i < act[u].size(); i ++ )
    {
        int j = act[u][i];
        f[u][cnt] = max(f[u][cnt], dfs(j, cnt - 1) + w[u]);
    }
    return f[u][cnt];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 2; i <= n; i ++ )
        scanf("%d", &w[i]);

    for (int i = 1; i <= m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    memset(f, -1, sizeof f);
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= n; i ++ )
        bfs(i);

    dfs(1, 5);

    printf("%lld\n", f[1][5]);

    return 0;
}