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

stack<int> stk;
int n;
char command[10];

void init()
{
    memset(command, 0, sizeof(command));
}

void input()
{
    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++)
    {
        char ch;
        scanf("%s", command);
        if(strcmp(command, "push") == 0)
        {
            int item;
            scanf("%d", &item);
            stk.push(item);
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", stk.size());
        }
        else if (strcmp(command, "pop") == 0)
        {
            if(!stk.empty())
            {
                int popitem = stk.top();
                stk.pop();
                printf("%d\n", popitem);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (strcmp(command, "top") == 0)
        {
            if(!stk.empty())
            {
                int popitem = stk.top();
                printf("%d\n", popitem);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (strcmp(command, "empty") == 0)
        {
            stk.empty() ? printf("1\n") : printf("0\n");
        }
        else
        {

        }
        while ( (ch = getchar()) != '\n') ;
    }
}

void solve()
{

}

int main()
{
    init();
    input();
    solve();
    return 0;
}