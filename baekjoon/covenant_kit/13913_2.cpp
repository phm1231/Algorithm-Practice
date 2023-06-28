// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, k;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
}

void solve()
{
    if(n == k){
        cout << 0 << "\n" << n;
        return;
    }

    vector<bool> visited(100001, false);
    vector<int> parents(100001, 0);
    queue<int> q;
    parents[n] = n;
    visited[n] = true;
    q.push(n);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int next:{here*2, here+1, here-1}){
            if(next < 0 || next > 100000) continue;
            if(visited[next]) continue;

            if(next == k){
                parents[next] = here;
                stack<int> path;
                int x = next;
                while(x != n){
                    path.push(x);
                    x = parents[x];
                }
                path.push(n);
                cout << path.size() - 1 << "\n";
                while(!path.empty()){
                    int tmp = path.top();
                    path.pop();
                    cout << tmp << ' ';
                }
                return;
            }

            visited[next] = true;
            parents[next] = here;
            q.push(next);
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