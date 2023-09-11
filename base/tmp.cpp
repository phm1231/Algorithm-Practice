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

int N, M, answer = 987654321;
vector<vector<int>> mat(9, vector<int>(9));
vector<pair<int, int>> cctvs;
int dir[9];
bool visited[9];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void see(int x, int y, int added, int& i, vector<vector<int>>& tmp) {
   /*while (true) {
      int nx += dx[(dir[i] + added) % 4];
      int ny += dy[(dir[i] + added) % 4];
      if (0 <= nx && nx < N && 0 <= ny && ny < M && tmp[nx][ny] != 6) {
         if (tmp[nx][ny] == 0) {
            tmp[nx][ny] = 7;
         }
      }
      else break;
   }*/
}

int check() {
   vector<vector<int>> tmp = mat;
   for (int i = 0; i < cctvs.size(); i++) {
    int nx = cctvs[i].first;
    int ny = cctvs[i].second;
    int cur = tmp[cctvs[i].first][cctvs[i].second];

      if (cur == 1) {
         see(nx, ny, 0, i, tmp);
      }
      else if (cur == 2) {
         see(nx, ny, 0, i, tmp);
         see(nx, ny, 2, i, tmp);
      }
      else if (cur == 3) {
         see(nx, ny, 0, i, tmp);
         see(nx, ny, 1, i, tmp);
      }
      else if (cur == 4) {
         see(nx, ny, 0, i, tmp);
         see(nx, ny, 1, i, tmp);
         see(nx, ny, 3, i, tmp);
      }
      else if (cur == 5) {
         for (int j = 0; j < 4; j++) {
            see(nx, ny, j, i, tmp);
         }
      }
   }

   int res = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         if (tmp[i][j] == 0) res++;
      }
   }

   return res;
}

void dfs(int cnt, vector<int>& v) {
   if (cnt == cctvs.size()) {
      answer = min(answer, check());
      return;
   }
   
   for (int i = 0; i < cctvs.size(); i++) {
      if (visited[i]) continue;
      v.push_back(i);
      visited[i] = true;

      int cur = mat[cctvs[i].first][cctvs[i].second];
      if (cur == 1 || cur == 3 || cur == 4) {
         for (int j = 0; j < 4; j++) {
            dir[i] = j;
            dfs(cnt + 1, v);
         }
      }
      else if (cur == 2) {
         for (int j = 0; j < 2; j++) {
            dir[i] = j;
            dfs(cnt + 1, v);
         }
      }
      else if (cur == 5) {
         dfs(cnt + 1, v);
      }
        v.pop_back();
      visited[i] = false;
   }
}

int main() {
   cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

   cin >> N >> M;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cin >> mat[i][j];
         if (1 <= mat[i][j] && mat[i][j] <= 5) {
            cctvs.push_back({ i, j });
         }
      }
   }
    vector<int> v;
   dfs(0, v);

   cout << answer;

   return 0;
}