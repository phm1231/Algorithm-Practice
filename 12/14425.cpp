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
#include <map>

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
    for(int i=0; i<n; i++)
    {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for(int i=0; i<m; i++)
    {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{
    int answer = 0;
    int siz = v.size();

    for(int i=0; i<siz; i++)
    {
        auto checker = s.insert(v[i]);
        if(checker.second)
        {
            s.erase(v[i]);
        }
        else
        {
            answer++;   
        }
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}