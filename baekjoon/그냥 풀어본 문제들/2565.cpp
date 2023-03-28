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
bool cmp(pair<int, int>&, pair<int, int>&);

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.first < b.first;
}
int n;
vector<pair<int, int> > lines;

void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int src, dst;
        cin >> src >> dst;
        lines.push_back(make_pair(src, dst));
    }
}

void solve()
{
    sort(lines.begin(), lines.end(), cmp); // 오름차순 정렬
    int dp[101] = {0, };
    int answer = 0;
    for(int i=0; i<n; i++){
        int minimum = 1;
        for(int j=0; j<i; j++){
            if(lines[i].second > lines[j].second){
                minimum = max(dp[j], minimum);
            }
        }
        dp[i] = minimum + 1;
        answer = max(answer, dp[i]);
    }
    cout << n - answer << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}