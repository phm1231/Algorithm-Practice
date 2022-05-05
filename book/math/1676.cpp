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

int n;

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
    scanf("%d", &n);
}

void solve()
{
    int numberofzero = 0;
    for(int i=5; i<=n; i+=5)
    {
        numberofzero++;
    }
    for(int i=25; i<=n; i+=25)
    {
        numberofzero++;
    }
    for(int i=125; i<=n; i+=125)
    {
        numberofzero++;   
    }
    printf("%d", numberofzero);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}