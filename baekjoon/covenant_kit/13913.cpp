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
        cout << 0 << "\n" << n << endl;
        return;
    }
    if(n > k){
        cout << n-k << "\n";
        for(int i=n; i>=k; i--){
            cout << i << ' ';
        }
        return;
    }

    queue<int> q;
    queue<vector<int> > paths;
    vector<bool> visited(100001, false);

    vector<int> init_path;
    init_path.push_back(n);
    q.push(n);
    paths.push(init_path);
    visited[n] = true;


    while(!q.empty()){
        int here = q.front();
        vector<int> path = paths.front();
        q.pop(), paths.pop();

        for(int next:{here*2, here+1, here-1}){
            if(next < 0 || next > 100000) continue;
            if(visited[next]) continue;
            if(next == k){
                cout << path.size() << "\n";
                for(int p: path) cout << p << ' ';
                cout << next;
                return;
            }

            visited[next] = true;
            q.push(next);

            path.push_back(next);
            paths.push(path);
            path.pop_back();
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