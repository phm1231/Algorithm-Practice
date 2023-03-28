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

string s1;
string s2;
string s3;

int dp[101][101][101];

void init()
{
    FAST
    memset(dp, 0, sizeof(dp));
}

void input()
{
    cin >> s1;
    cin >> s2;
    cin >> s3;
}

void solve()
{
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            for(int k=1; k<=s3.size(); k++){
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    cout << dp[s1.size()][s2.size()][s3.size()];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}