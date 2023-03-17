// based problem: Hanoi
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
#define MAX 21
using namespace std;

int n;
ll dp[MAX];

void init();
void input();
void solve();
void hanoi(int, int, int);
void print_pair(int, int);

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, 0, sizeof(dp));
}

void input()
{
    dp[1] = 1;
    cin >> n;

    for(int i=2; i<=n; i++) dp[i] = dp[i-1]*2+1;
}

void solve()
{
    cout << dp[n] << "\n";
    hanoi(n, 1, 3);
}

void hanoi(int num, int src, int dst)
{
    int tmp;
    if(num == 1)
    {
        print_pair(src, dst);
    }

    else
    {
        if(dst == 1)
        {
            if(src == 2) tmp = 3;
            if(src == 3) tmp = 2;
        }
        else if(dst == 2)
        {
            if(src == 3) tmp = 1;
            if(src == 1) tmp = 3;
        }
        else if(dst == 3)
        {
            if(src == 1) tmp = 2;
            if(src == 2) tmp = 1;
        }

        hanoi(num-1, src, tmp);
        hanoi(1, src, dst);
        hanoi(num-1, tmp, dst);
    }
}

void print_pair(int src, int dst)
{
    cout << src << " " << dst << "\n";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}