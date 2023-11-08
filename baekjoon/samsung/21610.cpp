#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
void MoveCloud(const int idx, vector<pair<int, int> >& clouds);
void Rain(vector<pair<int, int> >& clouds);
void WaterCopyBug(const vector<pair<int, int> >& clouds);
int GetWaterBasketCount(const pair<int, int>& cloud);
vector<pair<int, int> > CreateCloud(const vector<vector<bool> >& is_colud);
int CorrectRange(const int value);

const int MAX = 1e9;
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m;
vector<vector<int> > bd;
vector<pair<int, int> > movements;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(n, 0));
    movements.reserve(m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
        }
    }
    for(int i=0; i<m; i++){
        cin >> movements[i].first >> movements[i].second;
        --movements[i].first;
    }
}

void Solve()
{
    vector<pair<int, int>> clouds = {{n-1, 0}, {n-1, 1}, {n-2, 0}, {n-2, 1}};

    for(int i=0; i<m; i++){
        MoveCloud(i, clouds); // 구름이 이동한다
        Rain(clouds); // 각 구름에서 비가 내린다.
        WaterCopyBug(clouds); // 물복사버그
        // 구름 정보 저장
        vector<vector<bool> > is_cloud(n, vector<bool>(n, false));
        for(const pair<int, int>& cloud: clouds){
            is_cloud[cloud.first][cloud.second] = true;
        }
        clouds = CreateCloud(is_cloud);
    }
    
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer += bd[i][j];
        }
    }
    cout << answer;
}

void MoveCloud(const int idx, vector<pair<int, int> >& clouds){
    // 모든 구름이 d방향으로 s만큼 이동한다.
    const int d = movements[idx].first;
    const int s = movements[idx].second;
    for(int i=0; i<clouds.size(); i++){
        int y = clouds[i].first;
        int x = clouds[i].second;
        for(int j=0; j<s; j++){
            y = y + dy[d];
            x = x + dx[d];
            y = CorrectRange(y);
            x = CorrectRange(x);
        }
        clouds[i].first = y;
        clouds[i].second = x;
    }
}

void Rain(vector<pair<int, int> >& clouds){
    for(const pair<int, int>& cloud: clouds){
        bd[cloud.first][cloud.second]++;
    }
}

void WaterCopyBug(const vector<pair<int, int> >& clouds){
    for(const pair<int, int>& cloud: clouds){
        bd[cloud.first][cloud.second] += GetWaterBasketCount(cloud);
    }
}

int GetWaterBasketCount(const pair<int, int>& cloud){
    const int y = cloud.first;
    const int x = cloud.second;
    int cnt = 0;
    for(int d=1; d<=7; d+=2){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(0 <= ny && ny < n && 0 <= nx && nx < n){
            if(bd[ny][nx] > 0) cnt++;
        }
    }   
    return cnt;
}

vector<pair<int, int> > CreateCloud(const vector<vector<bool> >& is_cloud){
    vector<pair<int, int> > clouds;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(bd[i][j] >= 2 && !is_cloud[i][j]){
                bd[i][j] -= 2;
                clouds.push_back({i, j});
            }
        }
    }
    return clouds;
}

int CorrectRange(const int value){
    if(value > n-1) return 0;
    else if(value < 0) return n-1;
    else return value;
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}