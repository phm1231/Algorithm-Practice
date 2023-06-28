// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

ll a, b, answer;
void dfs(ll, ll);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> a >> b;
}

void solve()
{
    answer = 987654321;
    dfs(a, 0);

    if(answer == 987654321) cout << -1;
    else cout << answer + 1;
}

void dfs(ll number, ll cnt){
    if(number == b){
        answer = min(cnt, answer);
        return;
    }
    if(number > b) return;

    dfs(number * 2, cnt + 1);
    dfs(number * 10 + 1, cnt + 1);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}