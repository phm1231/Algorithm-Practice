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
#define MAX 300001

using namespace std;

void init();
void input();
void solve();
int getNext(int);

int a, p;
int visited[MAX];

void init()
{
    memset(visited, 0, sizeof(visited));
}

void input()
{
    scanf("%d %d", &a, &p);
}

void solve()
{
    int current_value = a;
    int ans = 0;
    visited[current_value]++;

    while(1)
    {
        int next = getNext(current_value);

        if(visited[next] <= 1)
        {
            visited[next]++;
        }
        else
        {
            break;
        }
        current_value = next;
    }
    for(int i=0; i<MAX; i++)
    {
        if(visited[i] == 1) ans++;
    }
    printf("%d", ans);
    
}

int getNext(int v)
{
    char num_str[10];
    int num_str_len;
    int ret = 0;
    sprintf(num_str, "%d", v);
    num_str_len = strlen(num_str);
    for(int i=0; i<num_str_len; i++)
    {
        ret = ret + (int)pow(num_str[i] - '0', p);
    }
    return ret;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}