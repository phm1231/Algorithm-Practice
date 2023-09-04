#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
string matstr[1001];
int mat[1001][1001];
int mat_val[1001][1001];
bool visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = {0, 0, 1, -1};

int answer[1001][1001] = {0, };

vector<pair<int, int>> v_p;

void dfs(int x, int y, int &cnt, vector<vector<bool>>& visited_s) {
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny] && mat[nx][ny] == 0) {
         visited[nx][ny] = true;
         dfs(nx, ny, ++cnt, visited_s);
      }
      else if (mat[nx][ny] == 1) {
         if (!visited_s[nx][ny]) {
            visited_s[nx][ny] = true;
            v_p.push_back({ nx, ny });
         }
      }
   }
}

int bfs(int sx, int sy, vector<vector<bool>>& visited_s) {
   int cnt = 0;

   queue<pair<int, int> > q;
   q.push(make_pair(sx, sy));
   visited_s[sx][sy] = true;

   while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny] && mat[nx][ny] == 0) {
            cnt++;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
         }
         else if (mat[nx][ny] == 1) {
            if (!visited_s[nx][ny]) {
               visited_s[nx][ny] = true;
               v_p.push_back({ nx, ny });
            }
         }
      }
   }

   return cnt;
}

int main()
{
   cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
   cin >> N >> M;
   for (int i = 0; i < N; i++) {
      cin >> matstr[i];
      for (int j = 0; j < M; j++) {
         mat[i][j] = matstr[i][j] == '1' ? 1 : 0;
      }
   }
   // 빈칸들이 몇개씩 이어져 있는지 계산
   int idx = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         vector<vector<bool>> visited_s(N, vector<bool>(M, false));
         if (mat[i][j] == 0 && !visited[i][j]) {
            int cnt = bfs(i, j, visited_s);
            while (!v_p.empty()) {
               pair<int, int> p = v_p.back();
               answer[p.first][p.second] += cnt;
               answer[p.first][p.second] %= 10;
               v_p.pop_back();
            }
            idx++;
         }
      }
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cout << answer[i][j];
      }
      cout << '\n';
   }

   return 0;
}