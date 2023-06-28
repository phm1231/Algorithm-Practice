
// based problem:
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

ll a, b, answer;
void bfs(ll, ll);

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
    bfs(a, 0);
    if(answer == 987654321) cout << -1;
    else cout << answer + 1;
}

void bfs(ll number, ll cnt){
    if(number == b){
        answer = 0;
        return;
    }
    queue<pair<ll, ll> > q;
    q.push({number, cnt});
    while(!q.empty()){
        ll here = q.front().first;
        ll c = q.front().second;
        q.pop();

        for(ll next:{here * 2, here * 10 + 1}){
            if(next == b){
                answer = c + 1;
                return;
            }
            if(next > b) continue;
            q.push({next, c+1});
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