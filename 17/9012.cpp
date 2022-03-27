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

int t;
stack<int> stk;

void init()
{

}

void input()
{
    scanf("%d", &t);
    getchar();
}

void solve()
{
    char ch;
    bool flag = true;
    while(!stk.empty()) stk.pop();

    while (1)
    {
        ch = getchar();
        if (ch == '\n') break;
        else if (ch == '(') stk.push(1);
        else if (ch == ')')
        {
            if(stk.empty()) flag = false;
            else stk.pop();
        }
    }
    if(!stk.empty()) flag = false;

    flag ? printf("YES\n") : printf("NO\n");
}

int main()
{
    init();
    input();
    for(int i=0; i<t; i++)
    {
        solve();
    }
    return 0;
}