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
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int n, m;
set<string> s;
vector<string> v;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n >> m;
}

void solve()
{
    string str;
    for(int i=0; i<n; i++)
    {
        cin >> str;
        auto check = s.insert(str);
        if(!check.second)
        {
            v.push_back(str);
        }
    }

    for(int i=0; i<m; i++)
    {
        cin >> str;
        auto check = s.insert(str);
        if(!check.second)
        {
            v.push_back(str);
        }
    }

    int siz = v.size();
    sort(v.begin(), v.end());
    cout << siz << "\n";
    for(int i=0; i<siz; i++) cout << v[i] << "\n";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}