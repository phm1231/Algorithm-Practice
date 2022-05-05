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
#define MAX 1001
// #define CPP_INOUT true

using namespace std;

void init();
void input();
void solve();

char n[20];
stack<char> stk;
int b;

void init()
{
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif

    memset(n, 0, sizeof(n));
}

void input()
{
    scanf("%s %d", n, &b);
    for(int i=0; i<strlen(n); i++)
    {
        stk.push(n[i]);
    }
}

void solve()
{
    int sum = 0;
    int weight = 1;
    while(!stk.empty())
    {
        char ch = stk.top();
        if('A' <= ch && ch <= 'Z')
        {
            sum = sum + (ch - 'A' + 10) * weight;
        }
        else if('0' <= ch && ch <= '9')
        {
            sum = sum + (ch - '0') * weight;
        }
        stk.pop();
        weight = weight * b;
    }
    printf("%d", sum);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}