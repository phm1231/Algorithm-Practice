#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    vector<int> visited(n+1, 987654321);
    visited[n] = 0;
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        if(here == 1) break;

        if(here % 3 == 0){
            int tmp = here / 3;
            if(visited[tmp] > visited[here] + 1){
                visited[tmp] = visited[here] + 1;
                q.push(tmp);
            }
        }
        if(here % 2 == 0){
            int tmp = here / 2;
            if(visited[tmp] > visited[here] + 1){
                visited[tmp] = visited[here] + 1;
                q.push(tmp);
            }
        }
        int tmp = here - 1;
        if(visited[tmp] > visited[here] + 1){
            visited[tmp] = visited[here] + 1;
            q.push(tmp);
        }
    }

    int here = 1;
    int cnt = visited[here];
    cout << cnt << endl;
    stack<int> stk;
    stk.push(here);
    while(here != n){
        int next = here * 3;
        if(next <= n && visited[next] == cnt - 1){
            cnt = visited[next];
            stk.push(next);
            here = next;
            continue;
        }
        next = here * 2;
        if(next <= n && visited[next] == cnt - 1){
            cnt = visited[next];
            stk.push(next);
            here = next;
            continue;
        }
        next = here + 1;
        if(next <= n && visited[next] == cnt - 1){
            cnt = visited[next];
            stk.push(next);
            here = next;
            continue;
        }   
    }
    while(!stk.empty()){
        cout << stk.top() << ' ';
        stk.pop();
    }
    
}


int main()
{
    init();
    input();
    solve();
    return 0;
}