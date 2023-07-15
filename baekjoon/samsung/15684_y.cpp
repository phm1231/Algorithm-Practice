#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
vector<vector<char>> v;
int answer = 4;

bool check() {
   for (int i = 0; i < N; i++) {
      vector<int> cur{ 1, i + 1 };
      char tmp = 'd';
      while (cur[0] < H + 1) {
         if (v[cur[0]][cur[1]] == 'd') {
            cur[0] += 1;
            tmp = 'd';
         }
         else if (v[cur[0]][cur[1]] == 'r') {
            if (tmp == 'z') {
               cur[0] += 1;
               tmp = 'd';
            }
            else {
               cur[1] += 1;
               tmp = 'z';
            }
         }
         else if (v[cur[0]][cur[1]] == 'l') {
            if (tmp == 'z') {
               cur[0] += 1;
               tmp = 'd';
            }
            else {
               cur[1] -= 1;
               tmp = 'z';
            }
         }
      }
      if (i + 1 != cur[1]) return false;
   }
   return true;
}

void dfs(int cnt, int idx1, int idx2) {
   if (cnt <= 3) {
      if (check()) {
         answer = min(answer, cnt);
      }
      if (cnt == 3) return;
   }
   for (int i = idx1; i <= H; i++) {
      for (int j = idx2; j < N; j++) {
         if (v[i][j] == 'd' && v[i][j + 1] == 'd') {
            v[i][j] = 'r';
            v[i][j + 1] = 'l';
            if (j + 1 < N) {
               dfs(cnt + 1, i, j + 1);
            }
            else if (i + 1 <= H) {
               dfs(cnt + 1, i + 1, 1);
            }
            v[i][j] = 'd';
            v[i][j + 1] = 'd';
         }
      }
   }
}

int main() {
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);

   cin >> N >> M >> H;

   v.resize(H + 1, vector<char>(N + 1, 'd'));

   for (int i = 0; i < M; i++) {
      int q, w;
      cin >> q >> w;
      v[q][w] = 'r';
      v[q][w + 1] = 'l';
   }
   dfs(0, 1, 1);

   if (answer == 4) cout << -1;
   else cout << answer;

   return 0;
}