// based problem:
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(vector<int>& v, int idx);
bool isMoreThan4(const vector<int>& v);
bool isAdjacent(const vector<int>& v);

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int answer = 0;
char bd[5][5];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    vector<int> v;
    dfs(v, 0);
    cout << answer;
}

void dfs(vector<int>& v, int idx){
    if(v.size() == 7){
        if(isMoreThan4(v) && isAdjacent(v)) answer++;
        return;
    }

    for(int i=idx; i<25; i++){
        v.push_back(i);
        dfs(v, i + 1);
        v.pop_back();
    }

}

bool isMoreThan4(const vector<int>& v){
    int cntS = 0;

    for(int i=0; i<v.size(); i++){
        int y = v[i] / 5;
        int x = v[i] % 5;
        if(bd[y][x] == 'S') cntS++;
    }

    return cntS >= 4;
}

bool isAdjacent(const vector<int>& v){
    int visitedCnt = 1;
    bool canGo[5][5];
    bool visited[5][5];
    memset(canGo, false, sizeof(canGo));
    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > q;

    bool isFirst = true;

    for(int i=0; i<v.size(); i++){
        int y = v[i] / 5;
        int x = v[i] % 5;
        canGo[y][x] = true;

        if(isFirst){
            isFirst = false;
            q.push(make_pair(y, x));
            visited[y][x] = true;
        }
    }


    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < 5 && 0 <= nx && nx < 5){
                if(canGo[ny][nx] && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    visitedCnt++;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    return visitedCnt == 7;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}