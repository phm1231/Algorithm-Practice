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
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();
int check(int);

string s;

void init()
{
    FAST
}

void input()
{
    cin >> s;
}

void solve()
{
    int answer = 0;
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    
    for(int i=0; i<s.size(); i++) dp[i][i] = true;

    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]) dp[i][i+1] = true;
    }

    for(int len=3; len<=s.size(); len++){
        for(int i=0; i+len<=s.size(); i++){
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                answer = len;
            }
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