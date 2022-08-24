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
using namespace std;

void init();
void input();
void solve();

int n, k;
vector<int> v;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    int input;

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &input);
        v.push_back(input);
    }    
}

void solve()
{
    sort(v.begin(), v.end(), greater<int>());
    printf("%d", v[k-1]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}