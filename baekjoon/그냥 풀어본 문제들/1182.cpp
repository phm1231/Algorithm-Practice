
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
using namespace std;

void init();
void input();
void solve();
void dfs(int, int, bool);

vector<int> inputs;
int n, m, result;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        inputs.push_back(tmp);
    }
}

void solve()
{
    sort(inputs.begin(), inputs.end());
    dfs(inputs[0], 1, true); // 선택
    dfs(0, 1, false); // 선택하지 않음
    cout << result;

}

void dfs(int sum, int idx, bool b){

    if(idx < inputs.size()){
        dfs(sum + inputs[idx], idx+1, true);
        dfs(sum, idx+1, b ? true : false);
    }

    else{
        if(sum == m && b) result++;
    }

    return;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}