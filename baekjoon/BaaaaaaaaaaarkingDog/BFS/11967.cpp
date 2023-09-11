#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<vector<pair<int, int> > > > bd;
bool visited[101][101] = {false, };
bool isOn[101][101] = {false, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n, vector<vector<pair<int, int> > >(n, vector<pair<int, int> >()));

    for(int i=0; i<m; i++){
        int y, x, a, b;
        cin >> y >> x >> a >> b;
        bd[y-1][x-1].push_back(make_pair(a-1, b-1));
    }

}

void solve()
{
    queue<pair<int, int> > q;

    q.push(make_pair(0, 0));
    visited[0][0] = true;
    isOn[0][0] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(const pair<int, int>& p: bd[y][x]){
            int _y = p.first;
            int _x = p.second;
            if(!isOn[_y][_x]){
                isOn[_y][_x] = true;
                // 새로 불이 켜진 방의 주변 네 방에 대하여
                for(int i=0; i<4; i++){
                    int ny = _y + dy[i];
                    int nx = _x + dx[i];
                    if(visited[ny][nx]){
                        q.push(make_pair(_y, _x));
                        visited[_y][_x] = true;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                if(!visited[ny][nx] && isOn[ny][nx]){
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isOn[i][j]) answer++;
        }
    }

    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}