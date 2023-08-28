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
void dfs(vector<int>& R, vector<int>& G, int idx);
void go(const vector<int> R, const vector<int> G);

int n, m, g, r, answer;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > board;
vector<pair<int, int> > v; // 배양지임

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> g >> r;
    board.resize(n, vector<int>(m, 0));
    answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                v.push_back(make_pair(i, j));
            }
        }
    }
}

// 0은 통과하지 못함.
// 1이랑 2는 통과할 수 있음
void solve()
{
    vector<int> R, G;
    int idx = 0;
    dfs(R, G, idx);
    cout << answer;
}

void dfs(vector<int>& R, vector<int>& G, int idx){
    if(idx == v.size()){
        if(R.size() == r && G.size() == g){
            go(R, G);
        }
        return;
    }

    // idx번 배양지에 R을 사용함
    if(R.size() < r){
        R.push_back(idx);
        dfs(R, G, idx + 1);
        R.pop_back();
    }
    // idx번 배양지를 사용하지 않음
    dfs(R, G, idx + 1);

    // idx번 배양지에 G를 사용함
    if(G.size() < g){
        G.push_back(idx);
        dfs(R, G, idx + 1);
        G.pop_back();
    }
}

void go(const vector<int> R, const vector<int> G){
    queue<pair<int, int> > redQ;
    queue<pair<int, int> > greenQ;
    queue<pair<int, int> > checkQ;

    vector<vector<int> > bd = board;
    vector<vector<int> > redV(n, vector<int>(m, 987654321)); 
    vector<vector<int> > greenV(n, vector<int>(m, 987654321)); // vistied

    int flower = 0;

    for(int i=0; i<R.size(); i++){
        pair<int, int> loc = v[R[i]];
        redV[loc.first][loc.second] = 1; // 1 2 3 4 5 6
        redQ.push(loc);
    }
    for(int i=0; i<G.size(); i++){
        pair<int, int> loc = v[G[i]];
        greenV[loc.first][loc.second] = 1; // 1 2 3 4 5 6
        greenQ.push(loc);
    }

    while(1){
        int qs = redQ.size();
        while(qs--){
            int y = redQ.front().first;
            int x = redQ.front().second;
            redQ.pop();
            if(bd[y][x] == -1) continue; // 9, 

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < m){
                    if(bd[ny][nx] == 0 || bd[ny][nx] == -1) continue;

                    if(redV[ny][nx] > redV[y][x] + 1){
                        redV[ny][nx] = redV[y][x] + 1;
                        redQ.push(make_pair(ny, nx)); // 다음에 순회할 곳들. 즉 visited가 1 큰곳들임 
                        checkQ.push(make_pair(ny, nx)); // 체크할 곳인데, greenQ 끝난 다음에 겹치는 곳이 있으면 flower를 자라게 함
                    }
                }
            }        
        }
        qs = greenQ.size();
        while(qs--){
            int y = greenQ.front().first;
            int x = greenQ.front().second;
            greenQ.pop();
            if(bd[y][x] == -1) continue;

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < m){
                    if(bd[ny][nx] == 0 || bd[ny][nx] == -1) continue;

                    if(greenV[ny][nx] > greenV[y][x] + 1){
                        greenV[ny][nx] = greenV[y][x] + 1;
                        greenQ.push(make_pair(ny, nx));
                    }
                }
            }        
        }

        // checkQ에는 방금 이제 redQ에서 끝난 친구들이잖아 -> 방금 빨간 배양액이 간 곳임.
        while(!checkQ.empty()){
            int y = checkQ.front().first;
            int x = checkQ.front().second;
            checkQ.pop();
            if(redV[y][x] == greenV[y][x]){ // visited가 똑같으면, 즉 거리가 똑같으면
                bd[y][x] = -1;
                flower++;
            }
        }

        if(redQ.empty() && greenQ.empty()){
            answer = max(answer, flower);
            return;
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}