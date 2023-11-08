#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
int GetSum();
int GetBiggestIsland();
int Bfs(int sy, int sx, vector<vector<bool> >& visited);
void Divide(int y1, int x1, int siz, int target_siz);
void Melt();
void Rotate(int y, int x, int siz, vector<vector<int> >& tmp_bd);

const int MAX = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, q;
vector<vector<int> > bd;
vector<int> powers;
void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> q;
    powers.resize(q, 0);
    n = (int)pow(2, n);
    bd.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
        }
    }
    for(int i=0; i<q; i++) cin >> powers[i];
}

void Solve()
{
    for(const int power: powers){
        Divide(0, 0, n, 1 << power);
        Melt();
    }
    cout << GetSum() << endl;
    cout << GetBiggestIsland() << endl;
}

int GetSum(){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum += bd[i][j];
        }
    }
    return sum;
}

int GetBiggestIsland(){
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    int maximum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(bd[i][j] > 0 && !visited[i][j]){
                maximum = max(maximum, Bfs(i, j, visited));
            }
        }
    }
    return maximum;
}

int Bfs(int sy, int sx, vector<vector<bool> >& visited){
    queue<pair<int, int> > q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    int cnt = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                if(bd[ny][nx] >= 1 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void Divide(int y1, int x1, int siz, int target_siz){
    int y2 = y1 + siz;
    int x2 = x1 + siz;

    if(target_siz == siz){
        vector<vector<int> > tmp_bd(target_siz, vector<int>(target_siz, 0));
        for(int i=y1; i<y2; i++){
            for(int j=x1; j<x2; j++){
                tmp_bd[i-y1][j-x1] = bd[i][j];
            }
        }
        Rotate(y1, x1, target_siz, tmp_bd);
        for(int i=y1; i<y2; i++){
            for(int j=x1; j<x2; j++){
                bd[i][j] = tmp_bd[i-y1][j-x1];
            }
        }
        return;
    }
    Divide(y1, x1, siz/2, target_siz); // 0, 0, 4, 4
    Divide(y1 + siz/2, x1, siz/2, target_siz); // 0, 4, 4, 8
    Divide(y1, x1 + siz/2, siz/2, target_siz); // 4, 0, 8, 4
    Divide(y1 + siz/2, x1 + siz/2, siz/2, target_siz); // 4, 4, 8, 8
}

void Melt(){
    vector<pair<int, int> > targets;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            // 녹을 얼음이 없음.
            if(bd[y][x] == 0) continue;

            int cnt = 0;
            for(int d=0; d<4; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    // 얼음이 있는 칸이면
                    if(bd[ny][nx] > 0) cnt++;
                }
            }
            if(cnt >= 3) continue;
            else targets.push_back({y, x});
        }
    }
    for(const pair<int, int>& target: targets){
        bd[target.first][target.second]--;
    }
}

void Rotate(int y, int x, int siz, vector<vector<int> >& origin_bd){
    vector<vector<int> > rotated_bd(siz, vector<int>(siz, 0));

    for(int i=0; i<siz; i++){
        for(int j=0; j<siz; j++){
            rotated_bd[j][siz-1-i] = origin_bd[i][j];
        }
    }
    for(int i=0; i<siz; i++){
        for(int j=0; j<siz; j++){
            origin_bd[i][j] = rotated_bd[i][j];
        }
    }
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}