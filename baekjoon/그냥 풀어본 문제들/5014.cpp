// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int f, s, g, u, d;
vector<bool> visited;

// 총 f층
// u층 위, d층 아래
// s층 현재, g층 목적지

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> f >> s >> g >> u >> d;
    visited.resize(f+1, false);
}

void solve()
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    int answer = 0;
    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            int here = q.front();
            q.pop();

            if(here == g){
                cout << answer;
                return;
            }

            int up = here + u;
            if(up <= f && !visited[up]){
                visited[up] = true;
                q.push(up);
            }
            int down = here - d;
            if(1 <= down && !visited[down]){
                visited[down] = true;
                q.push(down);
            }
        }
        answer++;
    }
    cout << "use the stairs";
}


int main()
{
    init();
    input();
    solve();
    return 0;
}