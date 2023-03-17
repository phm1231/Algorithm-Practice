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
#include <map>

#define ll long long
#define MAX 101
#define WEIGHT 1000000000
using namespace std;

void init();
void input();
void solve();

int n;
vector<int> v_origin;
vector<int> v_sorted;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    int input;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &input);
        v_origin.push_back(input);
    }
}

void solve()
{
    v_sorted = v_origin;
    sort(v_sorted.begin(), v_sorted.end());
    v_sorted.erase(unique(v_sorted.begin(), v_sorted.end()), v_sorted.end());
    int len = v_sorted.size();

    map<int, int> m;
    for(int i=0; i<len; i++)
    {
        m.insert({v_sorted[i], i});
    }

    for(int i=0; i<n; i++)
    {
        auto item = m.find(v_origin[i]);
        printf("%d ", item->second);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}