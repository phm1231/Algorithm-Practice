// based problem:
#include <vector>
#include <iostream>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();
void dfs(int idx, vector<int> v);

int n, m, answer;
vector<vector<int> > board;

vector<pair<int, int> > chickens;
vector<pair<int, int> > houses;

vector<vector<int> > distances;

void init()
{
    FAST
}

void input()
{
    cin >> n >> m;
    board.resize(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];            
            if(board[i][j] == 1) houses.push_back({i, j});
            else if(board[i][j] == 2) chickens.push_back({i, j});
        }
    }
    distances.resize(houses.size(), vector<int>(chickens.size(), 0));
}

void solve()
{
    answer = 987654321;
    for(int i=0; i<houses.size(); i++){
        int hy = houses[i].first;
        int hx = houses[i].second;

        for(int j=0; j<chickens.size(); j++){
            int cy = chickens[j].first;
            int cx = chickens[j].second;
            int dist = abs(cy - hy) + abs(cx - hx);
            distances[i][j] = dist;
        }
    }

    dfs(0, vector<int>());
    cout << answer;
    // 치킨 거리는 집과 가장 가까운 치킨 집
}

void dfs(int idx, vector<int> v){
    // m개를 모음.
    if(v.size() == m){
        // 지금 v에 있는 것들은 치킨집 인덱스
        // 집을 순회하면서 v에 있는 치킨집 들 중 최소값을 뽑아서 더한다.
        int _answer = 0;
        for(int i=0; i<houses.size(); i++){
            int min_dist = 987654321;
            for(int j=0; j<v.size(); j++){
                min_dist = min(min_dist, distances[i][v[j]]);
            }
            _answer += min_dist;
        }
        answer = min(answer, _answer);
        return;
    }
    // 초과함
    if(idx == chickens.size()){
        return;
    }
    else{
        v.push_back(idx);
        dfs(idx + 1, v);
        v.pop_back();
        dfs(idx + 1, v);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}