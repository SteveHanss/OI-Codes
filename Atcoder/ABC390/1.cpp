#include <iostream>
#include <algorithm>
#include <time.h> 
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 6;

int a[N];

int main()
{
    for (int i = 0; i < 5; i ++ ) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < 4; i ++ )
        for (int j = i + 1; j < 5; j ++ )
        if (a[j] < a[i])
            cnt ++ ;

    if (cnt == 1) puts("Yes");
    else puts("No");

    cerr << clock() << endl;

    return 0;
}