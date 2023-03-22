// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int x, y, z;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> x >> y >> z;
}

void solve()
{
    int max_number = -1;
    int same_number = -1;

    if (x == y && y == z)
    {
        cout << 10000+x*1000;
    }
    else if (x == y || y == z || z == x)
    {
        if(x == y)
        {
            cout << 1000 + x*100;
        }
        else if (y == z)
        {
            cout << 1000 + y*100;
        }
        else if(z == x)
        {
            cout << 1000 + z*100;
        }
    }
    else
    {
        int max_value = x;
        max_value = max(max_value, y);
        max_value = max(max_value, z);
        cout << max_value * 100;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}