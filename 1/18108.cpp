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

int year;
int weight;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    weight = 543;
}

void input()
{
    cin >> year;
}

void solve()
{
    cout << year - weight;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}