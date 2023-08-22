
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int N, M, K, answer{ 0 };
vector<vector<int>> v;
vector<vector<pair<vector<int>, pair<int, int>>>> arr;
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool check(int x, int y) {
    vector<int> cur = arr[x][y].first;
    int tmp = cur[0] % 2;
    for (int i = 1; i < cur.size(); i++) {
        if (cur[i] % 2 != tmp) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    arr.resize(N, vector< pair<vector<int>, pair<int, int>>>(N));
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        v.push_back({ r - 1, c - 1, m, s, d });
    }

    while (K--) {
        while (!v.empty()) {
            vector<int> cur = v.back(); // 현재 파이어볼
            v.pop_back();
            int nr, nc;
            int nrtmp = cur[0] + dr[cur[4]] * cur[3];
            int nctmp = cur[1] + dc[cur[4]] * cur[3];
            if (nrtmp >= 0) {
                nr = nrtmp % N;
            }
            else {
                nr = N + nrtmp % N;
            }
            if (nctmp >= 0) {
                nc = nctmp % N;
            }
            else {
                nc = N + nctmp % N;
            }
            arr[nr][nc].second.first += cur[2]; // 질량
            arr[nr][nc].second.second += cur[3]; // 속력
            arr[nr][nc].first.push_back(cur[4]); // 방향
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int as = arr[i][j].first.size();
                if (as >= 2) {
                    // [i][j]에 있는 파이어볼들이 저장되어있는거잖아
                    int weight = arr[i][j].second.first / 5;
                    int speed = arr[i][j].second.second / as;
                    if (weight == 0) {
                        arr[i][j].first.clear();
                        arr[i][j].second = { 0, 0 };
                        continue;
                    }

                    if (check(i, j)) {
                        v.push_back({ i, j, weight, speed, 0 });
                        v.push_back({ i, j, weight, speed, 2 });
                        v.push_back({ i, j, weight, speed, 4 });
                        v.push_back({ i, j, weight, speed, 6 });
                    }
                    else {
                        v.push_back({ i, j, weight, speed, 1 });
                        v.push_back({ i, j, weight, speed, 3 });
                        v.push_back({ i, j, weight, speed, 5 });
                        v.push_back({ i, j, weight, speed, 7 });
                    }
                }
                else if (as == 1) {
                    v.push_back({ i, j, arr[i][j].second.first, arr[i][j].second.second, arr[i][j].first[0]});
                }
                arr[i][j].first.clear();
                arr[i][j].second = { 0, 0 };
            }
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        answer += v[i][2];
    }

    cout << answer;

    return 0;
}
