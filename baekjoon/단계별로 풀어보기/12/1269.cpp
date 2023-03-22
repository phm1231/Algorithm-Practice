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
#include <set>

#define ll long long
#define MAX 200001
using namespace std;

void init();
void input();
void solve();
void counter(set<int>, set<int>);

int n, m, answer;
set<int> sa;
set<int> sb;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    answer = 0;
}

void input()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        sa.insert(tmp);
    }

    for(int i=0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        sb.insert(tmp);
    }
}

void solve()
{
    counter(sa, sb);
    counter(sb, sa);
    cout << answer;
}

void counter(set<int> puller, set<int> pusher)
{
    for(set<int>::iterator iter=pusher.begin(); iter!=pusher.end(); iter++)
    {
        auto isThere = puller.insert(*iter);
        if(isThere.second)
        {
            answer++;
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}