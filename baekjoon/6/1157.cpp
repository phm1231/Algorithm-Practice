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
#define MAX 1000001
using namespace std;

void init();
void input();
void solve();

char str[MAX];
int res[26];
int result = INT_MIN;
char chr_result;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(str, 0, sizeof(str));
    memset(res, 0, sizeof(res));

}

void input()
{
    scanf("%s", str);
}

void solve()
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if('A' <= str[i] && str[i] <= 'Z' ) res[str[i] - 'A']++;
        else if ('a' <= str[i] && str[i] <= 'z') res[str[i] - 'a'] ++;
    }

    for(int i=0; i<26; i++)
    {
        if(result < res[i])
        {
            chr_result = i + 'A';
            result = res[i];
        }
    }

    int count = 0;
    for(int i=0; i<26; i++)
    {
        if(result == res[i])
        {
            count++;
        }
    }

    if(count == 1) cout << chr_result;
    else cout << '?';

}

int main()
{
    init();
    input();
    solve();
    return 0;
}