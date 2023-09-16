#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

struct tile {
    int x;
    int y;
    int cnt;
    int maxNum;
    vector<int> routes;
};

int N, N2;
int mat[501][1001];
int tileNum[501][1001];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool visited[501][1001];
int minMove = 987654321;
int maxTile = -1;
vector<int> answer;

void bfs() {
    queue<tile> q;
    q.push({ 0, 0, 1, 1, vector<int>({1}) });
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int maxNum = q.front().maxNum;
        vector<int> routes = q.front().routes;
        q.pop();

        if(tileNum[x][y] == N*N-N/2){
            maxTile = tileNum[x][y];
            minMove = cnt;
            answer = routes;
            break;
        }

        if(tileNum[x][y] > maxTile){
            maxTile = tileNum[x][y];
            minMove = cnt;
            answer = routes;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N2){
                if(mat[nx][ny] == 0) continue; // 없는 타일
                if(visited[nx][ny]) continue; // 방문한적 있는 타일

                // 똑같은 타일
                if (tileNum[x][y] == tileNum[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny, cnt, tileNum[nx][ny], routes});
                }
                else if (mat[x][y] == mat[nx][ny]) {
                    visited[nx][ny] = true;
                    routes.push_back(tileNum[nx][ny]);
                    q.push({ nx, ny, cnt + 1, tileNum[nx][ny], routes});
                    routes.pop_back();
                }
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    cin >> N;
    N2 = N * 2;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N2; j += 2) {
                cin >> mat[i][j] >> mat[i][j + 1];
            }
        }
        else {
            for (int j = 1; j < N2 - 1; j += 2) {
                cin >> mat[i][j] >> mat[i][j + 1];
            }
        }
    }
    // 홀수 행 타일 정하기
    for (int i = 0; i < N; i += 2) {
        int t = (2 * N - 1) * (i / 2) + 1;
        for (int j = 0; j < N2; j += 2) {
            tileNum[i][j] = tileNum[i][j + 1] = t + j / 2;
        }
    }
    // 짝수 행 타일 정하기
    for (int i = 1; i < N2; i += 2) {
        int t = (2 * N - 1) * (i / 2) + N + 1;
        for (int j = 1; j < N2 - 1; j += 2) {
            tileNum[i][j] = tileNum[i][j + 1] = t + j / 2;
        }
    }

    bfs();

    cout << minMove << '\n';
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    
    return 0;
}