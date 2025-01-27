#include <iostream>
#include <algorithm>
#include <time.h> 
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

int n, m;
char g[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ )
        scanf("%s", g[i]);

    int ey = -1, sx = -1, wy = N, nx = N;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '#')
            {
                if (i > sx) sx = i;
                if (i < nx) nx = i;
                if (j > ey) ey = j;
                if (j < wy) wy = j;
            }

    bool su = true;
    for (int i = nx; i <= sx; i ++ )
    {
        for (int j = wy; j <= ey; j ++ )
            if (g[i][j] == '.')
            {
                su = false;
                break;
            }
        if (!su) break;
    }

    if (!su) puts("No");
    else puts("Yes");    

    cerr << clock() << endl;

    return 0;
}