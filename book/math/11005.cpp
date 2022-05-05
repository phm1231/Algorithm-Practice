// based problem: Decimal To B_number_base

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
#define MAX 20
// #define CPP_INOUT true

using namespace std;

void init();
void input();
void solve();

char calculation[36];
int n, b;
stack<char> stk;

void init()
{
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
}

void input()
{
    scanf("%d %d", &n, &b);
}

void solve()
{
    for(int i=0; i<=9; i++) calculation[i] = i + '0';
    for(int i=10; i<=35; i++) calculation[i] = 'A' + (i - 10);

    while(n != 0)
    {
        stk.push(calculation[n%b]);
        n = n / b;
    }
    while(!stk.empty())
    {
        putchar(stk.top());
        stk.pop();
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}