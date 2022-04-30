// based problem: sort
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

typedef struct Info
{
    int age;
    char name[101];
}Info;

void init();
void input();
void solve();
bool compare(Info, Info);

int n;
Info arr[MAX];

void init()
{
    memset(arr, 0, sizeof(arr));
}

void input()
{
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++)
    {
        scanf("%d %s", &arr[i].age, &arr[i].name);
        getchar();
    }
}

void solve()
{
    stable_sort(arr, arr + n, compare);
    for(int i=0; i<n; i++)
    {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
}

bool compare(Info p, Info q)
{
    return p.age < q.age;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}