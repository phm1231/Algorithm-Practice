// based problem:
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n, min_height, max_height;
vector<vector<int> > board;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};


void init()
{
    FAST
}

void input()
{
    min_height = 987654321;
    max_height = 0;

    cin >> n;
    board.resize(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            min_height = min(min_height, board[i][j]);
            max_height = max(max_height, board[i][j]);
        }
    }
}

void solve()
{   
    int answer = 1;

    for(int height = min_height; height < max_height; height++){
        vector<vector<bool> > visited(n, vector<bool>(n, false));
        queue<pair<int, int> > q;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] > height) q.push({i, j});
            }
        }
        int _answer = 0;
        while(!q.empty()){
            int _y = q.front().first;
            int _x = q.front().second;
            q.pop();

            if(!visited[_y][_x]){
                _answer++;
                visited[_y][_x] = true;
                stack<pair<int, int> > stk;
                stk.push({_y, _x});

                while(!stk.empty()){
                    int y = stk.top().first;
                    int x = stk.top().second;
                    stk.pop();
                    
                    for(int i=0; i<4; i++){
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(0 <= ny && ny < n && 0 <= nx && nx < n){
                            if(board[ny][nx] > height && !visited[ny][nx]){
                                visited[ny][nx] = true;
                                stk.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
        answer = max(answer, _answer);
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