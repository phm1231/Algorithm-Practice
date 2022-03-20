// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

#define ll long long
#define MAX 1001

using namespace std;

void init();
void input();
void solve();
void check();

bool map[MAX][MAX];
int n, m;

void init()
{
    memset(map, false, sizeof(map));
}

void input()
{
    char ch;
    scanf("%d %d", &n, &m);
    while( (ch = getchar()) != '\n') ;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%c", &ch);
            if(ch == '0') map[i][j] = 0;
            if(ch == '1') map[i][j] = 1;
        }
        getchar();
    }    
}

void solve()
{
    check();
}

void check()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%d", map[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}