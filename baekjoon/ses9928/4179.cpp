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

int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

vector<string> bd;
vector<vector<int> > fireVisited;
vector<vector<int> > jVisited;
queue<pair<int, int> > fireQ;
queue<pair<int, int> > JQ;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    fireVisited.resize(n+1, vector<int>(m+1, 987654321));
    jVisited.resize(n+1, vector<int>(m+1, 987654321));

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        bd.push_back(tmp);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(bd[i][j] == 'J'){
                jVisited[i][j] = 0;
                JQ.push(make_pair(i, j));
                bd[i][j] = '.';
            }
            if(bd[i][j] == 'F'){
                fireVisited[i][j] = 0;
                fireQ.push(make_pair(i, j));
            }
        }
    }
}

void solve()
{
    while(!fireQ.empty()){
        int y = fireQ.front().first;
        int x = fireQ.front().second;
        fireQ.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == '.' && fireVisited[ny][nx] > fireVisited[y][x] + 1){
                    fireVisited[ny][nx] = fireVisited[y][x] + 1;
                    fireQ.push(make_pair(ny, nx));
                }
            }
        }
    }

    while(!JQ.empty()){
        int y = JQ.front().first;
        int x = JQ.front().second;
        JQ.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == '.' && jVisited[ny][nx] > jVisited[y][x] + 1 && jVisited[y][x] + 1 < fireVisited[ny][nx]){
                    jVisited[ny][nx] = jVisited[y][x] + 1;
                    JQ.push(make_pair(ny, nx));
                }
            }
            else{
                cout << jVisited[y][x] + 1;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}