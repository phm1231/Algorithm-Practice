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

int n, m;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
vector<string> board;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
}

void solve()
{
    vector<vector<int> > visited(n, vector<int>(m, 987654321));
    visited[0][0] = 1;
    queue<pair<int, int> > q;
    q.push({0, 0});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(board[ny][nx] == '1' && visited[ny][nx] > visited[y][x] + 1){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }


    cout << visited[n-1][m-1];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}