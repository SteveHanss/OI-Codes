#include <iostream>
#include <algorithm>
#include <time.h> 
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    bool su = true;
    for (int i = 1; i <= n - 3 + 1; i ++ )
        if ((LL)a[i + 2] * a[i] != (LL)a[i + 1] * a[i + 1])
        {
            su = false;
            break;
        }  
    if (su) puts("Yes");
    else puts("No");

    cerr << clock() << endl;

    return 0;
}