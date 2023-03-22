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
#include <set>


#define ll long long
#define MAX 1001

using namespace std;

void init();
void input();
void solve();

string str;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> str;
}

void solve()
{
    set<string> s;
    int length = str.length();
    for(int i=1; i<length; i++)
    {
        for(int j=0; j<length - i + 1; j++)
        {
            s.insert(str.substr(j, i));
        }
    }
    s.insert(str);

    cout << s.size();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}