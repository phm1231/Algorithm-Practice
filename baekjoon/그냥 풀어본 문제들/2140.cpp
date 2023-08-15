// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {1, 0, -1, -1, 1, 1, 0, -1};

vector<vector<char> > bd;
vector<vector<bool> > mine;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    bd.resize(n, vector<char>(n, 0));
    mine.resize(n, vector<bool>(n, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    int cnt = 0;
    // 테두리 제외하고 회전
    for(int y=1; y<n-1; y++){
        for(int x=1; x<n-1; x++){
            // #임
            if(bd[y][x] == '#'){
                // 둘 수 있는 곳인지 검사
                bool canOn = true;
                for(int i=0; i<8; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(0 <= ny && ny < n && 0 <= nx && nx < n){
                        if(bd[ny][nx] == '#') continue;
                        if(bd[ny][nx] - '0' == 0) canOn = false;
                    }
                }

                // 둘 수 있는 곳이라면
                if(canOn){
                    cnt++;
                    mine[y][x] = true;
                    for(int i=0; i<8; i++){
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(0 <= ny && ny < n && 0 <= nx && nx < n){
                            if(bd[ny][nx] != '#') bd[ny][nx]--;
                        }
                    }
                }
            }
        }
    }

    // 모든 테두리를 만족한 후에, 둘 수 있는 곳 찾기
    for(int y=1; y<n-1; y++){
        for(int x=1; x<n-1; x++){
            // 이미 지뢰라면
            if(mine[y][x]) continue;

            bool canOn = true;
            for(int i=0; i<8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(bd[ny][nx] != '#') canOn = false;
                }
            }
            if(canOn) cnt++;
        }
    }
    cout << cnt;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}