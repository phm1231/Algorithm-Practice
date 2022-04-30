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
    string name;
}Info;

void init();
void input();
void solve();
bool compare(Info, Info);

int n;
Info arr[MAX];

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i].age >> arr[i].name;
    }
}

void solve()
{
    stable_sort(arr, arr + n, compare);
    for(int i=0; i<n; i++)
    {
        cout << arr[i].age << ' ' << arr[i].name << endl;
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