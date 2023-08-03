// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct node{
    int a, b, d;
    node(int a, int b, int d): a(a), b(b), d(d) {}
}node;

void init();
void input();
void solve();

int n, m, answer;
int edge[20][20];
bool chk[20][20] = {false, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            edge[i][j] = -1;
        }
    }
    while(m--){
        int a, b;
        char c;
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = c - 'a';
    }
}

void solve()
{
    queue<node> q;
    q.push({0, 1, 0});
    answer = -1;

    while(!q.empty()){
        int a = q.front().a;
        int b = q.front().b;
        int d = q.front().d;
        q.pop();

        chk[a][b] = chk[b][a] = true;

        // bfs를 하다가 서로 같은 곳에 도착함.
        if(a == b){
            if(answer == -1) answer = d * 2;
            else answer = min(answer, d*2);
            continue;
        }
        // a와 b 사이에 길이 있음
        else if(edge[a][b] != -1){
            if(answer == -1) answer = d * 2 + 1;
            else answer = min(answer, d*2 + 1);
            continue;
        }

        for(int i=0; i<n; i++){
            if(i == a) continue;
            for(int j=0; j<n; j++){
                if(j == b) continue;
                // a-i, b-j간 길이 있고, a-i, b-j간 길이 동일하며, 동시에 방문한 적이 없던 지역이라면
                if(edge[a][i] != -1 && edge[b][j] != -1 && edge[a][i] == edge[b][j] && !chk[i][j]){
                    if(answer == -1 || d*2 < answer) q.push(node(i, j, d+1));
                }
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