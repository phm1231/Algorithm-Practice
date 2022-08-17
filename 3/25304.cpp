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
#define MAX 101
using namespace std;

void init();
void input();
void solve();

int x, n;
int values[MAX];
int counts[MAX];
int sum = 0;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(values, 0, sizeof(values));
    memset(counts, 0, sizeof(counts));
}

void input()
{
    cin >> x;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> values[i] >> counts[i];
}

void solve()
{
    for(int i=1; i<=n; i++)
    {
        sum += values[i] * counts[i];
    }
    x == sum ? cout << "Yes" : cout << "No";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}