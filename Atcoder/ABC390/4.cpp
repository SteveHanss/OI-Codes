#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <time.h> 
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 12;

int n;
LL a[N];
LL s[N];
LL val;
unordered_set<LL> st;

void dfs(int u, int cnt)
{
    for (int i = 0; i <= cnt; i ++ )
    {
       val ^= s[i];
       s[i] += a[u];
       val ^= s[i];
       if (u == n - 1) st.insert(val);
       else if (i < cnt) dfs(u + 1, cnt);
       else dfs(u + 1, cnt + 1);
       val ^= s[i];
       s[i] -= a[u];
       val ^= s[i];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    dfs(0, 0);
    cout << (int)st.size() << endl;

    cerr << clock() << endl;

    return 0;
}