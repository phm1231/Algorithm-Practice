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

int n, m, cy, cx, d;
vector<vector<int> > bd;
vector<vector<bool> > isClean;
// d = 0이면 북쪽, 1이면 동쪽, 2이면 남쪽, 3이면 서쪽
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    cin >> cy >> cx >> d;
    bd.resize(n, vector<int>(m, 0));
    isClean.resize(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    int y = cy;
    int x = cx;
    int dist = d;
    int answer = 0;
    while(1){
        // 아직 청소하지 않은 칸인 경우
        if(!isClean[y][x]){
            isClean[y][x] = true;
            answer++;
            continue;
        }
        // 주변 칸 검사
        bool isDirty = false;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == 0 && !isClean[ny][nx]){
                    isDirty = true;
                    break;
                }
            }
        }
        // 청소되지 않은 빈 칸이 있는 경우
        if(isDirty){
            // 반시계 방향으로 90도 회전
            dist--;
            if(dist < 0) dist = 3;

            int ny = y + dy[dist];
            int nx = x + dx[dist];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                // 바라보는 방향이 청소되지 않은 곳일 경우
                if(bd[ny][nx] == 0 && !isClean[ny][nx]){
                    // 한 칸 전진한다.
                    y = ny;
                    x = nx;
                    continue;
                }
            }
        }
        else{
            // 바라보는 방향을 유지하면서 한 칸 후진.
            int ny = y + dy[dist] * -1;
            int nx = x + dx[dist] * -1;
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                // 후진 가능하면
                if(bd[ny][nx] == 0){
                    y = ny;
                    x = nx;
                    continue;
                }
            }
            break;
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