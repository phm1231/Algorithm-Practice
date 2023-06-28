// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<string> board;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
}

void solve()
{
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    vector<int> answer;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '0') continue;
            if(visited[i][j]) continue;

            queue<pair<int, int> > q;
            q.push({i, j});
            visited[i][j] = true;
            int siz = 1;
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for(int a=0; a<4; a++){
                    int ny = y + dy[a];
                    int nx = x + dx[a];
                    if(0 <= ny && ny < n && 0 <= nx && nx < n){
                        if(board[ny][nx] == '1' && !visited[ny][nx]){
                            visited[ny][nx] = true;
                            siz++;
                            q.push({ny, nx});
                        }
                    }
                }
            }
            answer.push_back(siz);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for(int a: answer) cout << a << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}