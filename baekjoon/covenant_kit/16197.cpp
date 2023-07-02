// based problem:
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
bool checkY(int);
bool checkX(int);

int n, m, sy1, sx1, sy2, sx2;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};
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
    bool isOne = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'o'){
                board[i][j] = '.';
                if(isOne){
                    sy2 = i;
                    sx2 = j;
                }
                else{
                    sy1 = i;
                    sx1 = j;
                    isOne = true;
                }
            }
        }
    }
}

void solve()
{
    queue<pair<int, int> > Q1;
    queue<pair<int, int> > Q2;
    bool visited[21][21][21][21];
    memset(visited, false, sizeof(visited));

    Q1.push({sy1, sx1});
    Q2.push({sy2, sx2});
    visited[sy1][sx1][sy2][sx2] = true;
    visited[sy2][sx2][sy1][sx1] = true;

    int answer = 0;
    while(!Q1.empty()){
        int qs = Q1.size();
        answer++;
        if(answer > 10){
            cout << -1;
            return;
        }
        while(qs--){
            int hy1 = Q1.front().first;
            int hx1 = Q1.front().second;
            int hy2 = Q2.front().first;
            int hx2 = Q2.front().second;
            Q1.pop(), Q2.pop();

            for(int i=0; i<4; i++){
                int ny1 = hy1 + dy[i];
                int nx1 = hx1 + dx[i];
                int ny2 = hy2 + dy[i];
                int nx2 = hx2 + dx[i];

                // 모두 범위 안이면
                if(checkY(ny1) && checkX(nx1) && checkY(ny2) && checkX(nx2)){
                    // 벽이라면
                    if(board[ny1][nx1] == '#'){
                        ny1 = hy1;
                        nx1 = hx1;
                    }
                    if(board[ny2][nx2] == '#'){
                        ny2 = hy2;
                        nx2 = hx2;
                    }

                    // 이미 방문한 곳이라면
                    if(visited[ny1][nx1][ny2][nx2]) continue;
                    // 두 동전이 겹쳤다면
                    if(ny1 == ny2 && nx1 == nx2) continue;

                    // 이동 가능한 곳
                    if(board[ny1][nx1] == '.' && board[ny2][nx2] == '.'){
                        visited[ny2][nx2][ny1][nx1] = visited[ny1][nx1][ny2][nx2] = true;
                        Q1.push({ny1, nx1});
                        Q2.push({ny2, nx2});
                        continue;
                    }
                }
                // 1번 동전이 범위 밖으로, 2번 동전이 범위 안에.
                else if( (!checkY(ny1) || !checkX(nx1)) && (checkY(ny2) && checkX(nx2)) ){
                    cout << answer;
                    return;
                }
                // 2번 동전이 범위 안에, 1번 동전이 범위 밖에.
                else if( (!checkY(ny2) || !checkX(nx2)) && (checkY(ny1) && checkX(nx1)) ){
                    cout << answer;
                    return;
                }
                // 모두 범위 밖에
            }
        }
    }
    cout << -1;
}

bool checkY(int number){
    return (0 <= number && number < n);
}

bool checkX(int number){
    return (0 <= number && number < m);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}